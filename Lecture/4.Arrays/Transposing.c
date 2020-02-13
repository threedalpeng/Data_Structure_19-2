#include <stdio.h>
#include <windows.h>
#define MAX_TERMS 101
#define MAX_COL 11

typedef struct 
{
    int col;
    int row;
    int value;
} term;

void print_terms(term a[])
{
    for (int i = 1; i <= a[0].value; i++)
    {
        printf("(%d, %d) : %d\n", a[i].col, a[i].row, a[i].value);
    }
}

void transpose(term a[], term b[])
{
    int n, i, j, currentb;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;
    if (n > 0)
    {
        currentb = 1;
        for (i = 0; i < a[0].col; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[j].col == i)
                {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}

void fasttranspose(term a[], term b[])
{
    int rowTerms[MAX_COL];
    int startingPos[MAX_COL];
    int i, j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols; b[0].col = a[0].row;
    b[0].value = numTerms;
    if (numTerms > 0)
    {
        for (i = 0; i < numCols; i++)
            rowTerms[i] = 0;
        for (i = 1; i < numTerms; i++)
            rowTerms[a[i].col]++;
        startingPos[0] = 1;
        for (i = 1; i < numCols;i++)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        for (i = 1; i <= numTerms; i++)
        {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col; b[j].col = a[i].row;
            b[i].value = a[i].value;
        }
    }
}

int main()
{
    LARGE_INTEGER start1, start2, end1, end2, freq;
    QueryPerformanceFrequency(&freq);

    term a[MAX_TERMS] = {
        {6, 6, 11},
        {0, 0, 15},
        {0, 1, 23},
        {0, 2, 9},
        {0, 3, 22},
        {0, 4, 23},
        {0, 5, -15},
        {1, 1, 11},
        {1, 2, 3},
        {2, 3, -6},
        {4, 0, 91},
        {5, 2, 28}
    };

    puts("Terms a before using any transpose:\n");
    print_terms(a);

    term b[MAX_TERMS];
    term c[MAX_TERMS];
    
    QueryPerformanceCounter(&start1);
    transpose(a, b);
    QueryPerformanceCounter(&end1);
    double d1 = (double)(end1.QuadPart - start1.QuadPart) / freq.QuadPart * 1000000;

    QueryPerformanceCounter(&start2);
    fasttranspose(a, c);
    QueryPerformanceCounter(&end2);
    double d2 = (double)(end2.QuadPart - start2.QuadPart) / freq.QuadPart * 1000000;

    puts("\nTerms b after using transpose:");
    print_terms(b);
    printf("duration: %.4lf us\n", d1);
    puts("\nTerms c after using fasttranspose:");
    print_terms(c);
    printf("duration: %.4lf us\n", d2);
}