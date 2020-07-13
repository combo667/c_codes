#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data, col;
    Node *next;
} Node;

void displayMatrix(Node*,int,int);

int main(int argc, char const *argv[])
{
    Node **node = NULL;
    Node *p = NULL;
    int i, j, rows, nnz,d_rows,d_colms;

    node = (Node **)malloc(sizeof(Node *) * 4);
    printf("Input the dimensions of the matrix!\n");
    scanf("%d%d",&d_rows,&d_colms);
    printf("Input the number of rows in the matrix!\n");
    scanf("%d", &rows);
    for (j = 0; j < rows; ++j)
    {
        node[j] = createNode();
        p = node[j];
        printf("Input the number of nonzero element in the row!\n");
        scanf("%d", &nnz);
        for (i = 1; i < nnz; ++i)
        {
            p->next = createNode();
        }
    }

    return 0;
}

Node *createNode()
{
    Node *temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    printf("Input the data!\n");
    scanf("%d", &temp->data);
    printf("Input the column number !\n");
    scanf("%d", &temp->col);
    temp->next = NULL;
    return temp;
}

void displayMatrix(Node*node,int rows,int columns){
    Node p=node;int j;
    for(int i=0;i<rows;++i){
        for(j=0;j<columns;++j){
            p=node[j];
            if(p.col==j)
                printf("%d ",p.data);
            else
            {
                printf("0 ");
            }
            
        }
      printf("\n");
    }
    printf("\n");
}