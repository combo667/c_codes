/*          GENERALISE PATTERN

            A 1
          A B 1 2
        A B C 1 2 3
      A B C D 1 2 3 4
    A B C D E 1 2 3 4 5


    */



#include <stdio.h>
int main(void){
int i=0,j=0,n=0,rows=0;
char k=' ';
printf("INPUT THE NUMBER OF ROWS : \n");
scanf("%d",&rows);


for(i=1;i<=rows;++i){
k='A';n=1;
    for(j=1;j<=(2*rows);++j){

        if(j>=(rows+1)-i&&j<=rows+i){
            if(j<=4){

                printf(" %c",k);
                ++k;
                }
                else{
                    printf(" %d",n);
                    ++n;
                }

        }
        else{
        printf("  ");
        }


    }

    printf("\n");



}



return 0;
}

