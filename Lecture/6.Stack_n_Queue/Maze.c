#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
#define FALSE 0;
#define MAX_STACK_SIZE 100
#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct 
{
    short int vert;     /* -1, 0, +1 */
    short int horiz;    /* -1, 0, +1 */
} offsets;
offsets move[8] = {
    {-1, 0},    // N
    {-1, 1},    // NE
    {0, 1},     // E
    {1, 1},     // SE
    {1, 0},     // S
    {1, -1},    // SW
    {0, -1},    // W
    {1, -1}     // NW
};

typedef struct
{
    short int row;  /* current position */
    short int col;  /* current position */
    short int dir;  /* direction of next move */
} element;
element stack[MAX_STACK_SIZE];

int maze[MAX_ROWS][MAX_COLS] = {
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 1}, // start at maze[1][1]
    {1, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 0, 0, 1}, // end at maze[5][5]
    {1, 1, 1, 1, 1, 1, 1}
};
int mark[MAX_ROWS][MAX_COLS] = {
    {0, }, {0, }, {0, }, {0, }, {0, }, {0, }
};
#define EXIT_ROW 5
#define EXIT_COL 5
int top;

void push (element item)
{
    /* add an item to the global stack */
    if (top >= MAX_STACK_SIZE - 1)
    {
        puts("Push Error!");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}

element pop()
{
    /* retrun the top element from the stack, so called 'pop' */
    if (top == -1)
    {
        puts("Pop Error!");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

void path(void)
{
    /* output a path through the maze if such a path exists */
    int i;
    int row, col;
    int nextRow, nextCol;
    int dir;
    int found = FALSE;
    element position;

    mark[1][1] = 1; top = 0;
    stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;

    while(top > -1 && !found)
    {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;
        
        while (dir < 8 && !found)
        {
            /* move in direction dir */
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            
            if ( nextRow == EXIT_ROW && nextCol == EXIT_COL )
            {
                found = TRUE;
            }
            else if ( !maze[nextRow][nextCol] && !mark[nextRow][nextCol] )
            {
                mark[nextRow][nextCol] = 1;
                position.row = row; position.col = col;
                position.dir = ++dir;
                push(position);
                row = nextRow; col = nextCol; dir = 0;
            }
            else ++dir;
        }
    }

    if (found)
    {
        printf("The path is:\n");
        printf("row  col\n");
        for (i = 0; i <= top; i++)
            printf("%2d%5d\n", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    }
    else
    {
        printf("The maze does not have a path\n");
    }
    
}

int main()
{
    path();
    return 0;
}