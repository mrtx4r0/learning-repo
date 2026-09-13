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
* プロキシサーバ
  * クライアント側に置かれるプロキシ
* リバースプロキシサーバ
  * サーバ側に置かれ、インターネット上のクライアントからの要求を代理で受け付ける
  * メリット
    * 負荷分散
    * キャッシュによる負荷軽減
    * TLS通信も代理させることによる負荷軽減
* **PAC**(Proxy Auto Config)
* **WPAD**(Web Proxy Auto-Discovery protocol)

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
