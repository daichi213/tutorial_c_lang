# include <stdio.h>

int main(void)
{
    char str[16];
    char str1[12] = "DRAGON";
    char str2[] = "QUEST";
    int i = 3;
    sprintf(str, "%s%s%d\n", str1, str2, i);
    // 文字列のフォーマット指定子%sは使用しなくても出力できる
    // 理由はprintfは元々文字列を表示させるための関数だから
    printf(str);
    return 0;
}