#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUF_SIZE 2048

int main(int argc, char* argv[])
{
	unsigned char buf[BUF_SIZE];
	int lfcounts = 0; /* line feeds` counts */
	int fd;
	int rdbytes;
	int totalCounts = 0;

	if (argc < 2) {
		for (;;) {
			rdbytes = read(STDIN_FILENO, buf, sizeof(buf));
			if (rdbytes < 0) {
				perror("stdin");
				exit(1);
			}
			if (rdbytes == 0) {
				fprintf(stdout, "%d\n", lfcounts);
				break;
			}
			for (int i=0; i < rdbytes; i++) {
				if (buf[i] == '\n') {
					lfcounts++;
				}
			}
		}
	} else {
		for (int i=1; i < argc; i++) {
			fd = open(argv[i], O_RDONLY);
			if (fd < 0) {
				perror(argv[i]);
				exit(0);
			}
			/* 1ファイル(fd)ごとの読み出し処理 */
			for (;;) {
				rdbytes = read(fd, buf, sizeof(buf));
				if (rdbytes < 0) {
					perror(argv[i]);
					exit(1);
				}
				/* 読み終わったら、ファイル名と行数を出力してfdを片付ける */
				if (rdbytes == 0) {
					fprintf(stdout, "%d %s\n", lfcounts, argv[i]);
					/* 1ファイルごとに合計行数を加算 */
					totalCounts += lfcounts;
					/* 行数カウントを初期化 */
					lfcounts = 0;
					/* fdを片付ける */
					if (close(fd) < 0) {
						perror(argv[i]);
						exit(1);
					}
					break;
				}
				for (int j=0; j < rdbytes; j++) {
					if (buf[j] == '\n') {
						lfcounts++;
					}
				}		
			}	
		}
		/* ファイル数が2つ以上のときだけ、totalも出力する  */
		if (argc > 2) {
			fprintf(stdout, "%d total\n", totalCounts);
		}
	}
	exit(0);
}
