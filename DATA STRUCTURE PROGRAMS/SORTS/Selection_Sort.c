#include <stdio.h>
void Selection_sort(int[], int);
void Swap(int*, int*);

void Selection_sort(int Array[], int size)
{
    int i, j, k;
    for (i = 0; i < size; ++i)
    {
        for (j = k = i; j < size; ++j)
        {
            if (Array[j] < Array[k])
                k = j;
        }

        Swap(&Array[i], &Array[k]);
    }
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char const *argv[])
{
    int Array[] = {90, 80, 30, 22, 12, 1, 227};
    int size = sizeof(Array) / sizeof(Array[0]);
    Selection_sort(Array, size);
    printf("The sorted List is :\n");

    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", Array[i]);
    }

    printf("\n");

    return 0;
}
