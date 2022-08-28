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

#### C言語での配列について

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
- また、ブログの執筆時点ではそれぞれの要素に対して宣言時にメモリが割り当てられているようだが、2022/9時点では配列自体のみに対してアドレスが割り当てられている。

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

- 上のようにコンソールから文字列を配列に格納する処理を行なったところ、入力開始されているindex2からアドレスが割り当てられているところが確認できた
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

- また、配列を関数へ渡す際は配列のアドレスを渡すようになっていることが上のgetaverage関数の宣言方法からわかる
    - 宣言に要素数を含めるor含めないの表現で動作していることから確認できる

#### 構造体

構造体は複数の変数を一まとめにして定義することができる型（機能）で、Goと同じような使い方をする（GoはC言語を踏襲して設計されているよう）。

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

#### リンカー

[参考ページ](https://qiita.com/kazatsuyu/items/5c8d9f539cd925fda007)

### 個人的まとめ

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

## C++
