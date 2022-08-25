#include <stdio.h>

int countfunc(void);

int main(void)
{
    countfunc();
    countfunc();
    countfunc();
    return 0;
}

int countfunc(void)
{
    // ブログでは、静的なローカル変数とは異なるようだったが、新しいコンパイラーでは？staticを宣言しなくても静的なローカル変数となるよう
    int count;

    count++;
    printf("%d\n", count);

    return count;
}