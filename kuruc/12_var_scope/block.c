#include <stdio.h>

int main(void)
{
    int value1 = 10;
    int value2 = 20;

    printf("1:value1 %d\n", value1);
    printf("1:value2 %d\n", value2);

    {
        int value1;
        value1 = 30;
        value2 = 40;
        printf("2:value1 %d\n", value1);
        printf("2:value2 %d\n", value2);
    }

    printf("3:value1 %d\n", value1);
    printf("3:value2 %d\n", value2);

    return 0;
}