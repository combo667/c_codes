#include <stdio.h>
void swap(int *,int *);
int main(void){

int a=45,b=90;

swap(&a,&b);




return 0;}

void swap(int *c,int *d){

printf("The value of a is : %d\n",*d);

printf("The value of b is : %d",*c);
}
