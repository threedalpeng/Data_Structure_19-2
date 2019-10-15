#include <stdio.h>
#include <stdlib.h>
/*
#define MAX_DEGREE  101 // 다항식의 최대 차수 + 1
typedef struct
{
    int degree;
    float coef[MAX_DEGREE];
} polynomial;
*/

#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)
#define MAX_TERMS   100 /* 항 배열의 크기 */
typedef struct 
{
    float coef;
    int expon;
} polynomial;

/* A(x) = 2x^1000 + 1, B(x) = x^4 + 10x^3 + 3x^2 + 1 */
polynomial terms[MAX_TERMS] =   {
    {2, 1000},  /* startA */
    {1, 0},     /* finshA */
    {1, 4},     /* startB */
    {10, 3},
    {3, 2},
    {1, 0}      /* finishB */
    /* avail */
};
int avail = 6;

void padd(int starta, int finisha, int startb, int finishb, int* startd, int* finishd);
void attach(float coefficient, int exponent);

int main(void)
{
    int start, finish, i;
    padd(0, 1, 2, 5, &start, &finish);
    printf("Result:\ncoef   exp\n");
    for (i = start; i <= finish; i++)
    {
        printf("%4.0f%6d\n", terms[i].coef, terms[i].expon);
    }
}

void padd(int starta, int finisha, int startb, int finishb, int* startd, int* finishd)
{
    float coefficient;
    *startd = avail;
    while(starta <= finisha && startb <= finishb)
        switch (COMPARE(terms[starta].expon, terms[startb].expon))
        {
        case -1: /* a의 expon이 b의 expon보다 작은 경우 */
            attach(terms[startb].coef, terms[startb].expon);
            startb++;
            break;
        case 0: /* 지수가 같은 경우 */
            coefficient = terms[starta].coef + terms[startb].coef;
            if (coefficient)
                attach(coefficient, terms[starta].expon);
            starta++; startb++;
            break;
        case 1: /* a의 expon이 b의 expon보다 큰 경우 */
            attach(terms[starta].coef, terms[starta].expon);
            starta++;
            break;
        }
    /* A(x)의 나머지 항들을 첨가한다. */
    for (; starta <= finisha; starta++)
        attach(terms[starta].coef, terms[starta].expon);
    /* B(x)의 나머지 항들을 첨가한다. */
    for (; startb <= finishb; startb++)
        attach(terms[startb].coef, terms[startb].expon);
    *finishd = avail - 1;
}

void attach(float coefficient, int exponent)
{
    if (avail >= MAX_TERMS)
    {
        fprintf(stderr, "다항식에 항이 너무 많다.");
        exit(1);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}