#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

Node *createNode(int element)
{
    Node *temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = element;
    temp->next = NULL;
    return temp;
}

void insertNode(Node **Bins, int element)
{
    Node *p = NULL, *q = NULL;
    Node *temp = createNode(element);
    if (Bins[element % 10] == NULL)
        Bins[element % 10] = temp;
    else
    {
        p = Bins[element % 10];
        while (p != NULL && p->data < element)
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
        {
            Bins[element % 10] = temp;
            temp->next = p;
        }
        else
        {
            if (q->next == NULL)
                q->next = temp;
            else
            {
                temp->next = q->next;
                q->next = temp;
            }
        }
    }
}

bool Search(Node **Bins, int element)
{
    Node *p = NULL;
    p = Bins[element % 10];
    if (p == NULL)
        return false;
    else
    {
        while (p != NULL && p->data != element)
            p = p->next;
        if (p == NULL)
            return false;
        else
            return true;
    }
}

bool Delete(Node **Bins, int element)
{
    Node *p = NULL, *q = NULL;
    if (Search(Bins, element) != true)
        return false;
    else
    {
        p = Bins[element % 10];

        if (Bins[element % 10] == p)
            Bins[element % 10] = NULL;
        else
        {
            while (p->data != element)
            {
                q = p;
                p = p->next;
            }
            if (p->next == NULL)
                q->next = NULL;
            else
            {
                q->next = p->next;
            }

            free(p);
            return true;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node **Bins = NULL;
    int choice = 0;

    int element = 0;

    Bins = (Node **)malloc(sizeof(Node *) * 10);

    for (int i = 0; i < 10; i++)
    {
        Bins[i] = NULL;
    }

    while (1)
    {
        printf("Input 1 for inserting the element!");
        printf("Input 2 for Searching any Element!\n");
        printf("Input 3 for Deleting any Element!\n");
        printf("Input 4 for Exiting out!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element !\n");
            scanf("%d", &element);
            insertNode(Bins, element);
            break;
        case 2:
            printf("Input the element to be searched!\n");
            scanf("%d", &element);
            if (Search(Bins, element))
                printf("Element %d Successfully found!\n", element);
            else
                printf("Searched Element is not found!\n");
            break;
        case 3:
            printf("Input the element you wanna delete!\n");
            scanf("%d", &element);
            Delete(Bins, element);
            break;

        case 4:
            free(Bins);
            printf("Thanks for using my Code :)\n");
            exit(0);
            break;

        default:
            printf("Oops!,wrong Choice!\n");
            break;
        }
    }

    return 0;
}
