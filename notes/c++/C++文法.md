# 参照渡し


# テンプレート
```cpp
template <typename T>
// template <class T> も同じ意味
// typename、classは型パラメータを表すキーワード
```
* クラス、関数のパラメータの型を汎用的にする仕組み
* templateで定義した型(ここではT)は、テンプレートクラス/関数を使う側が任意の型で渡せる
* template定義 直後の宣言(クラス、関数、変数)に対して有効

# クラス
## デストラクタ
```cpp
class Device {
public:
  Device(const std::string& name,
         const std::string& serialNumber);
  virtual ~Device() = default; // デストラクタを自分では書かず、コンパイラに標準の実装を作ってもらう

  virtual bool initialize() = 0; // 純粋仮想関数 基底クラスでは実装せず、派生クラスでの実装を要求
  
}
```

## 仮想関数

# new演算子
ヒープ領域にメモリを確保(動的に確保)して、そのアドレスを返す。mallocのイメージ

# その他
`static_assert`宣言
```cpp
static_assert(N > 0, "number of array elements must greater than 0");
};
```
第1引数の条件式が偽の場合に、コンパイルエラーを起こして第2引数の文字列を表示させる
