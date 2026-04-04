#include <stdio.h>
#include <stdlib.h> /* exit()を使う */

int main(int argc, char* argv[])
{
	printf("argc=%d\n", argc);
	for(int i=0; i < argc; i++) {
		printf("arg[%d]: %s\n", i, *(argv+i));
		printf("*(argv+i)=%p\n", *(argv+i));
	}
	exit(0);
} 
