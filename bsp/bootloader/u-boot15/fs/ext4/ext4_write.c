/*
 * (C) Copyright 2011 - 2012 Samsung Electronics
 * EXT4 filesystem implementation in Uboot by
 * Uma Shankar <uma.shankar@samsung.com>
 * Manjunatha C Achar <a.manjunatha@samsung.com>
 *
 * ext4ls and ext4load : Based on ext2 ls and load support in Uboot.
 *		       Ext4 read optimization taken from Open-Moko
 *		       Qi bootloader
 *
 * (C) Copyright 2004
 * esd gmbh <www.esd-electronics.com>
 * Reinhard Arlt <reinhard.arlt@esd-electronics.com>
 *
 * based on code from grub2 fs/ext2.c and fs/fshelp.c by
 * GRUB  --  GRand Unified Bootloader
 * Copyright (C) 2003, 2004  Free Software Foundation, Inc.
 *
 * ext4write : Based on generic ext4 protocol.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */


#include <common.h>
#include <linux/stat.h>
#include <div64.h>
#include "ext4_common.h"

static void ext4fs_update(void)
{
	short i;
	ext4fs_update_journal();
	struct ext_filesystem *fs = get_fs();

	/* update  super block */
	put_ext4((uint64_t)(SUPERBLOCK_SIZE),
		 (struct ext2_sblock *)fs->sb, (uint32_t)SUPERBLOCK_SIZE);

	/* update block groups */
	for (i = 0; i < fs->no_blkgrp; i++) {
		fs->bgd[i].bg_checksum = ext4fs_checksum_update(i);
		put_ext4((uint64_t)((uint64_t)fs->bgd[i].block_id * (uint64_t)fs->blksz),
			 fs->blk_bmaps[i], fs->blksz);
	}

	/* update inode table groups */
	for (i = 0; i < fs->no_blkgrp; i++) {
		put_ext4((uint64_t) ((uint64_t)fs->bgd[i].inode_id * (uint64_t)fs->blksz),
			 fs->inode_bmaps[i], fs->blksz);
	}

	/* update the block group descriptor table */
	put_ext4((uint64_t)((uint64_t)fs->gdtable_blkno * (uint64_t)fs->blksz),
		 (struct ext2_block_group *)fs->gdtable,
		 (fs->blksz * fs->no_blk_pergdt));

	ext4fs_dump_metadata();

	gindex = 0;
	gd_index = 0;
}

int ext4fs_get_bgdtable(void)
{
	int status;
	int grp_desc_size;
	struct ext_filesystem *fs = get_fs();
	grp_desc_size = sizeof(struct ext2_block_group);
	fs->no_blk_pergdt = (fs->no_blkgrp * grp_desc_size) / fs->blksz;
	if ((fs->no_blkgrp * grp_desc_size) % fs->blksz)
		fs->no_blk_pergdt++;

	/* allocate memory for gdtable */
	fs->gdtable = zalloc(fs->blksz * fs->no_blk_pergdt);
	if (!fs->gdtable)
		return -ENOMEM;
	/* read the group descriptor table */
	status = ext4fs_devread((lbaint_t)fs->gdtable_blkno * fs->sect_perblk,
				0, fs->blksz * fs->no_blk_pergdt, fs->gdtable);
	if (status == 0)
		goto fail;

	if (ext4fs_log_gdt(fs->gdtable)) {
		printf("Error in ext4fs_log_gdt\n");
		return -1;
	}

	return 0;
fail:
	free(fs->gdtable);
	fs->gdtable = NULL;

	return -1;
}

static void delete_single_indirect_block(struct ext2_inode *inode)
{
	struct ext2_block_group *bgd = NULL;
	static int prev_bg_bmap_idx = -1;
	long int blknr;
	int remainder;
	int bg_idx;
	int status;
	unsigned int blk_per_grp = ext4fs_root->sblock.blocks_per_group;
	struct ext_filesystem *fs = get_fs();
	char *journal_buffer = zalloc(fs->blksz);
	if (!journal_buffer) {
		printf("No memory\n");
		return;
	}
	/* get  block group descriptor table */
	bgd = (struct ext2_block_group *)fs->gdtable;

	/* deleting the single indirect block associated with inode */
	if (inode->b.blocks.indir_block != 0) {
		//debug("SIPB releasing %u\n", inode->b.blocks.indir_block);
		blknr = inode->b.blocks.indir_block;
		bg_idx = blknr / blk_per_grp;
		if (fs->blksz == 1024) {
			remainder = blknr % blk_per_grp;
			if (!remainder)
				bg_idx--;
		}
		ext4fs_reset_block_bmap(blknr, fs->blk_bmaps[bg_idx], bg_idx);
		bgd[bg_idx].free_blocks++;
		fs->sb->free_blocks++;
		/* journal backup */
		if (prev_bg_bmap_idx != bg_idx) {
			status =
			    ext4fs_devread((lbaint_t)bgd[bg_idx].block_id *
					   fs->sect_perblk, 0, fs->blksz,
					   journal_buffer);
			if (status == 0)
				goto fail;
			if (ext4fs_log_journal
			    (journal_buffer, bgd[bg_idx].block_id))
				goto fail;
			prev_bg_bmap_idx = bg_idx;
		}
	}
fail:
	free(journal_buffer);
}

