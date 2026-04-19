#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "read_line.h"

int main(int argc, char *argv[])
{
	read_line_status_t readline_status;
	char **tmp = NULL;
	char *tmp2 = NULL;
	char *token;
	char *delim = " ";	
	char *saveptr;
	char *cmdline;
	char **cmd_argv = NULL;
	size_t cmd_argc_buf_size;
	size_t cmd_argc = 0;
	pid_t pid;

	for (;;) {
		fprintf(stdout, "minsh-$ ");
		fflush(stdout);
		readline_status = read_line(stdin, &cmdline);
		/* 標準入力から読み込み */
		if (readline_status != READ_LINE_OK) {
			exit(EXIT_FAILURE);
		}
		if (readline_status == READ_LINE_EOF) {
			continue;
		}
		token = strtok_r(cmdline, delim, &saveptr);
		while (token != NULL) {
			/* cmd_argvの領域を確保 */
			 /* reallocは失敗するとNULLを返し、元のargvのアドレスが失われるため、
				一旦tmpで受ける　→　NULLを返されても、argvは残る */
			if (cmd_argc >= cmd_argc_buf_size) {
				cmd_argc_buf_size = cmd_argc_buf_size ? cmd_argc_buf_size * 2 : 16;
				tmp = realloc(cmd_argv, sizeof(char *) * cmd_argc_buf_size);
				if (!tmp) {
					exit(EXIT_FAILURE);
				}
				cmd_argv = tmp;	
				/* cmd_argvの要素(char *型)の領域を確保 */	
				tmp2 = malloc(strlen(token) + 1);
				if (!tmp2) {
					exit(EXIT_FAILURE);
				}
				cmd_argv[cmd_argc] = tmp2; 
				strcpy(cmd_argv[cmd_argc], token);	
				cmd_argc++;
				/* 次のトークンを切り出す */	
				token = strtok_r(NULL, delim, &saveptr);
			}	
		}
		/* NULLで終端する */
		cmd_argv[cmd_argc] = NULL;

	    pid =fork();
		if (pid < 0) {
			exit(EXIT_FAILURE);
		}
		if (pid == 0) {
			/* 子プロセス */
			execv(cmd_argv[0], cmd_argv);
			/* 呼び出しが戻ったらエラー */
			exit(EXIT_FAILURE);
		}
		else {
			int status;
			waitpid(pid, &status, 0);
			if (WIFEXITED(pid)) {
				fprintf(stdout, "exit, status: %d\n", WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status)) {
				fprintf(stdout, "signal, sig: %d\n", WTERMSIG(status));
			}
			else {
				fprintf(stderr, "abnormal exit\n");
			}
		}
	}
	exit(EXIT_SUCCESS);
}

