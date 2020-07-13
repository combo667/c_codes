#include <stdio.h>
#include "CircularQueue.h"
#include <stdbool.h>
#include <stdlib.h>

Node *createNode();
Node *createTree();



Node *createNode()
{
    Node *temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = 0;
    temp->rchild = temp->lchild = 0;
    return temp;
}

Node *createTree()
{

    Node *root = createNode();
    Queue *queue = createQueue();
    int x = 0;
    Node *p = NULL, *temp = NULL;

    printf("Input the Root Node value!\n");
    scanf("%d", &x);
    root->data = x;
    Enqueue(queue, root);
    while (isEmptyQueue(queue) != true)
    {
        p = Dequeue(queue);
        printf("Is left Child Available for Node %d?Input value for Yes or -1 for No!\n",p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            temp = createNode();
            temp->data = x;
            p->lchild = temp;
            Enqueue(queue, temp);
        }
        printf("Is Right Child Available for Node %d ?Input value for Yes or -1 for No!\n",p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            temp = createNode();

            temp->data = x;
            p->rchild = temp;
            Enqueue(queue, temp);
        }
    }

    freeQueue(queue);
    return root;
}
