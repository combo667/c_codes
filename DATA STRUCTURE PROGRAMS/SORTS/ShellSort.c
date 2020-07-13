#include <stdio.h>

void ShellSort(int[], int);
void printArray(int[], int);


int main(int argc, char const *argv[])
{
    int Array[] = {200, 6, 11, 877, 568, 90, 232, 11, 678, 982, 774, 777, 2221, 876, 898, 556, 2551, 666, 2100, 222, 111, 8999, 672, 4521, 886, 933, 422, 542, 761, 7222};
    int size = sizeof(Array) / sizeof(Array[0]);

    ShellSort(Array, size);
    printArray(Array, size);

    return 0;
}

void ShellSort(int Array[], int size)
{
    int gap = 0, i = 0, j = 0, temp = 0;

    for (gap = size / 2; gap >=1; gap /= 2)
    {
        for (i = gap; i < size; ++i)
        {
            j = i - gap;
            temp = Array[i];
            while (j > -1 && Array[j] > temp)
            {
                Array[j + gap] = Array[j];
                j -= gap;
            }
            Array[j + gap] = temp;
        }
    }
}

void printArray(int Array[], int size)
{
    printf("The Sorted List is :\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", Array[i]);
    }
    printf("\n");
}

