#include <stdio.h>

// グローバル変数
// この宣言時に0に初期化される
int count;

int countfunc(void);

int main(void)
{

    // グローバル変数と同名のローカル変数を宣言
    int count;
    countfunc();
    count = 10;
    countfunc();
    countfunc();
    // 関数内で使用される変数はローカル変数が優先して使用される
    printf("main : count = %d\n", count);
    return 0;
}

int countfunc(void)
{
    count++;
    printf("%d\n",count);
    return count;
}