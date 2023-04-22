#include <iostream>
using namespace std;

int main() {
    bool b1 = true , b2 = false , b3 = 0;
    // TODO bool型でもインクリメントでき、こうするとtrueとして認識される
    // TODO しかし、デクリメントは動作保障されない
    if (b1 && (b2 || ++b3)) cout << "Hello World!" << "\n";
    return 0;
}