#include "cat.h"

int main(int argc, char* argv[])
{
	if (argc < 2) {
#if 0 /* ステップ1 ファイルを指定されない場合はエラーをだす  */
		/* fprintf は第1引数FILE*に指定したストリームに書き出す stderrはstdio.hのグローバル変数 */
		fprintf(stderr, "%s: file name not given\n", argv[0]);	
		exit(1);
#else /* ステップ2 ファイルを指定されない場合は標準入力から読む */
		do_cat_stdin();	
#endif
	}
	for (int i=1; i < argc; i++) {
		/* 実処理はこの中でやる */
		do_cat(argv[i]);
	}
	exit(1);
}

#define BUFFER_SIZE 2048

void do_cat(const char* path)
{
	int fd; 
	unsigned char buf[BUFFER_SIZE];
	int n;

	/* ファイルをopenし、ファイルディスクリプタを取得 */
	fd = open(path, O_RDONLY);
	if (fd < 0) {
		die(path);
	}
	/* 無限ループ */
	for (;;) {
		/* fdからbufサイズ分bufに読み出す. nは読み込んだバイト数 */
		n = read(fd, buf, sizeof(buf));
		/* nが負のときはエラーなので処理終了 */
		if (n < 0) { 
			die(path);
		}
		/* nが0のときは読み出し完了なのでループを終了 */
		if (n == 0) {
			break;
		}
		/* 読み出した分だけ, 標準出力に書き込む */
		if (write(STDOUT_FILENO, buf, n) < 0) {
			die(path);
		}
	}
	/* ファイルディスクリプタを片付ける */
	if (close(fd) < 0) {
		die(path);
	}
}

void do_cat_stdin(void)
{
	int n;
	unsigned char buf[BUFFER_SIZE];
	
	for(;;) {
		 n = read(STDIN_FILENO, buf, sizeof(buf));
		if (n < 0) {
			die("stdin");
		}
		if (n == 0) {
			break;
		}
		if (write(STDOUT_FILENO, buf, n) < 0) {
			die("stdin");
		}
	}	
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

