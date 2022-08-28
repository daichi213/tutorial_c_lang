#include <stdio.h>
#include <string.h>

typedef struct
{
    int year;
    int clas;
    int number;
    char name[64];
    double stature;
    double weight;
} student;

int main(void)
{
    student data;
    student *pdata;

    pdata = &data;
    (*pdata).year = 10;
    strcpy((*pdata).name, "MARIO");

    printf("data.year:%d\n", data.year);
    printf("data.year:%s\n", data.name);

    return 0;
}