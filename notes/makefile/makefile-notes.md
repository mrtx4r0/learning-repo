 # 何を書くか
「ターゲット」を作るため「ルール」を書く
***

# ルールの基本構文
```makefile
target: prerequisite
    recipe
```
target:&ensp;作りたいファイル。あるいはそれ自体を作ることが目的ではない疑似ターゲット。省略不可。<br>
prerequisite:&ensp;依存ファイルリスト。ターゲットを作るために必要な材料となるファイル。省略可能<br>
recipe:&ensp;コマンド行。ターゲットを作るための必要な手続き。複数行可。必ずタブで字下げする<br>
***

# makeの基本の動き
基本的にはMakefileに書かれた先頭のターゲットを作るためにルールを解釈する
* ルールの解釈を始める前に、変数への文字列代入と変数参照箇所の文字列への置換処理を行う（C言語のプリプロセスに似ている）
* makeはMakefileの先頭のターゲットを作ろうとする。ターゲットが存在しない場合に、コマンド行の実行を試みる
ただし、依存ファイルリストが存在していることが条件であり、依存ファイルリストが存在しない場合、その依存ファイルを作るため、依存ファイルをターゲットとしたルールを探す
* ターゲットが存在する場合でも、依存ファイルリストのどれかが**ターゲットのタイムスタンプより後に更新されているならば、コマンド行を実行する**
***

# 明示的な擬似ターゲットの宣言
`.PHONY`に続き疑似ターゲット名を宣言すると、そのターゲット名と同名のファイルの有無に関係なく、ターゲットは実行対象となる
以下の例では、all, cleanというファイルが存在したとしてもall, clearnを実行対象にできる
```makefile
.PHONY: all clean
all: 
    cc sample.c -o sample_app
clean:
    rm -f sample.o
```
***

# ビルトイン変数(予約済み変数)
|変数名|意味|
|---|---|
|CC|Cコンパイラ|
|CFLAGS|Cコンパイラオプション|
|CXX|C++コンパイラ|
|CXXFLAGS|C++コンパイラオプション|
|CPPFLAGS|C/C++のプリプロセッサに渡されるオプション(-I,-Dなど)|
|LDFLAGS|リンカオプション|
|MAKE|再帰呼び出し用の make コマンド本体。サブディレクトリで $(MAKE) -C subdir のように使うのが定石|
|MAKECMDGOALS|コマンドラインで渡されるターゲットリスト|
|MAKEFLAGS|`-j`, `-k` などのフラグ。再帰 make へ引き継がれる|
|CURDIR|カレントディレクトリの絶対パス。cdしても不変|
|MAKEFILE_LIST|読み込まれた Makefile の一覧。$(lastword $(MAKEFILE_LIST)) で「今読んでいる Makefile パス」を取る用途が多い|
|SHELL|レシピ実行に使うシェル。Windows 環境では意図したシェルに固定する運用が多い|
|VPATH|依存ファイル探索パス。ソース分離構成で便利|
***

# 演算子
|演算子|説明|
|---|---|
|:=|単純展開。=と異なり再帰代入しない|
|?=|変数が未定義のときのみ代入を行う|
|+=|既に代入されている文字列の末尾に空白付きで追加する|
***

# 内部変数
依存関係の記述を簡略化・一般化するための内部変数が用意されている <br>
`$@`: &ensp;依存関係行のターゲットに置き換わる<br>
`$?`:&ensp;依存ファイルのうち、ターゲットよりも更新時刻が新しいファイルに置き換わる<br>
`$^`:&ensp;依存ファイルリスト全体(更新の新旧に関係ない)に置き換わる<br>
`$>`:&ensp;依存ファイルリストの先頭の依存ファイルに置き換わる<br>
`$*':&ensp;ターゲット名から拡張子を除いたものに置き換わる<br>
***

# パターン置換
### 構文
```make
$(変数:変換前パターン=変換後パターン)
```
変数に含まれる空白区切りの文字列を1個ずつ取り出し、変換前パターンにマッチするものだけを変換後パターンに置き換える
ワイルドカード`%`が使える
### 例
```make
SRCS = src/main.c src/app.c src/mylib.c
***
OBJS = $(SRCS:src/%.c=build/objs/%.o)
# OBJS = build/objs/main.o build/objs/app.o build/objs/mylib.o
***
```
# エラー無視記号&ensp;`-`
`-`を先頭に付与した行は、エラーが起きてもmakeが無視する
例
```make
clean:
    -rm -rf build bin
