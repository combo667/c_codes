#include <stdio.h>
#include <string.h>


int main(void){

struct student{

int roll,age;
char name[20];



};

struct student jubesh;
struct student *p;

p=&jubesh;

printf("Input the name : \n");
scanf("%s",&p->name);
fflush(stdin);
printf("Input the student roll :\n");
scanf("%d",&p->roll);
fflush(stdin);
printf("Input the student age :\n");
scanf("%d",&p->age);




printf("The name of the student is :%s\n",p->name);
printf("The age of the student is :%d\n",p->age);
printf("The roll of the student is :%d\n",p->roll);



    return 0;
}