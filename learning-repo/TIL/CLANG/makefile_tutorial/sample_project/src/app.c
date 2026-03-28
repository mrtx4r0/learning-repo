#include <stdio.h>
#include "app.h"
#include "mathutil.h"

void app_run(void)
{
	int result = add(3, 4);
	printf("result = %d\n", result);
}
