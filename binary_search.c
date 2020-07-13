//BINARY SEARCH ALGORITHM
int binary_search(int *a, int size, int element)
{
    int LOW = 0, HIGH = size;
    int flag = 0;
    int MID = (LOW + HIGH) / 2;
    while (LOW != HIGH)
    {

        if (a[MID] == element)
        {
            flag = 1;
            break;
            return MID + 1;
        }
        else if (a[MID] < element)
        {

            LOW = MID + 1;
            MID = (LOW + HIGH) / 2;
        }
        else if (a[MID] > element)
        {
            HIGH = MID - 1;
            MID = (LOW + HIGH) / 2;
        }
    }

    if (flag == 0)
    {
        return 0;
    }
}


/* //LIBRARES AND HEADERS INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.c"
//FUNCTION DECLARATIONS
void output(int *, int);
int binary_search(int *, int, int);
void input(int, int *); */

//DRIVER FUNCTION
/* int main(void)
{

    int *p = NULL;
    int size;
    int element;
    int index;
    printf("Input the number of elements you want to input :\n");
    scanf("%d", &size);

    p = (int *)malloc(sizeof(int) * size);

    if (!p == NULL)
    {
        printf("MEMORY ALLOCATED!\n");
        input(size, p);
        bubble_sort(p, size);
        printf("Your sorted array is as :\n");
        output(p, size);
        printf("\n");
        printf("Input the element to be searched for :\n");
        scanf("%d", &element);
        index = binary_search(p, size, element);
        if (index)
            printf("The element is found at '%d' position !\n", index);
        else
            printf("The searched element is not found !\n");

        free(p);
    }
    else
    {
        printf("MEMORY ALLOCATION FAILED!\n");
        exit(0);
    }

    return 0;
} */
//THIS FUNCTION TAKED THE INPUT IN THE ARRAY  
/* void input(int x, int *p)
{

    printf("Input the elements in the array :\n");
    for (size_t i = 0; i < x; i++)
    {
        scanf("%d", (p + i));
    }
}
//THIS FUNCTION DISPLAYS ALL THE ELEMENTS IN THE ARRAY
void output(int *p, int size)
{

    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", *(p + i));
    }
} */