# プログラムの終了

C言語でプログラムの終了を行うコマンドの各挙動の違いなどについて

## exit

- プログラムを終了させ、デストラクターも実行する
- `return`と同じ挙動
- OSへ値を渡す

## abort

プログラムを終了させ、デストラクターは実行されない

## エラー

```bash
error: ‘errno_t’ was not declared in this scope; did you mean ‘error_t’?
    7 |         errno_t err;
      |         ^~~~~~~
      |         error_t
```

[参考ページ](https://stackoverflow.com/questions/33488793/g-errno-t-and-fopen-s-error-in-debian-8-1-jessie)

[ファイルへの書き込み参考](https://qiita.com/jiyu58546526/items/35a3341b7008b2b73e42)
