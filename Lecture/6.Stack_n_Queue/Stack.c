#include <stdio.h>
#define MAX_STACK_SIZE 100 /* maximum stack size */
typedef struct 
{
    int key;
    /* other fields may be added */
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

void push (element item)
{
    /* add an item to the global stack */
    if (top >= MAX_STACK_SIZE - 1)
    {
        puts("Push Error!");
        return;
    }
    stack[++top] = item;
}

element pop()
{
    /* retrun the top element from the stack, so called 'pop' */
    if (top == -1)
    {
        puts("Pop Error!");
        element error = {-1};
        return error; /* returns an error key */
    }
    return stack[top--];
}

int main(void)
{
    element e, f;

    e.key = 3; push(e);
    e.key = 2; push(e);

    if((f = pop()).key != -1)
        printf("%d %d", top, f.key);
}