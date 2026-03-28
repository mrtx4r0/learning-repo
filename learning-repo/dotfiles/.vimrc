"" 基本設定
set fileencodings=utf-8,cp932,euc-jp,iso-2022-jp
set fileformats=unix,dos,mac

"" 色の設定
" True Colorを有効にする
if has('termguicolors')
 set termguicolors
endif

" シンタックスハイライトを有効にする
 " vimはデフォルトでシンタックスハイライトを自動で有効にしないことがあり、
 " syntax enableやsyntax onがないと、colorschemeを指定しても見た目が変わらない
syntax enable

"" icebergはdarkテーマなので、背景をdarkにする
set background=dark

"" icebergのカラースキームを適用する
colorscheme iceberg

"" 行番号を表示
set number

"" キーバインド
" INSERTモードでのみの設定
inoremap jk <Esc>

"" タブ幅(<<, >>コマンドでインデントするときの幅)
set tabstop=4

"== netrw(ファイラ)の設定 =========================================
"" 選択ファイルをファイラ以外のウィンドウで開く
let g:netrw_browse_split = 4
"" ファイラのウィンドウ幅設定
let g:netrw_winsize = 20

"" vim起動時のnetrwの設定
 " vimの引数が1つかつディレクトリ指定されたときだけ、ファイラを開く
 " augroupはautocmdをまとめる名前付きグループ. 
 "  autocmdをグループ化して管理しやすくする・vimの同じセッション内でautocmdが二重登録されることを防ぐ目的で使用される
 " autocmd! でMyNetrwグループの中で登録されているautocmdをすべてクリアする
augroup MyNetrw
	autocmd!  
	autocmd VimEnter * if argc() == 1 && isdirectory(argv(0))
			\ | Vex
			\ | wincmd h
			\ | endif
augroup END
"==================================================================



"" vim終了時に実行するコマンド
augroup ByeMsg
   autocmd!
   autocmd VimLeavePre * echohl WarningMsg 
                        \ | echo "✋️ Bye!" 
			\ | echohl none
			\ | sleep 1 
augroup END
