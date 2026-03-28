# ~/.pythonrc.py
# 2026.2.18作成 pythonインタープリタ起動時に実行するスクリプト
# 環境変数PYTHONSTARTUPにパスを通してある

import sys
import os
import pathlib
import pprint
import datetime
import json
import math
import re
from pprint import pprint as pp

# ===== プロンプトを見やすく =====
sys.ps1 = ">>> "
sys.ps2 = "... "

# ===== よく使うショートカット =====
cwd = pathlib.Path.cwd()
home = pathlib.Path.home()

def ls(path="."):
    """簡易ls"""
    for p in pathlib.Path(path).iterdir():
        print(p)

def cat(path):
    """簡易cat"""
    print(pathlib.Path(path).read_text())

def now():
    """現在時刻"""
    return datetime.datetime.now()

def clear():
	"""画面クリア"""
	return os.system('clear')

# ===== JSON整形表示 =====
def jprint(obj):
    print(json.dumps(obj, indent=2, ensure_ascii=False))

# ===== 変数確認用 =====
def vars_():
    """現在のグローバル変数一覧"""
    return [k for k in globals().keys() if not k.startswith("_")]

# ===== readline有効化（履歴・補完） =====
try:
    import readline
    import rlcompleter

    readline.parse_and_bind("tab: complete")

    histfile = os.path.expanduser("~/.python_history")
    try:
        readline.read_history_file(histfile)
    except (FileNotFoundError, OSError): # OSErrorはMac用 MacはGNU readlineではないため例外が起きやすいらしい
        pass

    import atexit
    atexit.register(readline.write_history_file, histfile)

except ImportError:
    pass

print("Python REPL ready. (customized)")
