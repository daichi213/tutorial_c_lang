#include <stdio.h>
#include <string.h>

char filename[] = "test.csv";
int raw_num = 4;

typedef struct
{
    int num;
    char name[1024];
    int score;
} person;

void input_person(person *person, int num, int score, char *name);
void write_row_in_file(person *person);

int main(void)
{
    int i;
    person person[raw_num];

    input_person(&person[0],1,0,"Nobita Nobi");
    input_person(&person[1],2,90,"Shizuka Minamoto");
    input_person(&person[2],3,40,"Takeshi Gouda");
    input_person(&person[3],4,7,"Suneo Honekawa");

    for (i = 0; i < raw_num; i++) {
        write_row_in_file(&person[i]);
        // debug
        printf("%i\n",person[i].num);
        printf("%i\n",person[i].score);
        printf("%s\n",person[i].name);
    }
    return 0;
}

void input_person(person *person, int num, int score, char *name)
{
    person->num = num;
    person->score = score;
    strcpy(person->name, name);

    return;
}

void write_row_in_file(person *person)
{
    FILE *file;
    file = fopen(filename, "a");

    // fwriteの場合、文字列は問題なく書き込めるが、int型に関しては文字化けしてしまった
    // fwrite(&person->num,sizeof(&person->num),1,file);
    // fwrite(",",sizeof(","),1,file);
    // fwrite(&person->score,sizeof(&person->score),1,file);
    // fwrite(",",sizeof(","),1,file);
    // fwrite(&person->name,sizeof(&person->name),1,file);
    // fwrite("\n",sizeof("\n"),1,file);
    
    fprintf(file,"%d,%d,%s\n",person->num,person->score,&person->name);
    fclose(file);

    return;
}