static void delete_double_indirect_block(struct ext2_inode *inode)
{
	int i;
	short status;
	static int prev_bg_bmap_idx = -1;
	long int blknr;
	int remainder;
	int bg_idx;
	unsigned int blk_per_grp = ext4fs_root->sblock.blocks_per_group;
	unsigned int *di_buffer = NULL;
	unsigned int *DIB_start_addr = NULL;
	struct ext2_block_group *bgd = NULL;
	struct ext_filesystem *fs = get_fs();
	char *journal_buffer = zalloc(fs->blksz);
	if (!journal_buffer) {
		printf("No memory\n");
		return;
	}
	/* get the block group descriptor table */
	bgd = (struct ext2_block_group *)fs->gdtable;

	if (inode->b.blocks.double_indir_block != 0) {
		di_buffer = zalloc(fs->blksz);
		if (!di_buffer) {
			printf("No memory\n");
			return;
		}
		DIB_start_addr = (unsigned int *)di_buffer;
		blknr = inode->b.blocks.double_indir_block;
		status = ext4fs_devread((lbaint_t)blknr * fs->sect_perblk, 0,
					fs->blksz, (char *)di_buffer);
		for (i = 0; i < fs->blksz / sizeof(int); i++) {
			if (*di_buffer == 0)
				break;

			//debug("DICB releasing %u\n", *di_buffer);
			bg_idx = *di_buffer / blk_per_grp;
			if (fs->blksz == 1024) {
				remainder = *di_buffer % blk_per_grp;
				if (!remainder)
					bg_idx--;
			}
			ext4fs_reset_block_bmap(*di_buffer,
					fs->blk_bmaps[bg_idx], bg_idx);
			di_buffer++;
			bgd[bg_idx].free_blocks++;
			fs->sb->free_blocks++;
			/* journal backup */
			if (prev_bg_bmap_idx != bg_idx) {
				status = ext4fs_devread((lbaint_t)
							bgd[bg_idx].block_id
							* fs->sect_perblk, 0,
							fs->blksz,
							journal_buffer);
				if (status == 0)
					goto fail;

				if (ext4fs_log_journal(journal_buffer,
							bgd[bg_idx].block_id))
					goto fail;
				prev_bg_bmap_idx = bg_idx;
			}
		}

		/* removing the parent double indirect block */
		blknr = inode->b.blocks.double_indir_block;
		bg_idx = blknr / blk_per_grp;
		if (fs->blksz == 1024) {
			remainder = blknr % blk_per_grp;
			if (!remainder)
				bg_idx--;
		}
		ext4fs_reset_block_bmap(blknr, fs->blk_bmaps[bg_idx], bg_idx);
		bgd[bg_idx].free_blocks++;
		fs->sb->free_blocks++;
		/* journal backup */
		if (prev_bg_bmap_idx != bg_idx) {
			memset(journal_buffer, '\0', fs->blksz);
			status = ext4fs_devread((lbaint_t)bgd[bg_idx].block_id *
						fs->sect_perblk, 0, fs->blksz,
						journal_buffer);
			if (status == 0)
				goto fail;

			if (ext4fs_log_journal(journal_buffer,
						bgd[bg_idx].block_id))
				goto fail;
			prev_bg_bmap_idx = bg_idx;
		}
		//debug("DIPB releasing %ld\n", blknr);
	}
fail:
	free(DIB_start_addr);
	free(journal_buffer);
}

static void delete_triple_indirect_block(struct ext2_inode *inode)
{
	int i, j;
	short status;
	static int prev_bg_bmap_idx = -1;
	long int blknr;
	int remainder;
	int bg_idx;
	unsigned int blk_per_grp = ext4fs_root->sblock.blocks_per_group;
	unsigned int *tigp_buffer = NULL;
	unsigned int *tib_start_addr = NULL;
	unsigned int *tip_buffer = NULL;
	unsigned int *tipb_start_addr = NULL;
	struct ext2_block_group *bgd = NULL;
	struct ext_filesystem *fs = get_fs();
	char *journal_buffer = zalloc(fs->blksz);
	if (!journal_buffer) {
		printf("No memory\n");
		return;
	}
	/* get block group descriptor table */
	bgd = (struct ext2_block_group *)fs->gdtable;

	if (inode->b.blocks.triple_indir_block != 0) {
		tigp_buffer = zalloc(fs->blksz);
		if (!tigp_buffer) {
			printf("No memory\n");
			return;
		}
		tib_start_addr = (unsigned int *)tigp_buffer;
		blknr = inode->b.blocks.triple_indir_block;
		status = ext4fs_devread((lbaint_t)blknr * fs->sect_perblk, 0,
					fs->blksz, (char *)tigp_buffer);
		for (i = 0; i < fs->blksz / sizeof(int); i++) {
			if (*tigp_buffer == 0)
				break;
			debug("tigp buffer releasing %u\n", *tigp_buffer);

			tip_buffer = zalloc(fs->blksz);
			if (!tip_buffer)
				goto fail;
			tipb_start_addr = (unsigned int *)tip_buffer;
			status = ext4fs_devread((lbaint_t)(*tigp_buffer) *
						fs->sect_perblk, 0, fs->blksz,
						(char *)tip_buffer);
			for (j = 0; j < fs->blksz / sizeof(int); j++) {
				if (*tip_buffer == 0)
					break;
				bg_idx = *tip_buffer / blk_per_grp;
				if (fs->blksz == 1024) {
					remainder = *tip_buffer % blk_per_grp;
					if (!remainder)
						bg_idx--;
				}

				ext4fs_reset_block_bmap(*tip_buffer,
							fs->blk_bmaps[bg_idx],
							bg_idx);

				tip_buffer++;
				bgd[bg_idx].free_blocks++;
				fs->sb->free_blocks++;
				/* journal backup */
				if (prev_bg_bmap_idx != bg_idx) {
					status =
					    ext4fs_devread(
							(lbaint_t)
							bgd[bg_idx].block_id *
							fs->sect_perblk, 0,
							fs->blksz,
							journal_buffer);
					if (status == 0)
						goto fail;

					if (ext4fs_log_journal(journal_buffer,
							       bgd[bg_idx].
							       block_id))
						goto fail;
					prev_bg_bmap_idx = bg_idx;
				}
			}
			free(tipb_start_addr);
			tipb_start_addr = NULL;

			/*
			 * removing the grand parent blocks
			 * which is connected to inode
			 */
			bg_idx = *tigp_buffer / blk_per_grp;
			if (fs->blksz == 1024) {
				remainder = *tigp_buffer % blk_per_grp;
				if (!remainder)
					bg_idx--;
			}
			ext4fs_reset_block_bmap(*tigp_buffer,
						fs->blk_bmaps[bg_idx], bg_idx);

			tigp_buffer++;
			bgd[bg_idx].free_blocks++;
			fs->sb->free_blocks++;
			/* journal backup */
			if (prev_bg_bmap_idx != bg_idx) {
				memset(journal_buffer, '\0', fs->blksz);
				status =
				    ext4fs_devread((lbaint_t)
						   bgd[bg_idx].block_id *
						   fs->sect_perblk, 0,
						   fs->blksz, journal_buffer);
				if (status == 0)
					goto fail;

				if (ext4fs_log_journal(journal_buffer,
							bgd[bg_idx].block_id))
					goto fail;
				prev_bg_bmap_idx = bg_idx;
			}
		}

		/* removing the grand parent triple indirect block */
		blknr = inode->b.blocks.triple_indir_block;
		bg_idx = blknr / blk_per_grp;
		if (fs->blksz == 1024) {
			remainder = blknr % blk_per_grp;
			if (!remainder)
				bg_idx--;
		}
		ext4fs_reset_block_bmap(blknr, fs->blk_bmaps[bg_idx], bg_idx);
		bgd[bg_idx].free_blocks++;
		fs->sb->free_blocks++;
		/* journal backup */
		if (prev_bg_bmap_idx != bg_idx) {
			memset(journal_buffer, '\0', fs->blksz);
			status = ext4fs_devread((lbaint_t)bgd[bg_idx].block_id *
						fs->sect_perblk, 0, fs->blksz,
						journal_buffer);
			if (status == 0)
				goto fail;

			if (ext4fs_log_journal(journal_buffer,
						bgd[bg_idx].block_id))
				goto fail;
			prev_bg_bmap_idx = bg_idx;
		}
		debug("tigp buffer itself releasing %ld\n", blknr);
	}
fail:
	free(tib_start_addr);
	free(tipb_start_addr);
	free(journal_buffer);
}

