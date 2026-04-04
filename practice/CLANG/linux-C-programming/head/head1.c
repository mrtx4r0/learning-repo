#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int maxlines; 
	int lineCounts = 0; /* 改行カウンタ */
	if ((argc != 2) || ((maxlines = atoi(argv[1])) == 0)) {
		fprintf(stderr, "Usage: %s <number of row>\n", argv[0]);
		exit(1);
	}
	
	if (maxlines <= 0) {
		return 0;
	}	
	int c;
	while ((c = fgetc(stdin)) != EOF) {
		if (c == '\n') {
			lineCounts ++;
		}	
		if (lineCounts <= maxlines) {
			/* 行数が指定行数に達するまでは標準出力に書き続ける */
			if ( fputc(c, stdout) < 0 ) {
				/* 書き込み失敗 */
				exit(1);
			}
			if ( lineCounts == maxlines ) {
				/* 指定行数に達したらループ終了 */
				break;
			}
		}
	}
	exit(0);
}
