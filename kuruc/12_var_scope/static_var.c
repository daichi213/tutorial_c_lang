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
    // 静的なローカル変数
    static int count;

    count++;
    printf("%d\n", count);

    return count;
}