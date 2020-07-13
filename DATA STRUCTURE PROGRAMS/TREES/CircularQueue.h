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

bool isEmpty(Queue *);
bool isFull(Queue *);
void Enqueue(Queue *, Node *);
Node *Dequeue(Queue *);
Queue *createQueue();
void freeQueue(Queue *);