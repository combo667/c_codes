#include <stdio.h>
int main(void){
int i=0,j=0,k=0;

for(i=1;i<=4;++i){
k=1;
    for(j=1;j<=7;++j){

        if(j>=5-i&&j<=3+i){

        printf("%d",k);
        j<4?++k:--k;

        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}

