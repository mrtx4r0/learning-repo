#include <windows.h>

/* ウィンドウプロシージャ ウィンドウで発生したイベントを処理する関数 */
LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam
) {
    switch(msg) {
        /* WM_DESTROY: ウィンドウが破棄されるときに送信されるメッセージ */
        /* このメッセージのときの処理のみ自身で定義する */
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    /* WM_DESTROY以外のメッセ―ジのときは、デフォルトのウィンドウプロシージャをコール */
    return DefWindowProc(hwnd, msg, wParam, lParam);
}


/* Windowsアプリのエントリポイント */
int WINAPI WinMain(
    HINSTANCE hInstance,    /* インスタンスハンドル　プログラムを識別する */
    HINSTANCE,                  /* 第2引数は意味なし。常に0。16bit Windowsで使用されていた。引数を使用しない場合は変数名省略可 */
    LPSTR,                  /* コマンドライン引数 LPSTRはWindows標準の文字型 */
    int nCmdShow            /* アプリケーションの初期表示方法 */
) {
    const char CLASS_NAME[] = "MyWindowClass";
    
    /* ウィンドウクラスの定義 */
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    /* ウィンドウクラスの登録
        OSにウィンドウを認識させ、ユーザプログラムが使えるようにする 
        これをしないと、CreateWindowが失敗する */
    RegisterClass(&wc);

    /* ウィンドウの生成 */
    /* 戻り値はウィンドウハンドル */
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "My First 32 Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        640, 480,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    /* ウィンドウの表示 */
    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    /* メッセージループ */
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);          /* この関数内でWndProc()がコールバックされてメッセージが処理される */
    }

    return 0;
}
