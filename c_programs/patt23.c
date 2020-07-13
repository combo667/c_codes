#include <stdio.h>
int main(void){
int i=0,j=0,k=0,rows=0;
printf("INPUT THE NUMBER OF ROWS : \n");
scanf("%d",&rows);
printf("\n\n");

for(i=1;i<=rows;++i){
k=1;
    for(j=1;j<=rows;++j){

        if(j<=i){
        printf(" %d",k);
        j%2==0?++k:--k;
        }
        else{
        printf("  ");
        }


    }

    printf("\n");



}



return 0;
}

