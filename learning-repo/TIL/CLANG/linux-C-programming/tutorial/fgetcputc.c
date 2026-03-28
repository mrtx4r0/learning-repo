#include <stdio.h>

int main(int argc, char* argv[])
{
	int c = 0;
	while ((c = fgetc(stdin)) != EOF) {
		fprintf(stdout, "%c\n", (char)c);
	}
}
