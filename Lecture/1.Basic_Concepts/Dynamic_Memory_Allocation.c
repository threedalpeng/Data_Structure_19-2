#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, *pi;
    float f, *pf;

    // memory allocation
    pi = (int*)malloc(sizeof(int));
    pf = (float*)malloc(sizeof(float));
    *pi = 1024;
    *pf = 3.14;
    printf("an integer = %d, a float = %f\n", *pi, *pf);

    // memory free
    free(pi);
    free(pf);
}