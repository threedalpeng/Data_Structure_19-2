#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

typedef struct polyNode *polyPointer;
typedef struct polyNode
{
    int coef;
    int expon;
    polyPointer link;
};
polyPointer a,b;

/* a global variable that points to the first node
of the free nodes list */
polyPointer avail;

polyPointer padd (polyPointer a, polyPointer b)
{
    /* return a polynomial which is the sum of a and b */
    polyPointer c, rear, temp;
    int sum;
    rear = (polyPointer)malloc(sizeof(*rear));
    if (!rear) exit(1);
    c = rear;
    while(a&&b)
    {
        switch (COMPARE(a->expon, b->expon))
        {
            case -1:
                attach(b->coef, b->expon, &rear);
                b = b->link;
                break;
            case 0:
                sum = a->coef + b->coef;
                if (sum) attach(sum, a->expon, &rear);
                a = a->link; b = b->link; break;
            case 1:
                attach(a->coef, a->expon, &rear);
                a = a->link;
        }
    }

    /* copy the rest of list a and list b */
    for (; a; a = a->link) attach(a->coef, a->expon, &rear);
    for (; b; b = b->link) attach(b->coef, b->expon, &rear);
    rear->link = NULL;

    /* delete the useless initial node */
    temp = c; c = c->link; free(temp);
    return c;
}

void attach(float coefficient, int exponent, polyPointer *ptr)
{
    polyPointer temp = (polyPointer)malloc(sizeof(*ptr));
    if (!temp) exit(1);

    temp->coef = coefficient;
    temp->expon = exponent;
    (*ptr)->link = temp;
    *ptr = temp;
}

void erase(polyPointer *ptr)
{
    /* erase the polynomial pointed to by ptr */
    polyPointer temp;
    while (*ptr)
    {
        temp = *ptr;
        *ptr = (*ptr)->link;
        free(temp);
    }
}

polyPointer getNode(void)
{
    /* provide a node for use */
    polyPointer node;

    if (avail)
    {
        node = avail;
        avail = avail->link;
    }
    else
        node = (polyPointer)malloc(sizeof(*node));
    return node;
}

void retNode(polyPointer node)
{
    /* return a node to the available list */
    node->link = avail;
    avail = node;
}

int main()
{
    polyPointer sa = a, sb = b;
    attach(3, 14, &a);
    attach(2, 8, &a);
    attach(1, 0, &a);
    attach(8, 14, &b);
    attach(-3, 10, &b);
    attach(10, 6, &b);
    polyPointer result = 
}