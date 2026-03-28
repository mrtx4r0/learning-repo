
ログから削除差分(ヘッダの"---ファイル名"は除く)に"KEYWORD"を含む行を、
"コミットハッシュ: マッチした行" の形式で出力する
```bash
git log -p --pretty=format:"commit %H" | \
awk '/^commit/ {hash=$2} \
/^-/ && $0 !~ /^---/ && /KEYWORD/ \
{print hash ": " $0}'
```

