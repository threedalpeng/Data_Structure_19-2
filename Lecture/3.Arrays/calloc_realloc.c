#include <stdio.h>
#include <stdlib.h>

#define CALLOC(p, n, s)\
        if (!((p) = calloc(n, s)))\
        {\
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE);\
        }
#define REALLOC(p, s)\
        if (!((p) = realloc(p, s)))\
        {\
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE);\
        }

int main(void)
{
    int* x;
    // x = calloc(5, sizeof(int));
    CALLOC(x, 5, sizeof(int));
    for(int i = 0; i < 5; i++)
        x[i] = i;
    REALLOC(x, sizeof(int) * 6);
    x[5] = 5;
    for(int i = 0; i < 6; i++)
        printf("%d ", x[i]);
}