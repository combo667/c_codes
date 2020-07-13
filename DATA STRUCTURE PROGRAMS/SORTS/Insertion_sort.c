#include <stdio.h>


void insertion_sort(int[],int);


int main(int argc, char const *argv[])
{
    int Array[] = {70, 50, 30, 20, 10};
    int size = sizeof(Array) / sizeof(Array[0]);
    insertion_sort(Array, size);

    printf("The sorted Array List is :\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", Array[i]);
    }
    printf("\n");

    return 0;
}

void insertion_sort(int Array[], int size)
{
    int j = 0;
    int temp = 0;
    for (int i = 1; i < size; ++i)
    {
        j = i - 1;
        temp = Array[i];
        while (j >= 0 && Array[j] > temp)
        {
            Array[j + 1] = Array[j];
            --j;
        }
        Array[j + 1] = temp;
    }
}