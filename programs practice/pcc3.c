#include <stdio.h>
#include <stdlib.h>

int *exchange(int *, int);
int *exchange_inrev(int *, int);

int main(void)
{
    int size = 0;
    int *p, *q;
    printf("Input the size of the array :\n");
    scanf("%d", &size);

    p = (int *)malloc(sizeof(int) * size);

    printf("Input the elements :\n");

    for (size_t i = 0; i < size; i++)
    {
        scanf("%d", p + i);
    }
    printf("The inputted array values are as :\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", *(p + i));
    }
    printf("\n");

    q = p;

    p = exchange_inrev(q, size);

    printf("The exchanged array values are as :\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", *(p+size-1-i));
    }
    printf("\n");
    free(q);
    q = NULL;

    free(p);

    return 0;
}

int *exchange(int *array, int size)
{

    int *x = (int *)malloc(sizeof(int) * size);
    for (size_t i = 0; i < size; i++)
    {
        *(x + i) = *(array + i);
    }

    return x;
}

int *exchange_inrev(int *array, int size)
{
    int *x = realloc(array, size);
   
    
    return x;
}