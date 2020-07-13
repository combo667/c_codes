#include <stdio.h>

void palindrome(int);

int main(void){
    int num=0;
printf("Input the number :\n");
scanf("%d",&num);
palindrome(num);



    return 0;
}

void palindrome(int num){
int check=num;
int mod=0,sum=0;
while(num>0){

    mod=num%10;
    sum=sum*10+mod;
    num/=10;}

    if(sum==check){
        printf("The number %d is a palindrome number !\n",check);
    }
    else{
        printf("The number %d is not a palindrome number !\n",check);
    }


}