#include <stdio.h>

int countfunc(void);

int main(void)
{
    int count = 100;
    countfunc();
    countfunc();
    countfunc();
    return 0;
}

int countfunc(void)
{
    int count; /* 初期化なし(本当はやってはいけない) */
    count++;
    printf("%d\n", count);
    return count;
}