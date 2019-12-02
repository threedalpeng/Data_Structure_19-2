#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#define INF 2e9

typedef struct _Point
{
    double x, y;
} Point;

double cal_dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int find_next(double* dist, bool* check, int size)
{
    double min = INF;
    int idx = 0;
    for (int i = 1; i <= size; i++)
        if (!check[i] && dist[i] < min) min = dist[i], idx = i;
    return idx;
}

int main(void)
{
    int V;
    double length = 0;
    scanf("%d", &V);
    Point* points = (Point*)calloc(V + 1, sizeof(Point));
    double* dist = (double*)calloc(V + 1, sizeof(double));
    bool* check = (bool*)calloc(V + 1, sizeof(bool));
    for (int i = 1; i <= V; i++)
    {
        scanf("%lf %lf", &points[i].x, &points[i].y);
        dist[i] = INF;
        check[i] = false;
    }
    dist[1] = 0;
    
    int vtx;
    while(vtx = find_next(dist, check, V))
    {
        check[vtx] = true;
        length += dist[vtx];
        for (int i = 1; i <= V; i++)
        {
            if (!check[i])
            {
                double d = cal_dist(points[vtx], points[i]);
                if (dist[i] > d) dist[i] = d;
            }
        }
        
        /*
        printf("%d: ", vtx);
        for (int i = 1; i <= V; i++)
        {
            printf("%.2lf ", (dist[i] == INF ? -1 : dist[i]));
        }
        puts("");
        */
    }

    printf("%.2lf", length);
}