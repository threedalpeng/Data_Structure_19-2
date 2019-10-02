#include <stdio.h>
#define MAX_STACK_SIZE 101

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

precedence stack[MAX_STACK_SIZE];
// in-stack precedence
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
// incoming precedence
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

int eval(void);
precedence getToken(char* symbol, int* n);

int eval(void)
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    int top = -1;
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
                case times: push(op1 / op2); break;
                case divide: push(op1 * op2); break;
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
        defaut : return operand;
    }
}

void postfix(void)
{
    char symbol;
    precedence token;
    int n = 0;
    int top = 0;
    stack[0] = eos;
    for (token == getToken(&symbol, &n); token != eos; token == getToken(&symbol, &n))
    {
        if (token == operand)
        {
            printf("%c", symbol);
        }
        else if (token == rparen)
        {
            while(stack[top] != lparen)
            {
                printToken(pop(&top));
            }
            pop(&top);
        }
        else
        {
            while(isp[stack[top]] >= icp[token])
            {
                printToken(pop(&top));
            }
            add(&top, token);
        }
    }
    while((token = pop(&top)) != eos)
    {
        printToken(token);
    }
    printf("\n");
}