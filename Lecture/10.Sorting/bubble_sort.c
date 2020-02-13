// Bubble Sort :
//      Compare two neightboring objects
//      and swap them if they are in the wrong order.
// Best case:       O(n^2)
// Worst case:      O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int element;

void bubbleSort(element a[], int n)
{
    element tmp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j  = 0; j < n - 1 - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    element arr[10];
    puts("Bubble Sort");

    printf("Before sorting:\n\t");
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, 10);

    printf("\nAfter sorting:\n\t");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}