#include <stdio.h>
int sum_count = 0, rsum_count = 0;

// sum_count : 2n + 3
float sum(float list[], int n)
{
    float tempsum = 0; ++sum_count;         /* for assignment */
    int i;
    for (i = 0; i < n; i++)
    {
        ++sum_count;                        /* for the for loop */
        tempsum += list[i]; ++sum_count;    /* for assignment */
    }
    ++sum_count;                            /* last execution of for */
    ++sum_count; return tempsum;            /* for return */
}

// rsum_count : 2n + 2
float rsum(float list[], int n)
{
    ++rsum_count;                           /* for if conditional */
    if (n)
    {
        ++rsum_count;                       /* for return and rsum invocation */
        return rsum(list, n - 1) + list[n - 1];
    }
    ++rsum_count;                           /* for return */
    return 0;
}

int main(void)
{
    float list[10] = {1.1, 2.4, 6.2, -1.5, 4.7, 20.2, -6.2, -3.6, 2.9, 4.6};
    float nsum = sum(list, 10), nrsum = rsum(list, 10);
    printf("sum: %.1f, count: %d\nrsum: %.1f, count: %d",
            nsum, sum_count, nrsum, rsum_count);
}