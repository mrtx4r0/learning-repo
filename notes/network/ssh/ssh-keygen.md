## ssh-keygenの基本構文
```bash
ssh -t <鍵のタイプ> -C "コメント"
```
### 鍵のタイプ（認証アルゴリズム）
|タイプ|説明|
|---|---|
|rsa1SSHプロトコルバージョン1用RSA1認証の鍵ペア|
|rsa|SSHプロトコルバージョン2用RSA認証の鍵ペア|
|dsa||SSHプロトコルバージョン2用DSA認証の鍵ペア|
|ecdsa||SSHプロトコルバージョン2用ECDSA認証の鍵ペア|
|ed25519||SSHプロトコルバージョン2用Ed25519認証の鍵ペア|

### コメント
任意の形式でコメントを付与できる（つけなくてもいい）
id_25519.pubの各鍵の末尾に付与される（あとで直接追記・書き換えてもいい）

```bash
$ ssh-keygen -t ed25519 -C “DUUMY_KEY”
Generating public/private ed25519 key pair.
Enter file in which to save the key (/home/tetsu/.ssh/id_ed25519):  # ①
Enter passphrase for "/home/tetsu/.ssh/id_ed25519" (empty for no passphrase): # ②
Enter same passphrase again: # ③
Your identification has been saved in /home/tetsu/.ssh/id_ed25519
Your public key has been saved in /home/tetsu/.ssh/id_ed25519.pub
The key fingerprint is: # ④
SHA256:5D/D4FyihwdzVGbYUjY91QlxBGDxPAp6Hf49VkwcgWM tetsu@ubuntu-server
The key's randomart image is: # ⑤ 
+--[ED25519 256]--+
|         +B=o=B*o|
|        o=o.=E.oo|
|        oo ..=. o|
|       +. + o .o |
|      o.S..+    o|
|       O.*  . . .|
|      o = =  . + |
|       o   o  . .|
|                 |
+----[SHA256]-----+
```

### 出力内容の意味
① 秘密鍵の保存場所。問題なければ何も入力せずreturn
② 秘密鍵を使うときに必要になるパスフレーズ。秘密鍵はそれ自体暗号化されており、使える状態にするにはパスフレーズを入力する必要がある
③ パスフレーズを再入力
④ fingerprintは公開鍵に対してハッシュ値（固有の値）をとったもの。公開鍵の指紋のようなもの
⑤ fingerprintをASCIIアートイメージに変換したもの
