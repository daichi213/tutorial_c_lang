#include <stdio.h>
#include <string.h>

int main(void)
{
    char strn[] = "DRAGON""QUEST";
    printf("%s\n\n", strn);

    // ただし、char型の配列を結合する場合は、strcat関数を使用する必要がある
    // このstrcat関数は破壊的関数のため注意が必要
    // 非処理配列であるstr1は結合されるstr2を加えられるサイズが必要、もしサイズが足りない場合はバッファオーバーランとなる
    char str1[12] = "DRAGON";
    char str2[] = "QUEST";
    strcat(str1, str2);
    printf("%s\n",str1);
    return 0;
}