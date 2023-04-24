#include <iostream>
using namespace std;

// 変数の型をテンプレートとして定義できる
// JSのジェネリクスっぽい
template <typename X>

X max(bool, X var1 , X var2) {
	if (var1 > var2) return var1;
	else return var2;
}

int main() {
	int x=50;
	decltype(x) y=52.1;
	cout << max(x , y) << '\n';
	cout << x+y << '\n';

	return 0;
}