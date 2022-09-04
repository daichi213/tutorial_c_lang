#include <iostream>

// TODO Cの場合は以下のように定義していた
// typedef struct S_TAG {
//     int i;
// } S_TAG;
// C++の場合はTAG名を省略することができる

// TODO UNION型、ENUM型について調べる

struct S_TAG {
    int i;
};

union U_TAG {
    int i;
    double d;
};

enum E_TAG {A,B,C};

int main() {
    S_TAG s_obj;
    U_TAG u_obj;
    E_TAG e_obj;
    return 0;
}