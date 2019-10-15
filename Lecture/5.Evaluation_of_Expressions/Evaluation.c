#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 101

/*
전역 변수로 되어있는 후위 표기식 expr을 연산한다.
'\0'은 수식의 끝을 나타낸다.
stack과 top은 전역 변수이다. 함수 getToken은 토큰의 타입과
문자 심벌을 반환한다. 피연산자는 한 문자로 된 숫자임을 가정한다.
*/

typedef enum {
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

// 후위 표기식 (마지막 스페이스 ' '는 end of string으로 사용)
char expr[] = "62/3-42*+ ";

// 스택
char stack[MAX_STACK_SIZE];
int top = -1;

int eval(void);
precedence getToken(char* symbol, int* n);
int pop();
void push(int);

int main(void)
{
    int result = eval();
    printf("Result: %d\n", result);
    return 0;
}

int eval(void)
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;  /* 수식 스트링을 위한 카운터 */
    token = getToken(&symbol, &n);
    while(token != eos)
    {
        if (token == operand)
            push(symbol - '0');
        else
        {
            // 두 피연산자를 삭제하여 연산 수행 후,
            // 그 결과를 스택에 삽입
            op2 = pop(); // 스택에서 삭제
            op1 = pop();
            switch(token)
            {
                case plus: push(op1 + op2); break;
                case minus: push(op1 - op2); break;
                case times: push(op1 * op2); break;
                case divide: push(op1 / op2); break;
                case mod: push(op1 % op2); break;
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop(); // 결과 반환
}

precedence getToken(char* symbol, int* n)
{
    *symbol = expr[(*n)++];
    switch(*symbol)
    {
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divide;
        case '*' : return times;
        case '%' : return mod;
        case ' ' : return eos;
        default : return operand;
    }
}

int pop()
{
    if (top < 0)
    {
        puts("Pop Error!");
        exit(EXIT_FAILURE);
    }

    return stack[top--];
}

void push(int op)
{
    if (top >= MAX_STACK_SIZE)
    {
        puts("Push Error!");
        exit(EXIT_FAILURE);
    }
    
    stack[++top] = op;
}