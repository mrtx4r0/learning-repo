========================================<br>
Git CLI よく使う特有の文法・記号まとめ<br>
========================================<br>

# リビジョン範囲（revision range）

1) A..B
   意味: B にあって A に無いコミット
   例:
     git log HEAD..origin/main

2) A...B
   意味: A と B の差集合（どちらか一方にのみ存在するコミット）
   例:
     git log main...feature

3) ^A
   意味: A を除外
   例:
     git log ^main feature
   ※ main..feature とほぼ同じ意味


# 親コミット指定

1) HEAD^
   意味: 1つ前のコミット
   同義:
     HEAD~1

2) HEAD~2
   意味: 2つ前のコミット

3) マージコミットの親指定
     HEAD^1   第1親
     HEAD^2   第2親


# 特殊参照名

1) HEAD
   現在のブランチの最新コミット

2) @{u}
   upstream ブランチ
   例:
     git log ..@{u}

3) @{-1}
   1つ前にチェックアウトしていたブランチ
   例:
     git checkout @{-1}

4) HEAD@{1}
   1つ前のHEAD位置（reflog参照）
   例:
     git reset --hard HEAD@{1}


# パス指定区切り

1) --
   以降はファイル名として解釈
   例:
     git log branch -- file.txt


# オブジェクト指定

1) HEAD:file.txt
   HEAD時点の file.txt の内容を表示
   例:
     git show HEAD:file.txt

2) 任意コミットのファイル
     git show a1b2c3d:path/to/file.c


# 比較系

1) 差分
     git diff A B

2) 共通祖先
     git merge-base A B


# ワーキングツリー関連

1) ステージ済みとの差分
     git diff --cached

2) ワーキングツリーとHEADとの差分
     git diff HEAD


# 実践でよく使う確認コマンド

1) pull前確認
     git fetch
     git log HEAD..@{u} --oneline

2) push前確認
     git log @{u}..HEAD --oneline

3) 直前操作の取り消し（reflog使用）
     git reset --hard HEAD@{1}


========================================<br>
補足<br>
========================================<br>

・A..B  は  ^A B  と同じ意味
・Gitの記号は「到達可能なコミット集合」を操作している
・コミットは親ポインタを持つDAG構造
