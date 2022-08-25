#include <memory.h>
#include <stdio.h>

int main(void)
{
    int array1[] = { 42, 79, 13, 19, 41 };
    int array2[] = {1,2,3,4,5};

    int i;
    int array1_size = sizeof(array1)/sizeof(array1[0]);
    int array2_size = sizeof(array2)/sizeof(array2[0]);

    for(i=0; i<array1_size; i++){
        printf("array1_size[%d]:%d\n",i,array1[i]);
    }
    for(i=0; i<array2_size; i++){
        printf("array2_size[%d]:%d\n",i,array2[i]);
    }

    memcpy(array2,array1,sizeof(array1));
    printf("\n\n\n");

    for(i=0; i<array1_size; i++){
        printf("array1_size[%d]:%d\n",i,array1[i]);
    }
    for(i=0; i<array2_size; i++){
        printf("array2_size[%d]:%d\n",i,array2[i]);
    }
}