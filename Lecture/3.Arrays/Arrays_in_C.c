#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

float input[MAX_SIZE];
int i;

float sum(float[], int);

int main(void)
{
    // randomize an array of 100 floats
    for (i = 0; i < MAX_SIZE; i++)
        input[i] = (float)(rand() % 100) / 10;
    float answer = sum(input, MAX_SIZE);
    printf("The sum is: %.1f\n", answer);
}

float sum(float list[], int n)
{
    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += list[i];
    return tempsum;
}