#include <iostream>
using namespace std;

class Kitty {
    public:
        Kitty() {
            cout << "Kitty on test" << endl;
        };
};

// Kitty::Kitty() {
//     cout << "Kitty on your lap\n";
// }

int main() {
    Kitty obj;
    return 0;
}