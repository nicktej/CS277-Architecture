#include <stddef.h>
#include "memcpy.h"

/**
 * Copy a memory area.
 *
 * <p>The memcpy function copies n bytes from memory area pointed to
 * by src (source area) to memory area pointed to by dest (destination
 * area).  The memory areas may not overlap.
 *
 * @param dest  destination area
 * @param src  source area
 * @param n  number of bytes to copy
 * @returns a pointer to the destination area
 */
void *memcpy(void *dest, const void *src, size_t n)
{
    if (n == 0)
        return dest;

    if (src == NULL || dest == NULL)
        return NULL;

    const char *s = src;
    char *d = dest;
    long i = 0;
    // HERE
    while (i < n) {

    	d[i] = s[i];
    	i++;
    }


    return dest;
}

/*

100/80 = 1.25



Program speedup by 1.25x.

1536/56 = 27.43



Internet access speedup by 27.43x.
*/