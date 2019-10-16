#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100 /* maximum queue size */
typedef struct
{
    int key;
    /* other fields may be added */
} element;
element queue[MAX_QUEUE_SIZE];

int rear = -1; int front = -1;

void addq(element item)
{
    /* insert an item into a queue, so called 'enqueue' */
    if (rear == MAX_QUEUE_SIZE - 1)
        exit(-1);

    queue[++rear] = item;
}

element deleteq()
{
    /* delete an item at the front of the queue, so called 'dequeue' */
    if (front == rear)
        exit(1); /* return an error key */
    
    return queue[++front];
}

int main()
{
    element e, f;

    e.key = 3; addq(e);
    e.key = 2; addq(e);
    f = deleteq();
    printf("%d %d %d\n", front, rear, f.key);
}