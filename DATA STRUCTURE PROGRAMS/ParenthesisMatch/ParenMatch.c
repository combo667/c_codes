/* THIS CODE CHECKS WHETHER THE GIVEN EXPRESSION IS BALANCED OR NOT */
/* Example:
case 1:
    (a+b)+(c-d)*((56)/2) is balanced
case 2:
    ((a+b)+(c-d)*((56)/2) is not balanced */

/* THIS PROGRAM ONLY CHECKS FOR ROUND BRACKETS i.e. "()" */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

struct Stack
{
    int Size;
    int Top;
    char *s;
};

struct Stack *createStack(char *);
void Push(struct Stack *, char *);
void Pop(struct Stack *);
void displayStack(struct Stack *);
void freeStack(struct Stack *);
int Exp_Length(char *);
bool isFull(struct Stack *);
bool isEmpty(struct Stack *);
bool checkExpression(char *, struct Stack *);
void printExpression(char *);

int main(int argc, char const *argv[])
{
    char exp[MAX];
    printf("Input the Expression!\n");
    fgets(exp, 100, stdin);
    struct Stack *temp = createStack(exp);
    if (checkExpression(exp, temp))
    {
        //printExpression(exp);
        printf("Given Expression is balanced!!\n");
    }
    else
    {

        //printExpression(exp);
        printf("Given Expression is not Balanced!\n");
    }

    freeStack(temp);

    return 0;
}

struct Stack *createStack(char *s)
{
    struct Stack *temp = NULL;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->Size = Exp_Length(s);
    temp->Top = -1;
    temp->s = (char *)malloc(sizeof(char) * temp->Size);

    return temp;
}

int Exp_Length(char *s)
{
    int i = 0;
    for (i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}

void Push(struct Stack *stack, char *c)
{
    if (isFull(stack) == true)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack->Top++;
        stack->s[stack->Top] = *c;
    }
}

void Pop(struct Stack *stack)
{
    if (isEmpty(stack) == true)
        printf("Stack Underflow!\n");
    else
    {
        stack->Top--;
    }
}

bool isFull(struct Stack *stack)
{
    if (stack->Top == stack->Size - 1)
        return true;
    else
        return false;
}

bool isEmpty(struct Stack *stack)
{
    if (stack->Top == -1)
        return true;
    else
        return false;
}

void displayStack(struct Stack *stack)
{
    if (isEmpty(stack) == true)
        printf("Stack is Empty!\n");
    else
    {
        printf("The elements in the Stack are :\n");
        for (int i = stack->Top + 1; i > 0; --i)
        {
            printf("%c\n", stack->s[stack->Top - i + 1]);
        }
        printf("\n");
    }
}

void freeStack(struct Stack *stack)
{
    free(stack->s);
    free(stack);
}

bool checkExpression(char *s, struct Stack *stack)
{

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == '(')
            Push(stack, s + i);
        else if (s[i] == ')')
        {
            if (isEmpty(stack))
                return false;
            else
            {
                Pop(stack);
            }
        }
    }
    return (isEmpty(stack)) ? true : false;
}

void printExpression(char *c)
{
    for (int i = 0; c[i] != '\0'; ++i)
        printf("%c", *(c+i));
}