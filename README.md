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

#### 文字の扱いについて

TODO 文字列の項目についてまとめる

#### C 言語での配列について

```c
#include <stdio.h>

int main(void)
{
    int array[10];
    printf("array____(%p)\n",array);
    printf("array[0](%p)\n",array[0]);
    printf("array[1](%p)\n",array[1]);
    printf("array[2](%p)\n",array[2]);
    return 0;
}
```

```sh
array____(0x7ffdcfe3f730)
array[0]((nil))
array[1]((nil))
array[2]((nil))
```

- 配列は他変数と扱いが異なり、配列自体はメモリのアドレスが格納されている。
- ブログ時点と異なる点として、配列のアドレスと要素のアドレスは切り分けて管理されていることが上の出力結果からわかる
- また、ブログの執筆時点ではそれぞれの要素に対して宣言時にメモリが割り当てられているようだが、2022/9 時点では配列自体のみに対してアドレスが割り当てられている。

```C
#include <stdio.h>

int main(void)
{
    char str[256];
    scanf("%s", &str[2]);
    printf("%s\n", str);
    printf("address_str:%p\n", str);
    printf("address_str[0]:%p\n", str[0]);
    printf("address_str[1]:%p\n", str[1]);
    printf("address_str[2]:%p\n", str[2]);
    printf("address_str[3]:%p\n", str[3]);
    printf("address_str[4]:%p\n", str[4]);
    printf("address_str[5]:%p\n", str[5]);
    printf("address_str[6]:%p\n", str[6]);
    printf("address_str[7]:%p\n", str[7]);
    return 0;
}
```

```sh
$ ./test
# scanf部分
test
# 入力開始されているindex2からアドレスが割り当てられている
address_str:0x7fff98b65f80
address_str[0]:(nil)
address_str[1]:(nil)
address_str[2]:0x74
address_str[3]:0x65
address_str[4]:0x73
address_str[5]:0x74
address_str[6]:(nil)
address_str[7]:(nil)
```

- 上のようにコンソールから文字列を配列に格納する処理を行なったところ、入力開始されている index2 からアドレスが割り当てられているところが確認できた
- また、「test」の終わりと始まりの「t」は同じアドレスとして配列に割り当てられており、メモリを節約するように動作していることがわかる

```C
#include <stdio.h>

int getaverage(int data[]);
int getaverage(int data[10]);
int getaverage(int *data);

int main(void)
{
    int average, array[10] = { 15, 78, 98, 15, 98 };
    average = getaverage(array);
    printf("average: %d\n", average);
    printf("array[3]: %d\n", array[3]);
    return 0;
}

int getaverage(int data[10])
{
    int i, average = 0;
    for (i = 0; i < 10; i++) {
        average += data[i];
    }
    data[3] = 1000;
    return average / 10;
}
```

- また、配列を関数へ渡す際は配列のアドレスを渡すようになっていることが上の getaverage 関数の宣言方法からわかる
  - 宣言に要素数を含める or 含めないの表現で動作していることから確認できる

#### 構造体

構造体は複数の変数を一まとめにして定義することができる型（機能）で、Go と同じような使い方をする（Go は C 言語を踏襲して設計されているよう）。

```C
...
struct student
{
    int year;
    int clas;
    int number;
    char name[64];
    double stature;
    double weight;
};

int main(void)
{
    // typedefを使用しない場合はstructを使用して型を再定義する必要がある
    struct student data1, data2;
...
    return 0;
}
```

##### typedef

```C
struct student_tag
{
    int year;       /* 学年 */
    int clas;       /* クラス */
    int number;     /* 出席番号 */
    char name[64];  /* 名前 */
    double stature; /* 身長 */
    double weight;  /* 体重 */
};

typedef struct student_tag student;
```

```C
typedef struct student_tag
{
    int year;       /* 学年 */
    int clas;       /* クラス */
    int number;     /* 出席番号 */
    char name[64];  /* 名前 */
    double stature; /* 身長 */
    double weight;  /* 体重 */
} student;
```

```C
typedef struct
{
    int year;       /* 学年 */
    int clas;       /* クラス */
    int number;     /* 出席番号 */
    char name[64];  /* 名前 */
    double stature; /* 身長 */
    double weight;  /* 体重 */
} student;
```

##### 構造体の初期化

```C
int main(void)
{
    student data;
    student *pdata;

    // 構造体の初期化
    pdata = &data;
}
```

##### 構造体ポインタ

```C
...

int main(void)
{
    student data;
    student *pdata;

    // 初期化
    pdata = &data;

    // アロー演算子なしのアクセス
    (*pdata).year = 10;
    strcpy((*pdata).name, "MARIO");
    // アロー演算子でのアクセス
    pdata->year = 10;
    strcpy(pdata->name, "MARIO");
...
}
```

###### 関数のポインタ経由アクセス

