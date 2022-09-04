#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int* heap;
    heap = (int*)malloc(sizeof(int) * 10);
    if (heap == NULL) exit(0);

    for (i = 0; i < 10; i++) {
        heap[i] = i;
    }

    printf("%d\n", heap[5]);

    free(heap);

    return 0;
}