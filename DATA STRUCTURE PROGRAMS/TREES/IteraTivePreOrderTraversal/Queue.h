#ifndef QUEUE
#define QUEUE

typedef struct Queue
{
    int Size, Front, Rear;
    Node **array;
} Queue;

#endif