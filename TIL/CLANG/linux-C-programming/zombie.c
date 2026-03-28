#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
		printf("Child pid == %d\n", pid);
        printf("Child exiting\n");
        exit(0);
    } else {
		printf("Parent pid == %d\n", pid);
        printf("Parent sleeping\n");
        sleep(30);   // waitしない
    }

    return 0;
}
