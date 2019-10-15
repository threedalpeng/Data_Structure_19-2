#include <stdio.h>

void printf1(int* ptr, int rows)
{
    /* print out a one-dimensional array using a pointer */
    int i;
    printf(" Address Contests\n");
    for (i = 0; i < rows; i++)
        printf("%8u%5d\n", ptr + i, *(ptr + i));
    printf("\n");
}

int main(void)
{
    int one[] = {0, 1, 2, 3, 4};
    puts("Pass \'&one[0]\' to the 1st parameter:");
    printf1(&one[0], 5);
    puts("Pass \'one\' to the 1st parameter:");
    printf1(one, 5);
}