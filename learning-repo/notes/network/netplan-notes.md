# netplanとは
linux(UbuntuServerなど)でネットワーク設定をユーザが簡単にできるようにする仕組み。<br>
OSとユーザの間に立つIF。<br>

## netplanがやっていること
* ユーザが記述したYAML(/etc/netplan/*.yaml)を読み込む
* YAMLの文法をチェックする
* バックエンド(systemd-networkdまたはNetworkManager)用の設定ファイルを自動生成(netplan generate)
* それをOSに反映する(netplan apply)
※YAMLの読み込み、文法チェック、設定ファイル自動生成までがnetplan generateが実行する処理<br>
※OSへの反映(=networkdに再読み込みを指示)がnetplan applyが実行する処理<br>
※netplan applyコマンドでgenerate+applyの処理を実行可能

# systemd-networkd
* systemd の一部で動くネットワークサービス
* 有線・無線インターフェイスの実管理（IP設定、ルート追加、DHCP クライアント動作等）を担当する
* 設定ファイルは /run/systemd/network/*.network などに置かれる（Netplan が生成する）

# 公式ドキュメント
https://netplan.readthedocs.io/en/stable/
