vimのtips

# colorschemeをicebergにする
https://github.com/cocopon/iceberg.vim/ をクローンしてそれを適用する

```bash
git clone https://github.com/cocopon/iceberg.vim ~/.vim/iceberg.vim
# .vimに移動
cp -r iceberg.vim/colors .
```

以下の構成になる
```bash
$ tree -L2 ~/.vim
/Users/username/.vim
├── colors
│   └── iceberg.vim
└── iceberg.vim
    ├── CHANGES.txt
    ├── LICENSE.txt
    ├── README.md
    ├── autoload
    ├── colors
    └── src
```

.vimrcの設定
```bash
# ~/.vimrc
colorsheme iceberg
```


