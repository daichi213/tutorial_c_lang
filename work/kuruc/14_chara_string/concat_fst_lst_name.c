#include <stdio.h>
#include <string.h>

int main(void)
{
    char firstName[256], lastName[256], fullName[512];

    printf("Input your first name;");
    scanf("%256s", firstName);

    printf("Input your last name;");
    scanf("%256s", lastName);

    strcpy(fullName, firstName);
    strcat(fullName, lastName);

    printf("%s\n",fullName);

    return 0;
}