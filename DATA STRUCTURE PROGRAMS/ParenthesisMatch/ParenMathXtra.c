/* So this code also checks for round,square,flower brackets moreover it also checks for the order in which the expression is wrote
for example

({)} -> This is a balanced expr but its order is not maintained ,so our code also checks that! 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack
{
    char *ch;
    int Size, Top;
} Stack;

bool isFull(Stack *);
bool isEmpty(Stack *);
struct Stack *createStack(char *);
bool checkExpression(char *, Stack *);
bool isMatchingPair(char, char);
char stackTop(struct Stack *);
void Push(Stack *, char);
char Pop(Stack *);
void freeStack(Stack *);

int main(int argc, char const *argv[])
{
    char *expr = "{(})";

    Stack *stack = createStack(expr);
    if (checkExpression(expr, stack) == true)
        printf("Expression is Balanced!\n");
    else
        printf("Expression is not balanced!\n");

    freeStack(stack);
    return 0;
}

bool isFull(struct Stack *stack)
{
    if (stack->Top == stack->Size - 1)
        return true;
    else
    {
        return false;
    }
}

bool isEmpty(struct Stack *stack)
{
    if (stack->Top == -1)
        return true;
    else
        return false;
}

struct Stack *createStack(char *s)
{
    struct Stack *temp = NULL;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->Size = strlen(s);
    temp->ch = (char *)malloc(sizeof(char) * temp->Size);
    temp->Top = -1;
    return temp;
}

char stackTop(struct Stack *stack)
{
    char ch = ' ';
    if (isEmpty(stack))
        printf("Stack is Empty");
    else
    {
        ch = stack->ch[stack->Top];
        return ch;
    }
    return ch;
}

void Push(Stack *stack, char ch)
{
    if (isFull(stack))
        printf("Stack Overflow!\n");
    else
    {
        stack->Top++;
        stack->ch[stack->Top] = ch;
    }
}

char Pop(Stack *stack)
{
    char ch = ' ';
    if (isEmpty(stack))
        printf("StackUnderFlow!\n");
    else
    {
        ch = stack->ch[stack->Top];
        stack->Top--;
        return ch;
    }
}

bool checkExpression(char *s, Stack *stack)
{

    char ch = ' ';
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            Push(stack, s[i++]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {

            if (isEmpty(stack))
                return false;
            else
            {

                if (isMatchingPair(Pop(stack), s[i++]) != true)
                    return false;
            }
        }
    }
    return isEmpty(stack) ? true : false;
}

bool isMatchingPair(char ch1, char ch2)
{
    if (ch1 == '(' && ch2 == ')')
        return true;
    else if (ch1 == '{' && ch2 == '}')
        return true;
    else if (ch1 == '[' && ch2 == ']')
        return true;
    else
    {
        return false;
    }
}

void freeStack(Stack *stack)
{
    free(stack->ch);
    free(stack);
}