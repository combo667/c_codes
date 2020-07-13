#include <stdio.h>
int main(void){
int i=0,j=0,n=0;
char k=' ';int rows=0;
printf("INPUT THE NUMBER OF ROWS :\n");
scanf("%d",&rows);


for(i=1;i<=rows;++i){
k='A';n=1;
    for(j=1;j<=(2*rows)-1;++j){

        if(j>=(rows+1)-i&&j<=(rows-1)+i){

            if(j<=rows){
            printf("%d",n);
            ++n;
            }

            else{
                printf("%c",k);
                ++k;
                }





        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}

