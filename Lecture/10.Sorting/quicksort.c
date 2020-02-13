// Quick Sort
// Best average time:   O(n*log2(n)) (when pivot is in middle)
// Worst case:          O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int element;

void quicksort(element a[], int left, int right)
{
    element tmp, pivot;
    int i, j;
    if (left < right)
    {
        i = left; j = right + 1;
        pivot = a[left];
        do
        {
            do i++; while (a[i] < pivot); /* && i < right */
            do j--; while (a[j] > pivot); /* && j > left */
        } while (i < j);
        tmp = a[left]; a[left] = a[j]; a[j] = tmp;
        quicksort(a, left, j - 1);
        quicksort(a, j + 1, right);
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    element arr[10];
    puts("Quicksort");

    printf("Before sorting:\n\t");
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, 9);

    printf("\nAfter sorting:\n\t");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}