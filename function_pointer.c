#include <stdio.h>
int function(int*,int*);
/* driver function */
int main(void){
int a=10,b=20;
//declaring function pointer p
int (*p)(int*,int*);
//initializing function pointer p
p=function;
printf("%d ",p(&a,&b));


    return 0;
}

//function
int function(int *a,int *b){
    int c=*a+*b;
    printf("%d ",c);
    return  (c+1);
}