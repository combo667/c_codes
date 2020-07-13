#include <stdio.h>
#include <stdlib.h>

struct array
{
    int size;
    int length;
    int *arr;
};

struct array *createArray(int);
void arrayInput(struct array *);
void arrayOutput(struct array *, int);
struct array *Union(struct array *, struct array *);

int main(void)
{
    int size1 = 0, size2 = 0;
    printf("Input the size of the array1 :\n");
    scanf("%d", &size1);

    struct array *p, *q;
    p = createArray(size1);
    printf("Input the size of the array2 :\n");
    scanf("%d", &size2);

    q = createArray(size2);

    printf("The union of the arrays are :\n");
    struct array *c = Union(p, q);
    for (size_t i = 0; i < c->length; i++)
    {
        printf("%d  ", *(c->arr + i));
    }

    free(p);
    free(q);

    return 0;
}

struct array *createArray(int size)
{
    struct array *p = (struct array *)malloc(sizeof(struct array));
    p->size = size;
    p->arr = (int *)malloc(sizeof(int) * size);
    arrayInput(p);
    return p;
}

void arrayInput(struct array *p)
{
    int length = 0;
    printf("Input the number of element you would like to enter to  the array !\n");
    scanf("%d", &length);
    p->length = length;

    if (p->length <= p->size)
    {
        printf("Input the elemnts in the array :\n");
        for (size_t i = 0; i < length; i++)
        {
            scanf("%d", p->arr + i);
        }
        printf("Elements successfully inputted !\n");
    }
    else
    {
        printf("Sorry but length exceeds the size of the array !\n");
        return;
    }
}

void arrayOutput(struct array *p, int length)
{
    printf("The array elements are :\n");
    for (size_t i = 0; i < length; i++)
    {
        printf("%d  ", *(p->arr + i));
    }

    printf("\n");
}

struct array *Union(struct array *p, struct array *q)
{
    struct array *c = (struct array *)malloc(sizeof(struct array));
    c->arr = (int *)malloc(sizeof(int) * 20);

    int i = 0, j = 0, k = 0;
    while (i < p->length && j < q->length)
    {

        if (*(p->arr + i) < *(q->arr + j))
        {
            *(c->arr + k) = *(p->arr + i);
            i++;
            k++;
        }
        else if (*(q->arr + j) < *(p->arr + i))
        {
            *(c->arr + k) = *(q->arr + j);
            j++;
            k++;
        }
        else
        {
            *(c->arr + k) = *(p->arr + i);
            ++i;
            ++j;
            ++k;
        }
    }

    for (; i < p->length; ++i)
    {
        *(c->arr + k) = *(p->arr + i);
        ++k;
    }

    for (; j < q->length; ++j)
    {
        *(c->arr + k) = *(q->arr + j);
        ++k;
    }

    c->length = k;
    c->size = 20;

    return c;
}