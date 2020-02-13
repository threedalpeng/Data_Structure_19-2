// Insertion Sort :
//    Insert element into already sorted subfile
// Best case:       O(n)
// Computing time:  O((k+1) * n) (if k LOOs exist)
// Worst case:      O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int element;

void insert(element e, element a[], int i)
{
    a[0] = e;
    while(e < a[i])
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i+1] = e;
}

void insertionSort(element a[], int n)
{
    int j;
    for (j  = 2; j <= n; j++)
    {
        element temp = a[j];
        insert(temp, a, j - 1);
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    element arr[11];
    puts("Insertion Sort");

    printf("Before sorting:\n\t");
    for (int i = 1; i <= 10; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    
    insertionSort(arr, 10);

    printf("\nAfter sorting:\n\t");
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", arr[i]);
    }
}