#include <iostream>
using namespace std;

int main() {
    // TODO C++ではfor文で変数定義することができる。このように宣言するとブロック内のみがスコープとなる。
    for (int i = 0; i < 10; i++)
        puts("Hello World!");
    return 0;
}