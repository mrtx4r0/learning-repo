## ショートカット

* `Ctrl＋＠`: ターミナルを起動・エディタからターミナルに移動
* `Ctrl+1`: ターミナルからエディタに移動

## ユーザ設定
* Windowsの場合
  %APPDATA%\Code\User\にsettings.jsonを置く

## ターミナルのデフォルトシェルを変更する

https://zenn.dev/unsoluble_sugar/articles/362a17a7f57020

## プラグイン

CSVを見やすくする
https://note.com/lush_clover5338/n/nebacafd396f7

## キーのバインド設定


```json5
// C:\Users\%USERNAME%\AppData\Roaming\Code\User\keybindings.json
// 既定値を上書きするには、このファイル内にキー バインドを挿入します
[
    {
        "key": "ctrl+tab",
        "command": "editor.action.inlineSuggest.commit",
        "when": "inInlineEditsPreviewEditor"
    },
    {
        "key": "tab",
        "command": "-editor.action.inlineSuggest.commit",
        "when": "inInlineEditsPreviewEditor"
    },
    {
        "key": "ctrl+tab",
        "command": "editor.action.inlineSuggest.commit",
        "when": "inlineEditIsVisible && tabShouldAcceptInlineEdit && !editorHoverFocused && !editorTabMovesFocus && !suggestWidgetVisible || inlineSuggestionHasIndentationLessThanTabSize && inlineSuggestionVisible && !editorHoverFocused && !editorTabMovesFocus && !suggestWidgetVisible || inlineEditIsVisible && inlineSuggestionHasIndentationLessThanTabSize && inlineSuggestionVisible && !editorHoverFocused && !editorTabMovesFocus && !suggestWidgetVisible || inlineEditIsVisible && inlineSuggestionVisible && tabShouldAcceptInlineEdit && !editorHoverFocused && !editorTabMovesFocus && !suggestWidgetVisible"
    },
    {
        "key": "tab",
        "command": "-editor.action.inlineSuggest.commit",
        "when": "inlineEditIsVisible && tabShouldAcceptInlineEdit && !editorHoverFocused && !editorTabMovesFocus && !suggestWidgetVisible || inlineSuggestionHasIndentationLessThanTabSize && inlineSuggestionVisible && !editorHoverFocused && !editorTabMovesFocus && !suggestWidgetVisible || inlineEditIsVisible && inlineSuggestionHasIndentationLessThanTabSize && inlineSuggestionVisible && !editorHoverFocused && !editorTabMovesFocus && !suggestWidgetVisible || inlineEditIsVisible && inlineSuggestionVisible && tabShouldAcceptInlineEdit && !editorHoverFocused && !editorTabMovesFocus && !suggestWidgetVisible"
    },
    {
        "key": "ctrl+tab",
        "command": "-workbench.action.quickOpenPreviousRecentlyUsedEditorInGroup",
        "when": "!activeEditorGroupEmpty"
    }
]
```
