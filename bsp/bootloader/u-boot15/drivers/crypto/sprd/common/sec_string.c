#include <sprd_crypto.h>

void *sec_memcpy_invert(void *dest, const void *src, unsigned int count)
{
    if (dest == NULL || src == NULL){
        return NULL;
    }
    char *tmp = dest;
    const char *s = src + count - 1;

    while (count--)
        *tmp++ = *s--;

    return dest;
}
