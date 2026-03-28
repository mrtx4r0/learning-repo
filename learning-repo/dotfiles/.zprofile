
export PATH=/Users/tetsu/.nodebrew/current/bin:/opt/homebrew/bin/git:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Library/Apple/usr/bin:/Users/tetsu/Library/Python/3.9/bin


# homebrewでnodebrewインストールしたときの指示が出たので追加①
export PATH=$HOME/.nodebrew/current/bin:$PATH
# homebrewでnodebrewインストールしたときの指示が出たので追加②
export PATH=/opt/homebrew/opt/openjdk@21/bin:$PATH
 # "To use Homebrew's directories rather than ~/.nodebrew add to your profile:"
export NODEBREW_ROOT=/opt/homebrew/var/nodebrew

# pythonインタープリタ起動時に実行するスクリプトのパス
export PYTHONSTARTUP=$HOME/.pythonrc.py
