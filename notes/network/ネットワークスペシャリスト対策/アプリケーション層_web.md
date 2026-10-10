# web関連のプロトコル・技術
## HTTP
* Cookie
  * `Set-Cookie`
    * `Domain`属性
    * `Secure`属性
  * `Cookie`
    
* WebSocket
  * Webアプリで、クライアントとWebサーバ間での**双方向通信**を実現する
  * つまり、１つのTCPセッション内で、サーバ側からも自由にデータ送信が行える
  * HTTPのGETメソッド(`upgrade`ヘッダ）でのリクエストとレスポンスのやり取り後、WebSocket通信に切り替わる
  * チャットなどで使われる技術

## プロキシ
* 基本：https://www.infraexpert.com/study/security23.html
* プロキシサーバ
  * クライアント側に置かれるプロキシ
* リバースプロキシサーバ
  * サーバ側に置かれ、インターネット上のクライアントからの要求を代理で受け付ける
  * メリット
    * 負荷分散
    * キャッシュによる負荷軽減
    * TLS通信も代理させることによる負荷軽減
* **プロキシサーバの認証機能**
  * 利用者IDとパスワードでの認証が可能
  * アクセスログに**利用者IDを付加できる**ため、アクセスしたユーザを一意に特定できる
  * 認証方式
    * **Basic認証**
      * 利用者IDとパスワードの組みを「:」で繋ぎ、BASE64でエンコードして送信する（復号が容易なのでセキュアではない）
    * **Digest認証**
      * MD5やSHA256でハッシュ化して送信する
* **PAC**(Proxy Auto Config)
* **WPAD**(Web Proxy Auto-Discovery protocol)
* プロキシサーバを介したSSL（TLS）通信
  * 以下が参考になる
    * https://www.ipa.go.jp/shiken/mondai-kaiotu/ug65p90000000ye5-att/2014h26a_nw_pm2_qs.pdf のp6の図3
    * https://www.ipa.go.jp/shiken/mondai-kaiotu/gmcbt8000000f01f-att/2018h30a_nw_pm1_qs.pdf のp3 \[G社SaaSの試用\]
## webアクセス技術
* WebDAV
  * HTTP1.1を拡張(COPYなどのメソッドを追加)
  * webサーバに対して直接ファイルのコピーや削除が可能
  * httpを使用するのでFTPのようにポートを開けなくていいのがメリット

* MQTT(Message Queuing Telemetry Transport)
  * TCP/IP上で利用可能な、HTTPよりも軽量・省電力なテキストベースのプロトコル
  * メッセージ送信側をパブリッシャー、受信側をサブスクライバー、2者間をMQTTサーバが中継する
  * MQTTサーバがメッセージを保管するため、送信側は受信側の状態意識せずに送れる
  * IoTに適している
* CoAP(Constrained Application Protocol)
  * IoT向けにTCPではくUDPを使用したプロトコル
  * HTTPに似ており、HTTPリクエストをCoAPリクエストに変換も可能

# 様々なプロトコルなどを利用したサービス・技術
* グループウェア
  * GroupSessionなど
