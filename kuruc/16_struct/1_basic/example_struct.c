#include <stdio.h>
#include <string.h>

struct student
{
    int year;
    int clas;
    int number;
    char name[64];
    double stature;
    double weight;
};

int main(void)
{
    struct student data;

    data.year = 10;
    strcpy(data.name, "MARIO");
    printf("%d\n", data.year);
    printf("%s\n", data.name);
    return 0;
}