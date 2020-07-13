#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    int Top;
    int Size;
    struct Node **Array;
};

struct Stack *createStack();
struct Node *createNode();
void appendNode(struct Node *);
void Push(struct Stack *, struct Node *);
struct Node *Pop(struct Stack *);
bool isFull(struct Stack *);
bool isEmpty(struct Stack *);
struct Node *stackTop(struct Stack *);
void freeList(struct Node *);
void freeStack(struct Stack *);
int lengthOfLinkedList(struct Node *);
void findIntersection(struct Node *, struct Node *);
void connect(struct Node *, struct Node *);
void display(struct Node*);

int main(int argc, char const *argv[])
{
    int num = 0;
    struct Node *first = NULL, *second = NULL;
    printf("Linked List 1 created!\n");
    first = createNode();
    printf("Input the Number of Nodes you want to insert to the first Linked List!\n");
    scanf("%d", &num);
    for (int i = 0; i < num; ++i)
        appendNode(first);
    printf("Linked List 2 created !");
    second = createNode();
    printf("Input the number of nodes you want to insert to the second Linked List!\n");
    scanf("%d", &num);
    for (int i = 0; i < num; ++i)
        appendNode(second);

    printf("The LinkedList 1 looks like:\n");
    display(first);
    printf("Linked List 2 looks like:\n");
    display(second);

    connect(first, second); //connection done

    printf("Now after connection:\n");

    printf("The LinkedList 1 looks like:\n");
    display(first);
    printf("Linked List 2 looks like:\n");
    display(second);

    findIntersection(first, second); //finding Intersection point

    freeList(first);
    freeList(second);

    return 0;
}

struct Stack *createStack(struct Node *node)
{
    struct Stack *temp;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    // printf("Input the Size of the stack you want to create!\n");
    //scanf("%d",&temp->Size);
    temp->Size = lengthOfLinkedList(node) + 1;
    temp->Array = (struct Node **)malloc(sizeof(struct Node *) * temp->Size);
    temp->Top = -1;
    return temp;
}

struct Node *createNode()
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Input the data!\n");
    scanf("%d", &temp->data);
    temp->next = 0;
    return temp;
}

void appendNode(struct Node *node)
{
    struct Node *temp = createNode();

    while (node->next != 0)
    {
        node = node->next;
    }
    node->next = temp;
}

void Push(struct Stack *stack, struct Node *address)
{
    if (isFull(stack))
        printf("StackOverFlow!\n");
    else
    {
        stack->Top++;
        stack->Array[stack->Top] = address;
    }
}

struct Node *Pop(struct Stack *stack)
{
    struct Node *temp = NULL;
    if (isEmpty(stack))
        printf("StackUnderFlow!\n");
    else
    {
        temp = stack->Array[stack->Top];
        stack->Top--;
        return temp;
    }
    return temp;
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
    {
        return false;
    }
}

struct Node *stackTop(struct Stack *stack)
{
    struct Node *temp = NULL;
    if (isEmpty(stack))
        printf("Stack is Empty!\n");
    else
    {
        temp = stack->Array[stack->Top];
        return temp;
    }
    return temp;
}

void freeList(struct Node *node)
{
    struct Node *p = node;
    while (node != 0)
    {
        node = node->next;
        free(p);
        p = node;
    }
}

void freeStack(struct Stack *stack)
{
    free(stack->Array);
    free(stack);
}

void findIntersection(struct Node *first, struct Node *second)
{

    struct Stack *stk1 = NULL, *stk2 = NULL;
    stk1 = createStack(first);
    stk2 = createStack(second);

    struct Node *p = first, *q = second;
    while (p != 0)
    {
        Push(stk1, p);
        p = p->next;
    }
    while (q != 0)
    {
        Push(stk2, q);
        q = q->next;
    }
    while (stackTop(stk1) == stackTop(stk2))
    {
        p = Pop(stk1);
        Pop(stk2);
    }
    printf("The intersection Node is at element :%d\n\n", p->data);

    freeStack(stk1);
    freeStack(stk2);
}

int lengthOfLinkedList(struct Node *node)
{
    if (node == 0)
        return 0;
    return 1 + lengthOfLinkedList(node->next);
}

void connect(struct Node *first, struct Node *second)
{
    int position = 0;
    struct Node *p = first, *q = second;
    printf("Input the position in LL 1 to connect LL 2\n");
    scanf("%d", &position);
    for (int i = 0; i < position - 1; ++i)
        p = p->next;
    while (q->next != 0)
    {
        q = q->next;
    }
    q->next = p;
}

void display(struct Node *node)
{
    while (node != 0)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
