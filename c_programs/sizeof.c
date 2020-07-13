#include <stdio.h>
int main(void){

int x=0,y=0,z=0;
x=sizeof(long  double);
y=sizeof(23.6d);
z=sizeof(); //ASCII for 'a' is 97 which is an integer,and sizeof(int)=4 so z=4
printf(" %d \n %d \n %d\n",x,y,z);



        return 0;}
