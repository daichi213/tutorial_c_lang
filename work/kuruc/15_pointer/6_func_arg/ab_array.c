#include <stdio.h>

int getaverage(int data[10]);
// 以下宣言でも上宣言と同じ挙動のため、配列は先頭アドレスを渡していることがわかる
// int getaverage(int *data);

int main(void)
{
    int average, array[10] = { 15, 78, 98, 15, 98 };
    average = getaverage(array);
    printf("average: %d\n", average);
    printf("array[3]: %d\n", array[3]);
    return 0;
}

int getaverage(int data[10])
{
    int i, average = 0;
    for (i = 0; i < 10; i++) {
        average += data[i];
    }
    data[3] = 1000;
    return average / 10;
}