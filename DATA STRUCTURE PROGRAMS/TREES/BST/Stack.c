#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "Node.h"
#include "Stack.h"





bool isEmptyStack(Stack *);
bool isFullStack(Stack *);
void freeStack(Stack *);
struct Stack *createStack();
void Push(Stack *, Node *);
Node *Pop(Stack *);
int stackTop(Stack*);


Stack *createStack()
{
    struct Stack *temp;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    printf("Input the size of the stack to be created:\n");
    scanf("%d", &temp->Size);
    temp->array = (Node **)malloc(sizeof(Node *) * temp->Size);
    temp->Top = -1;

    return temp;
}

bool isEmptyStack(Stack *temp)
{
    if (temp->Top == -1)
        return true;

    return false;
}

bool isFullStack(Stack *temp)
{
    if (temp->Top == temp->Size - 1)
        return true;
    return false;
}

void Push(Stack *stack, Node *node)
{

    if (isFullStack(stack))
        printf("Stack OverFlow!\n");
    else
    {
        stack->Top++;
        stack->array[stack->Top] = node;
       
    }
}

Node *Pop(Stack *stack)
{
    Node *element = NULL;
    if (isEmptyStack(stack))
        printf("Stack UnderFlow!\n");
    else
    {
        element = stack->array[stack->Top];
        --stack->Top;
    }
    return element;
}

int stackTop(Stack*stack){
    if(isEmptyStack(stack)==true)
        return INT_MAX;
    else
    {
        return stack->array[stack->Top]->data;
    }
    
}

void freeStack(Stack *stack)
{
    free(stack->array);
    free(stack);
}