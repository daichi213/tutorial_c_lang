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

void student_print(student data);

int main(void)
{
    // typedefのお陰でintなどと同じように型としてコンパイラーに認識される
    student data;

    data.year = 3;
    data.clas = 4;
    data.number = 18;
    strcpy(data.name, "MARIO");
    data.stature = 168.2;
    data.weight = 72.4;

    student_print(data);

    return 0;
}

void student_print(student data)
{
    printf("[学年]:%d\n",data.year);
    printf("[クラス]:%d\n",data.clas);
    printf("[出席番号]:%d\n",data.number);
    printf("[名前]:%s\n",data.name);
    printf("[身長]:%lf\n",data.stature);
    printf("[体重]:%lf\n",data.weight);
    return;
}