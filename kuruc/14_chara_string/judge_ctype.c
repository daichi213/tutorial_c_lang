#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c = 'A';
    int suuti;

    if (isdigit(c)) {
        suuti = c - '0';
    } else {
        suuti = 0;
    }

    printf("%d\n", suuti);
    return 0;
}