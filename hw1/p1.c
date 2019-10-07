#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 201 // last index: MAX_SIZE-1 = 200 -> '\0',

char* create_zero();
void print_large_int(char[]);
void shift_left_once(char[]);
void shift_right_all(char[]);
char* plus_large_int(char[], char[]);
char* multiply_large_int(char[], char[]);

int main(void)
{
    // input an operator
    char opr;
    scanf("%c", &opr);

    // input two large numbers
    char front[MAX_SIZE] = {0}, back[MAX_SIZE] = {0};
    scanf("%s", front);
    shift_right_all(front);
    scanf("%s", back);
    shift_right_all(back);
    switch(opr)
    {
    case '+':
        print_large_int(plus_large_int(front, back));
				//printf("%s", plus_large_int(front, back));
        break;
    case '*':
        print_large_int(multiply_large_int(front, back));
        break;
    }
    return 0;
}

char* create_zero()
{
    char* result = (char*)malloc(sizeof(char) * (MAX_SIZE));
    memset(result, '0', MAX_SIZE - 1);
    result[MAX_SIZE - 1] = '\0';
    return result;
}

void shift_right_all(char str[])
{  
    char buf[MAX_SIZE] = {0};
    sprintf(buf, "%*.*s", MAX_SIZE - 1, strlen(str), str);
		memset(buf, '0', MAX_SIZE - 1 - strlen(str));
    strcpy(str, buf);
}

void shift_left_once(char str[])
{
    int idx = 0;
    while(str[idx] == '0') ++idx;
    for(; idx < MAX_SIZE - 1; ++idx) str[idx-1] = str[idx];
    str[MAX_SIZE - 2] = '0'; 
    str[MAX_SIZE - 1] = '\0';
}

char* plus_large_int(char f[], char b[])
{
    int carry = 0;
    char digit;
    char* result = create_zero();
    for (int i = MAX_SIZE - 2; i >= 0; --i)
    {
        digit = (f[i] - '0') + (b[i] - '0') + '0' + carry;
        if (!isdigit(digit)) digit -= 10, carry = 1;
        else carry = 0;
        result[i] = digit;
    }
    return result;
}

char* multiply_large_int(char f[], char b[])
{
    int carry = 0;
    char digit;
    char* result = create_zero();
    int j = 0;
    while(b[j] == '0' && b[j] != '\0') ++j;
    for(; j < MAX_SIZE - 1; ++j)
    {
        char* temp = create_zero();
        for(int i = MAX_SIZE - 2; i >= 0; --i)
        {
            digit = (f[i] - '0') * (b[j] - '0') + carry;
            carry = 0;
            while(10 <= digit || 0 > digit) digit -= 10, ++carry;
            temp[i] = digit + '0';
        }
        //print_large_int(temp);
        //puts("");
        shift_left_once(result);
        char* del = result;
        result = plus_large_int(result, temp);
        free(del);
        free(temp);
    }
    return result;
}

void print_large_int(char str[])
{
    int idx = 0;
    while(str[idx] == '0' && str[idx] != '\0') ++idx;
    if (idx == MAX_SIZE - 1) printf("0");
    else printf("%s", str + idx);
}