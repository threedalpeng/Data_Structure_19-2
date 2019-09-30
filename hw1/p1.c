#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_I 101

char* plus_large_int(char[], char[]);
char* multiply_large_int(char[], char[]);

int main(void)
{
    // input an operator
    char operator;
    scanf_s("%c", &operator);

    // input two large numbers
    char input_buf[MAX_SIZE_I] = {0};
    scanf_s("%s", input_buf);
    char* front = (char*)malloc(sizeof(char) * (strlen(input_buf) + 1));
    strcpy(front, input_buf);
    memset(input_buf, '\0', strlen(front));
    scanf_s("%s", input_buf);
    char* back = (char*)malloc(sizeof(char) * (strlen(input_buf) + 1));
    strcpy(back, input_buf);

    switch(operator)
    {
    case '+':
        printf("%s", plus_large_int(front, back));
        break;
    case '*':
        printf("%s", multiply_large_int(front, back));
        break;
    }

    return 0;
}

char* plus_large_int(char f[], char b[])
{
    int carry = 0;
    int f_len = strlen(f);
    int b_len = strlen(b);
    char* result = (char*)malloc(sizeof(char) * (max(f_len, b_len) + 1));
    while(f_len > 0 && b_len > 0)
    {
        
    }
}