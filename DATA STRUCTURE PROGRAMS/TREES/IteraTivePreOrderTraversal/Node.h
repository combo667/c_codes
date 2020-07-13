#ifndef NODE
#define NODE

typedef struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
}Node;

#endif