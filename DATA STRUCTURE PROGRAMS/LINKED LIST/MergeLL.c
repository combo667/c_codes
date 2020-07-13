#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *createNode(void);
void insertNode(struct Node *);
void display(struct Node *);
struct Node *mergeLinkedList(struct Node *, struct Node *);
void freeList(struct Node *);

int main(void)
{
    int size = 0;
    struct Node *p = NULL, *q = NULL, *three = NULL;
    p = createNode();
    q = createNode();

    printf("Input the number of Nodes you would like to insert to Linked List 1:\n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        insertNode(p);
    }
    printf("Input the number of Nodes you would like to insert to Linked List 2:\n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        insertNode(q);
    }
    display(p);
    display(q);
    printf("The merged Linked List is :\n");
    three = mergeLinkedList(p, q);
    display(three);

    freeList(p);
    freeList(q);
    freeList(three);

    return 0;
}

struct Node *createNode(void)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    printf("Input the Data:\n");
    scanf("%d", &p->data);
    p->link = 0;

    return p;
}

void insertNode(struct Node *p)
{
    if (p)
    {
        struct Node *temp;
        temp = p;
        while (temp->link != 0)
        {
            temp = temp->link;
        }
        temp->link = createNode();
    }
    else
    {
        printf("Please create the Node first!\n");
    }
}

void display(struct Node *p)
{
    struct Node *temp;
    temp = p;
    if (temp)
    {
        printf("The data in the Linked List is :\n");
        while (temp)
        {
            printf("%d  ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else
    {
        printf("Please create the List First!\n");
    }
}
//This is the merging algorithm for merging two linked list
//it has a time complexity of theta(m+n)
struct Node *mergeLinkedList(struct Node *first, struct Node *second)
{
    struct Node *three, *last;
    if (first->data < second->data)
    {
        three = last = first;
        first = first->link;
        last->link = 0;
    }
    else
    {
        three = last = second;
        second = second->link;
        last->link = 0;
    }
    while (first != 0 && second != 0)
    {
        if (first->data < second->data)
        {
            last->link = first;
            last = first;
            first = first->link;
            last->link = 0;
        }
        else
        {
            last->link = second;
            last = second;
            second = second->link;
            last->link = 0;
        }
    }
    if (first == 0)
        last->link = second;
    else
        last->link = first;

    return three;
}

void freeList(struct Node *p)
{
    struct Node *temp;
    while (p != 0)
    {
        temp = p;
        p = p->link;
        free(temp);
    }
}