//source file
#include <stdio.h>
#include "bubblesort.h"
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    
    int *array = (int *)malloc(sizeof(int) * 5);
    printf("Input the elements one by one!\n");
    for (int i = 0; i < 5; ++i)
    {
        scanf("%d", array + i);
    }
    printf("The array looks as:\n");
    for (int i = 0; i < 5; ++i)
        printf("%d  ", *(array + i));
    printf("\n");

    bubblesort(array,5);

    printf("The array looks as:\n");
    for (int i = 0; i < 5; ++i)
        printf("%d  ", *(array + i));
    printf("\n");
    free(array);
    
    return 0;
}
