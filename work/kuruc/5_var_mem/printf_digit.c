#include <stdio.h>

int main(void) {
    int a = 1000, b = 500, c = 3;
    double pi = 3.141592654;

    printf("Aは %d です。\n", a);
    printf("Bは %d です。\n", b);
    printf("Cは %d です。\n", c);

    printf("Aは %5d です。\n", a);
    printf("Bは %5d です。\n", b);
    printf("Cは %5d です。\n", c);

    printf("Aは %05d です。\n", a);
    printf("Bは %05d です。\n", b);
    printf("Cは %05d です。\n", c);

    printf("%6.2f\n", pi);
    printf("%7.3f\n", pi);
    printf("123456789\n");

    return 0;
}