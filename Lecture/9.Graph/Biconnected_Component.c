#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define MIN2(x, y) ((x) < (y) ? (x) : (y))
bool dfn[MAX_VERTICES];
bool low[MAX_VERTICES];
int num;

// initialization of dfn and low
void init(void)
{
    int i;
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
        dfn[i] = low[i] = -1;
    }
    num = 0;
}

// determining dfn and low performing depth first search
void dfnlow(int u , int v)
[
    nodePointer ptr;
]