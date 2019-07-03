/**
 * Measure the performance of memcpy().
 *
 * For various sizes measure the performance of memcpy().  The program
 * outputs the statistics in a CSV format.
 */

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#ifdef LOCAL
#include "../src/memcpy.h"
#else
#define memcpy2 memcpy
#endif

#define minimum_bytes_copied (1L << 30)
#define log_max_block_size 27
#define max_block_size (1L << log_max_block_size)

int main(int argc, char *argv[])
{
    // We reserve twice as much: one half for the source, the other
    // for the destination.
    size_t alloc_size = 2 * max_block_size;
    void *m = malloc(alloc_size);
    if (m == NULL) {
        fprintf(stderr, "%s: Could allocate %zu bytes\n", argv[0], alloc_size);
        return 1;
    }

    // Clear the memory (and ignore the returned value).
    (void)memset(m, 0, alloc_size);

    // Minimum amount of work (to get decent latency measurements).
    int num_iterations = minimum_bytes_copied;

    // Print a header.
    printf("\"block size in bytes\", \"bandwidth (gigabytes/second)\"\n");

    // For each block size, measure how long it takes to copy an area
    // of memory of that size.  Double the block size at each iteration.
    for (int log_block_size = 0;
         log_block_size < log_max_block_size;
         ++log_block_size) {

        // Prepare the parameters of the copy.
        size_t block_size = 1L << log_block_size;
        void *src = m;
        void *dst = m + block_size;

        // Warm up the cache.
        memcpy2(src, dst, block_size);

        // Sample current time.
        struct timespec start_time, end_time;
        int r = clock_gettime(CLOCK_REALTIME, &start_time);
        assert(r == 0);

        for (int i = 0; i < num_iterations; ++i) {
            memcpy2(src, dst, block_size);
        }

        // Sample current time again.
        r = clock_gettime(CLOCK_REALTIME, &end_time);
        assert(r == 0);

        // Measure the bandwdith.
        unsigned long long int elapsed_nsec;
        double bw_gb_per_sec;
        elapsed_nsec = 1000000000 * (end_time.tv_sec - start_time.tv_sec)
            + end_time.tv_nsec - start_time.tv_nsec;
        bw_gb_per_sec = ((double)num_iterations * block_size)/elapsed_nsec;
        
        // Print the results.
        printf("%zu,%f\n", block_size, bw_gb_per_sec);

        // Never less than one iteration.
        if (num_iterations > 1)
            num_iterations /= 2;

    }

    return 0;
}
