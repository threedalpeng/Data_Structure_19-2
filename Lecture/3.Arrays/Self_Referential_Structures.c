#include <stdlib.h>

typedef struct list
{
    char data;
    struct list* link;
} list;

int main(void)
{
    list item1, item2, item3;
    item1.data = 'a';
    item2.data = 'b';
    item3.data = 'c';
    item1.link = item2.link = item3.link = NULL;

    item1.link = &item2; // 구조들을 서로 연결
    item2.link = &item3; // item1->item2->item3
}