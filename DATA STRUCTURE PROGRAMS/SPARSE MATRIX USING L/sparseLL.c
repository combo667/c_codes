#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int col;
    int data;
    struct Node *next;
};
void display(struct Node **, int, int);
struct Node *createNode();
void freeAll(struct Node **, int, int);

int main(int argc, char const *argv[])
{

    int nnz = 0;
    int m = 0, n = 0;
    struct Node *p = 0;
    printf("Input the dimensions of the Matrix!\n");
    printf("Input the number of rows!\n");
    scanf("%d", &m);
    printf("Input the number of columns!\n");
    scanf("%d", &n);
    struct Node **A = malloc(sizeof(struct Node *) * m);

    for (int i = 0; i < m; ++i)
    {
        printf("Input the number of non-zero elements in row %d\n", i);
        scanf("%d", &nnz);
        if (nnz != 0)
        {
            A[i] = createNode();
            p = A[i];
            for (int j = 1; j < nnz; ++j)
            {
                p->next = createNode();
                p = p->next;
            }
        }
        else
        {
            A[i] = 0;
        }
    }

    display(A, m, n);
    freeAll(A, m, n);

    return 0;
}

struct Node *createNode()
{
    struct Node *temp = 0;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Input the column number !\n");
    scanf("%d", &temp->col);
    printf("Input the element!\n");
    scanf("%d", &temp->data);
    temp->next = 0;
    return temp;
}

void display(struct Node **A, int m, int n)
{
    struct Node *p = 0;
    int j = 0;
    printf("The MATRIX representation is :\n");
    for (int i = 0; i < m; ++i)
    {
        if (A[i] != 0)
        {
            p = A[i];
            for (j = 0; j < n; ++j)
            {
                if (p->col == j && p != 0)
                {
                    printf("%d ", p->data);
                    p = p->next;
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
        else
        {
            for (int k = 0; k < n; ++k)
                printf("0 ");
            printf("\n");
        }
    }
    printf("\n");
}

void freeAll(struct Node **A, int m, int n)
{
    struct Node *p = 0, *q = 0;
    for (int i = 0; i < m; ++i)
    {
        if (A[i] != 0)
        {
            p = A[i];
            while (p != 0)
            {
                q = q->next;
                free(p);
                p = q;
            }
        }
    }
    free(A);
}