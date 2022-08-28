#include <stdio.h>

int sum(int, int);

int main(void)
{
    int value;
    value = sum(50, 100);
    printf("value: %d\n", value);
    return 0;
}

int sum(int min, int max)
{
    int num;
    num = (min + max) * (max - min + 1) / 2;
    return num;
}