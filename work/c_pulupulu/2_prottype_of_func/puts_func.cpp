#include <iostream>
using namespace std;

//TODO C++では引数に何も受け取らない場合はvoidを指定しなくてもよい
void func();

void func() {
    puts("Hello World!");
    return;
}

int main() {
    func();
    return 0;
}