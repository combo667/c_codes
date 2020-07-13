
#include <stdio.h>
int main(void){
int i=0,j=0;
char k=64;int rows=0;
printf("Input the number of rows : \n");
scanf("%d",&rows);

for(i=1;i<=rows;++i){
    k+=i;
    for(j=1;j<=rows;++j){

        if(j<=i){
        printf("%c",k);
        --k;
        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}
