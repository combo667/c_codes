/*
 Generalised pattern

    * * * * * * * * *
      * * * * * * *
        * * * * *
          * * *
            *


            */


#include <stdio.h>
int main(void){
int i=0,j=0;
int rows=0;
printf("INPUT THE NUMBER OF ROWS : \n");
scanf("%d",&rows);


for(i=1;i<=rows;++i){
    for(j=1;j<=(2*rows)-1;++j){

        if(j>=i&&j<=(rows*2)-i){
        printf(" *");
        }
        else{
        printf("  ");
        }


    }

    printf("\n");



}



return 0;
}

