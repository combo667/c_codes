#include <stdio.h>
int main(void){

struct hello{

    int *a;

};

struct hello h1;
struct hello *p;
p=&h1;

int d=20;

p->a=&d;
printf("The address of d is :%u \n",&d);
printf("The address of p is :%u\n",p->a);
printf("The value of p is : %d\n",*(p->a));
    
}