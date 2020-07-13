//DOUBLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    struct Node *next;
    int data;
};

struct Node *createNode();
void appendNode(struct Node *);
int countNodes(struct Node *);
void displayNode(struct Node *);
struct Node *freeList(struct Node *);
void reverseDisplay(struct Node *);
struct Node *moveToLast(struct Node *);
struct Node *insertNode(struct Node *);
struct Node *reverseList(struct Node *);

int main(void)
{
    struct Node *head = 0;
    int choice = 0;

    while (1)
    {
        printf("Please input your choice accordingly!\n");
        printf("Input 1 for creating the List!\n");
        printf("Input 2 for appending Nodes to the LinkedList!\n");
        printf("Input 3 for Displaying the List!\n");
        printf("Input 4 for showing the total number of Nodes created!\n");
        printf("Input 5 for displaying the list in reverse!\n");
        printf("Input 6 for inserting a Node!\n");
        printf("Input 7 for reversing the list!\n");
        printf("Input 8 for exiting !\n");

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
            displayNode(head);
            break;
        case 4:
            printf("The number of Nodes are :%d \n", countNodes(head));
            break;
        case 5:
            reverseDisplay(head);
            break;
        case 6:
            head = insertNode(head);
            break;
        case 7:
            head = reverseList(head);
            break;
        case 8:
            head = freeList(head);
            exit(20);

        default:
            printf("You made a wrong choice!\n");
        }
    }

    return 0;
}

struct Node *createNode()
{
    int data = 0;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Input the data:\n");
    scanf("%d", &data);
    temp->data = data;
    temp->next = temp->prev = 0;

    return temp;
}

void appendNode(struct Node *head)
{
    struct Node *p, *temp;
    if (head != 0)
    {
        p = head;
        temp = createNode();
        while (p->next != 0)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    else
    {
        printf("Please create the Node first!\n");
    }
}

void displayNode(struct Node *head)
{

    if (head != 0)
    {
        printf("The data in the Linked List is :\n");
        while (head != 0)
        {
            printf("%d  ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    else
    {
        printf("PLease create the Linked List First!\n");
    }
}

int countNodes(struct Node *head)
{
    if (head != 0)
    {
        int count = 0;
        do
        {
            ++count;
            head = head->next;
        } while (head);
        return count;
    }
    else
    {
        printf("The List is Empty!\n");
        return -1;
    }
}

struct Node *freeList(struct Node *head)
{
    struct Node *p;
    p = head;
    while (head)
    {
        head = head->next;
        free(p);
        p = head;
    }
    printf("The list is freed successfully!\n");
    return head;
}

void reverseDisplay(struct Node *head)
{
    struct Node *p;
    if (head != 0)
    {
        printf("The Elements in reverse order is :\n");
        p = moveToLast(head);
        do
        {
            printf("%d ", p->data);
            p = p->prev;
        } while (p != 0);
        printf("\n");
    }
    else
    {
        printf("The List is empty!\n");
    }
}

struct Node *moveToLast(struct Node *head)
{
    do
    {
        head = head->next;

    } while (head->next != 0);
    return head;
}

struct Node *insertNode(struct Node *head)
{
    int pos = 0;

    if (head != 0)
    {
        printf("Input the position on which you want to insert!\n");
        scanf("%d", &pos);
        struct Node *temp;
        temp = createNode();
        if (pos == 0)
        {
            temp->next = head;
            head->prev = temp;

            head = temp;
            printf("Node inserted Successfully!\n");
            return head;
        }
        else if (pos > 0 && pos <= countNodes(head))
        {
            struct Node *p = head;
            for (int i = 0; i < pos - 1; ++i)
                p = p->next;
            temp->next = p->next;
            temp->prev = p;
            if (p->next)
                p->next->prev = temp;
            p->next = temp;
            printf("Node inserted successfully!\n");
            return head;
        }
    }
    else
    {
        printf("Please create the List first!\n");
        return 0;
    }
}

struct Node *reverseList(struct Node *Head)
{
    if (Head->next != 0)
    {
        struct Node *p = Head, *temp = 0;
        while (p)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            if (p->prev == 0)
                Head = p;
            p = p->prev;
        }
        printf("The List is reversed Successfully!\n");

        return Head;
    }
    else
    {
        printf("Please create the List with atleast two elements!\n");
        return Head;
    }
}