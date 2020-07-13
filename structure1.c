#include <stdio.h>
int main(void)
{
    int num = 0, avg = 0;

    struct student
    {1

        int age, roll;
        char name[20];
    };

    printf("Input the number of students :\n");
    scanf("%d", &num);
    struct student s1[num];

    for (int i = 0; i < num; ++i)
    {
        printf("INPUT THE NAME OF THE STUDENT : \n");
        scanf("%s", &s1[i].name);
        printf("INput the age of the student : \n");
        scanf("%d", &s1[i].age);
        printf("Input the roll of the student :\n");
        scanf("%d", &s1[i].roll);
    }
    for (int i = 0; i < num; ++i)
    {
        printf("The age of the student is : %d\n", s1[i].age);
        printf("The name of the student is :%s\n", s1[i].name);
        printf("The roll of the student is :%d\n", s1[i].roll);
    }

    for (int i = 0; i < num; ++i)
        avg += s1[i].age;

    avg /= num;

    printf("THE AVERAGE AGE OF ALL THE STUDENTS  IS : %d\n", avg);

    return 0;
}