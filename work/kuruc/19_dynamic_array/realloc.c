#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int* heap;
    heap = (int*)malloc(sizeof(int) * 10);
    heap = (int*)realloc(heap, sizeof(int) * 100);
    free(heap);
    return 0;
}