static int ext4fs_delete_file(int inodeno)
{
	struct ext2_inode inode;
	short status;
	int i;
	int remainder;
	long int blknr;
	int bg_idx;
	int ibmap_idx;
	char *read_buffer = NULL;
	char *start_block_address = NULL;
	unsigned int no_blocks;

	static int prev_bg_bmap_idx = -1;
	unsigned int inodes_per_block;
	long int blkno;
	unsigned int blkoff;
	unsigned int blk_per_grp = ext4fs_root->sblock.blocks_per_group;
	unsigned int inode_per_grp = ext4fs_root->sblock.inodes_per_group;
	struct ext2_inode *inode_buffer = NULL;
	struct ext2_block_group *bgd = NULL;
	struct ext_filesystem *fs = get_fs();
	char *journal_buffer = zalloc(fs->blksz);

	printf("enter ext4fs_delete_file,inode no is %d\n",inodeno);

	if (!journal_buffer)
		return -ENOMEM;
	/* get the block group descriptor table */
	bgd = (struct ext2_block_group *)fs->gdtable;
	status = ext4fs_read_inode(ext4fs_root, inodeno, &inode);
	if (status == 0)
		goto fail;

	/* read the block no allocated to a file */
	no_blocks = inode.size / fs->blksz;
	if (inode.size % fs->blksz)
		no_blocks++;

	if (le32_to_cpu(inode.flags) & EXT4_EXTENTS_FL) {
		struct ext2fs_node *node_inode =
		    zalloc(sizeof(struct ext2fs_node));
		if (!node_inode)
			goto fail;
		node_inode->data = ext4fs_root;
		node_inode->ino = inodeno;
		node_inode->inode_read = 0;
		memcpy(&(node_inode->inode), &inode, sizeof(struct ext2_inode));

		for (i = 0; i < no_blocks; i++) {
			blknr = read_allocated_block(&(node_inode->inode), i);
			bg_idx = blknr / blk_per_grp;
			if (fs->blksz == 1024) {
				remainder = blknr % blk_per_grp;
				if (!remainder)
					bg_idx--;
			}
			ext4fs_reset_block_bmap(blknr, fs->blk_bmaps[bg_idx],
						bg_idx);
			debug("EXT4_EXTENTS Block releasing %ld: %d\n",
			      blknr, bg_idx);

			bgd[bg_idx].free_blocks++;
			fs->sb->free_blocks++;

			/* journal backup */
			if (prev_bg_bmap_idx != bg_idx) {
				status =
				    ext4fs_devread((lbaint_t)
						   bgd[bg_idx].block_id *
						   fs->sect_perblk, 0,
						   fs->blksz, journal_buffer);
				if (status == 0)
					goto fail;
				if (ext4fs_log_journal(journal_buffer,
							bgd[bg_idx].block_id))
					goto fail;
				prev_bg_bmap_idx = bg_idx;
			}
		}
		if (node_inode) {
			free(node_inode);
			node_inode = NULL;
		}
	} else {

		delete_single_indirect_block(&inode);
		delete_double_indirect_block(&inode);
		delete_triple_indirect_block(&inode);

		/* read the block no allocated to a file */
		no_blocks = inode.size / fs->blksz;
		if (inode.size % fs->blksz)
			no_blocks++;
		for (i = 0; i < no_blocks; i++) {
			blknr = read_allocated_block(&inode, i);
			bg_idx = blknr / blk_per_grp;
			if (fs->blksz == 1024) {
				remainder = blknr % blk_per_grp;
				if (!remainder)
					bg_idx--;
			}
			ext4fs_reset_block_bmap(blknr, fs->blk_bmaps[bg_idx],
						bg_idx);
			//debug("ActualB releasing %ld: %d\n", blknr, bg_idx);

			bgd[bg_idx].free_blocks++;
			fs->sb->free_blocks++;
			/* journal backup */
			if (prev_bg_bmap_idx != bg_idx) {
				memset(journal_buffer, '\0', fs->blksz);
				status = ext4fs_devread((lbaint_t)
							bgd[bg_idx].block_id
							* fs->sect_perblk,
							0, fs->blksz,
							journal_buffer);
				if (status == 0)
					goto fail;
				if (ext4fs_log_journal(journal_buffer,
						bgd[bg_idx].block_id))
					goto fail;
				prev_bg_bmap_idx = bg_idx;
			}
		}
	}

	/* from the inode no to blockno */
	inodes_per_block = fs->blksz / fs->inodesz;
	ibmap_idx = inodeno / inode_per_grp;

	/* get the block no */
	inodeno--;
	blkno = __le32_to_cpu(bgd[ibmap_idx].inode_table_id) +
		(inodeno % __le32_to_cpu(inode_per_grp)) / inodes_per_block;

	/* get the offset of the inode */
	blkoff = ((inodeno) % inodes_per_block) * fs->inodesz;

	/* read the block no containing the inode */
	read_buffer = zalloc(fs->blksz);
	if (!read_buffer)
		goto fail;
	start_block_address = read_buffer;
	status = ext4fs_devread((lbaint_t)blkno * fs->sect_perblk,
				0, fs->blksz, read_buffer);
	if (status == 0)
		goto fail;

	if (ext4fs_log_journal(read_buffer, blkno))
		goto fail;

	read_buffer = read_buffer + blkoff;
	inode_buffer = (struct ext2_inode *)read_buffer;
	memset(inode_buffer, '\0', sizeof(struct ext2_inode));

	/* write the inode to original position in inode table */
	if (ext4fs_put_metadata(start_block_address, blkno))
		goto fail;

	/* update the respective inode bitmaps */
	inodeno++;
	ext4fs_reset_inode_bmap(inodeno, fs->inode_bmaps[ibmap_idx], ibmap_idx);
	bgd[ibmap_idx].free_inodes++;
	fs->sb->free_inodes++;
	/* journal backup */
	memset(journal_buffer, '\0', fs->blksz);
	status = ext4fs_devread((lbaint_t)bgd[ibmap_idx].inode_id *
				fs->sect_perblk, 0, fs->blksz, journal_buffer);
	if (status == 0)
		goto fail;
	if (ext4fs_log_journal(journal_buffer, bgd[ibmap_idx].inode_id))
		goto fail;

	ext4fs_update();
	ext4fs_deinit();
	ext4fs_reinit_global();

	if (ext4fs_init() != 0) {
		printf("error in File System init\n");
		goto fail;
	}

	free(start_block_address);
	free(journal_buffer);

	return 0;
fail:
	free(start_block_address);
	free(journal_buffer);

	return -1;
}

