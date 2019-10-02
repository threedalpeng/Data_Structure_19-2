#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_I 101
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

void swap_large_int(char**, char**);
//char* plus_large_int(char[], char[]);
//char* multiply_large_int(char[], char[]);

int main(void)
{
    // input an operator
    char opr;
    scanf("%c", &opr);

    // input two large numbers
    char input_buf[MAX_SIZE_I] = {0};
    scanf("%s", input_buf);
    char* front = (char*)malloc(sizeof(char) * (strlen(input_buf) + 1));
    strcpy(front, input_buf);
    memset(input_buf, '\0', strlen(front));
    scanf("%s", input_buf);
    char* back = (char*)malloc(sizeof(char) * (strlen(input_buf) + 1));
    strcpy(back, input_buf);

    // set larger-digits number to front
    printf("front: %s\nback : %s", front, back);
    if (strlen(front) < strlen(back)) swap_large_int(&front, &back);
    printf("\n\nfront: %s\nback : %s", front, back);

    /*
    switch(opr)
    {
    case '+':
        printf("%s", plus_large_int(front, back));
        break;
    case '*':
        printf("%s", multiply_large_int(front, back));
        break;
    }
    */
    return 0;
}

void swap_large_int(char** s1, char** s2)
{
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

char* plus_large_int(char f[], char b[])
{
    int carry = 0;
    int f_len = strlen(f);
    int b_len = strlen(b);
    char* result = (char*)malloc(sizeof(char) * ( MAX(f_len, b_len) + 2));
    while(f_len > 0 && b_len > 0)
    {
    }
    return result;
}