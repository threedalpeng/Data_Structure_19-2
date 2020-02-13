#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUES 10 /* maximum number of queues */
typedef struct 
{
    int key;
    /* other fields */
} element;

typedef struct queue *queuePointer;
typedef struct queue
{
    element data;
    queuePointer link;
};
queuePointer front[MAX_QUEUES], rear[MAX_QUEUES];

void initQueue()
{
    for (int i = 0; i < MAX_QUEUES; i++)
    {
        front[i] = NULL;
    }
}

bool is_empty(queuePointer q)
{
    if (q) return true;
    else return false;
}

bool is_full()
{
    queuePointer temp;
    if (temp = (queuePointer)malloc(sizeof(*temp)))
    {
        free(temp);
        return true;
    }
    else
        return false;
}

void addq(int i, element item)
{
    /* add item to the ith queue */
    queuePointer temp = (queuePointer)malloc(sizeof(*temp));
    if (temp)
    {
        temp->data = item;
        temp->link = NULL;
        if (front[i]) rear[i]->link = temp;
        else front[i] = temp;
        rear[i] = temp;
    }
    else exit(1);
}

element deleteq(int i)
{
    queuePointer temp = front[i];
    element item;
    if (!temp) exit(1);
    item = temp->data;
    front[i] = temp->link;
    free(temp);
    return item;
}

