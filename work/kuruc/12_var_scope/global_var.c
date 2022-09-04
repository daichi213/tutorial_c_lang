#include <stdio.h>

// グローバル変数
// この宣言時に0に初期化される
int count;

int countfunc(void);

int main(void)
{
    countfunc();
    count = 10;
    countfunc();
    countfunc();
    return 0;
}

int countfunc(void)
{
    count++;
    printf("%d\n",count);
    return count;
}