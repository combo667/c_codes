#include <stdio.h>
int main(void){
int i=0,j=0,rows=0;char k=' ';
printf("INPUT THE NUMBER OF ROWS : \n");
scanf("%d",&rows);

for(i=1;i<=rows;++i){
k='A';
    for(j=1;j<=(2*rows)-1;++j){

        if(j>=(rows+1)-i&&j<=(rows-1)+i){
        printf("%c",k);
        j<rows?++k:--k;
        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}

