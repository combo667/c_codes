//THIS IS AVL TREE Hahahahahahaha.......  :)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
    int height;
} *root = NULL;

typedef struct Node Node;

Node *RecursiveBST(Node *, int);
int BalanceFactor(Node *);
int NodeHeight(Node *);
Node *LLRotation(Node *);
Node *LRRotation(Node *);
Node *RLRotation(Node *);
Node *RRRotation(Node *);
void Display(Node *);

int main(int argc, char const *argv[])
{

    root = RecursiveBST(root, 10);
    RecursiveBST(root, 20);
    RecursiveBST(root, 30);
    RecursiveBST(root, 25);
    RecursiveBST(root, 28);
    RecursiveBST(root, 27);
    RecursiveBST(root, 5);

    printf("The tree looks like :\n");

    Display(root);
}

void Display(Node *root)
{

    //preorder traversal
    if (root != NULL)
    {

        printf("%d  ", root->data);
        Display(root->lchild);
        Display(root->rchild);
    }
}

Node *RecursiveBST(Node *p, int key)
{
    if (p == NULL)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = key;
        temp->lchild = temp->rchild = NULL;
        temp->height = 1;
        return temp;
    }

    if (key < p->data)
    {
        p->lchild = RecursiveBST(p->lchild, key);
    }

    else
    {
        p->rchild = RecursiveBST(p->rchild, key);
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);

    return p;
}

Node *LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

Node *RRRotation(Node *p)
{

    Node *pl = p->rchild;
    Node *prl = pl->lchild;

    pl->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    if (root == p)
        root = plr;
    return plr;
}

Node *RLRotation(Node *p)
{

    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

int NodeHeight(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}