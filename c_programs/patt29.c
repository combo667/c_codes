/*  GENERALISED PATTERN



                    A
                   CB
                  FED
                 JIHG
                ONMLK


                */


#include <stdio.h>
int main(void){
int i=0,j=0,rows=0;
char k=64,p=' ';
printf("Input the number of rows : \n");
scanf("%d",&rows);
for(i=1;i<=rows;++i){
k+=i;p=k;
    for(j=1;j<=rows;++j){

        if(j>=(rows+1)-i){
        printf("%c",p);
        --p;
        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}

