#include <common.h>
#include <malloc.h>
#include <linux/input.h>
#include "sparse_format.h"
#include <dl_common.h>
#include "nvmerge.h"
#include "dl_operate.h"
#ifdef  NVMERGE_TRACE
#undef  NVMERGE_TRACE
#endif // NVMERGE_TRACE

#define  NVMERGE_TRACE debugf
/*
    id:
    nvBuf:        nv data
    nvLength:    nv size
    itemPos:    item pos
    itemSize:    item size
*/
static BOOLEAN ___findItem( /*IN*/ uint32 id, /*IN*/ uint8 * nvBuf, /*IN*/ uint32 nvLength, /*OUT*/ uint32 * itemSize, /*OUT*/ uint32 * itemPos)
{
    uint32 offset = 4;
    uint16 tmp[2];
    while (1) {
        if (*(uint16 *) (nvBuf + offset) == INVALID_ID) {
            NVMERGE_TRACE("NVMERGE:___findItem find the tail\n");
            break;
        }
        if (offset + sizeof(tmp) > nvLength) {
            NVMERGE_TRACE("NVMERGE: ___findItem Surpass the boundary of the part\r\n");
            break;
        }
        memcpy(tmp, nvBuf + offset, sizeof(tmp));
        offset += sizeof(tmp);
        if (id == (uint32) tmp[0]) {
            *itemSize = (uint32) tmp[1];
            *itemPos = offset;
            NVMERGE_TRACE("NVMERGE:___findItem id = 0x%x\n", id);
            return TRUE;
        }
        offset += tmp[1];
        offset = (offset + 3) & 0xFFFFFFFC;
    }
    return FALSE;
}

BOOLEAN mergeItem(uint8 * oldBuf, uint32 oldNVlength, uint8 * newBuf, uint32 newNVlength)
{
    uint32 i;
    uint32 oldSize, oldPos;
    uint32 newSize, newPos;
    for (i = 0; strcmp(nv_cfg[i].name,"\0"); i++) {
        if (!___findItem(nv_cfg[i].id, oldBuf, oldNVlength, &oldSize, &oldPos)) {
            continue;
        }
        if (!___findItem(nv_cfg[i].id, newBuf, newNVlength, &newSize, &newPos)) {
            continue;
        }
        NVMERGE_TRACE("NVMERGE:__mergeItem oldSize 0x%x newSize 0x%x\n", oldSize, newSize);
        if (oldSize == newSize) {
            memcpy(newBuf + newPos, oldBuf + oldPos, newSize);
            NVMERGE_TRACE("NVMERGE:__mergeItem success id = 0x%x\n", nv_cfg[i].id);
        } else {
            return FALSE;
        }
    }
    return TRUE;
}
