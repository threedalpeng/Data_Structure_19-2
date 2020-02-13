/* c++ 환경에서는 delete는 이미 키워드가 예약되어 있기 때문에
delete함수 선언에서 에러가 나므로 다른 이름으로 바꿀 것! */
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
struct listNode
{
    int data;
    listPointer link;
};

listPointer create2()
{
    /* Create a linked list with two nodes */
    listPointer first, second;

    first = (listPointer)malloc(sizeof(*first));
    second = (listPointer)malloc(sizeof(*second));

    second->link = NULL;
    second->data = 20;

    first->data = 10;
    first->link = second;

    return first;
}

void insert50(listPointer *first, listPointer x)
{
    /* insert a new node with data = 50 into the chain first after node x */
    listPointer temp;
    temp = (listPointer)malloc(sizeof(*temp));
    temp->data = 50;
    if (*first)
    {
        temp->link = x->link;
        x->link = temp;
    }
    else
    {
        temp->link = NULL;
        *first = temp;
    }
}

void delete(listPointer* first, listPointer trail, listPointer x)
{
    /* delete x from the list, trail is the preceding node 
    and *first is the front of the list */
    if (trail) 
        trail->link = x->link;
    else
        *first = (*first)->link;
    free(x);
}

void printList(listPointer first)
{
    printf("%d ", first->data);
    while(first->link)
    {
        first = first->link;
        printf("%d ", first->data);
    }
    puts("");
}

int main(void)
{
    listPointer list = create2();
    puts("Created list:");
    printList(list);
    insert50(&list, list);
    puts("After insertion:");
    printList(list);
    delete(&list, list, list->link);
    puts("After deletion:");
    printList(list);
}