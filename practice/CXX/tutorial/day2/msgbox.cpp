#include <windows.h> /* Win32APIほぼ全部入りヘッダ ここではMessageBoxを使用 */

int main(){
    MessageBox(
        NULL,           /* HWND hWnd: 親ウィンドウのハンドル NULL=「親なしの独立したハンドル」*/
        "Hello from win32 API", /* メッセージ本文 */
        "WinAPI Test",  /* ダイアログ上部に表示するタイトル */
        MB_OK | MB_ICONINFORMATION  /* 表示オプション
                                        MB_OK: OKボタン 
                                        MB_ICONINFORMATION: 情報アイコン 
                                        | はビットのOR演算 */
    );
    return 0;
}