```C
#include <stdio.h>
#include <string.h>

typedef struct
{
    int year;
    int clas;
    int number;
    char name[64];
    double stature;
    double weight;
} student;

void student_print(student *data);

int main(void)
{
    // typedefのお陰でintなどと同じように型としてコンパイラーに認識される
    student data;

    data.year = 3;
    data.clas = 4;
    data.number = 18;
    strcpy(data.name, "MARIO");
    data.stature = 168.2;
    data.weight = 72.4;

    student_print(&data);

    return 0;
}

void student_print(student *data)
{
    printf("[学年]:%d\n",data->year);
    printf("[クラス]:%d\n",data->clas);
    printf("[出席番号]:%d\n",data->number);
    printf("[名前]:%s\n",data->name);
    printf("[身長]:%lf\n",data->stature);
    printf("[体重]:%lf\n",data->weight);
    return;
}
```

上記のようにして関数内から構造体へのアクセスをポインター経由で行うことができる。この処理によるメリットをいかに記載する。

- 関数内から変数の書き換えを行うことができる
- 関数の呼び出しを高速にすることができる
  - 構造体は配列と異なり、通常の値渡しが行われる。そのため、通常の値わたしを行うと、構造体のデータを全てコピーして関数に渡すことによる処理速度の低下が発生する。

#### ファイルの読み書き

##### テキストファイル

```C
#include <stdio.h>

int main(void)
{
    int i, j;
    // fileの構造体定義
    FILE *f;
    // 構造体の初期化
    f = fopen("test.txt", "r");
    fscanf(f, "%d,%d", &i, &j);
    fclose(f);
    printf("i = %d, j = %d\n", i, j);
    return 0;
}
```

```csv
<!-- test.txt -->
23,56
```

- file の構造体を定義して、その構造体を初期化してファイルの読み書きを行う。
- 上記 test.txt ファイルではカンマで区切って、複数の値の読み込みを行っている。このようなデータ形式はおなじみ csv ファイルである。

##### 書き込みモード

```C
#include <stdio.h>
#include <string.h>

void write_row_in_file(person *person)
{
    FILE *file;
    file = fopen(filename, "a");

    fprintf(file,"%d,%d,%s\n",person->num,person->score,&person->name);
    fclose(file);

    return;
}
```

