#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void bubble_sort(int[], int);
void Swap(int *, int *);

void bubble_sort(int *Array, int size)
{

    bool flag = true;

    for (int i = 0; i < size - 1; ++i)
    {
        flag = true;
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (Array[j] > Array[j + 1])
            {
                Swap(&Array[j], &Array[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
            break;
    }
}

void Swap(int *x, int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char const *argv[])
{

    int size = 0;
    printf("Input the number of elements you wanna Input!\n");
    scanf("%d", &size);

    int *Array = (int *)malloc(sizeof(int) * size);
    printf("Input the ELements one by one :\n");

    for (int i = 0; i < size; ++i)
        scanf("%d", Array + i);

    bubble_sort(Array, size);

    printf("The sorted list is :\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", Array[i]);
    }
    printf("\n");

    return 0;
}
