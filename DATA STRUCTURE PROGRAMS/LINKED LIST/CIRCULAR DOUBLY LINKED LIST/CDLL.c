// CIRCULAR DOUBLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    struct Node *prev;
    int data;
};

struct Node *createNode();
void appendNode(struct Node *);
void Display(struct Node *);
struct Node *freeList(struct Node *);
struct Node *moveToLast(struct Node *);
struct Node *insertNode(struct Node *);

int main(void)
{

    int choice = 0;
    struct Node *head = 0;

    while (1)
    {
        printf("Input 1 for creating the List!\n");
        printf("Input 2 for appending Nodes!\n");
        printf("Input 3 for Displaying List!\n");
        printf("Input 4 for inserting Node!\n");
        printf("Input 5 for Exiting !\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = createNode();
            break;
        case 2:
            appendNode(head);
            break;
        case 3:
            Display(head);
            break;
        case 4:
            head = insertNode(head);
            break;
        case 5:
            head = freeList(head);
            exit(23);
        default:
            printf("Wrong choice made!\n");
        }
    }

    return 0;
}

struct Node *createNode()
{
    struct Node *temp;
    int data;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Input the data!\n");
    scanf("%d", &data);
    temp->data = data;
    temp->prev = temp;
    temp->next = temp;

    return temp;
}

void appendNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *temp = createNode();
    while (p->next != head)
        p = p->next;
    p->next = temp;
    temp->prev = p;
    temp->next = head;
    head->prev = temp;
}

void Display(struct Node *head)
{
    printf("The data in the List is:\n");
    struct Node *p = head;
    do
    {
        printf("%d  ", p->data);
        p = p->next;

    } while (p != head);
}

struct Node *freeList(struct Node *head)
{
    struct Node *last = moveToLast(head);
    struct Node *p = head;
    do
    {
        head = head->next;
        free(p);
        p = head;

    } while (head != last);
    free(last);
    head = 0;
    printf("The List is freed Successfully!\n");
    return head;
}

struct Node *moveToLast(struct Node *head)
{
    struct Node *p = head;
    while (p->next != head)
        p = p->next;
    return p;
}

struct Node *insertNode(struct Node *head)
{
    int pos = 0;
    printf("Input the position:\n");
    scanf("%d", &pos);
    if (pos == 0)
    {
        struct Node *temp = createNode();
        temp->next = head;
        head->prev->next = temp;
        temp->prev = head->prev;
        head->prev = temp;
        head = temp;
        printf("Insertion is successfull!\n");
        return head;
    }
    else
    {
        struct Node *p = head;
        struct Node *temp = createNode();
        for (int i = 0; i < pos - 1; ++i)
            p = p->next;
        temp->next = p->next;
        temp->prev = p;
        if (p->next)
            p->next->prev = temp;
        p->next = temp;

        return head;
    }
}