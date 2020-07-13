#include <stdio.h>
#include <stdlib.h>

enum COLOR
{
    Red,
    Black
};

typedef struct tree_node
{
    int data;
    struct tree_node *lchild, *rchild, *parent;
    enum COLOR color;

} tree_node;

typedef struct red_black_tree
{
    tree_node *NIL, *root;

} red_black_tree;

tree_node *new_tree_node(int data)
{
    tree_node *t = (tree_node *)malloc(sizeof(tree_node));
    t->parent = t->rchild = t->lchild = NULL;
    t->data = data;
    t->color = Red;

    return t;
}

red_black_tree *new_red_black_tree()
{
    red_black_tree *t = (red_black_tree *)malloc(sizeof(red_black_tree));
    tree_node *nil_node = (tree_node *)malloc(sizeof(tree_node));

    nil_node->lchild = nil_node->rchild = nil_node->parent = NULL;
    nil_node->data = 0;
    nil_node->color = Black;
    t->NIL = nil_node;
    t->root = t->NIL;

    return t;
}

void left_rotate(red_black_tree *t, tree_node *x)
{
    tree_node *y = x->rchild;
    x->rchild = y->lchild;
    if (y->lchild != t->NIL)
        y->lchild->parent = x;
    y->parent = x->parent;
    if (x->parent == t->NIL)
    {
        t->root = y;
    }
    else if (x == x->parent->lchild)
        x->parent->lchild = y;
    else
        x->parent->rchild = y;

    y->lchild = x;
    x->parent = y;
}

void right_rotate(red_black_tree *t, tree_node *x)
{
    tree_node *y = x->lchild;
    x->lchild = y->rchild;
    if (y->rchild != t->NIL)
        y->rchild->parent = x;
    y->parent = x->parent;
    if (x->parent == t->NIL)
        t->root = y;
    else if (x == x->parent->rchild)
    {
        x->parent->rchild = y;
    }
    else
        x->parent->lchild = y;

    y->rchild = x;
    x->parent = y;
}

void Fixit(red_black_tree *t, tree_node *z)
{
    while (z->parent->color == Red)
    {
        if (z->parent == z->parent->parent->lchild)
        {
            tree_node *y = z->parent->parent->rchild;

            if (y->color == Red)
            {
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->rchild)
                {

                    z = z->parent;
                    left_rotate(t, z);
                }
                z->parent->color = Black;
                z->parent->parent->color = Red;
                right_rotate(t, z->parent->parent);
            }
        }

        else
        {
            tree_node *y = z->parent->parent->lchild;

            if (y->color == Red)
            {
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->lchild)
                {
                    z = z->parent;
                    right_rotate(t, z);
                }
                z->parent->color = Black;
                z->parent->parent->color = Red;
                left_rotate(t, z->parent->parent);
            }
        }
    }

    t->root->color = Black;
}

void insert(red_black_tree *t, tree_node *z)
{
    tree_node *y = t->NIL;
    tree_node *temp = t->root;

    while (temp != t->NIL)
    {
        y = temp;
        if (z->data < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }

    z->parent = y;

    if (y == t->NIL)
        t->root = z;
    else if (z->data < y->data)
        y->lchild = z;
    else
        y->rchild = z;

    z->rchild = t->NIL;
    z->lchild = t->NIL;

    Fixit(t, z);
}

void inorder(red_black_tree *t, tree_node *n)
{
    if (n != t->NIL)
    {
        inorder(t, n->lchild);
        printf("%d  ", n->data);
        inorder(t, n->rchild);
    }
}

int main(int argc, char const *argv[])
{
    red_black_tree *t = new_red_black_tree();

    tree_node *tree = NULL;
    int times, num;
    printf("Input the number of Nodes:\n");
    scanf("%d", &times);
    for (int i = 0; i < times; i++)
    {
        printf("Input the data!\n");
        scanf("%d", &num);
        tree = new_tree_node(num);
        insert(t, tree);
    }

    printf("The tree looks like:\n");
    inorder(t, t->root);
    printf("\n");

    return 0;
}
