/* ACCESSING 2D ARRAY USING POINTERS  */
#include <stdio.h>
#include <stdlib.h>

int main(void){

int arr[3][4];
int *ptr=&arr[0][0];
ptr=arr;
for (size_t i = 0; i < 3; i++)
{
    for (int j = 0; j < 4; j++)
    {
        scanf("%d",((ptr+i)+j));
        
    }
    
}
printf("The array values are :\n");
for (size_t i = 0; i < 3; i++)
{
    for (size_t j= 0; j < 4; j++)
    {
        printf("%d  ",arr[i][j]);

    }
    printf("\n");
    
}



    return 0;
}