int ext4_del_file(const char *fname)
{
	int parent_inodeno;
	int existing_file_inodeno;
	int ret = 0;

	struct ext_filesystem *fs = get_fs();
	ALLOC_CACHE_ALIGN_BUFFER(char, filename, 256);
	memset(filename, 0x00, 256);

	if (!ext4fs_mount(0)) {
		printf("** Error Bad ext4 partition **\n");
		goto fail;
	}

	g_parent_inode = zalloc(sizeof(struct ext2_inode));
	if (!g_parent_inode)
		goto fail;

	if (ext4fs_init() != 0) {
		printf("error in File System init\n");
		return -1;
	}

	parent_inodeno = ext4fs_get_parent_inode_num(fname, filename, F_FILE);
	if (parent_inodeno == -1)
		goto fail;
	if (ext4fs_iget(parent_inodeno, g_parent_inode))
		goto fail;
	/* check if the filename is already present in root */
	existing_file_inodeno = ext4fs_filename_check(filename);
	printf("file inode no is %d\n", existing_file_inodeno);

	ret = ext4fs_delete_file(existing_file_inodeno);
	fs->first_pass_bbmap = 0;
	fs->curr_blkno = 0;

	fs->first_pass_ibmap = 0;
	fs->curr_inode_no = 0;
	if (ret)
		goto fail;

	ext4fs_update();
	ext4fs_deinit();
	free(g_parent_inode);

	return 0;

fail:
	free(g_parent_inode);
	return -1;



}

int ext4_del_dir(int dir_inode_no)
{
	int status;
	int totalbytes;
	int direct_blk_idx;
	long int blknr;
	struct ext2_inode dir_inode;

	char *block_buffer = NULL;
	struct ext2_dirent *dir = NULL;
	struct ext2_dirent *previous_dir = NULL;
	struct ext_filesystem *fs = get_fs();
	printf("enter ext4_del_dir\n");

	ext4fs_iget(dir_inode_no, &dir_inode);

	for(direct_blk_idx = 0; direct_blk_idx < INDIRECT_BLOCKS;direct_blk_idx++) {

		blknr = read_allocated_block(&dir_inode, direct_blk_idx);
		if(blknr == 0)
			break;

		block_buffer = zalloc(fs->blksz);
		if (!block_buffer)
			goto fail;

		status = ext4fs_devread((lbaint_t)blknr * fs->sect_perblk,
					0, fs->blksz, (char *)block_buffer);

		if(status == 0)
			goto fail;

		dir = (struct ext2_dirent *)( block_buffer + 12);

		if(dir->direntlen == (fs->blksz - 12)){



		}else{
			dir = (struct ext2_dirent *)( block_buffer + 24);
			totalbytes = 24;

			while(dir->direntlen >= 0){

				if(dir->filetype == FILETYPE_REG)
					ext4fs_delete_file(dir->inode);
				if(dir->filetype == FILETYPE_DIRECTORY)
					ext4_del_dir(dir->inode);

				if(dir->direntlen == fs->blksz - totalbytes)
					break;

				totalbytes += dir->direntlen;
				dir = (struct ext2_dirent *)((char *)dir + dir->direntlen); 
			}
		}
	}

	printf("delete empty dir, dir inode no is %d\n",dir_inode_no);

	ext4fs_delete_file(dir_inode_no);\

fail:
	free(block_buffer);
	return -1;


}

int ext4_rm_dir(const char *fname)
{
	int dir_inode_no;
	int parent_inode_no;
	ALLOC_CACHE_ALIGN_BUFFER(char, dirname, 256);
	memset(dirname, 0x00, 256);

	printf("enter ext4_rm_dir\n");
	if (!ext4fs_mount(0)) {
		printf("** Error Bad ext4 partition **\n");
		goto fail;
	}

	g_parent_inode = zalloc(sizeof(struct ext2_inode));
	if (!g_parent_inode)
		goto fail;

	if (ext4fs_init() != 0) {
		printf("error in File System init\n");
		goto fail;
	}

	dir_inode_no = get_inode_no(fname, dirname, &parent_inode_no);
	printf("deleted dir inode no is %d\n",dir_inode_no);

	ext4_del_dir(dir_inode_no);


	if (ext4fs_iget(parent_inode_no, g_parent_inode))
		goto fail;
	ext4fs_filename_check(dirname);

	ext4fs_update();
	ext4fs_deinit();

	free(g_parent_inode);
	return 0;

fail:
	free(g_parent_inode);
	return -1;

}




