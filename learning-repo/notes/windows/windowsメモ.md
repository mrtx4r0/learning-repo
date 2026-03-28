
## Windowsの主要なディレクトリ
#### システム領域
```terminal
C:\Windows
├─ System32      ← 中枢（64bit実体あり）
├─ SysWOW64      ← 32bit用のSystem32
├─ WinSxS        ← 部品倉庫
├─ Temp          ← OS用一時ファイル
├─ Logs          ← OSログ
└─ Fonts         ← フォント
```

#### ユーザー領域
```terminal
C:\Users
├─ <ユーザー名>
│  ├─ Desktop
│  ├─ Documents
│  ├─ AppData    ← アプリ設定の本体
```

## 環境変数設定
Windows+R→`SystemPropertiesAdvanced`と入力、Enter
→システムのプロパティ　画面で環境変数設定可能

## Win+Rは何をやっているか
**explorer.exe**がPATH検索、拡張子解決、システム登録コマンド実行　をやっている



## パス表記
### ローカルパス
```
C:\\Users\..
```
### UNCパス(UniversalNamingConvention)
\\\\で始まり、ネットワーク上のサーバの共有フォルダのパスを表す
\\\\サーバ名\共有名\パス\ファイル名
```
\\fileserever02\shared\docs\sample.pdf
\\192.168.1.20\..  #IPアドレスの場合
```
※`\\`はSMB(ServerMessageBlock)プロトコルというTCP/IP上のプロトコルを使用している。これはWindowsのネットワーク上のファイル共有用プロトコルの総称。

## 送る　の場所
C:\Users\\<Username\>\AppData\Roaming\Microsoft\Windows\SendTo

## レジストリの編集
例として、doskeyを設定するスクリプトを、cmd.exe起動時に実行する設定を行う<br>
1.レジストリエディターを起動<br>
 `Win + R`で`regedit`と入力<br>
2.`HKEY_CURRENT_USER\Software\Microsoft\`キーに移動<br>
3.Microsoft配下にCommand Processorが無い場合、新規にキーを追加する<br>
 `Microsoft`で右クリックし、新規→キーをクリック<br>
4.キー名に`Command Processor`として登録<br>
5.`Command Processor`を右クリックして、新規→文字列値をクリック<br>
6.追加した文字列値を<br>
　値の名前=AutoRun<br>
  値のデータ=実行したいスクリプトのパスv
  を登録する<br>
以上

## Windowsの設定ツール諸々
Windowsツール（Windows管理ツール）<br>
  サーバの設定とかができる<br>
コンピューターの管理<br>
  ユーザの追加などができる<br>
コントロールパネル<br>
　？
Win+Iで起動するやつ<br>
　？

## ブラウザデータの場所
* chromeのブックマークバーのデータ
以下、BookmarksというJSON形式で保存されている
```
C:\Users\<ユーザー名>\AppData\Local\Google\Chrome\User Data\Default\Bookmarks
```
