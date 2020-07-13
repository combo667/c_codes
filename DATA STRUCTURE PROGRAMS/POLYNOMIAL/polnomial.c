#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int terms;
    struct Term *ptr;
};

struct Poly *createPoly();
void input(struct Poly *);
void display(struct Poly *);
struct Poly *add(struct Poly *, struct Poly *);

int main(void)
{

    struct Poly *p;
    struct Poly *q;
    struct Poly *p3;
    p = createPoly();
    q = createPoly();

    p3 = add(p, q);
    printf("The addition of the two polynomials is :\n");
    display(p3);

    free(p->ptr);

    free(p);
    free(q->ptr);
    free(q);
    free(p3->ptr);
    free(p3);
    return 0;
}

struct Poly *createPoly()
{
    struct Poly *p;
    p = (struct Poly *)malloc(sizeof(struct Poly));
    printf("Input the number of terms in the polynomial:\n");
    scanf("%d", &p->terms);
    p->ptr = (struct Term *)malloc(sizeof(struct Term) * p->terms);

    input(p);

    return p;
}

void input(struct Poly *p)
{
    for (int i = 0; i < p->terms; i++)
    {
        printf("Input the term %d coefficient and exponent value!", i + 1);
        scanf("%d%d", &p->ptr[i].coeff, &p->ptr[i].exp);
    }
}

void display(struct Poly *p)
{
    printf("The Polynomial is :\t");
    for (int i = 0; i < p->terms; i++)
    {
        printf("%dx^%d", p->ptr[i].coeff, p->ptr[i].exp);
        if ((i + 1) != p->terms)
            printf("+");
        else
            printf("\n");
    }
    // printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    struct Poly *p3;
    int i = 0, j = 0, k = 0;
    p3 = (struct Poly *)malloc(sizeof(struct Poly));
    p3->ptr = (struct Term *)malloc(sizeof(struct Term) * (p1->terms + p2->terms));

    while (i < p1->terms && j < p2->terms)
    {

        if (p1->ptr[i].exp > p2->ptr[j].exp)
            p3->ptr[k++] = p1->ptr[i++];
        else if (p1->ptr[i].exp < p2->ptr[j].exp)
            p3->ptr[k++] = p2->ptr[j++];
        else
        {
            p3->ptr[k].exp = p1->ptr[i].exp;
            p3->ptr[k++].coeff = p1->ptr[i++].coeff + p2->ptr[j++].coeff;
        }
    }

    for (; i < p1->terms; i++)
    {
        p3->ptr[k++] = p1->ptr[i];
    }
    for (; j < p2->terms; j++)
    {
        p3->ptr[k++] = p2->ptr[j];
    }

    p3->terms = k;

    return p3;
}