#include <stddef.h>
#include "memcpy.h"

/**
 * Copy a memory area.
 *
 * <p>The memcpy2 function copies n bytes from memory area pointed to
 * by src (source area) to memory area pointed to by dest (destination
 * area).  The memory areas may not overlap.
 *
 * <p>This function is thread-safe.
 *
 * @param dest  destination area
 * @param src  source area
 * @param n  number of bytes to copy
 * @returns a pointer to the destination area
 */
void *memcpy2(void *dest, const void *src, size_t n)
{
    if (n == 0)
        return dest;

    if (src == NULL || dest == NULL)
        return NULL;

    const char *s = src;
    char *d = dest;

    // HERE

    return dest;
}
