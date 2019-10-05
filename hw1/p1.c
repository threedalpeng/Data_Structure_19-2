#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101
#define MAX_SIZE_M 201
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

void reverse_large_int(char*, char*);
void print_large_int(char[]);
//char* plus_large_int(char[], char[]);
//char* multiply_large_int(char[], char[]);

int main(void)
{
    // input an operator
    char opr;
    scanf("%c", &opr);

    // input two large numbers
    char front[MAX_SIZE] = {0}, back[MAX_SIZE] = {0};
    scanf("%s", front);
    scanf("%s", back);
    printf("%s, %s", front, back);
    /*
    switch(opr)
    {
    case '+':
        print_large_int(plus_large_int(front, back));
        break;
    case '*':
        print_large_int(multiply_large_int(front, back));
        break;
    }
    return 0;
    */
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
    char* result = (char*)malloc(sizeof(char) * (MAX_SIZE + 1));
    for(int i = MAX_SIZE, a = strlen(f), b = strlen(b);
        i >= 0 && a >= 0 && b >= 0;
        --i, --a, --b)
    {
        
    }
    return result;
}