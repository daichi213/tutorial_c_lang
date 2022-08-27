#include <stdio.h>

int main(void)
{
    int i;

    char str[256];
    scanf("%s", str);

    for (i = 0; i < str[i] != '\0'; i++);

    printf("%d\n", i);
    return 0;
}