//DOUBLE ENDED QUEUE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DEqueue
{
    int front, rear;
    int *array;
    int Size;

} Dequeue;

Dequeue* createQueue();
bool isFull(Dequeue*);
bool isEmpty(Dequeue*);
void insertFront(Dequeue*,int);
void insertRear(Dequeue*,int);
void deleteRear(Dequeue*);
void deleteFront(Dequeue*);
void freeQueue(Dequeue*);
int getFront(Dequeue*);
int getRear(Dequeue*);
void displayDequeue(Dequeue*dequeue);


int main(int argc, char const *argv[])
{
    int choice=0;
    int aux; Dequeue* dequeue=NULL;
    while(1){
        printf("Input 1 for creating Dequeue!\n");
        printf("Input 2 for Insertfront!\n");
        printf("Input 3 for InsertRear!\n");
        printf("Input 4 for DeleteFront!\n");
        printf("Input 5 for DeleteRear!\n");
        printf("Input 6 for Displaying the Queue!\n");
        printf("Input 7 for exit!\n");
        printf("Input 8 for Showcasing the rearmost element\n");
        printf("Input 9 for Showcasing the front element!\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                dequeue=createQueue();
                break;
            case 2:
                printf("Input the element!\n");
                scanf("%d",&aux);
                insertFront(dequeue,aux);
                break;
            case 3:
                printf("Input the element!\n");
                scanf("%d",&aux);
                insertRear(dequeue,aux);
                break;
            case 4:
                deleteFront(dequeue);
                break;
            case 5:
                deleteRear(dequeue);
                break;
            case 6:
                displayDequeue(dequeue);
                break;
            case 7:
                freeQueue(dequeue);
                exit(EXIT_SUCCESS);
            case 8:
                aux=getRear(dequeue);
                printf("The rear element is :%d\n",aux);
                break;
            case 9:
                aux=getFront(dequeue);
                printf("The front element is :%d\n ",aux);
                break;
            default:
                printf("Wrong Choice!\n");


        }
    }
    return 0;
}


bool isFull(Dequeue *dequeue)
{
    if ((dequeue->front == 0 && dequeue->rear == dequeue->Size - 1) || (dequeue->front == dequeue->rear + 1))
        return true;
    return false;
}

bool isEmpty(Dequeue *dequeue)
{
    if (dequeue->front == -1)
        return true;
    return false;
}

Dequeue *createQueue()
{
    Dequeue *temp = NULL;
    temp = (Dequeue *)malloc(sizeof(Dequeue));
    printf("Input the Size of the Queue!\n");
    scanf("%d", &temp->Size);
    temp->array = (int *)malloc(sizeof(int) * temp->Size);
    temp->front = temp->rear = -1;
    return temp;
}

void insertFront(Dequeue *dequeue, int element)
{
    if (isFull(dequeue)){
        printf("Overflow!\n");
        return;}
    else if (isEmpty(dequeue))
        dequeue->front = dequeue->rear = 0;
    else if (dequeue->front == 0)
        dequeue->front = dequeue->Size - 1;
    else
    {
        dequeue->front -= 1;
    }

    dequeue->array[dequeue->front] = element;
}

void insertRear(Dequeue *dequeue, int element)
{
    if (isFull(dequeue))
    {
        printf("Overflow!\n");
        return;
    }
    else if (isEmpty(dequeue))
        dequeue->front = dequeue->rear = 0;
    else if (dequeue->rear == dequeue->Size - 1)
        dequeue->rear = 0;
    else
    {
        dequeue->rear += 1;
    }

    dequeue->array[dequeue->rear] = element;
}

void deleteRear(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        printf("Underflow!\n");
        return;
    }
    else if (dequeue->rear == dequeue->front)
        dequeue->rear = dequeue->front = -1;
    else if (dequeue->rear = 0)
        dequeue->rear = dequeue->Size - 1;
    else
    {
        dequeue->rear -= 1;
    }
}

void deleteFront(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        printf("UnderFlow!\n");
        return;
    }
    else if (dequeue->front == dequeue->rear)
        dequeue->rear = dequeue->front = -1;
    else if (dequeue->front == dequeue->Size - 1)
        dequeue->front = 0;
    else
        dequeue->front += 1;
}

int getFront(Dequeue *dequeue)
{
    return dequeue->array[dequeue->front];
}

int getRear(Dequeue *dequeue)
{
    return dequeue->array[dequeue->rear];
}

void freeQueue(Dequeue*dequeue){
    free(dequeue->array);
    free(dequeue);
    return;
}


void displayDequeue(Dequeue*dequeue){
    if(isEmpty(dequeue))
        printf("EmptyQUeue!\n");

    else
    {
        printf("The Queue Elements are:\n");
        do{
            printf("%d  ",dequeue->array[dequeue->front]);
            dequeue->front=(dequeue->front+1)%dequeue->Size;

        }
        while(dequeue->front<=dequeue->rear);
        printf("\n");
    }
    
}