int ext4fs_init(void)
{
	short status;
	int i;
	unsigned int real_free_blocks = 0;
	struct ext_filesystem *fs = get_fs();

	/* populate fs */
	fs->blksz = EXT2_BLOCK_SIZE(ext4fs_root);
	fs->inodesz = INODE_SIZE_FILESYSTEM(ext4fs_root);
	fs->sect_perblk = fs->blksz >> fs->dev_desc->log2blksz;

	/* get the superblock */
	fs->sb = zalloc(SUPERBLOCK_SIZE);
	if (!fs->sb)
		return -ENOMEM;
	if (!ext4_read_superblock((char *)fs->sb))
		goto fail;

	/* init journal */
	if (ext4fs_init_journal())
		goto fail;

	/* get total no of blockgroups */
	fs->no_blkgrp = (uint32_t)ext4fs_div_roundup(
			(ext4fs_root->sblock.total_blocks -
			ext4fs_root->sblock.first_data_block),
			ext4fs_root->sblock.blocks_per_group);

	/* get the block group descriptor table */
	fs->gdtable_blkno = ((EXT2_MIN_BLOCK_SIZE == fs->blksz) + 1);
	if (ext4fs_get_bgdtable() == -1) {
		printf("Error in getting the block group descriptor table\n");
		goto fail;
	}
	fs->bgd = (struct ext2_block_group *)fs->gdtable;

	/* load all the available bitmap block of the partition */
	fs->blk_bmaps = zalloc(fs->no_blkgrp * sizeof(char *));
	if (!fs->blk_bmaps)
		goto fail;
	for (i = 0; i < fs->no_blkgrp; i++) {
		fs->blk_bmaps[i] = zalloc(fs->blksz);
		if (!fs->blk_bmaps[i])
			goto fail;
	}

	for (i = 0; i < fs->no_blkgrp; i++) {
		status =
		    ext4fs_devread((lbaint_t)fs->bgd[i].block_id *
				   fs->sect_perblk, 0,
				   fs->blksz, (char *)fs->blk_bmaps[i]);
		if (status == 0)
			goto fail;
	}

	/* load all the available inode bitmap of the partition */
	fs->inode_bmaps = zalloc(fs->no_blkgrp * sizeof(unsigned char *));
	if (!fs->inode_bmaps)
		goto fail;
	for (i = 0; i < fs->no_blkgrp; i++) {
		fs->inode_bmaps[i] = zalloc(fs->blksz);
		if (!fs->inode_bmaps[i])
			goto fail;
	}

	for (i = 0; i < fs->no_blkgrp; i++) {
		status = ext4fs_devread((lbaint_t)fs->bgd[i].inode_id *
					fs->sect_perblk,
					0, fs->blksz,
					(char *)fs->inode_bmaps[i]);
		if (status == 0)
			goto fail;
	}

	/*
	 * check filesystem consistency with free blocks of file system
	 * some time we observed that superblock freeblocks does not match
	 * with the  blockgroups freeblocks when improper
	 * reboot of a linux kernel
	 */
	for (i = 0; i < fs->no_blkgrp; i++)
		real_free_blocks = real_free_blocks + fs->bgd[i].free_blocks;
	if (real_free_blocks != fs->sb->free_blocks)
		fs->sb->free_blocks = real_free_blocks;

	return 0;
fail:
	ext4fs_deinit();

	return -1;
}

void ext4fs_deinit(void)
{
	int i;
	struct ext2_inode inode_journal;
	struct journal_superblock_t *jsb;
	long int blknr;
	struct ext_filesystem *fs = get_fs();

	/* free journal */
	char *temp_buff = zalloc(fs->blksz);
	if (temp_buff) {
		ext4fs_read_inode(ext4fs_root, EXT2_JOURNAL_INO,
				  &inode_journal);
		blknr = read_allocated_block(&inode_journal,
					EXT2_JOURNAL_SUPERBLOCK);
		ext4fs_devread((lbaint_t)blknr * fs->sect_perblk, 0, fs->blksz,
			       temp_buff);
		jsb = (struct journal_superblock_t *)temp_buff;
		jsb->s_start = cpu_to_be32(0);
		put_ext4((uint64_t) ((uint64_t)blknr * (uint64_t)fs->blksz),
			 (struct journal_superblock_t *)temp_buff, fs->blksz);
		free(temp_buff);
	}
	ext4fs_free_journal();

	/* get the superblock */
	ext4_read_superblock((char *)fs->sb);
	fs->sb->feature_incompat &= ~EXT3_FEATURE_INCOMPAT_RECOVER;
	put_ext4((uint64_t)(SUPERBLOCK_SIZE),
		 (struct ext2_sblock *)fs->sb, (uint32_t)SUPERBLOCK_SIZE);
	free(fs->sb);
	fs->sb = NULL;

	if (fs->blk_bmaps) {
		for (i = 0; i < fs->no_blkgrp; i++) {
			free(fs->blk_bmaps[i]);
			fs->blk_bmaps[i] = NULL;
		}
		free(fs->blk_bmaps);
		fs->blk_bmaps = NULL;
	}

	if (fs->inode_bmaps) {
		for (i = 0; i < fs->no_blkgrp; i++) {
			free(fs->inode_bmaps[i]);
			fs->inode_bmaps[i] = NULL;
		}
		free(fs->inode_bmaps);
		fs->inode_bmaps = NULL;
	}


	free(fs->gdtable);
	fs->gdtable = NULL;
	fs->bgd = NULL;
	/*
	 * reinitiliazed the global inode and
	 * block bitmap first execution check variables
	 */
	fs->first_pass_ibmap = 0;
	fs->first_pass_bbmap = 0;
	fs->curr_inode_no = 0;
	fs->curr_blkno = 0;
}

static int ext4fs_write_file(struct ext2_inode *file_inode,
			     int pos, unsigned int len, char *buf)
{
	int i;
	int blockcnt;
	unsigned int filesize = __le32_to_cpu(file_inode->size);
	struct ext_filesystem *fs = get_fs();
	int log2blksz = fs->dev_desc->log2blksz;
	int log2_fs_blocksize = LOG2_BLOCK_SIZE(ext4fs_root) - log2blksz;
	int previous_block_number = -1;
	int delayed_start = 0;
	int delayed_extent = 0;
	int delayed_next = 0;
	char *delayed_buf = NULL;

	/* Adjust len so it we can't read past the end of the file. */
	if (len > filesize)
		len = filesize;

	blockcnt = ((len + pos) + fs->blksz - 1) / fs->blksz;

	for (i = pos / fs->blksz; i < blockcnt; i++) {
		long int blknr;
		int blockend = fs->blksz;
		int skipfirst = 0;
		blknr = read_allocated_block(file_inode, i);
		if (blknr < 0)
			return -1;

		blknr = blknr << log2_fs_blocksize;

		if (blknr) {
			if (previous_block_number != -1) {
				if (delayed_next == blknr) {
					delayed_extent += blockend;
					delayed_next += blockend >> log2blksz;
				} else {	/* spill */
					put_ext4((uint64_t)
						 ((uint64_t)delayed_start << log2blksz),
						 delayed_buf,
						 (uint32_t) delayed_extent);
					previous_block_number = blknr;
					delayed_start = blknr;
					delayed_extent = blockend;
					delayed_buf = buf;
					delayed_next = blknr +
					    (blockend >> log2blksz);
				}
			} else {
				previous_block_number = blknr;
				delayed_start = blknr;
				delayed_extent = blockend;
				delayed_buf = buf;
				delayed_next = blknr +
				    (blockend >> log2blksz);
			}
		} else {
			if (previous_block_number != -1) {
				/* spill */
				put_ext4((uint64_t) ((uint64_t)delayed_start <<
						     log2blksz),
					 delayed_buf,
					 (uint32_t) delayed_extent);
				previous_block_number = -1;
			}
			memset(buf, 0, fs->blksz - skipfirst);
		}
		buf += fs->blksz - skipfirst;
	}
	if (previous_block_number != -1) {
		/* spill */
		put_ext4((uint64_t) ((uint64_t)delayed_start << log2blksz),
			 delayed_buf, (uint32_t) delayed_extent);
		previous_block_number = -1;
	}

	return len;
}

