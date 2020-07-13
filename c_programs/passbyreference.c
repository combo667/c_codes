#include <stdio.h>
void passbyref(int &c,int &d);
int main(void){

int a=45,b=90;
passbyref(a,b);



return 0;}

void passbyref(int &c,int &d){
printf("The value of a is : %d\n",c);
printf("The value of b is : %d",d);


}
