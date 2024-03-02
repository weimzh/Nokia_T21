#include <loader_common.h>
#include <chipram_env.h>

extern void reset_cpu (ulong ignored);
ulong sdram_base = CONFIG_SYS_SDRAM_BASE;
ulong ram_size;

#define TEST_LEN 0x10000000
#define RAM512 0x20000000
#define SECSIZE 0x3000000

extern void modem_entry(void);

DECLARE_GLOBAL_DATA_PTR;
typedef struct memtest{
	ulong memt_ads;
	ulong memt_len;
}mt_t;
const char *region_name[10] = MEMTEST_NODE;

/*********************************
 *ram_start
 *-----------------------
 *logbuf_start
 *
 *logbuf_end
 *----------------------
 *sec_start
 *
 *sec_end
 *----------------------
 *lcdrev_start
 *
 *lcdrev_end
 *---------------------
 *uboot_start
 *
 *uboot_end
 *---------------------
 *ram_end
 ********************************/

typedef struct memregion{
	ulong memr_num;
	ulong *regionp;
	mt_t *mt;
}mr_t;

void get_ddr_size(void)
{
#ifdef CONFIG_DDR_AUTO_DETECT
	ulong sdram_base = CONFIG_SYS_SDRAM_BASE;
	ulong sdram_size = 0;
	chipram_env_t * env = CHIPRAM_ENV_LOCATION;
	if (CHIPRAM_ENV_MAGIC != env->magic) {
		printf("Chipram magic wrong , ddr data may be broken\n");
		return 0;
	}

	ram_size = 0;

	if (env->cs_number == 1) {
		ram_size += env->cs0_size;
		debugf("dram cs0 size %lx\n",env->cs0_size);
	} else if(env->cs_number == 2){
		ram_size += env->cs0_size;
		ram_size += env->cs1_size;
		debugf("dram cs0 size 0x%lx dram cs1 size 0x%lx\n",env->cs0_size, env->cs1_size);

	}
#else
	ram_size = REAL_SDRAM_SIZE;
#endif
}
static void dcache_rebuild(void)
{
	bd_t *bd = gd->bd;
	long i;
	get_ddr_size();
	for (i = 0; i < CONFIG_NR_DRAM_BANKS; i++)
	{
		bd->bi_dram[i].size = (ram_size + 0x40000) & ~0x3ffff;
	}

	dcache_disable();
	dcache_enable();
}

int fdtdec_decode_region1(const void *blob, int node, const char *prop_name,
			 fdt_addr_t *basep, fdt_size_t *sizep)
{
	const fdt_addr_t *cell;
	int len;

	/*
	debug("%s: %s: %s\n", __func__, fdt_get_name(blob, node, NULL),
	      prop_name);
	*/
	cell = fdt_getprop(blob, node, prop_name, &len);
	if (!cell || (len < sizeof(fdt_addr_t) * 2)) {
		debug("cell=%p, len=%d\n", cell, len);
		return -1;
	}
/*
In x86 ,we need to read 32bit address from 64bit dts for lcd frambuffer.
*/
#ifndef CONFIG_X86
	*basep = fdt_addr_to_cpu(cell[1]);
	*sizep = fdt_size_to_cpu(cell[3]);
#else
	/*in sharklj1 "cell" are not aligned in 8 bytes, this will cause "Synchronous Abort",
	so we use a temporary array to force align*/
	ulong temp[2] = {0};
	memcpy((void *)temp, (void *)cell, 2 * sizeof(ulong));
	*basep = fdt_addr_to_cpu(temp[0]);
	*sizep = fdt_size_to_cpu(temp[1]);
#endif
	/*
	debug(format, arg...)("%s: base=%08lx, size=%lx\n", __func__, (ulong)*basep,
	      (ulong)*sizep);
	*/
	return 0;
}

int get_region_from_dt(ulong *basep, ulong *endp, const char *prop_name)
{
	ulong size;
	char nodename[256];
	const void *fdt_blob = gd->fdt_blob;
	int nodeoffset = fdt_path_offset(fdt_blob, "/reserved-memory");

	if (nodeoffset == -FDT_ERR_NOTFOUND)
	{
		debugf("reserved-memory node not found\n");
		return -1;
	}

	int childnode_logbuf = fdt_subnode_offset(fdt_blob, nodeoffset, prop_name);
	if (childnode_logbuf == -FDT_ERR_NOTFOUND)
	{
		debugf("%s node not found\n", prop_name);
		return -1;
	}

	if (fdtdec_decode_region(fdt_blob, childnode_logbuf, "reg", basep, &size))
	{
		 debugf("%s reg node not found", prop_name);
		return -1;
	}

	if (*basep == 0)
	{
		if (fdtdec_decode_region1(fdt_blob, childnode_logbuf, "reg", basep, &size))
		{
			debugf("%s reg node not found", prop_name);
		return -1;
	}
	}
	*endp = *basep + size;
	if (!strcmp("sml-mem", prop_name))
	{
		childnode_logbuf = fdt_next_subnode(fdt_blob, childnode_logbuf);
		sprintf(nodename, "%s", fdt_get_name(fdt_blob, childnode_logbuf, NULL));
		if (!strncmp("tos-mem", nodename, 7))
		{
			childnode_logbuf = fdt_next_subnode(fdt_blob, childnode_logbuf);
			if (fdtdec_decode_region(fdt_blob, childnode_logbuf, "reg", endp, NULL))
			{
				debugf("%s reg node not found", prop_name);
				return -1;
			}
		} else {
			if (fdtdec_decode_region(fdt_blob, childnode_logbuf, "reg", endp, NULL))
			{
				debugf("%s reg node not found", prop_name);
				return -1;
			}
		}
		if (*endp == 0)
		{
			if (fdtdec_decode_region1(fdt_blob, childnode_logbuf, "reg", endp, NULL))
			{
				debugf("%s reg node not found", prop_name);
				return -1;
			}
		}
	}
	printf("%s : bsae: 0x%lx, endp: 0x%lx\n", prop_name, *basep, *endp);
	return 0;
}

