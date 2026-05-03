#include <stdio.h>
#include <unistd.h>

int main()
{
	char *spin = "|/-\\";
	
	for (int i = 0; i < 100; i++) {
		fprintf(stdout, "\r%c processing...", spin[i % 4]);
		fflush(stdout);
		usleep(100000);
	}
	fprintf(stdout, "\n");
}