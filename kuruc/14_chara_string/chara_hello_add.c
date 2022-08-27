#include <stdio.h>

int main(void)
{
    char c = 'A';
    char c1 = 'A' + 10;
    char c2 = '8';
    // 数値へ変換
    int suuti = c2 - '0';
    printf("%c\n",c);
    printf("%c\n",c1);
    printf("%d\n",suuti);
    return 0;
}