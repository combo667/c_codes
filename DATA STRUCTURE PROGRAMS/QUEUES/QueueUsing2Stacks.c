#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{

    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *stack1;
    Node *stack2;
} Queue;

Queue *createQueue();
void Push(Node **, int);
int Pop(Node **);
void enqueue(Queue *, int);
int dequeue(Queue *);
void FreeQueue(Queue *);
void freeNodes(Node **);

int main(int argc, char const *argv[])
{
    Queue *queue = createQueue();

    int choice = 0;
    int aux = 0;

    while (1)
    {
        printf("Input 1 for Enqueue!\n");
        printf("Input 2 for Dequeue!\n");
        printf("Input 3 for exiting out!\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input the data!\n");
            scanf("%d", &aux);
            enqueue(queue, aux);
            break;
        case 2:
            aux = dequeue(queue);
            printf("Element %d is dequeued!\n", aux);
            break;
        case 3:
            FreeQueue(queue);
            exit(EXIT_SUCCESS);
        default:
            printf("Wrong choice!\n");
            break;
        }
    }

    return 0;
}

Queue *createQueue()
{
    Queue *queue = NULL;
    queue = (Queue *)malloc(sizeof(Queue));
    queue->stack1 = queue->stack2 = NULL;
    return queue;
}

void Push(Node **top, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("StackOverFlow!\n");
        exit(EXIT_FAILURE);
    }

    temp->next = *top;
    temp->data = data;
    *top = temp;
}

int Pop(Node **top)
{
    int aux;
    Node *temp = NULL;

    if (*top == NULL)
    {
        printf("StackUnderflow!\n");
        exit(EXIT_FAILURE);
    }

    temp = *top;
    *top = temp->next;
    aux = temp->data;
    free(temp);
    return aux;
}

void enqueue(Queue *queue, int data)
{
    Push(&queue->stack1, data);
}

int dequeue(Queue *queue)
{
    int x = 0;
    if (queue->stack1 == NULL && queue->stack2 == NULL)
    {
        printf("Queue is Empty!\n");
        exit(EXIT_FAILURE);
    }

    if (queue->stack2 == NULL)
    {
        while (queue->stack1 != NULL)
        {
            x = Pop(&queue->stack1);
            Push(&queue->stack2, x);
        }
    }

    x = Pop(&queue->stack2);
    return x;
}

void FreeQueue(Queue *queue)
{
    freeNodes(&queue->stack1);
    freeNodes(&queue->stack2);
    free(queue);
}

void freeNodes(Node **node)
{
    Node *p = NULL, *q = NULL;

    p = *node;

    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
}