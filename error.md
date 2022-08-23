# 遭遇エラー

## 依存オブジェクトの指定漏れ

math ライブラリを使用した際のコンパイルエラーについて記載する。具体的に、math ライブラリ内の pow 関数、sqrt 関数が見つからいと怒られた。

```sh
root@b477e5562391:/usr/local/src/kuruc/11_custom_func# gcc void_custom_func.c -o test
/usr/bin/ld: /tmp/ccmBqddl.o: in function `quadratic_eq':void_custom_func.c:(.text+0x6b): undefined reference to `pow'
/usr/bin/ld: void_custom_func.c:(.text+0x9e): undefined reference to `sqrt'
/usr/bin/ld: void_custom_func.c:(.text+0xfd): undefined reference to `pow'
/usr/bin/ld: void_custom_func.c:(.text+0x130): undefined
reference to `sqrt'
collect2: error: ld returned 1 exit status
```

```c
#include <stdio.h>
#include <math.h>

void quadratic_eq(double a, double b, double c);

int main(void)
{
    quadratic_eq(1,-4,4);
}

void quadratic_eq(double a, double b, double c)
{
    double num = 2;
    printf("%5.3f\n", (-b + sqrt(pow(b, num) - 4*a*c)) / num / a);
    printf("%5.3f\n", (-b - sqrt(pow(b, num) - 4*a*c)) / num / a);
}
```

### 解決

[math ライブラリを使用する際はコンパイル時にその旨を指定する必要がある](https://qiita.com/percipere/items/678a8ec1299a7564f6a3)。

```bash
$ gcc void_custom_func.c -o test -lm
```

[依存オブジェクト関連参考ページ](https://qiita.com/kazatsuyu/items/5c8d9f539cd925fda007)
