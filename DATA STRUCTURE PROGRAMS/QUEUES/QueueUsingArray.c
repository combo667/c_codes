#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int Front, Rear, Size;
    int *Array;
} Queue;

Queue *createQueue();
int Dequeue(Queue *);
void Enqueue(Queue *, int);
bool isEmpty(Queue *);
bool isFull(Queue *);
void freeQueue(Queue *);
void displayQueue(Queue*);

int main(int argc, char const *argv[])
{

    Queue *queue = createQueue();
    int choice = 0, aux = 0;
    while (1)
    {
        printf("Input 1 for Enqueue!\n");
        printf("Input 2 for Dequeue!\n");
        printf("Input 3 for checking whether the queue is Full or Empty!\n");

        printf("Input 4 for Displaying the Queue!\n");
        printf("Input 5 for exiting!\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input the element to be enqueued!\n");
            scanf("%d", &aux);
            Enqueue(queue, aux);
            break;
        case 2:
            aux = Dequeue(queue);
            printf("The Element %d was dequeued!\n", aux);
            break;
        case 3:
            if (isFull(queue)==true)
                printf("Queue is FUll!\n");
            else
                printf("Queue is Empty!\n");
            break;
        case 4:
            displayQueue(queue);
            break;
        case 5:
            freeQueue(queue);
            exit(EXIT_SUCCESS);
        default:
            printf("Wrong choice !\n");
            break;
        }
    }

    return 0;
}

Queue *createQueue()
{
    Queue *temp = NULL;
    temp = (Queue *)malloc(sizeof(Queue));
    printf("Input the size of the Queue!\n");
    scanf("%d", &temp->Size);
    temp->Array = (int *)malloc(sizeof(int) * temp->Size);
    temp->Front = temp->Rear = -1;
    return temp;
}

bool isFull(Queue *queue)
{
    if (queue->Rear == queue->Size - 1)
        return true;
    return false;
}

bool isEmpty(Queue *queue)
{
    if (queue->Front == queue->Rear)
        return true;
    return false;
}

void Enqueue(Queue *queue, int element)
{
    if (isFull(queue) != true)
    {
        queue->Rear++;
        queue->Array[queue->Rear] = element;
    }
    else
    {
        printf("Queue OverFlow!\n");
    }
}

int Dequeue(Queue *queue)
{
    int x = -1;
    if (isEmpty(queue) != true)
    {
        queue->Front++;
        x = queue->Array[queue->Front];
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
    free(queue->Array);
    free(queue);
}

void displayQueue(Queue *queue)
{
    int p=queue->Front;
    printf("The Queue Looks like:\n");
    if (isEmpty(queue) == false)
    {
        while (p < queue->Rear)
        {
            p++;
            printf("%d ", queue->Array[p]);
        }
        printf("\n");
    }
    else
    {
        printf("Queue is Empty!\n");
    }
}