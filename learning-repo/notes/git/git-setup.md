# githubに学習用リポジトリ作成したときの手順記録
## 1.githubにリポジトリを作成する
TILという名前で新規リポジトリを作る
## 2.ローカルPCに1で作成したリポジトリ用のディレクトリを作成する
```bash
# ディレクトリを作成
$ mkdir -p github/TIL

# git管理開始
$ git init

# デフォルトブランチ名をmainにかえる
$ git branch -m master main

# リポジトリ説明のためのREADMEだけとりあえず作成 
$ echo "TIL is repository for learning" > README.md

# コミット
$ git add .
$ git commit -m "Initial Commit"

# リモートリポジトリに名前をつける
$ git remote add origin git@github.com:mrtx4r0/TIL
$ git remote -v
origin	git@github.com:mrtx4r0/TIL (fetch)
origin	git@github.com:mrtx4r0/TIL (push)
```
## 3.githubのリポジトリ（リモート）にPUSHする
ユーザ認証のための公開鍵を作成しておく
```bash
$ ssh-keygen -t ed25519 -C "xxxxxxxx@gmail.com"
Generating public/private ed25519 key pair.
Enter file in which to save the key (/Users/(user)/.ssh/id_ed25519):
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /Users/(user)/.ssh/id_ed25519
Your public key has been saved in /Users/(user)/.ssh/id_ed25519.pub
The key fingerprint is:
SHA256:QS9C4InN4foMuE5Td3z9TQ1upCfsf69xJeWZgEhgpp4 xxxxxxxxx@gmail.com
The key's randomart image is:
+--[ED25519 256]--+
|    o..+o.       |
|   * ++.... .    |
(中略）
|o .          . o.|
| .            ooo|
+----[SHA256]-----+
```
sshが使用する公開鍵の認証アルゴリズムを指定しておく
```bash
$ touch ~/.ssh/config
```
configに以下のように記述する
```bash
# ~/.ssh/config
Host github.com
  User git
  Identityfile ~/.ssh/id_ed25519
```

プッシュする
※ -uでorigin/mainとローカルのmainブランチを紐づける(リモートのmainを追跡させる)
```bash
$ git push -u origin main
The authenticity of host 'github.com (20.27.177.113)' can't be established.
ED25519 key fingerprint is SHA256:+DiY3wvvV6TuJJhbpZisF/zLDA0zPMSvHdkr4UvCOqU.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'github.com' (ED25519) to the list of known hosts.
Enter passphrase for key '/Users/(user)/.ssh/id_ed25519':
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (4/4), 800 bytes | 800.00 KiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:mrtx4r0/TIL
   46ae43d..aae7330  main -> main
branch 'main' set up to track 'origin/main'.
```

