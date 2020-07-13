
#include <stdio.h>
int main(void){
int i=0,j=0,rows=0;
printf("Input the number of rows : \n");
scanf("%d",&rows);

for(i=1;i<=rows;++i){
    for(j=1;j<=rows;++j){

        if(j==i||j==(rows+1)-i){
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
