#include <stdio.h>
#include <stdlib.h>

int addFunc(int a);
int addFunc(int a)
{
	a++;
	return a;
}

int main(int argc, char *argv[])
{
	int (*func_p)(int);
	func_p = addFunc;
	printf("func_p(2)...%d\n", func_p(2));
	exit(0);
}
