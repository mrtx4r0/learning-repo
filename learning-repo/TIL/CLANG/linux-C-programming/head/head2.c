#include "head2.h"

int main(int argc, char* argv[])
{
	long nlines; 
	FILE* f;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <number of lines>\n", argv[0]);
		exit(1);
	}

	nlines = atol(argv[1]); 
	if (nlines <= 0) {
		return 0;
	}
	if (argc > 2) {
		/* ファイル指定がある場合 */
		for (int i=2; i<argc; i++) {
			f = fopen(argv[i], "r");
			if (!f) {
				perror(argv[i]);
				exit(1);
			}	
			if (argc == 3) {
				/* ファイルが1つだけの場合, ファイル内容だけ書き出す */
				do_head(f, nlines);
			}
			else {
				/* ファイルが2つ以上ある場合, ファイル名も含めて書き出す */
				printf("==> %s <==\n", argv[i]);
				do_head(f, nlines);
				if (i != (argc-1)) {
					/* 最後のファイル以外のときは改行を入れる */
					printf("\n");
				}
			}
			if (fclose(f) < 0) {
				perror(argv[i]);
				exit(1);
			}
		}
	}	
	/* ファイル指定がない場合、標準入力から読む */
	else {
		do_head(stdin, nlines);
	}
	exit(0);
}

void do_head(FILE* f, long nlines)
{
	int c = 0;
	while ((c = fgetc(f)) != EOF) {
		if (c == '\n') {
			nlines--;
		}
		if (fputc(c, stdout) < 0 ) {
			/* 書き込み失敗 */
			exit(1);
		}
		if (nlines == 0 ) {
			/* 指定行数に達したらループ終了 */
			break;
		}
	}
}
