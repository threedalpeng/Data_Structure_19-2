#include <stdio.h>
#define MAX_DEGREE 101 /* 다항식의 최대 차수 + 1 */
typedef struct
{
    int degree;
    float coef[MAX_DEGREE];
} polynomial;
