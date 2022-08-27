#include <stdio.h>

int main(void)
{
    char str[32];
    // このようにすることで入力文字を32文字に制限することができる
    // そのため、バッファオーバーランを防止することができる
    scanf("%32s", str);
    printf("%s\n", str);
    return 0;
}