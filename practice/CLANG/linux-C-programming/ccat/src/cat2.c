#include "cat2.h"

int main(int argc, char* argv[])
{
	int fd;
	if (argc < 2) {
		/* 引数ない場合、標準入力から読み出す */
		do_cat( STDIN_FILENO);	
	}
	for (int i=1; i < argc; i++) {
		/* 引数ある場合、それを渡す */
		fd = open(argv[i], O_RDONLY);
		if (fd < 0) {
			die(argv[i]);
		}
		if (do_cat(fd) < 0) {
			die(argv[i]);
		}
	}
	exit(0);
}

#define BUFFER_SIZE 2048

int do_cat(int fd)
{
	unsigned char buf[BUFFER_SIZE];
	int n;

	/* 無限ループ */
	for (;;) {
		/* fdからbufサイズ分bufに読み出す. nは読み込んだバイト数 */
		n = read(fd, buf, sizeof(buf));
		/* nが負のときはエラーなので処理終了 */
		if (n < 0) { 
			return -1;
		}
		/* nが0のときは読み出し完了なのでループを終了 */
		if (n == 0) {
			break;
		}
		/* 読み出した分だけ, 標準出力に書き込む */
		if (write(STDOUT_FILENO, buf, n) < 0) {
			return -1;
		}
	}
	/* ファイルディスクリプタを片付ける */
	if (close(fd) < 0) {
		return -1;
	}
	return 0;
}

/* 異常系の処理を行う */
void die(const char *s)
{
	/* perrorはerrno(システムコールが失敗したときにその原因を表す定数がセットされる)
		の値に合わせたエラーメッセージを標準エラー出力に出力する 
		引数に指定した文字列のあとに「:＜エラーメッセージ＞を出す */
	perror(s);
	exit(1);
} 

