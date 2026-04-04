#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	unsigned char buf[2048];

	strcpy(buf, argv[1]);
	size_t len = strlen(buf);
	for (int i=0; i<=len; i++) {
		fprintf(stdout, "%c\n", buf[i]);
	}

	return 0;
}
