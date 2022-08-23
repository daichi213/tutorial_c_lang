# C

## C

### 苦しんで覚える C 言語

[苦しんで覚えるＣ言語](https://9cguide.appspot.com/index.html)を参考にして、ハンズオン形式で C 言語の学習を行った。

#### 文字列の表示

[コンソール上での文字列の表示](https://9cguide.appspot.com/03-01.html)

- ファイルの最上部で宣言している`#include`は使用するファイル名を指定している
  - `#include<stdio.h>`は文字列をコンソール上へ表示させるためのヘッダーファイル
  - [ヘッダーファイルは関数や変数の宣言](https://teratail.com/questions/135939)を行っているファイル
  - エスケープシーケンス・・・`\n, \t, e.g.`

#### 数値の表示

[数値の表示](https://9cguide.appspot.com/04-01.html)

#### 関数

##### プロトタイプ宣言

C 言語で関数を定義すると、main 関数よりも後に定義した関数はコンパイラーに認識されない。そのため、main 関数よりも先に読み込みたい関数を宣言する必要がある。これを`プロトタイプ宣言`と呼ぶ。
`また、このプロトタイプ宣言を行うファイルは基本的に拡張子がhのファイルで行われる。`

```c
#include <stdio.h>

// プロトタイプ宣言
int sum(void);

int main(void) {
    return 0;
}

int sum(void) {
    printf("%d\n", (1 + 100) * 100 / 2);
    return 0;
}
```

##### 返却値

C では、返却値は 1 つのみしか返却することができないもよう。

```c
#include <stdio.h>

int sum(int, int);

int main(void)
{
    int value;
    value = sum(50, 100);
    printf("value: %d\n", value);
    return 0;
}

int sum(int min, int max)
{
    int num;
    num = (min + max) * (max - min + 1) / 2;
    return num;
}
```

#### リンカー

[参考ページ](https://qiita.com/kazatsuyu/items/5c8d9f539cd925fda007)

## C++
