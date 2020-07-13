#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int Top;
    int Size;
    int *array;
};

int isEmpty(struct Stack *);
int isFull(struct Stack *);
void freeStack(struct Stack *);
struct Stack *createStack();
void Push(struct Stack *, int);
int Pop(struct Stack *);
int stackTop(struct Stack *);
int Peek(struct Stack *, int);
void DisplayStack(struct Stack *);

int main(void)
{

    struct Stack *stack = NULL;
    int choice = 0, element = 0, position = 0;
    while (1)
    {
        printf("Input 1 for creating the Stack!\n");
        printf("Input 2 for pushing a element!\n");
        printf("Input 3 for popping an element !\n");
        printf("Input 4 for peeking any element!\n");
        printf("Input 5 for displaying the Stack!\n");
        printf("Input 6 for displaying the top most element!\n");
        printf("Input 7 for Exiting the stack!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            stack = createStack();
            break;
        case 2:
            printf("Input the element to be pushed !\n");
            scanf("%d", &element);
            Push(stack, element);
            break;
        case 3:
            element = Pop(stack);
            if (element)
                printf("The popped element is :%d\n", element);
            else
            {
                printf("The Stack is Empty!\n");
            }
            break;
        case 4:
            printf("Input the position!\n");
            scanf("%d", &position);
            element = Peek(stack, position);
            if (element)
            {
                printf("The element is :%d\n", element);
            }
            else
            {
                printf("The Stack is Empty!\n");
            }

            break;
        case 5:
            DisplayStack(stack);
            break;
        case 6:
            element = stackTop(stack);
            printf("The topmost element is :%d\n", element);
            break;
        case 7:
            freeStack(stack);
            exit(23);
            break;

        default:
            printf("Sorry Wrong Choice!\n");
            break;
        }
    }

    return 0;
}

struct Stack *createStack()
{
    struct Stack *temp;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    printf("Input the size of the stack to be created:\n");
    scanf("%d", &temp->Size);
    temp->array = (int *)malloc(sizeof(int) * temp->Size);
    temp->Top = -1;

    return temp;
}

int isEmpty(struct Stack *temp)
{
    if (temp->Top == -1)
        return 1;
    else
    {
        return 0;
    }
}

int isFull(struct Stack *temp)
{
    if (temp->Top == temp->Size - 1)
        return 1;
    else
    {
        return 0;
    }
}

void Push(struct Stack *stack, int element)
{

    if (isFull(stack))
        printf("Stack OverFlow!\n");
    else
    {
        stack->Top++;
        stack->array[stack->Top] = element;
        printf("Element inserted Successfully!\n");
    }
}

int Peek(struct Stack *stack, int pos)
{
    int x = -1;
    if (stack->Top - pos + 1 < 0)
        printf("Invalid position\n");
    else
    {
        x = stack->Top - pos + 1;
    }
    return x;
}

int stackTop(struct Stack *stack)
{
    if (stack->Top == -1)
        return -1;
    return stack->array[stack->Top];
}

int Pop(struct Stack *stack)
{
    int element = -1;
    if (isEmpty(stack))
        printf("Stack UnderFlow!\n");
    else
    {
        element = stack->array[stack->Top];
        --stack->Top;
    }
    return element;
}

void DisplayStack(struct Stack *stack)
{
    if (stack->Top == -1)
        printf("Nothing to Display!\n");
    else
    {

        printf("The elements in the Stack are :\n");
        for (int i = stack->Top + 1; i > 0; --i)
        {
            printf("%d\n", stack->array[stack->Top - i + 1]);
        }
        printf("\n");
    }
}

void freeStack(struct Stack *stack)
{
    free(stack->array);
    free(stack);
}