/* THIS PROGRAM EVLUATES A POSTFIX EXPRESSION 
FOR EXAMPLE :

    "35*62/+4-" evaluates to give =14 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack
{

    int Top, Size;
    int *array;

} Stack;

bool isEmpty(Stack *);
bool isFull(Stack *);
void freeStack(Stack *);
void Push(Stack *, int);
int Pop(Stack *);
int Evaluation(char *);
bool isOperand(char);
Stack *createStack(char *);

int main(int argc, char const *argv[])
{

    char *postfix = "35*62/+4-";
    printf("The result of the postfix expression is :%d\n", Evaluation(postfix));
    return 0;
}

Stack *createStack(char *expr)
{
    Stack *temp = NULL;
    temp = (Stack *)malloc(sizeof(Stack));
    temp->array = (int *)malloc(sizeof(int) * strlen(expr) + 1);

    temp->Size = strlen(expr) + 1;
    temp->Top = -1;
    return temp;
}

bool isEmpty(Stack *stack)
{
    if (stack->Top == -1)
        return true;
    else
        return false;
}

bool isFull(Stack *stack)
{
    if (stack->Top == stack->Size - 1)
        return true;
    else
        return false;
}

void Push(Stack *stack, int element)
{
    if (isFull(stack) != true)
    {
        stack->Top++;
        stack->array[stack->Top] = element;
    }
    else
    {
        printf("StackOverflow!\n");
    }
}

int Pop(Stack *stack)
{
    int pop = -1;
    if (isEmpty(stack) != true)
    {

        pop = stack->array[stack->Top];
        stack->Top--;
        return pop;
    }
    else
    {
        printf("StackUnderflow!\n");
    }
    return pop;
}

void freeStack(Stack *stack)
{
    free(stack->array);
    free(stack);
}

int Evaluation(char *postfix)
{
    int i = 0, j = 0, x1 = 0, x2 = 0, res = 0;
    Stack *stack = createStack(postfix);

    while (postfix[i] != '\0')
    {
        if (isOperand(postfix[i]))
            Push(stack, postfix[i++] - '0');
        else
        {
            x2 = Pop(stack);
            x1 = Pop(stack);
            switch (postfix[i++])
            {
            case '+':
                res = x1 + x2;
                Push(stack, res);
                break;
            case '-':
                res = x1 - x2;
                Push(stack, res);
                break;
            case '/':
                res = x1 / x2;
                Push(stack, res);
                break;
            case '*':
                res = x1 * x2;
                Push(stack, res);
                break;
            }
        }
    }
    res = Pop(stack);
    freeStack(stack);
    return res;
}

bool isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return false;
    return true;
}
