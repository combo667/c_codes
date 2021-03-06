/* THIS PROGRAMS ALSO SUPPORTS ASSOSIATIVITY OPERATORS FROM RIGHT TO LEFT SUCH AS ^ POWER OPERATOR MOREOVER THIS PROGRAM ALSO SUPPORTS () OPERATOR TOO
SO THIS CODE ALSO FOLLOWS ASSOCIATIVITY RULES

 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char *Array;
    int Top;
    int Size;
};

struct Stack *createStack(int);
bool isEmpty(struct Stack *);
bool isFull(struct Stack *);
char stackTop(struct Stack *);
char Pop(struct Stack *);
void Push(struct Stack *, char);
void freeStack(struct Stack *);
void displayStack(struct Stack *);
char *infixToPostFix(char *);
bool isOperand(char);
int outPrecedence(char);
int inPrecedence(char);

int main(int argc, char const *argv[])
{

    char *infix = "(a+b)*c-d^e^f";  //infix expression
    char *postfix = infixToPostFix(infix);  //postfix converted
    printf("The postfix of the expression is :%s\n", postfix);

    return 0;
}

struct Stack *createStack(int size)
{
    struct Stack *temp = 0;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->Size = size;
    temp->Array = (char *)malloc(sizeof(char) * temp->Size);
    temp->Top = -1;

    return temp;
}

bool isEmpty(struct Stack *stack)
{
    if (stack->Top == -1)
        return true;
    else
        return false;
}

bool isFull(struct Stack *stack)
{

    if (stack->Top == stack->Size - 1)
        return true;
    else
        return false;
}

void Push(struct Stack *stack, char element)
{

    if (isFull(stack) == true)
        printf("StackOverflow!\n");
    else
    {
        stack->Top++;
        stack->Array[stack->Top] = element;
    }
}

char Pop(struct Stack *stack)
{
    char element = ' ';
    if (isEmpty(stack) == true)
        printf("StackUnderFlow!\n");
    else
    {
        element = stack->Array[stack->Top];
        stack->Top--;
    }
    return element;
}

char stackTop(struct Stack *stack)
{
    char ch = '\0';
    if (isEmpty(stack) != true)
    {
        ch = stack->Array[stack->Top];
        return ch;
    }
    return ch;
}

void freeStack(struct Stack *stack)
{
    free(stack->Array);
    free(stack);
}

void displayStack(struct Stack *stack)
{
    if (stack->Top == -1)
        printf("Nothing to Display!\n");
    else
    {

        printf("The elements in the Stack are :\n");
        for (int i = stack->Top + 1; i > 0; --i)
        {
            printf("%c\n", stack->Array[stack->Top - i + 1]);
        }
        printf("\n");
    }
}

int outPrecedence(char c)
{

    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if(c=='^')
        return 6;
    else if(c=='(')
        return 7;
    else if(c==')')
        return 0;

    return -2;
}

bool isOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/'||c=='^'||c=='('||c==')')
        return false;

    return true;
}

char *infixToPostFix(char *s)
{

    struct Stack *stack = createStack(strlen(s) + 1);
    char *postfix = (char *)malloc(sizeof(char) * strlen(s) + 1);

    int i = 0, j = 0;
    while (s[i] != '\0')
    {
        if (isOperand(s[i]))
        {
            postfix[j++] = s[i++];
        }
        else
        {
            if (outPrecedence(s[i]) > inPrecedence(stackTop(stack)))
            {
                Push(stack, s[i++]);
            }
            else if(outPrecedence(s[i])==inPrecedence(stackTop(stack))){
                Pop(stack);
                i++;}
            else
            {
                postfix[j++] = Pop(stack);
            }
        }
    }
    while (isEmpty(stack) != true)
    {
        postfix[j++] = Pop(stack);
    }
    postfix[j] = '\0';
    freeStack(stack);
    return postfix;
}

int inPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/')
        return 4;
    else if (ch == '^')
        return 5;
    else if (ch == '(')
        return 0;
    else
    {
        return -1;
    }
}
