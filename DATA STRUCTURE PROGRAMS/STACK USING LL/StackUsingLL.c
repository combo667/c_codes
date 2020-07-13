#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode();
struct Node *Push(struct Node *);
struct Node *Pop(struct Node *);
int isEmpty(struct Node *);
int isFull(struct Node *);
int Peek(struct Node *);
void stackTop(struct Node *);
struct Node *freeList(struct Node *);
void Display(struct Node *);

int main(void)
{

    int choice = 0, element = 0;
    struct Node *Top = 0;

    while (1)
    {
        printf("Input 1 for Pushing Value!\n");
        printf("Input 2 for Popping Value!\n");
        printf("Input 3 for displaying the Top Value!\n");
        printf("Input 4 for peeking any position!\n");
        printf("Input 5 for Displaying the stack!\n");
        printf("Input 6 for exiting!\n");
        printf("Input your choice!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Top = Push(Top);
            break;
        case 2:
            Top = Pop(Top);
            break;
        case 3:
            stackTop(Top);
            break;
        case 4:
            element = Peek(Top);
            if (element)
                printf("The element is %d\n", element);
            else
            {
                printf("Stack is Empty!\n");
            }
            break;
        case 5:
            Display(Top);
            break;
        case 6:
            Top = freeList(Top);
            exit(33);
        default:
            printf("Wrong choice!\n");
            break;
        }
    }

    return 0;
}

struct Node *createNode()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = 0;
    printf("Input the data!\n");
    scanf("%d", &temp->data);
    return temp;
}

struct Node *Push(struct Node *Top)
{
    struct Node *temp = createNode();
    temp->next = Top;
    Top = temp;
    return Top;
}

struct Node *Pop(struct Node *Top)
{

    struct Node *p;
    p = Top;
    if (isEmpty(Top))
        printf("Stack UnderFlow!\n");
    else
    {
        Top = Top->next;
        printf("The Popped data is :%d\n", p->data);
        free(p);
    }
    return Top;
}

int isFull(struct Node *Top)
{
    struct Node *temp = createNode();
    if (temp == NULL)
        return 1;
    else
    {
        return 0;
    }
    free(temp);
}

int isEmpty(struct Node *Top)
{
    return Top == 0 ? 1 : 0;
}

void stackTop(struct Node *Top)
{
    if (isEmpty(Top))
        printf("Stack is Empty!\n");
    else
    {
        printf("The value at top is :%d\n", Top->data);
    }
}

int Peek(struct Node *Top)
{
    struct Node *p = Top;
    int position = 0;
    printf("Input the position!\n");
    scanf("%d", &position);
    for (int i = 0; i < position - 1 && p != 0; ++i)
        p = p->next;
    if (p->next != 0)
        return p->data;
    else
    {
        return -1;
    }
}

struct Node *freeList(struct Node *Top)
{
    struct Node *p = Top;
    while (Top != 0)
    {
        Top = Top->next;
        free(p);
        p = Top;
    }
    return Top;
}

void Display(struct Node *Top)
{
    if (isEmpty(Top))
        printf("List is Empty!\n");
    else
    {
        printf("The data in the stack is :\n");
        struct Node *p = Top;

        do
        {
            printf("%d \n", p->data);
            p = p->next;
        } while (p != 0);
        printf("\n");
    }
}