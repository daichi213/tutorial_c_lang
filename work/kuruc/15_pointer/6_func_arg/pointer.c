#include <stdio.h>

void func(int* pvalue);

int main(void)
{
    int value = 10;
    printf("&value = %p\n", &value);
    func(&value);
    printf("value = %d\n", value);
    return 0;
}

void func(int* pvalue)
{
    printf("pvalue = %p\n", pvalue);
    *pvalue = 100;
    return;
}