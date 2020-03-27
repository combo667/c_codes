//THIS IS AN IMPLEMENTATION OF STACK WITH THE HELP OF STRUCTURE AND DMA!

#include <stdio.h>
#include <stdlib.h>
struct arr_struct
{
    int top,capacity;
    int *array;
};

struct arr_struct * createStack(int cap){

    struct arr_struct *stack;
    stack=(struct arr_struct*)malloc(sizeof(struct arr_struct));
    stack->capacity=cap;
    stack->top=-1;
    stack->array=(int*)malloc(sizeof(int)*cap);

    return stack;

}

int isFull(struct arr_struct *stack){
    if(stack->top==stack->capacity-1)
        return 1;
    else
        return 0;

}

int isEmpty(struct arr_struct *stack){
    if(stack->top==-1)
        return 1;
    else
    {
        return 0;
    }
    

}

void PUSH(struct arr_struct *stack,int item){

    if(!isFull(stack)){
        stack->top++;
        stack->array[stack->top]=item;
        
    }
   

}


int POP(struct arr_struct *stack){
    int item;

    if(!isEmpty(stack)){
        item=stack->array[stack->top];
        stack->top--;
        return item;

    }
    else
    {
        return -1;
    }
    


}

int main(void){
int item,choice;

struct arr_struct *stack;
stack=createStack(5);
while(1){
printf("Please input your choice :\n");
printf("1. For PUSH\n");
printf("2. For POP\n");
printf("3. For Exiting\n");
scanf("%d",&choice);


switch (choice)
{
case 1:
    if(!isFull(stack)){
    printf("Input the item which you want to insert :\n");
    scanf("%d",&item);
    PUSH(stack,item);}
    else
    {
        printf("The stack is already full ! Please pop out some items.\n");
    }
    
    break;

case 2:
    item=POP(stack);
    if(item==-1)
        printf("The stack is empty!\n");
    else
        printf("The popped item is : %d\n",item);
    break;

case 3:
    free(stack);
    exit(0);
    break;


}


}




    return 0;
}