- fopen の第二引数にファイルの
  - [書き込みの a モードを使用すると fprintf などを使用したデータの書き込み時にファイルに追記することができる](https://webkaru.net/clang/file-append/)

#### マクロ

マクロとは、以下のコードブロックの define で示されている箇所のことを示している。具体的には、簡便な関数のような使い方と定数を定義する際に使用することが主な使い方となる。また、このマクロは基本的にすべて大文字で定義する。

```C
#include <stdio.h>

#define PRINTM(X) printf("%d\n",X)

int main(void)
{
    int a1 = 100, a2 = 100;
    PRINTM(a1);
    PRINTM(a2);
    return 0;
}
```

##### マクロの特徴

**関数は実態が 1 つで、それを呼び出すような仕組みとなっている。一方で、マクロは呼び出し箇所で、そっくりそのまま置き換わるような挙動を示す**

- グローバルな定数の定義に便利
- 関数よりも若干高速

##### マクロの副作用

マクロは上の特徴のために想定外の挙動を示すことがあり、計算結果などに悪影響を与えてしまうことがある。このことをマクロの副作用と呼ぶ。以下、台形の面積を求めるコードで具体的に副作用がどういうものか説明する。

```C
#include <stdio.h>

#define GET_TRAPEZOID_ARE(A, B, H) (A + B) / H * 2

int main(void) {
    int up, down, h, s;

    printf("上底, 下底, 高さ(,区切りで入力)：");
    scanf("%d, %d, %d", &up, &down, &h);
    s = GET_TRAPEZOID_ARE(up, down, h+2);
    printf("面積:%d\n", s);

    // 出力
    // 上底, 下底, 高さ(,区切りで入力)：2,2,8
    // 面積:33

    return 0;
}
```

上のコードでは、
$(2 + 2) * (8 + 2) / 2 = 20$
を期待しているが、実際の出力結果は 33 となっている。これは、
$(2 + 2) * 8 + 2 / 2 = 33$
のように引数`H`に`h+2`がそのまま置き換えられてしまったため、このような計算結果となってしまっている。
これは以下のようにマクロにカッコを付与することで想定外の計算を防止することはできる。

```C
#define GET_TRAPEZOID_ARE(A, B, H) (((A) + (B)) * (H) / 2)
```

##### まとめ

マクロは副作用があるため、数値計算などではなるべく使用せず定数の定義のみを行うことが望ましい。

#### malloc 関数

stdlib パッケージに含まれている`malloc関数`を使用すると、処理の途中でも配列のサイズを変更することができる。

```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int* heap;
    heap = (int*)malloc(sizeof(int) * 10);
    heap = (int*)realloc(heap, sizeof(int) * 100);
    free(heap);
    return 0;
}
```

- 具体的には`realloc関数`を使用して`malloc関数`にて定義した配列のポインターのサイズを変更するような方法をとる。
- `malloc関数`はメモリ上のアドレスに対してラベルを貼り付けて、領域を確保するようなイメージ
- `malloc関数`で確保した配列は、`free関数`でメモリを解放しなければならない
- `malloc`の使用時にメモリの確保に失敗すると、`NULL`が返却される。
- `malloc`で確保したメモリのことを**ヒープ**と呼ぶことがある、基本的な意味としては長期的に使用される大サイズのメモリ領域のこと
  - このヒープに紐づけられている配列のことを動的配列と呼ぶことがある。

##### メモリリーク

`malloc関数`を使用するとプログラムが終了するまでメモリが解放されないため、`free関数`を使用して明示的にメモリの解放をする必要がある。この解放を忘れると、メモリの空き領域が減少しマシンの性能低下に繋がる。この減少を**メモリリーク**と呼ぶ。
なお、プログラムが終了すると OS が自動的にメモリを解放するため、バッチ処理や処理量が少ないプログラムでは最悪`free関数`を使用しなくても大きな問題にはならない。

※この解放忘れを防止するための仕組みに**ガベージコレクション**と呼び、これが実装されている言語が RUST になる。

##### フラグメンテーション

`realloc関数`を複数回呼び出すと、データの格納アドレスが散らばっていき、動作が不安定になる。この現象を**フラグメンテーション**と呼ぶ。なお、この状態を解消するための対応を**デフラグメンテーション**と呼ぶ。

#### コードの複数ファイルへの分割

チーム開発を行う場合、1 ファイルで開発を行うことは不可能なため、機能単位などでファイル分割を行うことが基本となる。ここでは、ファイルを分割して開発を行っている方法について学習したので、その中でのポイントをまとめる。

##### 同ディレクトリ内のコンパイル

main ファイル内から読み込んでいるヘッダーファイルが同じディレクトリに存在する場合のポイントについてまとめる。

```bash
# ディレクトリ内に存在するファイルを一括でコンパイル
# mainファイルが別ファイルを読み込んでいる場合は以下コマンドで一括でコンパイルできる
$ gcc ./* -o test
$ ls -l ./
total 20
-rw-r--r-- 1 root root   146 Sep  3 13:27 main.c
-rw-r--r-- 1 root root   108 Sep  3 13:28 sum.c
-rw-r--r-- 1 root root    26 Sep  3 13:24 sum.h
```

```C
// main.c
#include "sum.h"
#include <stdio.h>

int main(void)
{
    int value;
    value = sum(50, 100);
    printf("%d\n", value);
    return 0;
}

// sum.h
int sum(int min, int max);

// sum.c
int sum(int min, int max)
{
    int num;
    num = (max - min) * (max - min + 1) / 2;
    return num;
}
```

- main ファイルは`#include "sum.h"`のようにダブルクォーテーションでヘッダーファイルのインクルードを行う
- コンパイル時は上のコードブロックのように、main ファイルからの読み込みファイルをまとめて指定する

##### ディレクトリが異なる場合のコンパイル

こちらの[参考ページ](https://qiita.com/DQNEO/items/4e5c2eca2761ec08b922)が読み込み方を丁寧に解説されていたので、参考になった。  
gcc の場合は、-I オプションを使用することで異なるディレクトリのヘッダーファイルについても読み込める。

#### リンカー

[参考ページ](https://qiita.com/kazatsuyu/items/5c8d9f539cd925fda007)

### 個人的まとめ

#### ポインターの扱い方

```C
...
int main(void)
{
    student data;
...
// 関数側の引数型がstudent
// 関数側に構造体への変換子がくっついているため、構造体のまま渡すと関数の引数型定義と一致しない
// 上を考慮して、アドレスを渡すことでstudentへ戻り引数定義の型と一致するようになる
    student_print(&data);
...
}

// 引数として受け取った時点では、アドレスだが変換子で構造体へ戻されているため、studentで型定義している
void student_print(student *data)
{
...
    return;
}
```

#### 関数への文字列の渡し方

```C
...
int main(void)
{
    person person[raw_num];

// 関数の定義では第四引数はアドレスを指定するようになっている
// 下の第四引数は通常の文字列に見えるが、これは文字列の配列のためC言語ではアドレスとして認識される
    input_person(&person[0],1,0,"Nobita Nobi");
...
}

void input_person(person *person, int num, int score, char *name)
{
    person->num = num;
    person->score = score;
    strcpy(person->name, name);

    return;
}
...
```

- [今回の文字列の渡し方参考例](https://github.com/narupo/blogsnippets/blob/main/c/pointerandfunc/args.c#L4-L5)
- [関数への文字列の渡し方（ポインターの配列使用）](http://www.eonet.ne.jp/~nao2/c/c_0b_char_string.html)
- 悩んだポイント
  - フォーマット指定子%s には文字配列の先頭アドレスを渡す
  - 文字列を関数に渡す際のポイント
    - 引数は`char`型
    - 関数の呼び出し時には、文字配列の先頭アドレスを渡す
    - **[具体的には上記コードブロックを参考にする。一番悩んだポイントとして、関数呼び出し時に指定している文字列は C 言語では配列の先頭アドレスとして認識される](https://github.com/narupo/blogsnippets/blob/main/c/pointerandfunc/args.c#L4-L5)**

## C++
