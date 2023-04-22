#include<iostream>

using namespace std;

namespace Kitten {
	class Kitten {};
	const char *str = "Kitten on your lap\n";
	void sakura() { cout << "test sakura\n";}
}

int main () {
	Kitten::Kitten obj;
	cout << Kitten::str;
	Kitten::sakura();
	return 0;
}

