# template関数

## ambiguousエラー

```cpp
#include <iostream>
using namespace std;

template <typename X>

X max(X var1 , X var2) {
	if (var1 > var2) return var1;
	else return var2;
}

int main() {
	cout << max(10 , 100);

	return 0;
}
```

```bash
$ g++ another_template_func.cpp
another_template_func.cpp: In function ‘int main()’:
another_template_func.cpp:12:20: error: call of overloaded ‘max(int, int)’ is ambiguous
   12 |       cout << max(10 , 100); 
      |               ~~~^~~~~~~~~~  

```

## decltype

計算を行う際に、変数同士の型を合わせるのに非常に便利な関数。
簡単な例では、整数型と実数型の計算を行う際、簡単に型を合わせることができるため非常に便利。
[参考ページ](https://ez-net.jp/article/0F/0gm--rZJ/DpE165MFpLIa/#:~:text=decltype%20%E3%81%AE%E4%BD%BF%E3%81%84%E6%96%B9,int%20%E5%9E%8B%E3%81%AB%E3%81%AA%E3%82%8A%E3%81%BE%E3%81%99%E3%80%82)

```cpp
	double x=50.5;
	decltype(x) y=52;
	cout << x+y << '\n';
```

## SFINAE

[テンプレート関数を調べる中で見つけた記事](https://izadori.net/cpp-templ-sfinae/)  
[c++の言語使用が解説されているページ](https://cpprefjp.github.io/lang.html)