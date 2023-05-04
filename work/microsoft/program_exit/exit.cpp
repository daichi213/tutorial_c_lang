#include<stdlib.h>
#include<iostream>
using namespace std;

struct S
{
    int value;
};

int main(int argc, char *argv[])
{
    // 第一引数に数字が渡される前提（エラーハンドリングなし）
    int arg_num = atoi(argv[1]);
    S s{ arg_num };

    cout << "arg_num: " << arg_num << endl;

    exit(arg_num);

    // return arg_num;
}