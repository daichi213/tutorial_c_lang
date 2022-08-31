#include <stdio.h>

int main(void)
{
    FILE *file;
    file = fopen("test.dat", "wb");
    fclose(file);
    return 0;
}