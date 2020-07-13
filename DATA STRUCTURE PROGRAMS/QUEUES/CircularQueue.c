#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int Size, Front, Rear;
    int *array;
} Queue;

void displayQueue(Queue *);
bool isEmpty(Queue *);
bool isFull(Queue *);
void Enqueue(Queue *, int);
int Dequeue(Queue *);
Queue *createQueue();
void freeQueue(Queue *);

int main(int argc, char const *argv[])
{

    int choice = 0;
    int aux = 0;
    Queue *queue = createQueue();

    while (1)
    {
        printf("Input 1 for Enqueue!\n");
        printf("Input 2 for Dequeue!\n");
        printf("Input 3 for Displaying the Queue!\n");
        printf("Input 4 for Exiting out!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element!\n");
            scanf("%d", &aux);
            Enqueue(queue, aux);
            break;
        case 2:
            aux = Dequeue(queue);
            printf("The element %d is dequeued!\n", aux);
            break;
        case 3:
            displayQueue(queue);
            break;
        case 4:
            freeQueue(queue);
            exit(EXIT_SUCCESS);
        default:
            printf("Wrong choice made !\n");
            break;
        }
    }

    return 0;
}

Queue *createQueue()
{
    Queue *temp = NULL;
    temp = (Queue *)malloc(sizeof(Queue));
    printf("Input the Size of the Queue!\n");
    scanf("%d", &temp->Size);
    temp->array = (int *)malloc(sizeof(int) * temp->Size);
    temp->Front = temp->Rear = 0;
    return temp;
}

bool isFull(Queue *q)
{
    if ((q->Rear + 1) % q->Size == q->Front)
        return true;
    return false;
}
bool isEmpty(Queue *queue)
{
    if (queue->Rear == queue->Front)
        return true;
    return false;
}

void Enqueue(Queue *queue, int element)
{
    if (isFull(queue) != true)
    {
        queue->Rear = (queue->Rear + 1) % queue->Size;
        queue->array[queue->Rear] = element;
    }
    else
    {
        printf("QueueOverFlow\n");
    }
}

int Dequeue(Queue *queue)
{
    int x = -1;
    if (isEmpty(queue) != true)
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

void displayQueue(Queue *queue)
{
    if (isEmpty(queue) != true)
    {
        printf("The Queue Looks Like!\n");
        int p = queue->Front + 1;
        do
        {
            printf("%d  ", queue->array[p]);
            p = (p + 1) % queue->Size;

        } while (p != (queue->Rear + 1) % queue->Size);
        printf("\n");
    }
    else
    {
        printf("Queue is Empty Nothing to Display!\n");
    }
}

void freeQueue(Queue *queue)
{
    free(queue->array);
    free(queue);
}