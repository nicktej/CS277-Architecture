/**
 * Unit tests for memcpy().
 */

#include <string.h>
#include <stdio.h>

#include "../src/memcpy.h"

int errors = 0;

void separate();

int main()
{
    separate();
    // More tests could be added here...

    if (errors == 0) {
        printf("The unit tests ran successfully.\n");
        return 0;
    }
    else if (errors == 1) {
        printf("\n");
        printf("1 unit test out of 1 failed.\n");
        printf("\n");
        return 1;
    }
    else {
        printf("\n");
        printf("%d unit tests out of 1 failed.\n", errors);
        printf("\n");
        return 1;
    }
}

/**
 * Test memcpy with two small memory areas;
 */
void separate()
{
    char s[10] = "1234567890";
    char d[22] = "canary" "xxxxxxxxxx" "canary";
    void *r = memcpy2(d + strlen("canary"), s, 10);
    if (strncmp(d + strlen("canary"), "1234567890", 10) != 0) {
        printf("separate test failed: expected \"1234567890\" in the destination area, instead got \"%.10s\"\n", d + strlen("canary"));
        ++errors;
        return;
    }
    if (r != d + strlen("canary")) {
        printf("separate failed: expected return value of %p, instead got %p\n", d, r);
        ++errors;
        return;
    }
    if (strncmp(d, "canary", 6) != 0) {
        printf("separate test failed: front canary corrupted: expected \"canary\", instead found %.6s\n", d);
        ++errors;
        return;
    }
    if (strncmp(d + 16, "canary", 6) != 0) {
        printf("separate test failed: back canary corrupted: expected \"canary\", instead found %.6s\n", d + 16);
        ++errors;
        return;
    }
}
