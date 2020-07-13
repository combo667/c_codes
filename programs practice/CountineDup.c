#include <stdio.h>
int main(void)
{

    int A[] = {2, 3, 3, 4, 5, 8, 9, 9, 9, 10, 11, 11, 12, 23, 23};

    int j = 0;
    printf("The Duplicate Occurences are :\n");
    for (int i = 0; i < 14; ++i)
    {

        if (A[i] == A[i + 1])
        {
            j = i + 1;
            while (A[j] == A[i])
                ++j;
            printf("%d Occurs %d times!\n", A[i], j - i);
            i = j - 1;
        }
    }

    return 0;
}