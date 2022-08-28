#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[256];
    int age;
    char sex[10];
} person;

void input_person(person *data);
void display_person(person *data);

int main(void)
{
    int i, number = 3;
    person data[number - 1];

    // 入力
    for (i = 0; i < number; i++) {
        input_person(&data[i]);
        printf("\n");
    }

    // 表示
    for (i = 0; i < number; i++) {
        display_person(&data[i]);
        printf("\n");
    }
}

void input_person(person *data)
{
    printf("Please, Fill down your name:");
    scanf("%s", data->name);
    printf("Done!\n");

    printf("Please, Fill down your age:");
    scanf("%d", &data->age);
    printf("Done!\n");

    printf("Please, Fill down your sex:");
    scanf("%s", data->sex);
    printf("Done!\n");

    return;
}

void display_person(person *data)
{
    printf("Your name is %s\n", data->name);
    printf("Your age is %d\n", data->age);
    printf("Your sex is %s\n", data->sex);
    return;
}