#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	for (int i = 0; i <= 100; i++) {
		fprintf(stdout, "\r\033[2Kprocessing: %d%%", i);
		fflush(stdout);
		sleep(1);
	}
}