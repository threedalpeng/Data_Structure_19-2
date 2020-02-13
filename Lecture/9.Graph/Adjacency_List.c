#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 1001

typedef struct node* nodePointer;
typedef struct node
{
    int vertex;
    nodePointer link;
} node;
nodePointer adjLists[MAX_NODES];

void push(nodePointer p, int vertex)
{
    nodePointer newNode = (nodePointer)malloc(sizeof(node));
    if (newNode)
    {
        newNode->vertex = vertex;
        newNode->link = p->link;
        p->link = newNode;
    }
}

void printList(nodePointer p)
{
    while(p->link)
    {
        p = p->link;
        printf("%d ", p->vertex);
    }
}

int main(void)
{
    int V, E; // vertices, edge
    int a, b; // edge: (a, b)
    int i, j, count;
    double util;
    
    scanf("%d", &V);
    scanf("%d", &E);

    for (i = 0; i < V; i++)
    {
        adjLists[i] = (nodePointer)malloc(sizeof(node));
        adjLists[i]->link = NULL;
    }
    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &a, &b);
        push(adjLists[a], b);
        push(adjLists[b], a);
    }

    printf("\nAdjacency List:\n");
    for (i = 0; i < V; i++)
    {
        printf("%d: ", i);
        printList(adjLists[i]);
        puts("");
    }
}