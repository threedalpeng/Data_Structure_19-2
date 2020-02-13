// Radix Sort :
//      a specialization of lexicographic-sort.
//      decomposing the sort key using some radix.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int element;

int digit(element a, int d, int r)
{

}

int radixSort(element a[], int link[], int d, int r, int n)
{
    int front[r], rear[r];
    int i, bin, current, first, last;
    first = 1;
    // link 초기화
    for (i = 1; i < n; i++)
        link[i] = i + 1;
    link[n] = 0;
    // 각 digit에 대해
    for (i = d - 1; i >= 0; i--)
    {
        // front 초기화
        for (bin = 0; bin < r; bin++)
            front[bin] = 0;
        // 다음 링크로 넘어가면서 front와 rear 설정
        for (current = first; current; current = link[current])
        {
            bin = digit(a[current], i , r);
            if (front[bin] == 0)
                front[bin] = current;
            else 
                link[rear[bin]] = current;
            rear[bin] = current;
        }
        for (bin = 0; !front[bin]; bin++);
        first = front[bin]; 
        last = rear[bin];
        for (bin++; bin < r; bin++)
            if (front[bin])
            {
                link[last] = front[bin];
                last = rear[bin];
            }
        link[last] = 0;
    }
    return first;
}

int main(void)
{
    srand((unsigned)time(NULL));
    element arr[10];
    puts("Radix Sort");

    printf("Before sorting:\n\t");
    for (int i = 1; i <= 10; i++)
    {
        arr[i] = rand() % 1000;
        
        printf("%d ", arr[i]);
    }

    radixSort(arr, 1);

    printf("\nAfter sorting:\n\t");
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", arr[i]);
    }
}