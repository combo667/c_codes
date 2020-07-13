#include <stdio.h>
int main(void){
int i=0,j=0,p=0;

for(i=1;i<=5;++i){
++p;
    for(j=1;j<=5;++j){

        if(j<=i){
        printf("%d",p);
        ++p;
        }
        else{
        printf(" ");
        }


    }

    printf("\n");



}



return 0;
}
