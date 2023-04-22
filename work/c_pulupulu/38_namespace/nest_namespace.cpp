#include<iostream>

using namespace std;

namespace Kitten {
	namespace Kitty {
		const char *str = "Kitty on your lap at nest namespace\n";
	}
	void print() { cout << Kitten::Kitty::str;}
}

int main() {
	Kitten::print();
}

