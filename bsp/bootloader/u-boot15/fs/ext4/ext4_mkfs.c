#include <common.h>
#include <linux/stat.h>
#include <div64.h>

#include "ext4_mkfs.h"

static int int_log2(unsigned long long arg)
{
	int l = 0;

	arg >>= 1;
	while (arg) {
		l++;
		arg >>= 1;
	}
	return l;
}


void ext4_mkfs_fill_meta(disk_partition_t *part_info, int flag)
{

	time_t timestamp = 0;

	int i;

	unsigned int group_count;
	unsigned int group_desc_blocks;
	unsigned int group_desc_per_block;
	unsigned int surplus_block;

	unsigned int overhead = 0;
	unsigned int inode_blocks_per_group;
	unsigned int free_blocks = 0;
	unsigned int byte_overhead_bm;
	unsigned int extra_overhead_bm;
	unsigned int ibm_offset;
	char pos_bm;

	unsigned int lpf_block_cnt;

	struct ext2_super_block *sb;
	char *gdt_block_start;
	char *bbm_block;
	char *ibm_block;
	char *itb_block_start;
	char *root_block;
	char *lpf_block;
	struct ext2_block_group *ptr_gdt;
	struct ext2_block_group group_desc;
	struct ext2_inode_large *init_inode;
	struct ext2_dir_init *root_dir_init;
	struct ext2_dirent *dirent;
	struct ext2_dir_init *lpf_dir_init;

	printf("Begin mkfs_fill_meta\n");
	/*fill super block*/
	sb = zalloc(sizeof(struct ext2_super_block));

	if(!sb){
		printf("No memory!\n");
		goto fail;
	}

	sb->s_magic = EXT2_SUPER_MAGIC;
	sb->s_state = EXT2_VALID_FS;
	sb->s_log_block_size = int_log2( MK_CONFIG_BLOCKSIZE >> EXT2_MIN_BLOCK_LOG_SIZE ); /*4096*/
	sb->s_log_cluster_size = sb->s_log_block_size;/*defect close bigalloc*/
	sb->s_max_mnt_count = 0xffff;/*-1*/
	sb->s_errors = EXT2_ERRORS_DEFAULT;
	sb->s_feature_compat = EXT2_FEATURE_COMPAT_EXT_ATTR | EXT2_FEATURE_COMPAT_DIR_INDEX;
	sb->s_feature_incompat = EXT2_FEATURE_INCOMPAT_FILETYPE;
	sb->s_feature_ro_compat = EXT2_FEATURE_RO_COMPAT_LARGE_FILE;
	sb->s_default_mount_opts = EXT2_DEFM_ACL | EXT2_DEFM_XATTR_USER;
	sb->s_flags = EXT2_FLAGS_UNSIGNED_HASH;
	sb->s_rev_level = EXT2_DYNAMIC_REV;
	sb->s_first_ino = 0x0b; /* 11 */
	sb->s_inode_size = MK_INODE_SIZE; /* 256 */
	sb->s_min_extra_isize = 0x20; /*large inode(160) - inode(128)*/
	sb->s_want_extra_isize = 0x20; /*large inode(160) - inode(128)*/
	sb->s_mkfs_time = sb->s_lastcheck = timestamp;
	sb->s_blocks_per_group = MK_BLOCKS_PER_GROUP;
	sb->s_clusters_per_group = sb->s_blocks_per_group;

	//calculate block
	sb->s_blocks_count = (part_info->size * part_info->blksz) / MK_CONFIG_BLOCKSIZE;
	sb->s_r_blocks_count = sb->s_blocks_count / 100;
	printf("blocks of part is %d\n", sb->s_blocks_count);
	if(flag == 1){
		sb->s_inodes_per_group = MK_INODES_PER_GROUP_MINI;
	}else{
		sb->s_inodes_per_group = MK_INODES_PER_GROUP;
	}
	inode_blocks_per_group = (sb->s_inodes_per_group * sb->s_inode_size) / MK_CONFIG_BLOCKSIZE;
retry:
	printf("Begin retry\n");
	group_count =  ((sb->s_blocks_count - 1) / sb->s_blocks_per_group) + 1;
	printf("group count is %d\n", group_count);
	group_desc_per_block = MK_CONFIG_BLOCKSIZE / sizeof(struct ext2_block_group);
	printf("group_desc_per_block is %d\n", group_desc_per_block);
	group_desc_blocks = (group_count - 1) / group_desc_per_block + 1;
	printf("group_desc_blocks is %d\n", group_desc_blocks);
	overhead = 3 + group_desc_blocks + inode_blocks_per_group;
	printf("overhead is %d\n", overhead);

	surplus_block = sb->s_blocks_count % sb->s_blocks_per_group;
	printf("surplus_block is %d\n", surplus_block);

	if( surplus_block < (overhead + 50) && surplus_block != 0 ){

		sb->s_blocks_count = sb->s_blocks_count - surplus_block;
		sb->s_r_blocks_count = sb->s_blocks_count / 100;

		goto retry;

	}

	sb->s_inodes_count = sb->s_inodes_per_group * group_count;
	sb->s_free_inodes_count = sb->s_inodes_count;

	/*fill group desc table*/

	gdt_block_start = zalloc(group_desc_blocks * MK_CONFIG_BLOCKSIZE); //block
        if(!gdt_block_start){
                printf("No memory!\n");
                goto fail;
        }


	ptr_gdt = (struct ext2_block_group *)gdt_block_start;


	memset(&group_desc, 0, sizeof(struct ext2_block_group));
	group_desc.free_blocks = sb->s_blocks_per_group - overhead;
	group_desc.free_inodes = sb->s_inodes_per_group;

	for(i = 0; i < group_count; i++)
	{
		if(i == (group_count - 1) )
			group_desc.free_blocks = surplus_block - overhead;

		group_desc.block_id = (sb->s_blocks_per_group * i) + 1 + group_desc_blocks;
		group_desc.inode_id = group_desc.block_id + 1;
		group_desc.inode_table_id = group_desc.inode_id + 1;

		memcpy(ptr_gdt + i, &group_desc, sizeof(struct ext2_block_group));

	}

	sb->s_free_blocks_count = sb->s_blocks_count - (overhead * group_count);//data block not use



	/*creat root dir*/
	itb_block_start = zalloc(MK_CONFIG_BLOCKSIZE);
        if(!itb_block_start){
                printf("No memory!\n");
                goto fail;
        }

	init_inode = (struct ext2_inode_large *)itb_block_start;

	/*inode 1*/
	init_inode->i_atime = timestamp;
	init_inode->i_ctime = timestamp;
	init_inode->i_mtime = timestamp;

	/*root inode*/
	init_inode = (struct ext2_inode_large *)(itb_block_start + sb->s_inode_size);
	init_inode->i_mode = S_IFDIR| S_IRWXU |S_IRGRP | S_IROTH | S_IXGRP | S_IXOTH;
	init_inode->i_size = MK_CONFIG_BLOCKSIZE;

	init_inode->i_atime = timestamp;
        init_inode->i_ctime = timestamp;
        init_inode->i_mtime = timestamp;

	init_inode->i_links_count = 2;
	init_inode->i_blocks = MK_CONFIG_BLOCKSIZE / 512;
	init_inode->i_block[0] = overhead;
	init_inode->i_extra_isize = sb->s_want_extra_isize;
	init_inode->i_crtime = timestamp;
	/*fill root block*/
	root_block = zalloc(MK_CONFIG_BLOCKSIZE);
        if(!root_block){
                printf("No memory!\n");
                goto fail;
        }

	root_dir_init = (struct ext2_dir_init *)root_block;
	root_dir_init->self_inode = 2;
	root_dir_init->self_direntlen = 12;
	root_dir_init->self_namelen = 1;
	root_dir_init->self_filetype = FILETYPE_DIRECTORY;
	root_dir_init->parent_inode = 2;
	root_dir_init->parent_direntlen = 4084;
	root_dir_init->parent_namelen = 2;
	root_dir_init->parent_filetype = FILETYPE_DIRECTORY;
	root_dir_init->self_name[0] = '.';
	root_dir_init->parent_name[0] = '.';
	root_dir_init->parent_name[1] = '.';

	sb->s_free_blocks_count -= 1;
	ptr_gdt->free_blocks -= 1;

	/*creat lost + found*/
	lpf_block_cnt = 4;
	/*update parent inode and dir*/
	init_inode->i_links_count += 1;
	root_dir_init->parent_direntlen = 12;
	dirent = (struct ext2_dirent *)(root_block + sizeof(struct ext2_dir_init));
	dirent->inode = 11;
	dirent->direntlen = 4072;
	dirent->namelen = 10;
	dirent->filetype = FILETYPE_DIRECTORY;
	memcpy(dirent + 1, "lost+found", dirent->namelen);
	/*creat inode*/
	init_inode = (struct ext2_inode_large *)(itb_block_start + (sb->s_inode_size * 10) );

	init_inode->i_mode = S_IFDIR| S_IRWXU;
	init_inode->i_size = MK_CONFIG_BLOCKSIZE * lpf_block_cnt;
	init_inode->i_atime = timestamp;
	init_inode->i_ctime = timestamp;
	init_inode->i_mtime = timestamp;
	init_inode->i_links_count = 2;
	init_inode->i_blocks = (MK_CONFIG_BLOCKSIZE / 512) * lpf_block_cnt;

	for(i = 0; i < lpf_block_cnt; i++)
		init_inode->i_block[i] = overhead + i + 1;

        init_inode->i_extra_isize = sb->s_want_extra_isize;
	init_inode->i_crtime = timestamp;
	/*fill lpf 4 data blocks*/
	lpf_block = zalloc(MK_CONFIG_BLOCKSIZE * lpf_block_cnt);
        if(!lpf_block){
                printf("No memory!\n");
                goto fail;
        }

	lpf_dir_init = (struct ext2_dir_init *)lpf_block;
	lpf_dir_init->self_inode = 11;
	lpf_dir_init->self_direntlen = 12;
	lpf_dir_init->self_namelen = 1;
	lpf_dir_init->self_filetype = FILETYPE_DIRECTORY;
	lpf_dir_init->parent_inode = 2;
	lpf_dir_init->parent_direntlen = 4084;
	lpf_dir_init->parent_namelen = 2;
	lpf_dir_init->parent_filetype = FILETYPE_DIRECTORY;
	lpf_dir_init->self_name[0] = '.';
	lpf_dir_init->parent_name[0] = '.';
	lpf_dir_init->parent_name[1] = '.';

	for(i = 1; i <lpf_block_cnt; i++ )
		memset(lpf_block + (MK_CONFIG_BLOCKSIZE * i) + 5, 0x10, 1);

	/*update free blocks in sb and gdt*/
	sb->s_free_blocks_count -= lpf_block_cnt;
	ptr_gdt->free_blocks -= lpf_block_cnt;
	/*update free inodes in sb and gdt*/
	sb->s_free_inodes_count -= 11;
	ptr_gdt->free_inodes -= 11;
	ptr_gdt->used_dir_cnt = 2;
	/*creat last + found done*/

	/*write first group meta to disk*/
	/*write first group sb*/
	put_ext4(1024, sb, sizeof(struct ext2_super_block));
	/*write first group gdt*/
	put_ext4(4096, gdt_block_start, group_desc_blocks * MK_CONFIG_BLOCKSIZE);
	/* fill first group block bitmap*/
	bbm_block = zalloc(MK_CONFIG_BLOCKSIZE);
        if(!bbm_block){
                printf("No memory!\n");
                goto fail;
        }

	byte_overhead_bm = (overhead + 1 +lpf_block_cnt) / 8;
	extra_overhead_bm = (overhead + 1 +lpf_block_cnt) % 8;
	pos_bm = ~(0xFF << extra_overhead_bm);

	memset(bbm_block, 0xFF, byte_overhead_bm);
	memset(bbm_block + byte_overhead_bm, pos_bm, 1);
	/*write first group bbm*/
	put_ext4((1 + group_desc_blocks) * MK_CONFIG_BLOCKSIZE, bbm_block, MK_CONFIG_BLOCKSIZE);


	/* fill first group inode bitmap*/
	ibm_block = zalloc(MK_CONFIG_BLOCKSIZE);
        if(!ibm_block){
                printf("No memory!\n");
                goto fail;
        }

	byte_overhead_bm = 11 / 8;
	extra_overhead_bm = 11 % 8;
	pos_bm = ~(0xFF << extra_overhead_bm);
	ibm_offset = sb->s_inodes_per_group / 8;

	memset(ibm_block, 0xFF, byte_overhead_bm);
	memset(ibm_block + byte_overhead_bm, pos_bm, 1);
	memset(ibm_block + ibm_offset, 0xFF, MK_CONFIG_BLOCKSIZE - ibm_offset);
        /*write first group ibm*/
        put_ext4((group_desc_blocks + 2) * MK_CONFIG_BLOCKSIZE, ibm_block, MK_CONFIG_BLOCKSIZE);

	/*write first group itb*/
	put_ext4((group_desc_blocks + 3) * MK_CONFIG_BLOCKSIZE, itb_block_start, MK_CONFIG_BLOCKSIZE);

	/*write root block*/
	put_ext4(overhead * MK_CONFIG_BLOCKSIZE, root_block, MK_CONFIG_BLOCKSIZE);

	/*write last+found block*/
	put_ext4((overhead + 1) * MK_CONFIG_BLOCKSIZE, lpf_block, MK_CONFIG_BLOCKSIZE * lpf_block_cnt);

	/*write other group meta*/
	/*fill other group bbm*/
	memset(bbm_block, 0, MK_CONFIG_BLOCKSIZE);
        byte_overhead_bm = overhead / 8;
        extra_overhead_bm = overhead % 8;
        pos_bm = ~(0xFF << extra_overhead_bm);

        memset(bbm_block, 0xFF, byte_overhead_bm);
        memset(bbm_block + byte_overhead_bm, pos_bm, 1);
	/*fill other group ibm*/
	memset(ibm_block, 0, MK_CONFIG_BLOCKSIZE);
	memset(ibm_block + ibm_offset, 0xFF, MK_CONFIG_BLOCKSIZE - ibm_offset);

	/*write other group meta to disk*/
	for(i=1; i < group_count; i++)
	{
		//printf("Group %d\n",i);
		//printf("Group %d\n superblock\n",i);
		put_ext4((uint64_t)((MK_BLOCKS_PER_GROUP * i) * MK_CONFIG_BLOCKSIZE + 1024), sb, sizeof(struct ext2_super_block));
		//printf("Group %d\n group desc\n",i);
		put_ext4((uint64_t)(((MK_BLOCKS_PER_GROUP * i) + 1) * MK_CONFIG_BLOCKSIZE), gdt_block_start, group_desc_blocks * MK_CONFIG_BLOCKSIZE);

		if ((i == (group_count - 1)) && (surplus_block != 0)) {

			byte_overhead_bm = surplus_block / 8;
			extra_overhead_bm = surplus_block % 8;
			pos_bm = (0xFF << extra_overhead_bm);
			memset(bbm_block + byte_overhead_bm, pos_bm, 1);
			memset(bbm_block + byte_overhead_bm + 1, 0XFF, MK_CONFIG_BLOCKSIZE - byte_overhead_bm - 1);
			put_ext4((uint64_t)(((MK_BLOCKS_PER_GROUP * i) + (uint64_t)group_desc_blocks + 1) * MK_CONFIG_BLOCKSIZE), bbm_block, MK_CONFIG_BLOCKSIZE);

		} else {
			//printf("Group %d\n block bit map\n",i);
			put_ext4((uint64_t)(((MK_BLOCKS_PER_GROUP * i) + (uint64_t)group_desc_blocks + 1) * MK_CONFIG_BLOCKSIZE), bbm_block, MK_CONFIG_BLOCKSIZE);	

		}
		//printf("Group %d\n inode bit map\n",i);
		put_ext4((uint64_t)(((MK_BLOCKS_PER_GROUP * i) + (uint64_t)group_desc_blocks + 2) * MK_CONFIG_BLOCKSIZE), ibm_block, MK_CONFIG_BLOCKSIZE);

	}

	free(ibm_block);
	free(bbm_block);
	free(lpf_block);
	free(root_block);
	free(itb_block_start);
	free(gdt_block_start);
	free(sb);

	return 0;

fail:
        free(ibm_block);
        free(bbm_block);
        free(lpf_block);
        free(root_block);
        free(itb_block_start);
        free(gdt_block_start);
        free(sb);

        return -1;


}
