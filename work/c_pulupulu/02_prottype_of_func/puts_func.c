#include <stdio.h>

// TODO 関数の戻り値をint指定している場合で、返却値が何も返されないとworningとなる
int func(void);

int main() {
    func();
    return 0;
}

int func(void) {
    puts("Hello World!");
    return;
}