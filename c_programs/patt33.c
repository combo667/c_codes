

#include <stdio.h>
int main(void){
int i=0,j=0,rows=0;
char k=' ';
printf("Input the number of rows : \n");
scanf("%d",&rows);

for(i=1;i<=rows;++i){
k=65;
    for(j=1;j<=(2*rows)-1;++j){

        if(j<=(rows+1)-i||j>=(rows-1)+i){
        printf("%c",k);
        ++k;
        }
        else{
        printf(" ");
        ++k;
        }


    }

    printf("\n");



}



return 0;
}