int ext4fs_write(const char *fname, unsigned char *buffer,
					unsigned long sizebytes)
{
	int ret = 0;
	struct ext2_inode *file_inode = NULL;
	unsigned char *inode_buffer = NULL;
	int parent_inodeno;
	int inodeno;
	time_t timestamp = 0;

	uint64_t bytes_reqd_for_file;
	unsigned int blks_reqd_for_file;
	unsigned int blocks_remaining;
	int existing_file_inodeno;
	char *temp_ptr = NULL;
	long int itable_blkno;
	long int parent_itable_blkno;
	long int blkoff;
	struct ext2_sblock *sblock = &(ext4fs_root->sblock);
	unsigned int inodes_per_block;
	unsigned int ibmap_idx;
	struct ext_filesystem *fs = get_fs();
	ALLOC_CACHE_ALIGN_BUFFER(char, filename, 256);
	memset(filename, 0x00, 256);

	g_parent_inode = zalloc(sizeof(struct ext2_inode));
	if (!g_parent_inode)
		goto fail;

	inodes_per_block = fs->blksz / fs->inodesz;
	parent_inodeno = ext4fs_get_parent_inode_num(fname, filename, F_FILE);
	if (parent_inodeno == -1 || parent_inodeno == -2)
		goto fail;
	if (ext4fs_iget(parent_inodeno, g_parent_inode))
		goto fail;
	/* check if the filename is already present in root */
	existing_file_inodeno = ext4fs_filename_check(filename);
	if (existing_file_inodeno != -1) {
		ret = ext4fs_delete_file(existing_file_inodeno);
		fs->first_pass_bbmap = 0;
		fs->curr_blkno = 0;

		fs->first_pass_ibmap = 0;
		fs->curr_inode_no = 0;
		if (ret)
			goto fail;
	}
	/* calucalate how many blocks required */
	bytes_reqd_for_file = sizebytes;
	blks_reqd_for_file = lldiv(bytes_reqd_for_file, fs->blksz);
	if (do_div(bytes_reqd_for_file, fs->blksz) != 0) {
		blks_reqd_for_file++;
		debug("total bytes for a file %u\n", blks_reqd_for_file);
	}
	blocks_remaining = blks_reqd_for_file;
	/* test for available space in partition */
	if (fs->sb->free_blocks < blks_reqd_for_file) {
		printf("Not enough space on partition !!!\n");
		goto fail;
	}

	ext4fs_update_parent_dentry(filename, &inodeno, FILETYPE_REG);
	/* prepare file inode */
	inode_buffer = zalloc(fs->inodesz);
	if (!inode_buffer)
		goto fail;
	file_inode = (struct ext2_inode *)inode_buffer;
	file_inode->mode = S_IFREG | S_IRWXU |
	    S_IRGRP | S_IROTH | S_IXGRP | S_IXOTH;
	/* ToDo: Update correct time */
	file_inode->mtime = timestamp;
	file_inode->atime = timestamp;
	file_inode->ctime = timestamp;
	file_inode->nlinks = 1;
	file_inode->size = sizebytes;

	/* Allocate data blocks */
	ext4fs_allocate_blocks(file_inode, blocks_remaining,
			       &blks_reqd_for_file);
	file_inode->blockcnt = (blks_reqd_for_file * fs->blksz) >>
		fs->dev_desc->log2blksz;

	temp_ptr = zalloc(fs->blksz);
	if (!temp_ptr)
		goto fail;
	ibmap_idx = inodeno / ext4fs_root->sblock.inodes_per_group;
	inodeno--;
	itable_blkno = __le32_to_cpu(fs->bgd[ibmap_idx].inode_table_id) +
			(inodeno % __le32_to_cpu(sblock->inodes_per_group)) /
			inodes_per_block;
	blkoff = (inodeno % inodes_per_block) * fs->inodesz;
	ext4fs_devread((lbaint_t)itable_blkno * fs->sect_perblk, 0, fs->blksz,
		       temp_ptr);
	if (ext4fs_log_journal(temp_ptr, itable_blkno))
		goto fail;

	memcpy(temp_ptr + blkoff, inode_buffer, fs->inodesz);
	if (ext4fs_put_metadata(temp_ptr, itable_blkno))
		goto fail;
	/* copy the file content into data blocks */
	if (ext4fs_write_file(file_inode, 0, sizebytes, (char *)buffer) == -1) {
		printf("Error in copying content\n");
		goto fail;
	}
	ibmap_idx = parent_inodeno / ext4fs_root->sblock.inodes_per_group;
	parent_inodeno--;
	parent_itable_blkno = __le32_to_cpu(fs->bgd[ibmap_idx].inode_table_id) +
	    (parent_inodeno %
	     __le32_to_cpu(sblock->inodes_per_group)) / inodes_per_block;
	blkoff = (parent_inodeno % inodes_per_block) * fs->inodesz;
	if (parent_itable_blkno != itable_blkno) {
		memset(temp_ptr, '\0', fs->blksz);
		ext4fs_devread((lbaint_t)parent_itable_blkno * fs->sect_perblk,
			       0, fs->blksz, temp_ptr);
		if (ext4fs_log_journal(temp_ptr, parent_itable_blkno))
			goto fail;

		memcpy(temp_ptr + blkoff, g_parent_inode,
			sizeof(struct ext2_inode));
		if (ext4fs_put_metadata(temp_ptr, parent_itable_blkno))
			goto fail;
		free(temp_ptr);
	} else {
		/*
		 * If parent and child fall in same inode table block
		 * both should be kept in 1 buffer
		 */
		memcpy(temp_ptr + blkoff, g_parent_inode,
		       sizeof(struct ext2_inode));
		gd_index--;
		if (ext4fs_put_metadata(temp_ptr, itable_blkno))
			goto fail;
		free(temp_ptr);
	}
	ext4fs_update();

	fs->first_pass_bbmap = 0;
	fs->curr_blkno = 0;
	fs->first_pass_ibmap = 0;
	fs->curr_inode_no = 0;
	free(inode_buffer);
	free(g_parent_inode);
	g_parent_inode = NULL;

	return 0;
fail:
	free(inode_buffer);
	free(g_parent_inode);
	g_parent_inode = NULL;

	return -1;
}


