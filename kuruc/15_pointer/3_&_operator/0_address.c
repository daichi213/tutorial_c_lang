#include <stdio.h>

int main(void)
{
    char str[256];
    scanf("%s", &str[0]);
    printf("%s\n", str);
    printf("address_str:%p\n", str);
    printf("address_str[0]:%p\n", str[0]);
    printf("address_str[1]:%p\n", str[1]);
    printf("address_str[2]:%p\n", str[2]);
    printf("address_str[3]:%p\n", str[3]);
    printf("address_str[4]:%p\n", str[4]);
    printf("address_str[5]:%p\n", str[5]);
    printf("address_str[6]:%p\n", str[6]);
    printf("address_str[7]:%p\n", str[7]);
    return 0;
}