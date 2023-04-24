#include<iostream>
using namespace std;

template <class X> void println(X out) { 
    cout << out << '\n';
}

int main() {
    println("hello");
    println(10);
    println(0.1);
}