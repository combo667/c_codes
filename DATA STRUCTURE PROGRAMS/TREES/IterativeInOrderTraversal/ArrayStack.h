#include <stdbool.h>

#include "Stack.h"
#include "Node.h"



bool isEmptyStack(Stack *);
bool isFullStack(Stack *);
void freeStack(Stack *);
struct Stack *createStack();
void Push(Stack *, Node *);
Node *Pop(Stack *);
Node *createTree();