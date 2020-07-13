#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Node.h"
#include "Stack.h"
#include "STACK_DEP.h"

Node *Generate(int[], int);
void Display(Node *);

int main(int argc, char const *argv[])
{
    int Array[] = {30, 20, 10, 15, 25, 40, 50, 45};
    Node *root = NULL;

    root = Generate(Array, sizeof(Array) / sizeof(Array[0]));
    printf("The PreOrder Traversal is :\n");
    Display(root);
    return 0;
}

Node *Generate(int Pre[], int size)
{
    Stack *stack = createStack();
    int i = 0;
    Node *temp = NULL, *p = NULL, *root = NULL;

    root = (Node *)malloc(sizeof(Node));
    p = root;
    p->data = Pre[i++];
    p->lchild = p->rchild = NULL;

    while (i < size)
    {
        if (Pre[i] < p->data)
        {
            temp = (Node *)malloc(sizeof(Node));
            temp->lchild = temp->rchild = NULL;
            temp->data = Pre[i++];
            p->lchild = temp;
            p = temp;
        }

        else
        {
            if (Pre[i] > p->data && Pre[i] < stackTop(stack))
            {
                temp = (Node *)malloc(sizeof(Node));
                temp->data = Pre[i++];
                temp->lchild = temp->rchild = NULL;
                p->rchild = temp;
                p = temp;
            }
            else
                p = Pop(stack);
        }
    }

    freeStack(stack);
    return root;
}

void Display(Node *root)
{

    if (root != NULL)
    {

        printf("%d  ", root->data);
        Display(root->lchild);
        Display(root->rchild);
    }
}