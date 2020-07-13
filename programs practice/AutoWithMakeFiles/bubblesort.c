#include <stdio.h>

void bubblesort(int *, int);

void bubblesort(int *array, int length)
{
    int temp = 0;
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length - 1; ++j)
        {
            if (*(array + j) > *(array + j + 1))
            {
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}