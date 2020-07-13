#include "Node.h"
#include "Stack.h"



bool isEmptyStack(Stack *);
bool isFullStack(Stack *);
void freeStack(Stack *);
struct Stack *createStack();
void Push(Stack *, Node *);
Node *Pop(Stack *);
int stackTop(Stack*);
