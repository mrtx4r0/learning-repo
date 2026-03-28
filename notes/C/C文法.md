# マクロ(プリプロセッサ)
## 可変引数 `(...)`, `__VA_ARGS__`<br>

```c
#define LOG(fmt, ...) printf(fmt, ##__VA_ARGS__)

/* 以下のいずれもLOG(fmt, ...)のマクロが効く */
LOG("value is %d", 123);
LOG("error occurred\n");
```
※`##__VA_ARGS__`は可変引数が空の時にカンマ `,` を削除してくれる
***
## トークン連結演算子 `##`
`##`は左右のトークンを結合して新しいトークンを作る<br>
```c
#define MAKE_VAR(name) var_##name

/* 展開前(マクロで記述) */
MAKE_VAR(test)
/*  展開後 */
var_test
```

## 定義済みマクロ
