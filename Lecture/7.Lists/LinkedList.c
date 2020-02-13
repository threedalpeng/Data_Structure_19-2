#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode* listPointer;
typedef struct listNode
{
    char data[4];
    listPointer link;
};

int main(void)
{
    listPointer first = NULL;
    first = (listPointer)malloc(sizeof(*first));
    strcpy(first->data, "BAT");
    first->link = NULL;
}