// Heap Sort :
//      Using max(or other) heap to sort
// Average case:    O(n*log_2(n))
// Worst case:      O(n*log_2(n))
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) { (t) = (x), (x) = (y), (y) = (t); }

typedef struct 
{
    int key;
} element;

void adjust(element list[], int root, int n)
{
    int child, rootkey;
    element temp;
    temp = list[root];
    rootkey = list[root].key;
    child = 2 * root; /* left child */
    while(child <= n)
    {
        if (child < n && list[child].key < list[child + 1].key)
            child++;
        if (rootkey > list[child].key)
            break;
        else
        {
            list[child / 2] = list[child];
            child *= 2;
        }
    }
    list[child / 2] = temp;
}

void heapSort(element list[], int n)
{
    int i, j;
    element temp;
    for (i = n / 2; i > 0; i--)
        adjust(list, i, n); /* initial heap construction */
    for (i = n - 1; i > 0; i--)
    {
        SWAP(list[1], list[i+1], temp);
        adjust(list, 1, i);
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    element arr[11];
    puts("Heap Sort");

    printf("Before sorting:\n\t");
    for (int i = 1; i <= 10; i++)
    {
        arr[i].key = rand() % 100;
        printf("%d ", arr[i]);
    }

    heapSort(arr, 10);

    printf("\nAfter sorting:\n\t");
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", arr[i].key);
    }
}