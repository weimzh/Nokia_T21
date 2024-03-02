#include <common.h>
#include <part.h>
#include <sparse_format.h>
#include <sprd_common_rw.h>
#include "sparse_crc32.h"
#include "../../fs/f2fs-tools/include/f2fs_fs.h"
#include <boot_mode.h>
#include <chipram_env.h>

#define COPY_BUF_SIZE (1024*1024)
#define SPARSE_HEADER_LEN       (sizeof(sparse_header_t))
#define CHUNK_HEADER_LEN (sizeof(chunk_header_t))

/* modify for download very big size ext4 image */
typedef enum EXT4_DL_STATUS_DEF
{
	START = 0,
	END
} EXT4_DL_STATUS_E;

typedef struct {
	chunk_header_t header;    /* chunk header */
	int idx;	  /* index of chunk */
	u64 saved_len;            /* length of chunk which was already saved */
} uncomplete_chunk_t;

extern u32 SCI_GetTickCount(void);

static u8 copybuf[COPY_BUF_SIZE];
static unsigned int g_buf_index = 0;

static sparse_header_t sparse_header;
static EXT4_DL_STATUS_E download_status = END;
static unsigned long current_chunks = 0;
static u32 total_blocks = 0;
static uncomplete_chunk_t uncomplete_ck;/* save chunk relative information */

extern int get_ab_partition(char *);
#ifdef CONFIG_WR_SPARSE
#define DBG_HIST_MAX		128
typedef struct {
	u32 *chunk_addr;
	chunk_header_t hdr;
} sparse_img_dbg_t;
static sparse_img_dbg_t dbg_his[DBG_HIST_MAX];
static int his_c;
#endif

static int read_all(void *buf_src, u32 src_index, void *buf_dest, size_t len)
{
	memcpy(buf_dest, (void*)((u32)buf_src + src_index), len);
	g_buf_index += len;
	return len;
}

static int preread_chunk(void *buf_src, u32 src_index, void *buf_dest, size_t len)
{
	memcpy(buf_dest, (void*)((u32)buf_src + src_index), len);
	return len;
}


static int process_crc32_chunk(void *buf, u32 crc32)
{
	u32 file_crc32;
	int ret;

	ret = read_all(buf, g_buf_index, &file_crc32, 4);
	if (ret != 4) {
		errorf("read returned an error copying a crc32 chunk\n");
		return -1;
	}

	if (file_crc32 != crc32) {
		errorf("computed crc32 of 0x%8.8x, expected 0x%8.8x\n",
			 crc32, file_crc32);
		return -1;
	}

	return 0;
}

#ifdef CONFIG_WR_SPARSE
static void dbg_his_print(void)
{
	chunk_header_t *hdr;
	int i;
	u32 *p;

	printf("%3s %4s %8s %8s\n", "cks", "type", "chunk_sz", "total_sz");
	printf("--- ---- -------- --------\n");
	for (i = 0; i <= his_c && i < DBG_HIST_MAX; i++) {
		hdr = &dbg_his[i].hdr;
		printf("%03d %04x %08x %08x\n", i, hdr->chunk_type, hdr->chunk_sz,
			hdr->total_sz);
	}

	for (i = 0; i <= his_c && i < DBG_HIST_MAX; i++) {
		p = dbg_his[i].chunk_addr - 4;
		printf("%p: %08x %08x %08x %08x\n", p, *p, *(p + 1), *(p + 2), *(p + 3));
		p += 4;
		printf("%p: %08x %08x %08x %08x\n", p, *p, *(p + 1), *(p + 2), *(p + 3));
		p += 4;
		printf("%p: %08x %08x %08x %08x\n\n", p, *p, *(p + 1), *(p + 2), *(p + 3));
	}

	if (his_c && dbg_his[his_c].chunk_addr) {
		p = (u32 *)((u8 *)dbg_his[his_c].chunk_addr + dbg_his[his_c].hdr.total_sz) - 4;
		printf("%p: %08x %08x %08x %08x\n", p, *p, *(p + 1), *(p + 2), *(p + 3));
		p += 4;
		printf("%p: %08x %08x %08x %08x\n", p, *p, *(p + 1), *(p + 2), *(p + 3));
		p += 4;
		printf("%p: %08x %08x %08x %08x\n\n", p, *p, *(p + 1), *(p + 2), *(p + 3));
	}
}
#endif

