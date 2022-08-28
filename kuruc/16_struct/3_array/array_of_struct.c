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

void student_print(student *data);

int main(void)
{
    student data[2];

    data[0].year = 3;
    data[0].clas = 4;
    data[0].number = 18;
    strcpy(data[0].name, "MARIO");
    data[0].stature = 168.2;
    data[0].weight = 72.4;

    data[1].year = 2;
    data[1].clas = 3;
    data[1].number = 17;
    strcpy(data[1].name, "LUIJI");
    data[1].stature = 173.2;
    data[1].weight = 70.4;

    int i, arraySize = sizeof(data)/sizeof(data[0]);

    for (i = 0; i < arraySize; i++){
        student_print(&data[i]);
        printf("\n");
    }

    return 0;
}

void student_print(student *data)
{
    printf("[学年]:%d\n",data->year);
    printf("[クラス]:%d\n",data->clas);
    printf("[出席番号]:%d\n",data->number);
    printf("[名前]:%s\n",data->name);
    printf("[身長]:%lf\n",data->stature);
    printf("[体重]:%lf\n",data->weight);
    return;
}