#ifndef STACK
#define STACK

#include "Node.h"

typedef struct Stack
{
    int Top;
    int Size;
    Node **array;
}Stack;

#endif