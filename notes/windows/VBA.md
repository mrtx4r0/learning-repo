
## プロシージャ
### Sub プロシージャ
戻り値なし

### Function プロシージャ
戻り値あり
プロシージャ名と同名の変数に値を代入すると、その値が戻り値となる
```vb
Function AddNum(x As Long y As Long)
    AddNum = x + y
End Function
```

### 引数
値渡し: ByVal
参照渡し: ByRef