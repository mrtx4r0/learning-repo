#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int c = 0;
	if (argc == 1) {
		while ((c = fgetc(stdin)) != EOF) {
			fputc(c, stdout);
		} 	
	} else {
		for (int i=1; i < argc; i++) {
			FILE* f = fopen(argv[i], "r");
			if (f == NULL) {
				perror(argv[i]);
				exit(1);
			}
			while ((c = fgetc(f)) != EOF) {
				if (fputc(c, stdout) < 0) {
					exit(1);
				}
			}
			if (fclose(f) < 0) {
				perror(argv[i]);
				exit(1);
			}
		}
	}
	exit(0);
}
