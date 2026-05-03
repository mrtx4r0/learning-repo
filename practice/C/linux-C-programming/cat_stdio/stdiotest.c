#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* f = fopen(argv[1], "r");
	if (!f) {
		perror(argv[1]);
		exit(1);
	}
	fprintf(stdout, "====%s=====\n", argv[1]);
	int c;
	while ((c = fgetc(f)) != EOF) {
		/* fprintf(stdout, "c = %d\n", c); */
		fputc(c, stdout);
	}
	if (fclose(f) < 0) {
		perror(argv[1]);
		exit(1);
	}
	exit(0);
}
	
