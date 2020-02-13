// Bubble Sort :
//      Find the smallest element between a[i] and a[n-1]
//      and swap a[i] and it.
// Best case:       O(n^2)
// Worst case:      O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int element;

void selectionSort(element a[], int n)
{
    element tmp;
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j  = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    element arr[10];
    puts("Selection Sort");

    printf("Before sorting:\n\t");
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    selectionSort(arr, 10);

    printf("\nAfter sorting:\n\t");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}