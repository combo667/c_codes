#include <stdio.h>
int main(void){
int i=0,j=0,k=0;

for(i=1;i<=9;++i){
        i<6?++k:--k;
    for(j=1;j<=9;++j){

        if(j<=6-k||j>=4+k){
        printf("*");

        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}
