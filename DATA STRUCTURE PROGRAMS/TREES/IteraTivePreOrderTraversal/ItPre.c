
#include "ArrayStack.h"
#include <stdlib.h>
#include <stdio.h>

void IterativePreOrder(Node*);

int main(int argc, char const *argv[])
{
    Node *root=createTree();
    printf("The Looks  like:\n");
    IterativePreOrder(root);
    

    return 0;
}

void IterativePreOrder(Node *root){
    Stack *stack=createStack();

    Node* traverse=root;

    while(traverse!=0||isEmptyStack(stack)!=true){
        if(traverse!=0){
        printf("%d  ",traverse->data);
        Push(stack,traverse);
        traverse=traverse->lchild;
        }
        else{
            traverse=Pop(stack);
            traverse=traverse->rchild;
        }
    }

    freeStack(stack);

}
