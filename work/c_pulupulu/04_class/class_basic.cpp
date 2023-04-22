#include <iostream>
using namespace std;

class Kitty {
    public:
        char *str;
        // char* str;
} obj;

int main() {
    obj.str = "Kitty on your lap";
    cout << obj.str << "\n";

    return 0;
}