#!/usr/bin/env python3

# 関数を引数にとる関数を定義
def after_greeting(func, name):
    func(name)
    print('今日はいいお天気ですね')

def greeting(name):
    print(f'こんにちは、{name}さん')
    
print('====after_greeting()の呼び出し====')
after_greeting(greeting, 'tetsutaro morita')

