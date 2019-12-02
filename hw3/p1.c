#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VTX 1500
#define MAX_EDGE (MAX_VTX * MAX_VTX)
#define INF 2e9
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct _Edge
{
    int from, to, weight;
} Edge;
Edge edges[MAX_EDGE + 1];
bool check[MAX_EDGE + 1];
bool cmp(const Edge* e1, const Edge* e2);
void quicksort(Edge* arr, int first, int last, bool (*comp)(const Edge* s1, const Edge* s2));

// for disjoint set
int parent[MAX_VTX + 1];
int find(int v);
void uni(int v1, int v2);

typedef struct
{
    int to, weight;
} Point;
typedef struct _Node
{
    Point p;
    struct _Node* next;
} List;
List* MST[MAX_VTX];
void insert(List* plist, int to, int weight);

int par[20][MAX_VTX];
int cost[20][MAX_VTX];
int level[MAX_VTX];
bool visit[MAX_VTX];

void init_lca(int cur)
{
    visit[cur] = true;
    List* tmp = MST[cur]->next;
    while(tmp)
    {
        int next = tmp->p.to;
        int w = tmp->p.weight;

        if (!visit[next])
        {
            par[0][next] = cur;
            level[next] = level[cur] + 1;
            cost[0][next] = w;
            init_lca(next);
        }
        tmp = tmp->next;
    }
    free(tmp);
}

int lca(int u, int v)
{
    int ret = 0;
    if (level[u] > level[v])
    {
        int temp = u; u = v; v = temp;
    }
    for (int i = 19; i >= 0; i--)
    {
        int dif = level[v] - level[u];
        if (dif >= (1 << i))
        {
            ret = MAX(ret, cost[i][v]);
            v = par[i][v];
        }
    }
    if (u == v) return ret;
    for (int i = 19; i >= 0; i--)
    {
        if (par[i][u] != par[i][v])
        {
            ret = MAX(ret, MAX(cost[i][u], cost[i][v]));
            u = par[i][u];
            v = par[i][v];
        }
    }
    return MAX(ret, MAX(cost[0][u], cost[0][v]));
}

int main(void)
{
    int V;
    FILE* f = fopen("input.txt", "r");
    fscanf(f, "%d", &V);
    int E = (V * (V - 1)) >> 1;
    for (int i = 0; i < E; i++)
    {
        fscanf(f, "%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight);
    }
    for (int i = 0; i < V; i++) 
    {
        parent[i] = -1;
        MST[i] = (List*)malloc(sizeof(List));
        MST[i]->next = NULL;
    }
    quicksort(edges, 0, E - 1, cmp);
    /*
    for (int i = 0; i < E; i++)
    {
        printf("%d %d %d\n", edges[i].from, edges[i].to, edges[i].weight);
    }
    */
    int cnt = 1, idx = 0, result = 0;
    while(cnt < V)
    {
        if (find(edges[idx].from) != find(edges[idx].to))
        {
            check[idx] = true;
            uni(edges[idx].from, edges[idx].to);
            result += edges[idx].weight;
            insert(MST[edges[idx].from], edges[idx].to, edges[idx].weight);
            insert(MST[edges[idx].to], edges[idx].from, edges[idx].weight);
            ++cnt;
        }
        ++idx;
    }
    init_lca(0);
    for (int i = 1; i < 20; i++)
    {
        for (int j = 0; j < V; j++)
        {
            par[i][j] = par[i - 1][par[i - 1][j]];
            cost[i][j] = MAX(cost[i - 1][j], cost[i - 1][par[i - 1][j]]);
        }
    }
    int max = INF;
    for (int i = 0; i < E; i++)
    {
        if (check[i]) continue;
        int from = edges[i].from;
        int to = edges[i].to;
        int w = edges[i].weight;
        int x = lca(from, to);
        if (x == w) continue;
        max = (max < result - x + w ? max : result - x + w);
    }
    printf("%d\n%d", result, max);
    return 0;
}

bool cmp(const Edge* e1, const Edge* e2)
{
    return (*e1).weight < (*e2).weight;
}

int find(int v)
{
    if (parent[v] == -1) return v;
    return parent[v] = find(parent[v]);
}

void uni(int v1, int v2)
{
    v1 = find(v1), v2 = find(v2);
    if (v1 != v2) parent[v1] = v2;
}

void quicksort(Edge* arr, int first, int last, bool (*comp)(const Edge* s1, const Edge* s2))
{
	int left, right;
	Edge tmp, pivot;
	if (first < last)
	{
		left = first - 1;
		right = last + 1;
		pivot = arr[(first + last) / 2];
		while (true) {
			while (comp(&arr[++left], &pivot));
			while (comp(&pivot, &arr[--right]));
			if (left >= right) break;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
		quicksort(arr, first, left - 1, comp);
		quicksort(arr, right + 1, last, comp);
	}
}

void insert(List* plist, int to, int weight)
{
    Point p = {to, weight};
    List* newNode = (List*)malloc(sizeof(List));
    newNode->p = p;
    newNode->next = plist->next;
    plist->next = newNode;
}