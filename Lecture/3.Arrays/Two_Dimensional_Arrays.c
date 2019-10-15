#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MALLOC(p, s) if (!((p) = malloc(s))) {\
                        fprintf(stderr, "Insufficient memory");\
                        exit(EXIT_FAILURE);\
                    }

int** make2dArray(int rows, int cols)
{
    /* create a two dimensional rows x cols array */
    int **x, i;

    /* get memory for row pointers */
    MALLOC(x, rows * sizeof(*x));

    /* get memory for each row */
    for (i = 0; i < rows; i++)
        MALLOC(x[i], cols * sizeof(**x));

    return x;
}

int main(void)
{
    int** myArray, i, j;
    myArray = make2dArray(5, 10);
    for (i = 0; i < 5; i++) 
        memset(myArray[i], 0, sizeof(int) * 10);
    myArray[2][4] = 6;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
            printf("%d ", myArray[i][j]);
        puts("");
    }
}