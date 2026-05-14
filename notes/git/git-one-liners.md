# git ワンライナー集

#### コミット間のファイル単位の差分一覧
* ファイル単位の＋/-も表示する
  ```bash
  $ git diff --stat hash1 hash2
  ```
* +/- をD: Deleted　M:Modified  A: Addedの表記で表示する
  ```bash
  $ git diff --name-status hash1 hash2
  ```

#### mainブランチのローカル最新〜リモートの最新までのコミットハッシュ、日付、コメントを出力する
```bash
git log HEAD..origin/main --pretty=format:"%ad %h %s" --date=format:"%Y.%m.%d %H:%M"

# 出力例
$ git log HEAD..origin/main --oneline --pretty=format:"%h %ad %s" --date=format:"%y.%m.%d %H:%M"
65e1144 26.02.01 21:51 add
5e35f2c 26.02.01 21:25 modify
9c076f6 26.02.01 21:16 modify
935dd10 26.02.01 21:00 add
```
`%ad`: author date
`%h`: 短縮コミットハッシュ
`%s`: コミットメッセージ
