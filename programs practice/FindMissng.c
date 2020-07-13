//This program finds  missing element from a sorted array

#include <stdio.h>

int main(void)
{

    int array[10] = {4, 5, 6, 7, 8, 9, 10, 11, 13, 14};
    int diff = array[0] - 0;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] - i != diff)
        {
            printf("The missing element is :%d\n", (i + diff));
            break;
        }
    }

    return 0;
}