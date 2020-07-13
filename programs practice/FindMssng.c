#include <stdio.h>

int main(void)
{

    int sum = 0, ssum = 0;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    int n = array[9];
    int element = 0;
    ssum = (n * (n + 1)) / 2;
    for (int i = 0; i < 10; ++i)
        sum += array[i];
    element = ssum - sum;
    printf("The missing element is :%d\n", element);

    return 0;
}