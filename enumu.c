#include <stdio.h>
enum boolean{

false,true

};


enum boolean isEven(int input){
    if(input%2==0)
        return true;
    else
        return false;


}
int main(void){


int input;
printf("Enter the number :\n");
scanf("%d",&input);
if(isEven(input))
    printf("Number is even!\n");
else
    printf("Number is odd!\n");




    return 0;
}