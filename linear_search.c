//LINEAR SEARCH ALGORITHM
#include <stdio.h>
/* #include <stdlib.h> */

int linear_search(int *array, int size, int element)
{
    int flag = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            flag = 1;
            return i+1;
        }
    }

    if (flag == 1)
        return 0;
}

/* //DRIVER FUNCTION
int main(void){

int element;
int *p=malloc(sizeof(int)*5);
for (size_t i = 0; i < 5; i++)
{
    scanf("%d",(p+i));

}
printf("Input the element :\n");
scanf("%d",&element);
int index=linear_search(p,5,element);

printf("%d",index);
free(p);


    return 0;
} */