#include <stdio.h>
#include <limits.h>



void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int Array[], int low, int high)
{
    int pivot = Array[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            ++i;

        } while (Array[i] <= pivot);

        do
        {
            --j;
        } while (Array[j] > pivot);

        if (i < j)
            Swap(&Array[i], &Array[j]);
    }

    Swap(&Array[low],&Array[j]);

    return j;
}

void QuickSort(int Array[], int low, int high)
{

    int j = 0;
    if(low<high){
    j = Partition(Array, low, high);
    QuickSort(Array, low, j);
    QuickSort(Array, j + 1, high);
    }
    
}

void PrintArray(int Array[],int size){
    printf("The Sorted List is :\n");
    size-=1;
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ",Array[i]);
    }

    printf("\n");
    
}

int main(int argc, char const *argv[])
{
    int Array[]={72,1,22,99,352,70,33,99,54,45,11,INT_MAX};
    int size=sizeof(Array)/sizeof(Array[0]);

    QuickSort(Array,0,size-1);
    PrintArray(Array,size);

    return 0;
}
