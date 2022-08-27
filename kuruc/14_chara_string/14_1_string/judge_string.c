#include <stdio.h>

int main(void)
{
    char c = 'A';
    int suuti;

    if (c >= '0' && c <= '9') {
        suuti = c - '0';
    } else {
        suuti = 0;
    }

    printf("%d\n", suuti);
    return 0;
}