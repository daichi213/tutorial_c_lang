# 複数ファイルにまたがるコードの記載について

## 外部リンケージと内部リンケージ

- [リンケージの解説](http://www7b.biglobe.ne.jp/~robe/cpphtml/html01/cpp01069.html)

### 外部リンケージ

[詳細](http://www7b.biglobe.ne.jp/~robe/cpphtml/html01/cpp01069.html#:~:text=%E3%81%AB%E3%81%AA%E3%82%8A%E3%81%BE%E3%81%99%E3%80%82-,%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%A0,-//%20Extern1.cpp%0A%23include)

```cpp
// Extern1.cpp
#include <iostream.h>

int a = 2;   // 実体

void Func()  // 実体
{
    cout << "a = " << a << endl;
}
```

```cpp
// Extern2.cpp
#include <iostream.h>

void Func();

int main()
{
    extern int a;

    Func();
    a = 5;
    Func();

    return 0;
}

// 実行結果
// a = 2
// a = 5
```

### 内部リンケージ

```cpp
// Intern1.cpp
#include <iostream.h>

static int a = 2;

static void Func1()
{
    cout << "a(1) = " << a << endl;
}

void Func2()
{
    Func1();
}
```

- Func1は内部リンケージのため、外部ファイルから呼び出すことができない
- Func2の外部リンケージを経由して、外部ファイルから呼び出すことができる

```cpp
// Intern2.cpp
#include <iostream.h>

static int a = 9;

void Func1()
{
    cout << "a(2) = " << a << endl;
}

void Func2();

int main()
{
    Func1();
    Func2();
    a = 5;
    Func1();
    Func2();

    return 0;
}

// 実行結果
// a(2) = 9
// a(1) = 2
// a(2) = 5
// a(1) = 2
```
- Func1：同じファイル内の関数・変数
- Func2：**別**ファイル内の関数・変数
- 内部リンケージの動作について
    - `a=5`で変数`a`に値を代入している
        - Func1：同じ内部リンケージ`a`の値が更新される
        - Func2：この関数が参照している内部リンケージの変数`a`は別ファイルで定義されているもの。そのため、**そちらの内部リンケージが優先される**
