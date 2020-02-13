#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACKS 10 /* maximum number of stacks */
typedef struct 
{
    int key;
    /* other fields */
} element;

typedef struct stack *stackPointer;
typedef struct stack
{
    element data;
    stackPointer link;
};
stackPointer top[MAX_STACKS]; /* multiple stacks */

void initStack()
{
    for (int i = 0; i < MAX_STACKS; i++)
    {
        top[i] = NULL;
    }
}

bool is_empty(stackPointer p)
{
    if (p) return true;
    else return false;
}

bool is_full()
{
    stackPointer temp;
    if (temp = (stackPointer)malloc(sizeof(*temp)))
    {
        free(temp);
        return true;
    }
    else
        return false;
}

void push(int i, element item)
{
    /* add item to the ith stack */
    stackPointer temp = (stackPointer)malloc(sizeof(*temp));
    if (temp)
    {
        temp->data = item;
        temp->link = top[i];
        top[i] = temp;
    }
    else exit(1);
}

element pop(int i)
{
    stackPointer temp = top[i];
    element item;
    if (!temp) exit(1);
    item = temp->data;
    top[i] = temp->link;
    free(temp);
    return item;
}

