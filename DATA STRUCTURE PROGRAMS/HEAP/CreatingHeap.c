#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int[], int);
void Insert(int *, int);
void createHeap(int *, int);

int main(void)
{

    int size;
    int random = 0;
    printf("Input the number of elements:\n");
    scanf("%d", &size);
    size++;
    int *Array = (int *)malloc(sizeof(int) * size);
    // printf("Input the elements one by one :\n");
    srand(time(0));
    printf("The randoms are :\n");
    for (int i = 1; i < size; ++i)
    {
        random = rand();
        printf("%d  ", random);
        *(Array + i) = random;
    }

    createHeap(Array, size);
    print(Array, size);

    free(Array);

    return 0;
}

void createHeap(int *Array, int length)
{

    int i = 0;
    for (i = 2; i < length; ++i)
    {
        Insert(Array, i);
    }
}

void Insert(int *Array, int n)
{
    int i = n;
    int temp = *(Array + n);

    while (i > 1 && temp > *(Array + (i / 2)))
    {
        *(Array + i) = *(Array + (i / 2));
        i = i / 2;
    }

    *(Array + i) = temp;
}

void print(int *Array, int length)
{
    printf("\n");
    printf("The Heap Looks like:\n");

    for (int i = 1; i < length; ++i)
        printf("%d  ", *(Array + i));
    printf("\n");
}