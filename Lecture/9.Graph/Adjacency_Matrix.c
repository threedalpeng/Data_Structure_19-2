#include <stdio.h>
#include <stdlib.h>

// undirected graph, expressed in adjacency matrix
int graph[101][101];

int main(void)
{
    int V, E; // vertices, edge
    int a, b; // edge: (a, b)
    int i, j, count;
    double util;
    
    scanf("%d", &V);
    scanf("%d", &E);
    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (graph[i][j] == 1) 
                ++count;
            printf("%d ", graph[i][j]);
        }
        puts("");
    }
    
    util = (double)count / (V * V) * 100;
    printf("\nUtilization: %d / %d = %.2lf(%%)", count, V * V, util);
}