extern _start;
int get_uboot_region(unsigned long *basep, unsigned long *sizep)
{
	*basep = (ulong)&_start;

	if (gd->ram_size > 0)
	    *sizep =  CONFIG_SYS_SDRAM_BASE + gd->ram_size;
	else
	    return -1;

	return 0;
}

void sort_region(ulong a[], int n)
{
	int i, j;
	for(i=1; i<n; i++)
		if (a[i] < a[i-1])
		{
			ulong temp = a[i];
			for(j=i-1; j>=0 && a[j]>temp; j--)
			a[j+1] = a[j];
			a[j+1] = temp;
		}
}

int get_memlayout_region(ulong * ads)
{
	int i;
	ulong start_ads, end_ads;
	for(i = 0; region_name[i] != NULL; i++)
	{
		if(get_region_from_dt(&start_ads, &end_ads, region_name[i]))
			return -1;
		ads[2*i] = start_ads;
		ads[2*i+1] = end_ads;
	}
	if (get_uboot_region(&start_ads, &end_ads))
		return -1;

	ads[2*i] = start_ads;
	ads[2*i+1] = end_ads;

	ads[2*i+2] = CONFIG_SYS_SDRAM_BASE;
	ads[2*i+3] = CONFIG_SYS_SDRAM_BASE + ram_size;

	ads[2*i+4] = CHIPRAM_ENV_LOCATION;
	ads[2*i+5] = CHIPRAM_ENV_LOCATION + sizeof(chipram_env_t);

	return 0;
}

int adjust_region(mr_t *memp, ulong start_ads, ulong end_ads)
{
	int i;

	for(i = 0; i < memp->memr_num; i++)
	{
		if(start_ads >= memp->regionp[2*i] && end_ads <= memp->regionp[2*i + 1])
			return 0;
	}
	printf("ERROR! The address range entered exceeds limit, please input commont \"memtest region\" to get correct range\n");
	return -1;
}

int set_memregion_arg(mr_t *memp)
{
	int i;
	for(i = 0; region_name[i] != NULL; i++);

	memp->memr_num = (i + 3) * 2;

	memp->regionp =(ulong *)malloc(memp->memr_num * sizeof(ulong));
	if (memp->regionp == NULL)
	{
		errorf("region malloc fail");
		return -1;
	}

	if (get_memlayout_region(memp->regionp))
		return -1;

	sort_region(memp->regionp, memp->memr_num);

	if (gd->ram_size > ram_size)
		memp->memr_num -= 2;

	memp->mt =(mt_t *)malloc(memp->memr_num/2 * sizeof(mt_t));
	if (memp->mt == NULL)
	{
		errorf("mt malloc fail");
		return -1;
	}

	for(i = 0; i < memp->memr_num/2; i++)
	{
		memp->mt[i].memt_ads = memp->regionp[2*i];
		memp->mt[i].memt_len = memp->regionp[2*i + 1] - memp->regionp[2*i];
	}
	return 0;
}

/*
 *U-Boot code: 9F000000 -> 9F09BE60  BSS: -> 9F252028
 *TLB table from 9fff0000 to 9fff1000
 *Top of RAM usable for U-Boot at: 9fff0000
 *Reserving 5128k for malloc() at: 9faee000
 *Reserving 72 Bytes for Board Info at: 9faedfb8
 *Reserving 336 Bytes for Global Data at: 9faede68
 *Reserving 5984 Bytes for FDT at: 9faec708
 *New Stack Pointer is: 9faec700
 * */
int ddr_memtester(ulong test_len)
{
	int i;
	mr_t mr;
	printf("DDR mem test start\n");
	lcd_printf("DDR mem test start\n");

	dcache_rebuild();

	//boot cp
	modem_entry();
	if (set_memregion_arg(&mr))
	    return -1;

	for(i = 0; i < mr.memr_num/2; i++)
	{
		for(; mr.mt[i].memt_len > TEST_LEN; mr.mt[i].memt_len -= TEST_LEN)
		{
			ddr_mem_test(mr.mt[i].memt_ads, TEST_LEN);
			mr.mt[i].memt_ads += TEST_LEN;
		}

	    ddr_mem_test(mr.mt[i].memt_ads, mr.mt[i].memt_len);
	}
	lcd_printf("DDR mem test pass\n");
	printf("DDR mem test pass\n");
	return 0;
}

int ddr_region_printf(void)
{
	printf("ddr_region_printf\n");
	int i;
	mr_t mr;
	get_ddr_size();
	if (set_memregion_arg(&mr))
		return -1;

	printf("The range that can be tested:\n");
	for(i = 0; i < mr.memr_num/2; i++)
	{
		printf("memtest 0x%lx 0x%lx \n", mr.mt[i].memt_ads, mr.mt[i].memt_len);
	}
	return 0;
}

int ddr_manual_memtester(ulong start_ads, ulong test_len)
{
	mr_t mr;
	get_ddr_size();
	if (set_memregion_arg(&mr))
		return -1;

	if (adjust_region(&mr, start_ads, start_ads + test_len))
		return -1;

	printf("ddr_manual_memtest\n");

	ddr_mem_test(start_ads, test_len);
	return 0;
}
