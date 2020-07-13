//Radix Sort Made by JUbesH JOSeph
//DAted :25 th June 2020
//Time Complexity= O(dn)
//Space Complexity= O(n)



#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int);
int deleteNode(Node **);
void RadixSort(int[], int);
int FindMaxDigit(int[], int);
void insertNode(Node **, int, int);
void printArray(int[], int);

Node *createNode(int element)
{
    Node *temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = element;
    temp->next = NULL;

    return temp;
}

void RadixSort(int Array[], int size)
{
    int div = 1, i = 0, j = 0, count = 0;

    int pass = FindMaxDigit(Array, size);

    Node **Bins = (Node **)malloc(sizeof(Node *) * 10);

    for (size_t i = 0; i < 10; i++)
    {
        Bins[i] = NULL;
    }

    for (count = 0; count < pass; ++count)
    {

        for (i = 0; i < size; ++i)
        {
            insertNode(Bins, (Array[i] / div) % 10, Array[i]);
        }

        for (j = 0; j < size; ++j)
        {
            Array[j] = deleteNode(Bins);
        }

        div *= 10;
    }

    free(Bins);
}

int FindMaxDigit(int Array[], int size)
{
    int max = INT_MIN;
    int digits = 0;
    for (int i = 0; i < size; i++)
    {
        if (Array[i] > max)
            max = Array[i];
    }

    do
    {
        ++digits;
        max /= 10;
    } while (max > 0);

    return digits;
}

void insertNode(Node **Bins, int index, int element)
{
    Node *temp = NULL;
    Node *p = NULL;

    if (Bins[index] == NULL)
    {
        temp = createNode(element);
        Bins[index] = temp;
    }
    else
    {
        p = Bins[index];
        while (p->next != NULL)
        {
            p = p->next;
        }
        temp = createNode(element);
        p->next = temp;
    }
}

int deleteNode(Node **Bins)
{
    int element = 0;
    int i = 0;
    Node *p = NULL;

    while (Bins[i] == NULL)
    {
        ++i;
    }
    p = Bins[i];
    element = p->data;
    Bins[i] = p->next;

    return element;
}

void printArray(int Array[], int size)
{
    printf("The sorted List is :\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", Array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int Array[] = {200,190,166,134,120,12};
    int size = sizeof(Array) / sizeof(Array[0]);
    RadixSort(Array, size);
    printArray(Array, size);

    return 0;
}
