#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>

void InOrderTraversal(Node*);


int main(int argc, char const *argv[])
{
    Node *root=createTree();
    InOrderTraversal(root);
    return 0;
}


void InOrderTraversal(Node *root)
{
    Stack *stack = createStack();
    printf("The InOrder Traversal is :\n");
    while (root != 0 || isEmptyStack(stack)!=true)
    {
        if (root != 0)
        {
            Push(stack, root);
            root = root->lchild;
        }
        else{
            root=Pop(stack);
            printf("%d ",root->data);
            root=root->rchild;
        }
    }
}
