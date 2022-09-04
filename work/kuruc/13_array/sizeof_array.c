#include <stdio.h>

int main(void)
{
    int array[] = {0,1,2,3,4};
    int i;
    int array_count = sizeof(array)/sizeof(array[0]);

    for (i = 0; i < array_count; i++){
        printf("a[%d] = %d\n", i, array[i]);
    }

    printf("sizeof(array):%d, sizeof(array[0]):%d\n", sizeof(array), sizeof(array[0]));

    return 0;
}