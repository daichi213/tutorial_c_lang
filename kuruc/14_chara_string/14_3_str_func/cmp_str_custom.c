#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, len;
    char str1[256], str2[] = "DRAGONQUEST";

    scanf("%s", str1);

    len = strlen(str1);

    for (i = 0; i < len + 1; i++){
        if (str1[i] != str2[i]) break;
    }

    // for文の最後でiがインクリメントされるので、それを考慮して+1
    if (i == len + 1){
        printf("Same!\n");
    } else {
        printf("Not!\n");
    }

    return 0;
}