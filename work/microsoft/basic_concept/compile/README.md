# コンパイルの流れ

[参考ページ](https://subscription.packtpub.com/book/programming/9781789801491/1/ch01lvl1sec03/the-c-compilation-model)

- [コンパイルの翻訳単位](https://learn.microsoft.com/ja-jp/cpp/cpp/program-and-linkage-cpp?view=msvc-170)
    - ソースコードが書かれたファイル毎に翻訳がされる
    - このとき、ファイルが参照しているヘッダーファイルまでは含まれる（シンボルまで）

## 前処理（Preprocessing）

`#include`で指定しているヘッダーファイルを読み込み、一時的にファイルにまとめあげる

## アセンブル

- 一時的にまとめられているファイルをアセンブラー言語で記載されているプログラムへ翻訳する。この時のプログラムをファイルとして、出力すると`・・・.s`の拡張子を持つアセンブラーファイルとなる。
- アセンブラーファイルを機械語（0と1で記述）で記載されているオブジェクトファイル（`・・・.o`）へ変換する。
    - この時、オブジェクトファイルのみでは外部ライブラリに含まれている関数などは実行することができない
    - このオブジェクトファイルには、外部ライブラリに含まれるシンボルのみが含まれる

### シンボル（symbol）

C言語、C++言語で頻繁に登場するシンボルとは、変数名、関数名、クラス名などが含まれる。これの使用目的は、コンパイラーとリンカーがエンティティ（実行される実態）を解決するときに使用される。

以下、ChatGPTに回答してもらったシンボルに対する説明。
> In the context of C++, a symbol is typically the name of a function or a variable, but it can also refer to other types of entities such as classes, namespaces, or macros. A symbol is used by the compiler and the linker to identify a specific entity within the program and to resolve references to it.

## リンク

### 外部リンク・内部リンク

- [動的リンク（dllファイル）と静的リンク（libファイル）](https://learn.microsoft.com/ja-jp/cpp/build/dlls-in-visual-cpp?view=msvc-170)
- [dllとlibの違い](https://akegure.com/difference-dll-lib/)