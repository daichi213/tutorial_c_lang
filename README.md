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

#### ブロック

ブロックとは、{}で囲まれた部分のところで、for や if 文の`{}`もブロックとなっている。また、ブロック内は以下のような特徴を持っている。

- ブロック内で変数宣言をすると、宣言ブロック内をスコープとするローカル変数を定義できる

```c
#include <stdio.h>

int main(void)
{
    int value1 = 10;
    int value2 = 20;

    printf("1:value1 %d\n", value1);
    printf("1:value2 %d\n", value2);

    {
        // ブロック内で宣言をすると新たな変数として認識される
        int value1;
        value1 = 30;
        // 一つ外側で宣言した変数として認識されている
        value2 = 40;
        printf("2:value1 %d\n", value1);
        printf("2:value2 %d\n", value2);
    }

    printf("3:value1 %d\n", value1);
    printf("3:value2 %d\n", value2);

    return 0;
}
```

##### ローカル変数とグローバル変数

```C
#include <stdio.h>

// グローバル変数
// この宣言時に0に初期化される
int count;

int countfunc(void);

int main(void)
{

    // グローバル変数と同名のローカル変数を宣言
    int count;
    countfunc();
    count = 10;
    countfunc();
    countfunc();
    // 関数内で使用される変数はローカル変数が優先して使用される
    printf("main : count = %d\n", count);
    return 0;
}

int countfunc(void)
{
    count++;
    printf("%d\n",count);
    return count;
}
```

- グローバル変数・・・ブロック外で宣言されている変数
  - 1 つのソースファイル内では、どの関数からでもこの変数へアクセスできる
- ローカル変数・・・ブロック内で宣言されている変数
  - ブロック内では、ローカル変数が優先して使用される。
    - 例えば、上の場合 printf の出力でローカル変数の count が使用されている

#### 配列

```C
#include <memory.h>
#include <stdio.h>

int main(void)
{
    int array1[] = { 42, 79, 13, 19, 41 };
    int array2[] = {1,2,3,4,5};

    int i;
    // 配列全体のバイト数を要素のバイト数で割ることで、要素数を算出できる
    int array1_size = sizeof(array1)/sizeof(array1[0]);
    int array2_size = sizeof(array2)/sizeof(array2[0]);

    for(i=0; i<array1_size; i++){
        printf("array1_size[%d]:%d\n",i,array1[i]);
    }
    for(i=0; i<array2_size; i++){
        printf("array2_size[%d]:%d\n",i,array2[i]);
    }

    memcpy(array2,array1,sizeof(array1));
    printf("\n\n\n");

    for(i=0; i<array1_size; i++){
        printf("array1_size[%d]:%d\n",i,array1[i]);
    }
    for(i=0; i<array2_size; i++){
        printf("array2_size[%d]:%d\n",i,array2[i]);
    }
}
```

- [sizeof は演算子で、配列のバイト数を返却する](http://www1.cts.ne.jp/~clab/hsample/Func/Func07.html)
- [その他の演算子](https://www.itsenka.com/contents/development/c/operator.html)

##### バッファオーバーラン

処理中に使用しているメモリ以外のスタックを上書きしてしまう挙動を`バッファオーバーラン`とよぶ。memcpy 関数は、同じサイズの配列同士をコピーすることを想定しているため、コピー元がコピー先の配列よりも大きいと別のスタックのメモリを上書きしてしまうことにより、重大なエラーが発生してしまったりする。

#### リンカー

[参考ページ](https://qiita.com/kazatsuyu/items/5c8d9f539cd925fda007)

## C++
