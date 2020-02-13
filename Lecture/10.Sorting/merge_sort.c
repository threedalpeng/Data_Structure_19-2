// Quick Sort
// Best average time:   O(n*log2(n)) (when pivot is in middle)
// Worst case:          O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
typedef int element;

void merge(element initList[], element mergedList[], int i, int m, int n)
{
    int j = m + 1, k = i, t;
    while(i <= m && j <= n)
    {
        if (initList[i] <= initList[j])
            mergedList[k++] = initList[i++];
        else
            mergedList[k++] = initList[j++];
    }
    if (i > m)  /* mergedList[k : n] = initList[j : n] */
        for (t = j; t <= n; t++)
            mergedList[t] = initList[t];
    else        /* mergedList[k : n] = initList[i : m] */
        for (t = j; t <= m; t++)
            mergedList[k + t - i] = initList[t];
}

void mergePass(element initList[], element resultList[], int n, int s)
{
    int i, j;
    for (i = 1; i <= n - 2*s + 1; i += 2*s)
        merge(initList, resultList, i, i + s - 1, i + 2*s - 1);

    if ((i + s - 1) < n)
        merge(initList, resultList, i, i + s - 1, n);
    else
        for (j = i; j <= n; j++)
            resultList[j] = initList[j];
}

void mergeSort(element a[], int n)
{
    int s = 1;
    element extra[MAX_SIZE + 1];

    while (s < n)
    {
        mergePass(a, extra, n, s);
        s *= 2;
        mergePass(extra, a, n, s);
        s *= 2;
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    element arr[MAX_SIZE + 1];
    puts("Merge Sort");

    printf("Before sorting:\n\t");
    for (int i = 1; i < 11; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 10);

    printf("\nAfter sorting:\n\t");
    for (int i = 1; i < 11; i++)
    {
        printf("%d ", arr[i]);
    }
}