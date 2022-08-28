#include <stdio.h>

void getMinMaxFunction(double array[], int arraySize, double* min, double* max);

int main(void)
{
    int i, n = 10, arraySize;
    double num[n], min, max;

    printf("Please, Input Number 0~100\n");
    for (i = 0;i < n;i++){
        printf("%dth number...", i);
        scanf("%lf", &num[i]);
        arraySize = i + 1;
        if (num[i] == -1) break;
    }

    // C言語では返却値を複数返せないため、ポインタを使用して値をmainへ渡した
    getMinMaxFunction(num, arraySize, &min, &max);
    printf("Max Number is %lf\n", max);
    printf("Min Number is %lf\n", min);

    return 0;
}

void getMinMaxFunction(double array[], int arraySize, double* min, double* max)
{
    int i = 1;
    *min = array[0];
    *max = array[0];

    for (i = 0; i < arraySize; i++) {
        if (*min > array[i] && array[i] != -1) *min = array[i];
        if (*max < array[i]) *max = array[i];
    }
}