#include <stdio.h>
int main(void){
    int num=0,mod=0,div=0,bits=0;
    printf("Input the decimal number :\n");
    scanf("%d",&num);
    printf("Input the number of bits :\n");
    scanf("%d",&bits);
    int arr[bits];
    for (size_t i = 0; i < bits; i++)
    {
        div=num/2;
        mod=num%2;
        arr[bits-1-i]=mod;
        num=div;
    }
    
    for (size_t i = 0; i < bits  ; i++)
    {
        printf("%d  ",arr[i]);
    }
    





    return 0;
}