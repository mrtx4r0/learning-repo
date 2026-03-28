#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int do_wcl(FILE *f);

int main(int argc, char *argv[])
{	
	FILE *f = NULL;
	int nlines = 0;
	int i = 0; /* ファイル読み込みループカウンタ */
	int ntotallines = 0; /* 全ファイルの行数トータル */
	if (argc == 1) {
		/* stdinから読む */
		nlines = do_wcl(stdin);	
		fprintf(stdout, "%d\n", nlines);
	}
	else {
		/* argv[]から読む */
		for (i = 1; i < argc; i++) {
			f = fopen(argv[i], "r");
			if (!f) {
				fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
				exit(1);
			}
			/* ファイルの行数カウント */
			nlines = do_wcl(f);
			/* トータルを加算 */
			ntotallines += nlines;
			/* 行数出力 */
			fprintf(stdout, "%d %s\n", nlines, argv[i]);
			/* ファイルクローズ */
			if (fclose(f) < 0) {
				perror("fclose");
				exit(1);
			}
		}
		/* ファイルが2つ以上渡されたときのみ、トータル行数を出力する */
		if (argc > 2) {
			fprintf(stdout, "%d total\n", ntotallines);
		}
	}
	exit(0);
}

int do_wcl(FILE *f)
{
	int c = 0;	/* 読み込んだバイト */
	int nlines = 0; /* numbler of lines */
	int ceof = 0; /* character of EOF */	

	while ((c = fgetc(f)) != EOF) {
		if (c == '\n') {
			nlines++;
		}
		ceof = c;
	}
	if (ceof != '\n') {
		/* ファイル終端が改行文字でない場合の最終行をカウントする */
		nlines++;
	}
	return(nlines);
}
