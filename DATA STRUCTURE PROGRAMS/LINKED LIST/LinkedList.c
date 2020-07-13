#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *createNode();
void display(struct Node *);
void insertNode(struct Node *);
void freeList(struct Node *);
void Sum(struct Node *);
int RSum(struct Node *);
void MaximumElement(struct Node *);
struct Node *introduceNode(struct Node *);
struct Node *reverseList(struct Node *);
struct Node *deleteNode(struct Node *);
int count(struct Node *);

int main(void)
{

    int choice = 0, aux = 0;

    struct Node *p = NULL;

    while (1)
    {
        printf("\n");
        printf("Please Input your choice Accordingly!\n");
        printf("Input 1 for creating the first Node :\n");
        printf("Input 2 for inserting more Nodes!\n");
        printf("Input 3 for displaying the Nodes !\n");
        printf("Input 4 for Calculating the Sum of all elements !\n");
        printf("Input 5 for Calculating the maximum of all elements !\n");
        printf("Input 6 for introducing a Node in between !\n");
        printf("Input 7 for Reversing the List!\n");
        printf("Input 8 for deleting a Node from List!\n");
        printf("Input 9 for displaying the number of Nodes Created!\n");
        printf("Input 10 for Exit!\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            p = createNode();
            break;
        case 2:
            insertNode(p);
            break;
        case 3:
            display(p);
            break;
        case 4:
            aux = RSum(p);
            printf("The sum is :%d", aux);
            break;
        case 5:
            MaximumElement(p);
            break;
        case 6:
            p = introduceNode(p);
            break;
        case 7:
            p = reverseList(p);
            break;
        case 8:
            p = deleteNode(p);
            break;
        case 9:
            printf("The total number of Nodes are :%d\n",count(p));
            break;
        case 10:
            freeList(p);
            exit(23);
            break;
        default:
            printf("You have made a wrong choice !\n");
        }
    }

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

void Sum(struct Node *p)
{

    int sum = 0;
    while (p != 0)
    {
        sum = sum + p->data;
        p = p->link;
    }
    printf("\n");
    printf("The sum of all the elements is %d:\n", sum);
}

int RSum(struct Node *p)
{
    if (p == 0)
        return 0;
    return p->data + RSum(p->link);
}

void MaximumElement(struct Node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->link;
    }
    printf("The maximum element in the Linked List  is %d:\n", max);
}

struct Node *introduceNode(struct Node *p)
{
    struct Node *temp, *aux;
    int index = 0;
    temp = createNode();

    printf("Input the index of the Node to get inserted!\n");
    scanf("%d", &index);
    if (index == 0)
    {

        temp->link = p;
        p = temp;
        return p;
    }
    else
    {

        aux = p;
        for (int i = 0; i < index - 1 && aux; ++i)
        {
            aux = aux->link;
        }
        if (p)
        {
            temp->link = aux->link;
            aux->link = temp;
        }

        return p;
    }
}

struct Node *reverseList(struct Node *first)
{
    if (first)
    {
        struct Node *p = first, *q = NULL, *r = NULL;

        while (p)
        {
            r = q;
            q = p;
            p = p->link;
            q->link = r;
        }
        first = q;

        printf("The list is reversed Successfully!\n");
        return first;
    }
    else
    {
        printf("The list is empty!Nothing to reverse!\n");
        return 0;
    }
}

struct Node *deleteNode(struct Node *first)
{

    int position = 0;
    struct Node *aux;
    struct Node *p;

    if (first)
    {
        printf("Input the position you want to delete!\n");
        scanf("%d", &position);
        if (position == 1)
        {
            aux = first;
            first = first->link;
            free(aux);
            return first;
        }
        else if (position > 1 || position <= count(first))
        {
            p = first;
            aux = NULL;
            for (int i = 0; i < position - 1; i++)
            {
                aux = first;
                first = first->link;
            }
            aux->link = first->link;
            free(first);
            return p;
        }
        else
        {
            printf("The input position is Invalid !\n");
        }
    }
    else
    {
        printf("Please create the List First!\n");
        return 0;
    }
}

int count(struct Node *p)
{
    if (p == 0)
        return 0;
    return count(p->link) + 1;
}