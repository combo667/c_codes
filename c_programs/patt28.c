#include <stdio.h>
int main(void){
int i=0,j=0;
int k=0,p=0;

for(i=1;i<=5;++i){
    if(i%2==1)
        k+=1;
    else
        k+=i;
    p=k;
    for(j=1;j<=9;++j){


        if(j<=(2*i)-1){

            if(j%2==0)
                printf("*");
            else
                printf("%d",p);




        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}

