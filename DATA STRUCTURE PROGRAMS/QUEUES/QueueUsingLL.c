//QUEUE USING LINKED LIST



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
    Node *front, *rear;
} Queue;

void freeQueue(Queue*);
void displayQueue(Queue*);
bool isFull();
bool isEmpty(Queue*);
Node* createNode();
Queue* createQueue();
void Enqueue (Queue*);
Node* Dequeue(Queue*);

int main(int argc, char const *argv[])
{
    
    Queue* queue=NULL;
    int choice=0,aux=0;

    while(1){
        printf("Input 1 for creating Queue!\n");
        printf("Input 2 for ENqueue!\n");
        printf("Input 3 for Dequeue!\n");
        printf("Input 4 for Displaying the Queue!\n");
        printf("Input 5 for Exiting!\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                queue=createQueue();
                break;
            case 2:
                Enqueue(queue);
                break;
            case 3:
                queue->front=Dequeue(queue);
                break;
            case 4:
                displayQueue(queue);
                break;
            case 5:
                freeQueue(queue);
                exit(EXIT_SUCCESS);
            default:
                printf("Wrong choice !\n");
        }
    }



    return 0;
}



Node *createNode()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Input the data!\n");
    scanf("%d", &temp->data);
    temp->next = 0;
    return temp;
}

Queue *createQueue()
{
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    temp->front = temp->rear = createNode();
    return temp;
}

bool isFull()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        free(temp);
        return true;
    }
    free(temp);
    return false;
}

bool isEmpty(Queue* queue){
    if(queue->front==0)
        return true;
    return false;
}

void Enqueue(Queue* queue){
    if(queue->front==0)
        printf("Create the Queue again!\n");
    else{
        if(isFull()!=true)
        {
            Node* temp=createNode();
            queue->rear->next=temp;
            queue->rear=queue->rear->next;
        }
        else{
            printf("QueueOverFlow!\n");
        }
    }
}

Node* Dequeue(Queue*queue){
    Node *p=NULL;
    if(isEmpty(queue)!=true){
        p=queue->front;
        queue->front=queue->front->next;
       p->data;
        printf("Element %d is Dequeued!\n",p->data);
        free(p);
        return queue->front;

    }
    else{
        printf("QueueUnderFlow!\n");
        return queue->front;
    }
}

void freeQueue(Queue*queue){
    Node* p=NULL;
    while(queue->front!=0){
        p=queue->front;
        queue->front=queue->front->next;
        free(p);
    }
    free(queue);
}

void displayQueue(Queue*queue){
    Node*p=queue->front;
    if(isEmpty(queue)==true)
        printf("QueueEmpty!\n");
    else{
        printf("The elements in the Queue are :\n");
        while(p!=0){
            printf("%d  ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}