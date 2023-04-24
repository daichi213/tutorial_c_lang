#include <iostream>
using namespace std;

class Kitty {
    public:
        Kitty(bool , const char *);
};

Kitty::Kitty(bool bo, const char *str) {
    if (bo) cout << str << "\n";
}

int main() {
    Kitty obj[3] = {
        Kitty(true, "Kitty on your lap"),
        Kitty(false, "Kitty on your lap at second"),
        Kitty(true, "Kitty on your lap at third"),
    };
    return 0;
}