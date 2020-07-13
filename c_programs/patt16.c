#include <stdio.h>
int main(void){
int i=0,j=0;

for(i=1;i<=7;++i){

    for(j=1;j<=7;++j){

        if(j==i||j==8-i){
            printf(" ");
            if(i==j&&j!=4)
                printf("\\");
            else
                printf("/");
        }
        else{
        printf("*");

        }


    }

    printf("\n");



}



return 0;
}

