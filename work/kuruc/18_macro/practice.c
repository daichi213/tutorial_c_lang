#include<stdio.h>

enum {
    OLYMPIC_HAS,
    OLYMPIC_NOT,
};

int has_olympic_year(int year);

int main(void)
{
    int year, olympic_flag;

    printf("Please, Input Year by A.D.:");
    scanf("%d",&year);

    olympic_flag = has_olympic_year(year);

    if (olympic_flag == OLYMPIC_HAS) {
        printf("Olympic has in %d\n", year);
    } else {
        printf("Olympic has not in %d\n", year);
    }

    return 0;
}

int has_olympic_year(int year)
{
    if (year % 4 == 0) {
        return OLYMPIC_HAS;
    } else {
        return OLYMPIC_NOT;
    }
}