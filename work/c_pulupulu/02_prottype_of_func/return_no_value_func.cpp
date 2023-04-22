#include <iostream>
using namespace std;

// TODO 関数の戻り値をint指定している場合で、返却値が何も返されないとエラーとなる
int func();

int main() {
    func();
    return 0;
}

int func() {
    puts("Hello World!");
    return;
}