int ext4fs_append_write(const char *fname, unsigned char *buffer, unsigned long sizebytes)
{

	int parent_inodeno;
	int file_inode_no;
	int temp_inode_no;
	struct ext2_inode *file_inode;

	unsigned int ori_size;
	unsigned int cur_size;
	unsigned int ori_blocks;
	unsigned int cur_blocks;
	unsigned int add_blocks;
	unsigned int total_add_blocks;
	char *temp_inode_block = NULL;
	unsigned int ibmap_idx;
	unsigned int inodes_per_block;
	long int itable_blkno;
	long int blkoff;
	unsigned int end_blkoff;
	unsigned int end_bytoff;
	unsigned int end_blkno;
	char *end_block = NULL;
	unsigned int end_fillbyt;

	struct ext2_sblock *sblock = &(ext4fs_root->sblock);
	struct ext_filesystem *fs = get_fs();
	ALLOC_CACHE_ALIGN_BUFFER(char, filename, 256);
	memset(filename, 0x00, 256);


	g_parent_inode = zalloc(sizeof(struct ext2_inode));
	if (!g_parent_inode)
		goto fail;

        file_inode = zalloc(sizeof(struct ext2_inode));
        if (!file_inode)
                goto fail;


	printf("Begin get file inode\n");

	file_inode_no = ext4fs_get_file_inode_no (fname, filename, F_FILE);

	printf("file inode no is %d\n", file_inode_no);

	if( file_inode_no == -1 ){
		printf("file doesn't find\n");
		goto fail;
	}

        if (ext4fs_iget(file_inode_no, file_inode))
                goto fail;

	ori_size = file_inode->size;
	printf("original file size is %u\n", ori_size);
	ori_blocks = ((ori_size - 1) / fs->blksz) + 1;
	printf("original file blocks is %u\n", ori_blocks);

	cur_size = ori_size + sizebytes;
	printf("current file size is %u\n", cur_size);
	cur_blocks = ((cur_size - 1) / fs->blksz) + 1;
	printf("current file blocks is %u\n", cur_blocks);

	add_blocks = cur_blocks - ori_blocks;

	if (fs->sb->free_blocks < add_blocks) {
		printf("Not enough space on partition !!!\n");
		goto fail;
	}

	if( add_blocks > 0 ){
		printf("add inode addr block\n");
		total_add_blocks = add_blocks;
		ext4fs_allocate_append_blocks(file_inode, ori_blocks, add_blocks, &total_add_blocks);

		end_bytoff = ori_size % fs->blksz;

		if(end_bytoff == 0){

			ext4fs_write_file(file_inode,ori_size,sizebytes,buffer);

		}else{
			end_blkoff = ori_size / fs->blksz;
			end_blkno = read_allocated_block(file_inode, end_blkoff);
			end_fillbyt = fs->blksz - end_bytoff;
			end_block = zalloc(fs->blksz);
			if (!end_block)
				goto fail;
			ext4fs_devread((lbaint_t)end_blkno * fs->sect_perblk, 0, fs->blksz, end_block);

			memcpy(end_block + end_bytoff, buffer, end_fillbyt);

			put_ext4((end_blkno * fs->blksz), end_block, fs->blksz);

			ext4fs_write_file(file_inode, ori_size + fs->blksz,
					sizebytes - end_fillbyt, buffer + end_fillbyt);

		}
	}else{

		end_blkoff = ori_size / fs->blksz;
		end_blkno = read_allocated_block(file_inode, end_blkoff);
		end_block = zalloc(fs->blksz);
		if (!end_block)
			goto fail;
		ext4fs_devread((lbaint_t)end_blkno * fs->sect_perblk, 0, fs->blksz, end_block);
		memcpy(end_block + end_bytoff, buffer, sizebytes);
		put_ext4((end_blkno * fs->blksz), end_block, fs->blksz);

	}

	file_inode->size = cur_size;
	file_inode->blockcnt = ((cur_blocks + total_add_blocks)*fs->blksz) >> fs->dev_desc->log2blksz;

	inodes_per_block = fs->blksz / fs->inodesz;
	temp_inode_no = file_inode_no;
	temp_inode_block = zalloc(fs->blksz);
	if (!temp_inode_block)
		goto fail;
	ibmap_idx = temp_inode_no / ext4fs_root->sblock.inodes_per_group;
	temp_inode_no --;
	itable_blkno = __le32_to_cpu(fs->bgd[ibmap_idx].inode_table_id) +
			(temp_inode_no % __le32_to_cpu(sblock->inodes_per_group)) /
			inodes_per_block;
	blkoff = (temp_inode_no % inodes_per_block) * fs->inodesz;
	ext4fs_devread((lbaint_t)itable_blkno * fs->sect_perblk, 0, fs->blksz,temp_inode_block);
	if (ext4fs_log_journal(temp_inode_block, itable_blkno))
		goto fail;
	memcpy(temp_inode_block + blkoff, file_inode, sizeof(struct ext2_inode));
	if (ext4fs_put_metadata(temp_inode_block, itable_blkno))
		goto fail;

	ext4fs_update();
	free(temp_inode_block);
	free(end_block);
	free(file_inode);
	free(g_parent_inode);

	return 0;

fail:
        free(temp_inode_block);
        free(end_block);
        free(file_inode);
        free(g_parent_inode);


	return -1;



}


int ext4_write_file(const char *filename, void *buf, loff_t offset,
		    loff_t len, loff_t *actwrite, int append)
{
	int ret;


	if (offset != 0) {
		printf("** Cannot support non-zero offset **\n");
		return -1;
	}

	if(append == 1){

		ret = ext4fs_append_write(filename, buf, len);

	}else{

		ret = ext4fs_write(filename, buf, len);

	}
	if (ret) {
		printf("** Error ext4fs_write() **\n");
		goto fail;
	}

	*actwrite = len;

	return 0;

fail:
	*actwrite = 0;

	return -1;
}



