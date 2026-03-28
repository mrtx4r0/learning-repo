"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set fileencodings=utf-8,cp932,euc-jp,iso-2022-jp
set fileformats=unix,dos,mac
" 2025.7.27 ↑↑↑ここまではデフォルトで書かれていた
" ただし、fileencodings の適用順をutf-8を最初になるよう変えた
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" 以下、カスタマイズ

"" プラグイン
"call plug#begin('~/.vim/plugged')
call plug#begin()

Plug 'cocopon/iceberg.vim'

call plug#end()

"" 色の設定
" set termguicolors
colorscheme iceberg

"" 行番号を表示する
set number

"" キーバインド
" INSERTモードのみの挙動
inoremap jk <Esc> 
