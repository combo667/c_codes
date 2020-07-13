#include <stdio.h>
void swap(int*,int*);
int main(void){


int a=0,b=0;
printf("Input the value of a :\n");
scanf("%d",&a);
printf("The address of a is =%u\n",&a);
printf("Input the value of b :\n");
scanf("%d",&b);
printf("The address of b is =%u\n",&b);
swap(&a,&b);
printf("The values after swapping are as : \n a=%d\n b=%d\n",a,b);



        return 0;}
void swap(int *x,int *y){
printf("The address of x before swapp is =%d\n",&x);
printf("The value inside x before swapp is=%d\n",*x);
printf("The value inside normal x before swap is =%d\n",x);
printf("The address of y before swapp is =%d\n",&y);
printf("The value inside y before swapp is=%d\n",*y);
printf("The value inside normal y before swap is =%d\n",y);
int temp;
temp=*x;
*x=*y;
*y=temp;
printf("The address of x after swapp is =%d\n",&x);
printf("The value inside x after swapp is=%d\n",*x);
printf("The value inside normal x after swap is =%d\n",x);
printf("The address of y after swapp is =%d\n",&y);
printf("The value inside y after swapp is=%d\n",*y);
printf("The value inside normal y after swap is =%d\n",y);
    }
