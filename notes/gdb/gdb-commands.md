# ======== gdb使い方備忘録 ==============

# 環境構築
gdbのインストール
```bash
$ sudo apt install -y gdb
```

gccビルド
```bash
$ gcc -g -Wall -o myapp main.c
```
`-g` オプションを付ける。最適化オブションはつけない（デバッガがうまく働かないことがある）
<br>

# 基本的な使い方
* gdb起動
```bash
$ gdb ./myapp
```
これが成功すると、`(gdb)`とプロンプトが出てgdbコマンドが実行可能に鳴る<br>

* ソースコードを表示する
※これをしなくてもデバッグはできるが、視覚的にわかりやすくなる
```bash
(gdb) layout src
```

* ブレークポイントを貼る
```bash
(gdb) break main # main関数に入ったらブレークする
(gdb) break main.c:10 # 10行目にブレークポイントを貼る(layout src実行しているときは、行数だけでOK
```

* デバッグ開始
```bash
(gdb) run <arg>
```
runのあとに引数やオプションを付けると、それをそのままプログラムにつけて実行してくれる<br>

* ウォッチ
```bash
(gdb) print 変数名 # p 変数名　でもOK
```

* ブレークした後の実行再開/ステップイン/ステップオーバー
```bash
(gdb) continue # 実行再開
(gdb) step # ステップイン
(gdb) next # ステップオーバー（次の行でブレーク）
```

* デバッグ終了
```bash
(gdb) quit
```

