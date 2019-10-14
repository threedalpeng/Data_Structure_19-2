#include <stdio.h>
// x가 더 작으면 -1, 같으면 0, 더 크면 1
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

int binsearch(int list[], int searchnum, int left, int right)
{
    /* 
    Search list [0] <= list[1] <= … <= list[n-1] for searchnum. 
    Return its position if found. Otherwise return -1.
    */
    int middle;
    if (left <= right)
    {
        middle = (left + right) / 2;
        switch(COMPARE(list[middle], searchnum))
        {
            case -1 : return binsearch(list, searchnum, middle + 1, right);
            case 0 : return middle;
            case 1 : return binsearch(list, searchnum, left, middle - 1);
        }
    }
    return -1;
}

int main(void)
{
    int n, idx;
    int list[15] = {1, 3, 6, 8, 9, 11, 12, 14, 15, 18, 20, 24, 27, 28, 29};
    printf("Enter a number to search: ");
    scanf("%d", &n);
    if ((idx = binsearch(list, n, 0, 14)) != -1)
    {
        printf("Result: Found at the index %d.", idx);
    }
    else
    {
        printf("Result: Not found.");
    }
    return 0;
}