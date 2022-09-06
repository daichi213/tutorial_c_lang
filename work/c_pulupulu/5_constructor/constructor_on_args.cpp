#include <iostream>
using namespace std;

class Kitty {
    public:
        char *str;
        Kitty(char *);
};

Kitty::Kitty(char *ch) {
    str = ch;
}

int main() {
    Kitty obj("Kitty on your lap");
    cout << obj.str << "\n";
    return 0;
}