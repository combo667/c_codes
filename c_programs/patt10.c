#include <stdio.h>
int main(void){
int i=0,j=0,k=0,rows=0,n;
printf("Input the number of rows : \n");
scanf("%d",&rows);
n=(rows+1)/2;

for(i=1;i<=rows;++i){
    if(rows%2==0){
    if(i<=n)    k++;
    if(i>n+1) --k;
                }
    else
        i<=n?k++:--k;
    for(j=1;j<=rows;++j){

        if(j>=(n+1)-k&&j<=(n-1)+k){
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

