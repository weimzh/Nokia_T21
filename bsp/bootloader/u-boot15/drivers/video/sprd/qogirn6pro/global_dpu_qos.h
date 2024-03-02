#ifndef __DPU_SOC_H__
#define __DPU_SOC_H__

#define DPU_SOC_QOS_BASE 0x30120000

typedef struct _QOS_REG_STRUCT {
	unsigned int      offset;
	unsigned int      mask;
	unsigned int      value;

} QOS_REG_T;

QOS_REG_T dpu_mtx_qos[] = {
	{ 0x0000, 0x00000001, 0x00000000},
	{ 0x0004, 0xffffffff, 0x00000000},
	{ 0x0008, 0x3f3f3f3f, 0x00000000},
	{ 0x000C, 0x3f3fffff, 0x00000000},
	{ 0x0010, 0x00000003, 0x00000000},
	{ 0x0014, 0xffffffff, 0x00000000},
	{ 0x0018, 0xffffffff, 0x00000000},
	{ 0x0044, 0xffffffff, 0x00000000},
	{ 0x0048, 0x073fffff, 0x00000000},
	{ 0x004C, 0xffffffff, 0x00000000},
	{ 0x0050, 0x073fffff, 0x00000000},
	{ 0x0040, 0x00000003, 0x00000000},
	{ 0x0060, 0x80000003, 0x00000000},
	{ 0x0064, 0x3fff3fff, 0x06660dda},
	{ 0x0068, 0x00000701, 0x00000001},
	{ 0x0080, 0x00000001, 0x00000000},
	{ 0x0084, 0xffffffff, 0x00000000},
	{ 0x0088, 0x3f3f3f3f, 0x00000000},
	{ 0x008C, 0x3f3fffff, 0x00000000},
	{ 0x0090, 0x00000003, 0x00000000},
	{ 0x0094, 0xffffffff, 0x00000000},
	{ 0x0098, 0xffffffff, 0x00000000},
	{ 0x00C4, 0xffffffff, 0x00000000},
	{ 0x00C8, 0x073fffff, 0x00000000},
	{ 0x00CC, 0xffffffff, 0x00000000},
	{ 0x00D0, 0x073fffff, 0x00000000},
	{ 0x00C0, 0x00000003, 0x00000000},
	{ 0x00E0, 0x80000003, 0x00000000},
	{ 0x00E4, 0x3fff3fff, 0x06660dda},
	{ 0x00E8, 0x00000701, 0x00000001},
};
#endif
