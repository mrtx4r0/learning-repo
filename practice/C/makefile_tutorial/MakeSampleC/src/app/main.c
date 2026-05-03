#include <stdio.h>
#include "lib/math/math_ops.h"

int main(void)
{
    int sum = add(3, 4);
    int product = mul(3, 4);
    printf("sum=%d, product=%d\n", sum, product);
    return 0;
}
