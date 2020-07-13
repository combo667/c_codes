#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;

typedef struct Queue
{
    int Size, Front, Rear;
    Node **array;
} Queue;

bool isEmptyQueue(Queue *);
bool isFullQueue(Queue *);
void Enqueue(Queue *, Node *);
Node *Dequeue(Queue *);
Queue *createQueue();
void freeQueue(Queue *);

Queue *createQueue()
{
    Queue *temp = NULL;
    temp = (Queue *)malloc(sizeof(Queue));
    printf("Input the Size of the Queue!\n");
    scanf("%d", &temp->Size);
    temp->array = (Node **)malloc(sizeof(Node*) * temp->Size);
    temp->Front = temp->Rear = 0;
    return temp;
}

bool isFullQueue(Queue *q)
{
    if ((q->Rear + 1) % q->Size == q->Front)
        return true;
    return false;
}
bool isEmptyQueue(Queue *queue)
{
    if (queue->Rear == queue->Front)
        return true;
    return false;
}

void Enqueue(Queue *queue, Node *node)
{
    if (isFullQueue(queue) != true)
    {
        queue->Rear = (queue->Rear + 1) % queue->Size;
        queue->array[queue->Rear] = node;
    }
    else
    {
        printf("QueueOverFlow\n");
    }
}

Node * Dequeue(Queue *queue)
{
    Node *x = NULL;
    if (isEmptyQueue(queue) != true)
    {
        queue->Front = (queue->Front + 1) % queue->Size;
        x = queue->array[queue->Front];
        return x;
    }
    else
    {
        printf("Queue Underflow!\n");
    }
    return x;
}

void freeQueue(Queue *queue)
{
    free(queue->array);
    free(queue);
}