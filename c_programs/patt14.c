
#include <stdio.h>
int main(void){
int i=0,j=0,k=0,rows=0;
printf("Input the number of rows :\n");
scanf("%d",&rows);

for(i=1;i<=rows;++i){
    k=rows-i;
    for(j=1;j<=rows;++j){

        if(j<=(rows+1)-i){
        printf("%d ",k);

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
