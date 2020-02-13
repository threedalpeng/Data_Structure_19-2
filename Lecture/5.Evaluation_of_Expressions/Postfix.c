#include <stdio.h>
#include <stdlib.h>
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

// 중위 표기식
char expr[] = "3*(2+1)-5%4 ";

// 스택
precedence stack[MAX_STACK_SIZE];
// in-stack precedence  { (,   ),  +,  -,  *,  /,  %, EOS} 
static int isp[] =      { 0,  19, 12, 12, 13, 13, 13, 0};
// incoming precedence
static int icp[] =      { 20, 19, 12, 12, 13, 13, 13, 0};

void postfix(void);
precedence pop(int*);
void push(int*, precedence);
precedence getToken(char* symbol, int* n);
void printToken(precedence);

int main(void)
{
    puts("Infix expression:");
    printf("\t%s\n", expr);
    printf("Postfix expression:\n\t");
    postfix();
    return 0;
}

void postfix(void)
{
    /* 수식을 후위 표기식으로 출력한다. 수식 스트링, 스택은 전역적이다. */
    char symbol;
    precedence token;
    int n = 0;
    int top = 0; /* eos를 스택에 삽입한다. */
    stack[0] = eos;
    for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
    {
        if (token == operand)
            printf("%c", symbol);
        else if (token == rparen)
        {
            while (stack[top] != lparen)
                printToken(pop(&top));
            pop(&top);
        }
        else
        {
            while (isp[stack[top]] >= icp[token])
                printToken(pop(&top));
            push(&top, token);
        }
    }
    while((token = pop(&top)) != eos)
        printToken(token);
    printf("\n");
}

precedence pop(int* top)
{
    if (*top < 0)
    {
        puts("Pop Error!");
        exit(EXIT_FAILURE);
    }

    return stack[(*top)--];
}

void push(int* top, precedence token)
{
    if (*top >= MAX_STACK_SIZE)
    {
        puts("Push Error!");
        exit(EXIT_FAILURE);
    }
    
    stack[++(*top)] = token;
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

void printToken(precedence token)
{
    char symbol;
    switch(token)
    {
        case plus: symbol = '+'; break;
        case minus: symbol = '-'; break;
        case divide: symbol = '/'; break;
        case times: symbol = '*'; break;
        case mod: symbol = '%'; break;
        case eos: symbol = ' '; break;
    }
    printf("%c", symbol);
}