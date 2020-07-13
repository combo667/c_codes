#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *p,int size){

int temp=0;
for (size_t i = 0; i < size; i++)
{
    for (size_t j = 0; j < size-1; j++)
    {
        if(p[j]>p[j+1]){
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
        }
    }
    
}


}

//DRIVER FUNCTION
/* int main(void){

int  *a=NULL;
a=(int*)malloc(sizeof(int)*5);
for (size_t i = 0; i < 5; i++)
{
    scanf("%d",(a+i));
}

bubble_sort(a,5);
for (size_t j = 0; j < 5; j++)
{
    printf("%d\n",*(a+j));
}

free(a);
    return 0;
} */