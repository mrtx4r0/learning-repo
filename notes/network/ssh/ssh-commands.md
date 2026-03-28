===== sshのコマンド ====

# ssh



# sftp
SSHを利用したFTP<br>

* 通信開始
```bash
$ sftp username@domain
```
* 基本操作
pwd, ls, cdなどが使える
```bash
sftp> pwd
# Remote Working Directory: /home/$USER

sftp> ls
# bin src ...
```

* ファイル転送
ローカル→リモート
```bash
sftp> put <filename>
```

リモート→ローカル
```bash
sftp> get <filename>
```

