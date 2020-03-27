#include <stdio.h>
#include <stdlib.h>

struct array_stack{
    int top,capacity;
    int *arr;

};

struct array_stack* create_stack(int cap){


    struct array_stack *stack;
    

    stack=(struct array_stack*)malloc(sizeof(struct array_stack));
    stack->capacity=cap;
    stack->top=-1;
    stack->arr=(int*)malloc(sizeof(int)*cap);

    return stack;


}

int isfull(struct array_stack *stack){

    if(stack->top==stack->capacity-1)
        return 1;
    else
    {
        return 0;
    }
    

}

int isempty(struct array_stack *stack){

    if(stack->top==-1)
        return 1;
    else
        return 0;
}

void PUSH(struct array_stack *stack,int item){

    if(!isfull(stack)){
        stack->top++;
        stack->arr[stack->top]=item;

    }


}
int POP(struct array_stack *stack){
    int item;
    if(!isempty(stack)){
        item=stack->arr[stack->top];
        stack->top--;
        return item;
    }
    else
        return -1;

}

int main(void){
int item,choice,size;
struct array_stack *stack;
printf("INPUT THE SIZE OF ARRAY YOU WANT :\n");
scanf("%d",&size);
stack=create_stack(size);
while(1){

printf("INPUT YOUR CHOICE :\n");
printf("INPUT 1 FOR PUSH.\n");
printf("INPUT 2 FOR POP.\n");
printf("INPUT 3 FOR EXIT\n");
scanf("%d",&choice);
switch(choice){
    case 1:
        printf("Input the value to be pushed !\n");
        scanf("%d",&item);
        PUSH(stack,item);
        break;
    case 2:
        item=POP(stack);
        if(item==-1)
            printf("The stack is already empty!\n");
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