int do_ext4fs_creat(char *dirname, int parent_inode_no)
{

	int inodeno;
	int temp_inodeno;
	int temp_parent_inodeno;

	unsigned int blks_reqd_for_dir;
	struct ext2_inode *file_inode = NULL;
	unsigned char *inode_buffer = NULL;
	time_t timestamp = 0;

	char *temp_ptr = NULL;
	unsigned int ibmap_idx;
	long int itable_blkno;
	long int blkoff;
	long int parent_itable_blkno;

	unsigned char *init_dir_buf = NULL;
	struct ext2_dir_init *init_dir = NULL;

	struct ext2_sblock *sblock = &(ext4fs_root->sblock);
	unsigned int inodes_per_block;
	struct ext_filesystem *fs = get_fs();



	inodes_per_block = fs->blksz / fs->inodesz;

	//update_parent_dentry
	ext4fs_update_parent_dentry(dirname, &inodeno, FILETYPE_DIRECTORY);

	//prepare file inode
	inode_buffer = zalloc(fs->inodesz);
	if (!inode_buffer)
		goto fail;
	file_inode = (struct ext2_inode *)inode_buffer;
	file_inode->mode = S_IFDIR| S_IRWXU |S_IRGRP | S_IROTH | S_IXGRP | S_IXOTH;
	file_inode->mtime = cpu_to_le32(timestamp);
	file_inode->atime = cpu_to_le32(timestamp);
	file_inode->ctime = cpu_to_le32(timestamp);
	file_inode->nlinks = 2;
	file_inode->size = 4096;

	ext4fs_allocate_blocks(file_inode, 1, &blks_reqd_for_dir);

	file_inode->blockcnt = (blks_reqd_for_dir * fs->blksz) >>
		fs->dev_desc->log2blksz;

	temp_ptr = zalloc(fs->blksz);
	if (!temp_ptr)
		goto fail;
	
	temp_inodeno = inodeno;
	ibmap_idx = temp_inodeno / ext4fs_root->sblock.inodes_per_group; //find the group according to inode
	temp_inodeno--;
	itable_blkno = __le32_to_cpu(fs->bgd[ibmap_idx].inode_table_id) +
			(temp_inodeno % __le32_to_cpu(sblock->inodes_per_group)) /
			inodes_per_block;

	blkoff = (temp_inodeno % inodes_per_block) * fs->inodesz;
	ext4fs_devread((lbaint_t)itable_blkno * fs->sect_perblk, 0, fs->blksz,
			temp_ptr);
	if (ext4fs_log_journal(temp_ptr, itable_blkno))
		goto fail;

	memcpy(temp_ptr + blkoff, inode_buffer, fs->inodesz);


	if (ext4fs_put_metadata(temp_ptr, itable_blkno))
		goto fail;

	//write . and .. dirent in the new dir
	init_dir_buf = zalloc(sizeof(struct ext2_dir_init));
	if(!init_dir_buf)
		goto fail;

	init_dir = (struct ext2_dir_init *)init_dir_buf;

	init_dir->self_inode = inodeno;
	init_dir->self_direntlen = 12;
	init_dir->self_namelen = 1;
	init_dir->self_filetype = FILETYPE_DIRECTORY;
	init_dir->parent_inode = parent_inode_no;
	init_dir->parent_direntlen = 4084;
	init_dir->parent_namelen = 2;
	init_dir->parent_filetype = FILETYPE_DIRECTORY;
	init_dir->self_name[0] = '.';
	init_dir->parent_name[0] = '.';
	init_dir->parent_name[1] = '.';	

	if (ext4fs_write_file(file_inode, 0, sizeof(struct ext2_dir_init), init_dir) == -1) {
		printf("Init dirent fail\n");
		goto fail;
	}

	//updata parent_inode
	g_parent_inode->nlinks++;

	temp_parent_inodeno = parent_inode_no;
	ibmap_idx = temp_parent_inodeno / ext4fs_root->sblock.inodes_per_group;
	temp_parent_inodeno--;
	parent_itable_blkno = __le32_to_cpu(fs->bgd[ibmap_idx].inode_table_id) +
		(temp_parent_inodeno % __le32_to_cpu(sblock->inodes_per_group)) / inodes_per_block;
	blkoff = (temp_parent_inodeno % inodes_per_block) * fs->inodesz;
	if (parent_itable_blkno != itable_blkno) {
		memset(temp_ptr, '\0', fs->blksz);
		ext4fs_devread((lbaint_t)parent_itable_blkno * fs->sect_perblk,
				0, fs->blksz, temp_ptr);
		if (ext4fs_log_journal(temp_ptr, parent_itable_blkno))
			goto fail;

		memcpy(temp_ptr + blkoff, g_parent_inode,
			sizeof(struct ext2_inode));
		if (ext4fs_put_metadata(temp_ptr, parent_itable_blkno))
			goto fail;
		free(temp_ptr);	
	} else {
		memcpy(temp_ptr + blkoff, g_parent_inode,
			sizeof(struct ext2_inode));
		gd_index--;
		if (ext4fs_put_metadata(temp_ptr, itable_blkno))
			goto fail;
		free(temp_ptr);
	}
	ext4fs_update();

	fs->first_pass_bbmap = 0;
	fs->curr_blkno = 0;
	fs->first_pass_ibmap = 0;
	fs->curr_inode_no = 0;
	free(init_dir_buf);
	free(inode_buffer);
	free(g_parent_inode);
	g_parent_inode = NULL;

	return 0;
fail:
	ext4fs_deinit();
	free(init_dir_buf);
	free(temp_ptr);
	free(inode_buffer);
	free(g_parent_inode);
	g_parent_inode = NULL;

	return -1;		
}

int ext4fs_mkdir(char *dirname)
{
	int ret = 0;
        int parent_inodeno;
	ALLOC_CACHE_ALIGN_BUFFER(char, dname, 256);
	memset(dname, 0x00, 256);


        printf("enter into mkdir\n");

        parent_inodeno = ext4fs_get_parent_inode_num(dirname, dname, F_FILE);

        if (parent_inodeno == -1) {
                printf("parent dirent don't existed\n");
		ret = -1;
                goto fail;
        }

	if (parent_inodeno == -2){
		printf("dirent has existed\n");
		ret = -2;
		goto fail;
	}


        g_parent_inode = zalloc(sizeof(struct ext2_inode));
        if (!g_parent_inode){
		ret = -1;	
                goto fail;
	}
        if (ext4fs_iget(parent_inodeno, g_parent_inode)) {
                printf("find inode failed\n");
		ret = -1;
                goto fail;
        }

	if(do_ext4fs_creat(dname,parent_inodeno) == -1)
	{
		ret = -1;
		printf("do_ext4fs_creat failed\n");
		goto fail;
	}

	free(g_parent_inode);
	return 0;


fail:
	free(g_parent_inode);
	return ret;


}





