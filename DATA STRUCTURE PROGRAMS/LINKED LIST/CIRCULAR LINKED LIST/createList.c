#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
void Display(struct Node *);
void insertNode(struct Node *);
struct Node *createNode();
void RDisplay(struct Node *, struct Node *);
struct Node *moveToLast(struct Node *);
void freeList(struct Node *);

int main(void)
{
    struct Node *p;
    p = createNode();
    insertNode(p);
    insertNode(p);
    insertNode(p);
    insertNode(p);
    RDisplay(p, p);
    freeList(p);
    return 0;
}

struct Node *createNode()
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    printf("Input the Data:\n");
    scanf("%d", &p->data);
    p->link = p; //linked to self
}

void insertNode(struct Node *head)
{
    struct Node *p, *temp;
    p = head;
    do
    {
        p = p->link;

    } while (p->link != head);
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Input the Data:\n");
    scanf("%d", &temp->data);
    p->link = temp;
    temp->link = head;
    printf("Node inserted Successfully!\n");
}

void freeList(struct Node *head)
{
    struct Node *p, *q, *last;
    p = q = head;
    last = moveToLast(head);
    do
    {
        q = q->link;
        free(p);
        p = q;

    } while (q != last);

    free(last);
    printf("List Freed Successfully!\n");
}

void Display(struct Node *head)
{
    struct Node *p;
    p = head;
    printf("The Data in the linked list is :\n");
    do
    {
        printf("%d  ", p->data);
        p = p->link;

    } while (p != head);
    printf("\n");
}

void RDisplay(struct Node *head, struct Node *p)
{

    static int flag = 0;
    if (p != head || flag != 1)
    {
        flag = 1;
        printf("%d  ", p->data);
        RDisplay(head, p->link);
    }
    //flag=0;
}

struct Node *moveToLast(struct Node *head)
{
    struct Node *last;
    last = head->link;
    do
    {
        last = last->link;
    } while (last->link != head);
    return last;
}