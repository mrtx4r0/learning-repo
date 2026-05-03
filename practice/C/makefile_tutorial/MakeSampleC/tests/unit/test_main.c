#include <stdio.h>
#include "lib/math/math_ops.h"

int main(void)
{
    printf("Test: add(2, 3) = %d (expected 5)\n", add(2, 3));
    printf("Test: mul(2, 3) = %d (expected 6)\n", mul(2, 3));
    return 0;
}
