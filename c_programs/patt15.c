#include <stdio.h>
int main(void){
int i=0,j=0,k=0,p=0;

for(i=1;i<=9;++i){
        p=1;
    i<=5?++k:--k;
    for(j=1;j<=5;++j){

        if(j>=6-k){
        printf("%d",p);
        ++p;
        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}

