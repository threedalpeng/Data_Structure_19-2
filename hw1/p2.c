#include <stdio.h>
#include <stdlib.h>

typedef enum _BState
{
    unfilled,
    filled,
    counted // is also unfilled, but included in result
} BState;

typedef struct _Brick
{
    int r;
    int c;
    BState state;
} Brick;

typedef struct _Stack
{
    Brick data;
    struct _Stack* next;
} Stack;

void Push(Stack*, Brick);
Brick Pop(Stack*);
Brick Peek(Stack*);
int isEmpty(Stack*);

int is2x2(Brick**, int, int);

int main(void)
{
    int R, C, tmpfill;
    Stack* top = (Stack*)malloc(sizeof(Stack));
    top->next = NULL;
    scanf("%d %d", &R, &C);
    Brick** bricks = (Brick**)malloc(sizeof(Brick*) * R);
    for(int i = 0; i < R; i++)
    {
        bricks[i] = (Brick*)malloc(sizeof(Brick) * C);
        for(int j = 0; j < C; j++)
        {
            scanf("%d", &tmpfill);
            bricks[i][j].state = (BState)tmpfill;
            bricks[i][j].r = i;
            bricks[i][j].c = j;
        }
    }

    int count = 0;
    for(int i = 0; i < R-1; i++)
    {
        for(int j = 0; j < C-1; j++)
        {
            if(bricks[i][j].state == unfilled)
            {
                if(is2x2(bricks, i, j))
                {
                    bricks[i][j].state = counted;
                    Push(top, bricks[i][j]);
                    while(!isEmpty(top))
                    {
                        Brick cur = Pop(top);
                        int c_r = cur.r;
                        int c_c = cur.c;
                        if (c_r < R-1 && bricks[c_r+1][c_c].state == unfilled)
                        {
                            bricks[c_r+1][c_c].state = counted;
                            Push(top, bricks[c_r+1][c_c]);
                        }
                        if (c_c < C-1 && bricks[c_r][c_c+1].state == unfilled)
                        {
                            bricks[c_r][c_c+1].state = counted;
                            Push(top, bricks[c_r][c_c+1]);
                        }
                        if (0 < c_r && bricks[c_r-1][c_c].state == unfilled)
                        {
                            bricks[c_r-1][c_c].state = counted;
                            Push(top, bricks[c_r-1][c_c]);
                        }
                        if (0 < c_c && bricks[c_r][c_c-1].state == unfilled)
                        {
                            bricks[c_r][c_c-1].state = counted;
                            Push(top, bricks[c_r][c_c-1]);
                        }
                    }
                    ++count;
                }
            }
        }
    }

    printf("%d", count);
    /*
    puts("");
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            printf("%d ", (int)bricks[i][j].state);
        puts("");
    }*/
}

int is2x2(Brick** b, int r, int c)
{
    return (b[r + 1][c].state != filled
        && b[r][c + 1].state != filled
        && b[r + 1][c + 1].state != filled);
}

void Push(Stack* top, Brick b)
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->data = b;
    newStack->next = top->next;
    top ->next = newStack;
}

Brick Pop(Stack* top)
{
    Stack* tmp = top->next;
    Brick ret = top->next->data;
    top->next = top->next->next;
    free(tmp);
    return ret;
}

Brick Peek(Stack* top)
{
    return top->next->data;
}

int isEmpty(Stack* top)
{
    if(top->next) return 0;
    else return 1;
}