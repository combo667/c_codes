#include <stdbool.h>
#include "Node.h"
#include "Queue.h"



bool isEmptyQueue(Queue *);
bool isFullQueue(Queue *);
void Enqueue(Queue *, Node *);
Node *Dequeue(Queue *);
Queue *createQueue();
void freeQueue(Queue *);