/* -1 : error; x : buf is finished to write */
int write_sparse_img(uchar * partname, u8* buf, unsigned long length)
{
	unsigned int i;
	unsigned int j;
	chunk_header_t chunk_header;
	u32 crc32 = 0;
	int ret;
	static uint64_t offset = 0;
	uint64_t chunk_len = 0;
	int chunk;
	u32 fill_val;
	u32 *fillbuf;
	u64 sparse_sz, part_sz;
	char temp[32] = {0};
	int v_ab_flag = !get_ab_partition(temp);
	int succ;
	boot_mode_t boot_role = get_boot_role();

	g_buf_index = 0;

	if (download_status == END) {
		memset(&uncomplete_ck, 0, sizeof(uncomplete_ck));
		uncomplete_ck.idx = -1;
		current_chunks = 0;
		total_blocks = 0;
		offset = 0;
		memset(&sparse_header, 0, sizeof(sparse_header_t));
		ret = read_all(buf, g_buf_index, &sparse_header, sizeof(sparse_header));
		debugf("sparse_header file_hdr_sz = %d chunk_hdr_sz = %d blk_sz = %d total_blks = %d total_chunks = %d\n",
			sparse_header.file_hdr_sz, sparse_header.chunk_hdr_sz, sparse_header.blk_sz,

			sparse_header.total_blks, sparse_header.total_chunks);
		if (ret != sizeof(sparse_header)) {
			errorf("Error reading sparse file header\n");
			goto fail;
		}
		if (sparse_header.magic != SPARSE_HEADER_MAGIC) {
			errorf("Bad magic\n");
			goto fail;
		}
		if (sparse_header.major_version != SPARSE_HEADER_MAJOR_VER) {
			errorf("Unknown major version number\n");
			goto fail;
		}

		if (sparse_header.file_hdr_sz > SPARSE_HEADER_LEN) {
			/* Skip the remaining bytes in a header that is longer than
			* we expected.
			 */
			g_buf_index += (sparse_header.file_hdr_sz - SPARSE_HEADER_LEN);
		}
		download_status = START;

#ifdef CONFIG_WR_SPARSE
		memset(dbg_his, 0, sizeof(dbg_his));
		his_c = 0;
#endif
	}

	for (i = current_chunks; i < sparse_header.total_chunks; i++) {
		memset(&chunk_header, 0, sizeof(chunk_header_t));
		if ((g_buf_index + sizeof(chunk_header)) > length) {
			debugf("bufferindex(%d) + sizeof(chunk_header)(%lu) exceed length\n", g_buf_index, sizeof(chunk_header));
			current_chunks = i;
			break;
		}

		if (((!i) && (uncomplete_ck.idx == -1)) || (i != uncomplete_ck.idx)) {
			preread_chunk((void*)buf, g_buf_index, &chunk_header, sizeof(chunk_header));
			//debugf("chunk_header.total_sz(%d)\n", chunk_header.total_sz);

			/*
			 * fixup for "fastboot flash -S 200M system system.img"
			 *   1. first block(200M): the first chunk type must not be 0xCAC3
			 *   2. other blocks: the first chuck type is 0xCAC3 and chunk_len was offset continue
			 *   from last block
			 */
			if (!offset && !current_chunks
				&& (chunk_header.chunk_type != CHUNK_TYPE_DONT_CARE)
				&& strcmp(partname, "userdata")) {
				/* erase partition before spare image write */
				if (
#ifdef CONFIG_WR_SPARSE
					(boot_role == BOOTLOADER_MODE_DOWNLOAD) &&
#endif
					(get_img_partition_size(partname, &part_sz) >= 0)
						&& (part_sz > 0)) {
					unsigned long tick = SCI_GetTickCount();

					if (common_raw_erase((char *)partname, part_sz, 0)) {
						errorf("erase partition %s part sz %llx fail\n",
							(char *)partname, part_sz);
						goto fail;
					}
					printf("erase %s part sz %llx %lums\n", (char *)partname,
						part_sz, SCI_GetTickCount() - tick);
				}
			}

			ret = 0;
			switch (chunk_header.chunk_type) {
			case CHUNK_TYPE_RAW:
			case CHUNK_TYPE_FILL:
			case CHUNK_TYPE_DONT_CARE:
			case CHUNK_TYPE_CRC32:
				if ((g_buf_index + chunk_header.total_sz) > length) {
					debugf("->bufferindex(%d)+chunk_header.total_sz(%d) exceed  length(%lu) \n", g_buf_index, chunk_header.total_sz, length);
					ret = 1;
				}
				break;
			default:
				errorf("->Unknown chunk type 0x%4.4x\n", chunk_header.chunk_type);
#ifdef CONFIG_WR_SPARSE
				{
					int k;
					u32 *p = (u32 *)((u8 *)buf + g_buf_index) - 4;
					errorf("%p: %08x %08x %08x %08x\n", p, *(p), *(p + 1), *(p + 2), *(p + 3));
					p += 4;
					errorf("%p: %08x %08x %08x %08x\n", p, *(p), *(p + 1), *(p + 2), *(p + 3));
					p += 4;
					errorf("%p: %08x %08x %08x %08x\n", p, *(p), *(p + 1), *(p + 2), *(p + 3));
				}
				dbg_his_print();
#endif
				goto fail;
			}

			if (ret == 1) {
				/* save uncomplete chunk header only for type RAW */
				current_chunks = i;
				if (chunk_header.chunk_type == CHUNK_TYPE_RAW) {
					memcpy(&uncomplete_ck.header, &chunk_header, sizeof(chunk_header_t));
					uncomplete_ck.idx = i;
					uncomplete_ck.saved_len = 0;
				} else if ((chunk_header.chunk_type == CHUNK_TYPE_FILL)
							|| (chunk_header.chunk_type == CHUNK_TYPE_DONT_CARE)) {
					debugf("chunk_type %x current_chunks %lu g_buf_index %x, continue for next\n",
						chunk_header.chunk_type, current_chunks, g_buf_index);
					break;
				} else {
					errorf("no support type chunk_type %x\n", chunk_header.chunk_type);
#ifdef CONFIG_WR_SPARSE
					dbg_his_print();
#endif
					goto fail;
				}
			}

			memset(&chunk_header, 0, sizeof(chunk_header_t));
			ret = read_all((void*)buf, g_buf_index, &chunk_header, sizeof(chunk_header));
			if (ret != sizeof(chunk_header)) {
				errorf("Error reading chunk header\n");
				goto fail;
			}

#ifdef CONFIG_WR_SPARSE
			if ((i < DBG_HIST_MAX)
				&& !dbg_his[i].chunk_addr) {
				memcpy(&dbg_his[i].hdr, &chunk_header, sizeof(chunk_header));
				dbg_his[i].chunk_addr = (u32 *)((u8 *)buf + g_buf_index);
				his_c = i;
			}
#endif

			if (sparse_header.chunk_hdr_sz > CHUNK_HEADER_LEN) {
				/* Skip the remaining bytes in a header that is longer than
				 * we expected.*/
				g_buf_index += sparse_header.chunk_hdr_sz - CHUNK_HEADER_LEN;
			}

			/* write current part of this chunk to flash */
			if ((chunk_header.chunk_type == CHUNK_TYPE_RAW)
				&& (i == uncomplete_ck.idx)) {
				chunk_len = length - g_buf_index;
			} else
				chunk_len = (uint64_t)chunk_header.chunk_sz * sparse_header.blk_sz;
		} else {
			memcpy(&chunk_header, &uncomplete_ck.header, sizeof(chunk_header_t));

			chunk_len = (uint64_t)chunk_header.total_sz - sizeof(chunk_header_t)
							- uncomplete_ck.saved_len;
			if (chunk_len > (length - g_buf_index))
				chunk_len = length - g_buf_index;
		}

		switch (chunk_header.chunk_type) {
		case CHUNK_TYPE_RAW:
			if ((i != uncomplete_ck.idx)
				&& (chunk_header.total_sz != (sparse_header.chunk_hdr_sz + chunk_len))) {
				errorf("Bogus chunk size for chunk %d, type Raw\n", i);
				goto fail;
			}

			succ = 0;

			/* If buffer_size satisfies the resize condition, then decompresses the Img directly in memory and try to resize.
			Reserved_buffer here refers to the start address of buffer which used to save the copy of userdataimage. */
			if (!strcmp(partname, "userdata") && g_resize_config.resize_flag == RESIZE_IN_MEM) {
				if (g_resize_config.buffer_begin + offset + chunk_len <= g_resize_config.buffer_end) {
					memcpy(g_resize_config.buffer_begin + offset, buf + g_buf_index, chunk_len);
					succ = 1;
				} else {
					errorf("Reserve userdata in buffer failed: Out of memory!\n");
					goto fail;
				}
			}
#ifdef CONFIG_WR_SPARSE
			else if (boot_role == BOOTLOADER_MODE_LOAD) {
				wr_raw_dbg("RAW(CAC1) trunk_len=0x%x, offset=0x%llx!\n", chunk_len, offset);
				ret = wr_sparse_raw(partname, chunk_len, offset, buf + g_buf_index);
				if (ret < -1) {
					errorf("Raw fail, chunk_len%llx! offset%llx\n",chunk_len,
						offset);
					goto fail;
				} else if (ret == 0)
					succ = 1;/* wr success */
				 else {/* not enable, try raw write */
					 if (0 != common_raw_write(partname, chunk_len, (uint64_t)0, offset, buf + g_buf_index)) {
						 errorf("Raw chunk fail, trunk_len=0x%x!\n", chunk_len);
						 goto fail;
					 } else
						 succ = 1;
				 }
			}
#endif
			else if (0 != common_raw_write(partname, chunk_len, (uint64_t)0, offset, buf + g_buf_index)) {
				errorf("Write raw chunk fail, trunk_len=0x%llx!\n", chunk_len);
				goto fail;
			}
			else {
				/* download complete, nothing to do here. */
				succ = 1;
			}

			/* write partition b only if in download mode */
			if (boot_role == BOOTLOADER_MODE_DOWNLOAD && v_ab_flag) {
				debugf("download slot: %s\n", temp);
				if (0 != common_raw_write(temp, chunk_len, (uint64_t)0, offset, buf + g_buf_index)) {
					errorf("Write raw chunk fail, trunk_len=0x%llx!\n", chunk_len);
					goto fail;
				}
			}

			if (succ) {
				g_buf_index += chunk_len;
				offset += chunk_len;
				if (i == uncomplete_ck.idx) {
					uncomplete_ck.saved_len += chunk_len;
					if (uncomplete_ck.saved_len == (uint64_t)chunk_header.total_sz - sizeof(chunk_header_t)) {
						total_blocks += chunk_header.chunk_sz;
						memset(&uncomplete_ck, 0, sizeof(uncomplete_ck));
						uncomplete_ck.idx = -1;
					} else
						goto out;
				} else
					total_blocks += chunk_header.chunk_sz;
			}
			break;
		case CHUNK_TYPE_FILL:
			if (chunk_header.total_sz != (sparse_header.chunk_hdr_sz + sizeof(fill_val)) ) {
				errorf("Bogus chunk size for chunk %d, type Fill\n", i);
				goto fail;
			}
			/* Fill copy_buf with the fill value */
			ret = read_all(buf, g_buf_index, &fill_val, sizeof(fill_val));

#ifdef CONFIG_WR_SPARSE
			if ((boot_role == BOOTLOADER_MODE_LOAD)
					&& !(!strcmp(partname, "userdata") && g_resize_config.resize_flag == RESIZE_IN_MEM)) {
				wr_fill_dbg("FILL(CAC2) trunk_len=0x%llx, offset=0x%llx!\n", chunk_len, offset);
				ret = wr_sparse_fill(partname, chunk_header.chunk_type,
							chunk_len, offset, fill_val);
				if (ret < -1) { /* fail */
					errorf("Fill fail, chunk_len %llx, offset %llx, fill_val %x\n",
						chunk_len, offset, fill_val);
					goto fail;
				} else if (ret == 0) {/* succ */
					offset += chunk_len;
					chunk_len = 0;
				}/* else not enable */
			}
#endif
			if (chunk_len) {
				fillbuf = (u32 *)copybuf;
				for (j = 0; j < (COPY_BUF_SIZE / sizeof(fill_val)); j++)
					fillbuf[j] = fill_val;
			}

			while (chunk_len) {
				chunk = (chunk_len > COPY_BUF_SIZE) ? COPY_BUF_SIZE : chunk_len;
				if (!strcmp(partname, "userdata") && g_resize_config.resize_flag == RESIZE_IN_MEM) {
					if (g_resize_config.buffer_begin + offset + chunk <= g_resize_config.buffer_end) {
						memcpy(g_resize_config.buffer_begin + offset, copybuf, chunk);
					} else {
						errorf("Reserve userdata in buffer failed: Out of memory!\n");
						goto fail;
					}
				} else if (0 != common_raw_write(partname, chunk, (uint64_t)0, offset, copybuf)) {
					errorf("Write fill chunk fail, trunk_len=0x%llx!\n", chunk_len);
					goto fail;
				}
				else {
					/* download complete, nothing to do here. */
					succ = 1;
				}

				/* write partition b only if in download mode */
				if (boot_role == BOOTLOADER_MODE_DOWNLOAD && v_ab_flag) {
					debugf("download slot: %s\n", temp);
					if (0 != common_raw_write(temp, (uint64_t)chunk, (uint64_t)0, offset, copybuf)) {
						errorf("Write raw chunk fail, trunk_len=0x%x!\n", chunk);
						goto fail;
					}
				}

				offset += chunk;
				chunk_len -= chunk;
			}
			total_blocks += chunk_header.chunk_sz;
			break;
		case CHUNK_TYPE_DONT_CARE:
#ifdef CONFIG_WR_SPARSE
			wr_dontcare_dbg("DONTCARE(CAC3) trunk_len=0x%x, offset=0x%llx!\n", chunk_len, offset);
			if (boot_role == BOOTLOADER_MODE_LOAD) {
				if (!offset && !current_chunks) { /* first chunk */
					ret = wr_sparse_dontcare(partname, chunk_len, offset);
					if (ret < -1) { /* fail */
						errorf("First packet dont care fail, chunk_len %llx, offset %llx\n",
							chunk_len, offset);
						goto fail;
					}
				} else if (!(i == (sparse_header.total_chunks - 1))) { /* except last chunk */
					fill_val = 0;
					ret = wr_sparse_fill(partname, chunk_header.chunk_type,
								chunk_len, offset, fill_val);
					if (ret < -1) { /* fail */
						errorf("Dont care fail, chunk_len %llx, offset %llx, fill_val %x\n",
							chunk_len, offset, fill_val);
						goto fail;
					}
				}
			}
#endif
			if (chunk_header.total_sz != sparse_header.chunk_hdr_sz) {
				errorf("Bogus chunk size for chunk %d, type Dont Care\n", i);
				goto fail;
			}
			offset += chunk_len;
			total_blocks += chunk_header.chunk_sz;
			break;
		case CHUNK_TYPE_CRC32:
			break;
		default:
			errorf("Unknown chunk type 0x%4.4x\n", chunk_header.chunk_type);
#ifdef CONFIG_WR_SPARSE
			dbg_his_print();
#endif
			goto fail;
		}

	}

out:
	if (sparse_header.total_blks != total_blocks) {
		return g_buf_index;
	} else {
		debugf("image download end\n");
		download_status = END;
		current_chunks = 0;
		offset = 0;
		total_blocks = 0;
		return 0;
	}
fail:
	download_status = END;
	current_chunks = 0;
	offset = 0;
	total_blocks = 0;
	return -1;
}
