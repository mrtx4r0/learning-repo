# git config
|操作|コマンド|備考|
|---|---|---|
|ユーザ名を設定する|git config --global user.name "USERNAME"|globalスコープはユーザ全体|
|メールアドレスを設定する|git config --global user.email "ADDRESS"|
|設定一覧を出力|git config --list|system, global, local全スコープの設定一覧を出す。スコープをしぼりたければ、--global等つける|

# git branch
|操作|コマンド|備考|
|---|---|---|
|ブランチを作成する|git branch main|
|ブランチ名を変更する|git branch -m \<old\> \<new\>|mはmoveのm
|現在のブランチ名を強制的に変更|git branch -M \<new\>|git init後にgit branch -M mainをよく使う|
|チェックアウトしているブランチの追跡ブランチを設定する|git branch -u origin/main|
|チェックアウトしているブランチの追跡ブランチを設定する|git branch -u origin/feature||

# git checkout
|操作|コマンド|備考|
|---|---|---|
|ブランチ"work"を作成 & タグ "init_tag" をチェックアウトする|git checkout -b work init_tag|

# git switch
|操作|コマンド|備考|
|---|---|---|
|現在チェックアウトしているブランチを切り替える|git switch master main|

# git clone
|操作|コマンド|備考|
|---|---|---|
|任意のローカルディレクトリにリポジトリをブランチ指定してクローンする|git clone -b <ブランチ名> <リモートリポジトリのURL> <ローカルのディレクトリ名>||

# git add
|操作|コマンド|備考|
|---|---|---|
|対話モードでファイルごとに差分を確認してステージするかを決める|git add -p|git addで特定のファイルをステージしたいが、パスを指定するのが面倒なときに使える

# git push
|操作|コマンド|備考|
|---|---|---|
|mainブランチをリモートにPUSH＋今後はmainのpush/pullのデフォルトをorigin/mainに設定する|git push -u origin main|

# git reset
|操作|コマンド|備考|
|---|---|---|
|アンステージする|git reset <ファイル名>|

# git diff
|操作|コマンド|備考|
|---|---|---|
|作業ツリーとHEADの差分を表示する|git diff HEAD|
|ステージとHEADの差分を表示する|git diff --staged|

# git remote
|操作|コマンド|備考|
|---|---|---|
|リモートリポジトリに名前をつける|git remote add <リモート名> <リポジトリURL>||
|指定したリモート名のURLを変更|git remote set-url <リモート名> <新しいリポジトリURL>||

# git log
|操作|コマンド|備考|
|---|---|---|
|ログを表示する|git log||
|ログと差分(パッチ)を表示する|git log -p||
|指定されたパターンに一致するコミットコメントを含むコミットのログだけを抽出する|git log --grep="MESSAGE"|"="の代わりに半角スペースでもOK|
|ログを1行(コミットID コミットコメント)で出力する|git log --oneline||
|git logのメタ情報部分を任意のフォーマットに整える|git log --pretty=format:"commit %H"|"format:"のあとにはプレースホルダ(%Hなど)が使用可能。例の場合、メタ上方部分が"commit <フルコミットハッシュ>"の形式になる|
|ローカルmainブランチの最新コミットからリモート最新コミットまでのコミットを表示する|git log HEAD..origin/main --oneline|
