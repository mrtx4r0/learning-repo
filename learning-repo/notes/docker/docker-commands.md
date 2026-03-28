
## docker compose
コンテナの作成(ビルド)と実行<br>
```bash
docker compose up -d
```
* ローカルにビルド対象のイメージが存在しない場合はイメージをpullしてからビルドと実行を行う
* `-d`オプションはコンテナをバックグラウンドで実行させる。`-d`オプションを付けない場合、フォアグラウンドで実行されることにより、コンテナのログが画面上に出力されターミナル上で続けてコマンドを打つことができなくなる
* `up`に限らず、`docker compose`のコマンドは、`compose.yaml`を配置した階層で実行する

コンテナの起動<br>
```bash
docker compose start
```
* ビルドはしない。起動するだけ

コンテナの停止<br>
```bash
docker compose stop
```

コンテナの再ビルド<br>
```bash
docker compose up -d --build
```
* `--build`をつけると必ずbuildを試みてからupする
* `docker compose up -d`はDockerfileやbuild contextが変わっていなければ、既存イメージを使って再ビルドしないため、確実にビルドし直したい場合に使う

