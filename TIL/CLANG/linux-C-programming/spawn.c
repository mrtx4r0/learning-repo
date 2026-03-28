#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* fork(2), execl(3), */
#include <sys/wait.h> /* waitpid(3), wait(2) */

int main(int argc, char* argv[])
{
	pid_t pid;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <command> <arg>\n", argv[0]);
	}

	printf("Before fork()\n");

	pid = fork(); /* fork()の次の行から、親プロセス・子プロセスそれぞれで実行される */
	printf("right after fork; pid == %d\n", pid);
	if (pid < 0) {
		fprintf(stderr, "fork(2) failed\n");
		exit(1);
	}

	if (pid == 0) { 	/* 子プロセス */
		printf("now in spawn's child process. pid == %d\n", pid);		
		execl(argv[1], argv[1], argv[2], NULL);	/* プログラムのパス,プログラムに渡すコマンドライン引数リスト */
		/* execlが戻ったら起動失敗 */
		perror(argv[1]);
		exit(99);
	}
	else {
		int status;
		
		printf("now in parent's process, spawn about to waits..\n");
		waitpid(pid, &status, 0);
		printf("child (PID=%d) finished; ", pid); /* 子プロセスが終了したらwaitが戻る */
		if (WIFEXITED(status)){ 		/* WIFEXITED()はexitで終了していたら非0, elseなら0を返す */
			printf("exit, status=%d\n", WEXITSTATUS(status));	/* WEXITSTATUS()はexitで終了した場合の終了コードを返す */
		}
		else if (WIFSIGNALED(status)) {
			printf("signal, sig=%d\n", WTERMSIG(status));	/* WTERMSIG()はシグナルで終了した場合のシグナル番号を返す */	
		}
		else {
			printf("abnormal exit\n");
		}
		exit(0);	
	}		
}
