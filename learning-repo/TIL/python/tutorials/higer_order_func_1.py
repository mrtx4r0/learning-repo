#!/usr/bin/env python3

def func_greeting(name):
    def print_greeting(): # 関数の中に関数を定義できる
        print(f'こんにちは。{name}さん')
    return print_greeting  # 関数を返す（高階関数という) 

func = func_greeting('tetsutaro')  # func にfunc_greeting()の戻り値を代入

print('====funcのオブジェクト内部情報====')
print(func) # funcのオブジェクト内部情報を表示する

print('====func()の実行結果====')
func()
