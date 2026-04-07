# MakeSampleC

学習用の C 言語プロジェクトです。`defs.mak` と `rules.mak` で役割分担し、本番ビルドとテストビルドを切り替えます。

## フォルダ構成

- `make/` : ビルド設定とビルドルール
- `src/` : 本番コード
- `include/` : ヘッダ
- `tests/` : テストコード
- `build/` : 生成物

## 使い方

```bash
make prod      # 本番ビルド
make test      # テストビルド
make run       # 本番実行
make test-run  # テスト実行
make clean     # 生成物削除
```

## 役割

- `make/defs.mak` : 変数定義、ビルドモード別フラグ、ソース一覧
- `make/rules.mak` : ターゲット、コンパイル規則、リンク規則
- `Makefile` : 入口（defs/rules の include）
