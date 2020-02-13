#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200 /* maximum size of heap + 1 */
#define HEAP_FULL(n) ((n) == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!(n)) 

typedef struct 
{
    int key;
} element;
element heap[MAX_ELEMENTS];

void push(element item, int* n)
{
    int i;
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while((i != 1) && (item.key > heap[i / 2].key))
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
}

element pop(int* n)
{
    int parent, child;
    element item, temp;
    if (HEAP_EMPTY(*n))
    {
        fprintf(stderr, "The heap is empty");
        exit(EXIT_FAILURE);
    }

    item = heap[1];

    temp = heap[(*n)--];
    parent = 1;
    child = 2;

    while(child <= *n)
    {
        if ((child < *n) && (heap[child].key < heap[child+1].key))
            child++;
        if (temp.key >= heap[child].key) break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}

int main()
{
    int n = 0;
    element input[10] = {{82}, {35}, {72}, {43}, {26}, {97}, {11}, {34}, {19}, {56}};
    for (int i = 0; i < 10; i++)
    {
        push(input[i], &n);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", pop(&n).key);
    }
}