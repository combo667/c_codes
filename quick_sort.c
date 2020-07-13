#include <stdio.h>
#include <stdlib.h>

void display(int[]);
void swap(int *, int, int);
int partition(int *, int, int);
void quick_sort(int *, int, int);

int num = 0;
//driver function
int main(void)
{

    printf("Input the size of the array :\n");
    scanf("%d", &num);
    int *Array;
    Array = (int *)malloc(sizeof(int) * num);
    printf("Input the elements :\n");
    for (size_t i = 0; i < num; i++)
    {
        scanf("%d", (Array + i));
    }

    quick_sort(Array, 0, num - 1);
    display(Array);
    free(Array);
    return 0;
}
//array display function
void display(int *A)
{
    extern int num;
    for (size_t i = 0; i < num; i++)
    {
        printf("%d  ", *(A + i));
    }
    printf("\n");
}
//SWAP FUNCTION
void swap(int *p, int a, int b)
{
    int temp = 0;
    temp = *(p + a);
    *(p + a) = *(p + b);
    *(p + b) = temp;
}

//PARTITION ALGORITHM
int partition(int *a, int l, int h)
{
    int low = l + 1, high = h;
    int pivot = *(a + l);

    while (low <= high)
    {
        while (*(a + low) < pivot)
        {
            ++low;
        }

        while (*(a + high) > pivot)
        {
            --high;
        }
        if (low < high)
        {
            swap(a, low, high);
        }
    }
    swap(a, l, high);
    return high;
}
//QUICKSORT FUNCTION
void quick_sort(int *A, int low, int high)
{
    if (low < high)
    {
        int partition_point = 0;

        partition_point = partition(A, low, high);

        quick_sort(A, low, partition_point - 1);
        quick_sort(A, partition_point + 1, high);
    }
}






