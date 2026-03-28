DNS関連のメモ

※以下は、ubuntu-server 25.04環境を前提

# 設定ファイル
## /etc/resolv.conf
概要
* DNSの設定ファイル
* /run/systemd/resolve/stub-resolv.conf へのシンボリックリンクになっている
* netplan, NetworkManager, systemd-resolvedのいずれかが自動生成する（手動修正は基本NG）

設定例
```conf
# /etc/resolv.conf
   nameserver 127.0.0.53
   options edns0 trust -ad
   search  . 
```
記述の意味
```conf
nameserver 127.0.0.53
```
* 127.0.0.53はsystemd-resolvedが提供するローカルのDNSキャッシュサーバ（スタブ）
* DNSクライアント(ブラウザ、curl等)はDNSを直接外部に問い合わせず、まずこのローカルDNSに問合せる
* systemd-resolvedは、
 * netplanの設定
 * DHCPから取得したDNS
 * VPNのDNS
 * マルチキャストDNS(mDNS)
 などを統合して、最適なDNSへ問合せる
