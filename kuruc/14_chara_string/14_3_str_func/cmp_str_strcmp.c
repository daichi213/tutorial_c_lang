#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, len;
    char str1[256], str2[] = "DRAGONQUEST";

    scanf("%s", str1);

    if (strcmp(str1, str2) == 0){
        printf("Same!\n");
    } else {
        printf("Not!\n");
    }

    return 0;
}