```
buildやbinディレクトリがない場合rmコマンドはエラーとなるが、makeは止まらない

```make
-include $(DEPS)
```
.dファイルが存在しない/読み込みに失敗しても、makeは中断しない
（初回ビルド時に.dが存在しないのは普通なので、`-`は必須）
***

# ターゲット固有の変数の設定
```makefile
test: CFLAGS+=-DUSE_STUB
```
この例では、testターゲットの時だけ変数設定する
***

# Iオプションにインクルードパスを変数で渡す
```makefile
INCLUDES = include src ../common #パスのリスト
CFLAGS += $(addprefix -I,$(INCLUDES))
```
※addprefixは組み込み関数で、
```makefile
$(addprefix, <prefix>, <list>)
```
prefix(文字列)をlistの各要素に付与する
***

# ファイルの分割
大規模プロジェクトでは、ファイルを分割するのが一般的<br>
* `Makefile`: 入口。ビルド対象・デフォルトターゲット・includeの順序だけを持つ<br>
* `defs.mak`: ツールチェーン、ディレクトリ、共通フラグなど定数/既定値<br>
* `rules.mak`: `%.o: %.c` などのパターンルール、リンク手順、依存生成ルール<br>
* `targets.mak`: 実行ファイル/ライブラリ名、各ターゲットのソース一覧<br>
* `config/*.mak`: Debug/Release、OS別などの上書き設定<br>
* `tools/*.mak`: gcc/clang/iarなどコンパイラ別オプション差分<br>
* `phony.mak`: clean, test, format, help など運用ターゲット<br>
#### ※インクルード順の例<br>
defs.mak → tools/\*.mak → config/*.mak → targets.mak → rules.mak → phony.mak<br>
***

# インクルードでのファイル読み込み
`include ファイル名`:&ensp;makeはルールの実行前にincludeに遭遇したら、その場でファイルを展開する
***

# マクロを利用した関数の自作
* `define`で、関数のような処理をマクロ定義する
* `$(call ...)`で定義したマクロ関数を呼び出す
という仕組みを利用する

```makefile
# windows環境で使用する、DOS版のrealpathを自作する
# マクロ定義
ifeq ($(OS), Windows_NT)
define realdospath
$(shell echo $(realpath $(1)) | sed -e 's%/\([a-zA-Z]\)/%\1:/%')
endef

# マクロ関数呼び出し側
SRCNAME = $(call realdospath <変換したいパス>)
```
ポイント<br>
* `call`する側で引数を指定すると、関数側は`$(1)`, `$(2)`... でそれを受け取れる
* 
# 出典・参考
https://www.gnu.org/software/make/manual/ <br>
[『makeショート入門』](#https://www.amazon.co.jp/make%E3%82%B7%E3%83%A7%E3%83%BC%E3%83%88%E5%85%A5%E9%96%80-TENKAIKEN-ebook/dp/B09BYPMLR7/ref=sr_1_6?__mk_ja_JP=%E3%82%AB%E3%82%BF%E3%82%AB%E3%83%8A&crid=2CXVYRROTC0RR&dib=eyJ2IjoiMSJ9.bUyQDu9LiWqGUTnkzsLFX3wcg31RHjjmpNfNq1Pi8e1vSNF6AZJBFb71iaY9QHC3KpasbT92ZEO2kcPC8LorBAXzbpNFjSaDYyaDjWOcSwXhJPWnZTTqAAgEwpz1_NSH_8dwb1bR0iK81uXeci09rAEpsVd8EQWi9Au09ko2GPn34gT0VDFll8bG8VRiqOyfuwk4YtJzeE3o6wP-h0d_bcDfJQtILyw52OIklug26JxaUqcBnZKbrwDDi33cpXiL8q3I8TcOGBEGAHhQ7xBgrxUMSX3-maBE2NQZMVPSKnw.mD-oXZYPY29C3mg1XBqShm9APDfwsVvsjXLT-gT5r7I&dib_tag=se&keywords=make&qid=1769862483&sprefix=make%2Caps%2C224&sr=8-6)

https://www.ecoop.net/coop/translated/GNUMake3.77/make_9.jp.html

https://tex2e.github.io/blog/makefile/functions
