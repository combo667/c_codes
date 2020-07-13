#include <stdio.h>
int main(void){
int i=0,j=0;int rows=0;
printf("Input the number of rows :\n");
scanf("%d",&rows);

for(i=1;i<=rows;++i){
    for(j=1;j<=2*rows-1;++j){

        if(j>=i&&j<=(2*rows)-i){
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
