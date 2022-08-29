#include <stdio.h>

int main(void)
{
    int i, j;
    FILE *f;
    f = fopen("test.txt", "r");
    fscanf(f, "%d,%d", &i, &j);
    fclose(f);
    printf("i = %d, j = %d\n", i, j);
    return 0;
}