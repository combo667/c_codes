#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;

} Node;

typedef struct stack
{
    int Top;
    Node **array;
    int Size;
} Stack;

Stack *createStack();
bool isEmpty(Stack *);
bool isFull(Stack *);
void Push(Stack *, Node *);
Node *Pop(Stack *);
int stackTop(Stack *);
Node *createNode(int);
Node *GenerateBST(int[], int);
void freeStack(Stack *);
void display_Inorder(Node *);
void display_PostOrder(Node *);
void freeTree(Node *);

Stack *createStack()
{
    Stack *temp = NULL;
    temp = (Stack *)malloc(sizeof(Stack));
    printf("Input the size of the Stack!\n");

    scanf("%d", &temp->Size);
    temp->Top = -1;
    temp->array = (Node **)malloc(sizeof(Node *) * temp->Size);
    return temp;
}

bool isEmpty(Stack *stack)
{
    return stack->Top == -1 ? true : false;
}

bool isFull(Stack *stack)
{
    return stack->Top == stack->Size - 1 ? true : false;
}

void Push(Stack *stack, Node *node)
{
    if (isFull(stack) != true)
    {
        stack->Top++;
        stack->array[stack->Top] = node;
    }
    else
        printf("StackOverFlow!\n");
}

Node *Pop(Stack *stack)
{
    Node *temp = NULL;
    if (isEmpty(stack) != true)
    {
        temp = stack->array[stack->Top];
        --stack->Top;
        return temp;
    }
    else
    {
        printf("StackUnderFlow!\n");
        return temp;
    }
}

int stackTop(Stack *stack)
{
    if (isEmpty(stack) == true)
        return INT_MAX;
    else
        return stack->array[stack->Top]->data;
}

void freeStack(Stack *stack)
{
    free(stack->array);
    free(stack);
}

Node *createNode(int data)
{
    Node *temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

Node *GenerateBST(int Pre[], int size)
{
    Node *temp = NULL, *p = NULL, *root = NULL;
    Stack *stack = createStack();

    int i = 0;
    root = createNode(Pre[i++]);
    p = root;

    while (i < size)
    {
        if (Pre[i] < p->data)
        {
            temp = createNode(Pre[i++]);
            p->lchild = temp;
            Push(stack, p);
            p = p->lchild;
        }
        else
        {
            if (Pre[i] > p->data && Pre[i] < stackTop(stack))
            {
                temp = createNode(Pre[i++]);
                p->rchild = temp;
                p = p->rchild;
            }
            else
            {
                p = Pop(stack);
            }
        }
    }
    freeStack(stack);
    return root;
}

void display_Inorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
        display_Inorder(root->lchild);
        display_Inorder(root->rchild);
    }
}

void display_PostOrder(Node *root)
{
    if (root != NULL)
    {
        display_PostOrder(root->lchild);
        display_PostOrder(root->rchild);
        printf("%d ", root->data);
    }
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->lchild);
    freeTree(root->rchild);

    free(root);
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int Pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    root = GenerateBST(Pre, sizeof(Pre) / sizeof(Pre[0]));
    display_PostOrder(root);
    printf("\n");

    freeTree(root);
    root = NULL;

    return 0;
}
