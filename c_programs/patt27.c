#include <stdio.h>
int main(void){
int i=0,j=0,k=0,rows=0;
printf("Input the number of rows : \n");
scanf("%d",&rows);

for(i=1;i<=rows;++i){
k=i;
    for(j=1;j<=(2*rows)-1;++j){

        if(j>=(rows+1)-i&&j<=(rows-1)+i){
        printf("%d",k);
        j<4?--k:++k;
        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}

