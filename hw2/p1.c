#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NAME_SIZE 31

typedef struct 
{
    int age;
    char name[NAME_SIZE];
    int rank;
} Horse;

typedef struct _Heap
{
	int n_data;
	Horse heap[1001];
} Heap;

int compare(Horse first, Horse second);
void init(Heap* h);
void insert(Heap* h, Horse horse);
Horse delete(Heap* h);

int main(void)
{
    Heap heap;
    Horse horse;
    init(&heap);
    int N;
    char name[NAME_SIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d", name, &horse.age, &horse.rank);
        strcpy(horse.name, name);
        insert(&heap, horse);
    }
    for (int i = 0; i < N; i++)
    {
        horse = delete(&heap);
        printf("%d %s %d\n", horse.age, horse.name, horse.rank);
    }
}

int compare(Horse first, Horse second)
{
    int i, j, lenf, lens, charf, chars, gap;
    if (first.age > second.age) return 1;
    else if (first.age < second.age) return -1;
    else
    {
        gap = 'a' - 'A';
        lenf = strlen(first.name);
        lens = strlen(second.name);
        for (i = 0; i < lenf && i < lens; i++)
        {
            charf = (isupper(first.name[i]) ? first.name[i] + gap : first.name[i]);
            chars = (isupper(second.name[i]) ? second.name[i] + gap : second.name[i]);
            
            if (charf < chars) return 1;
            else if (charf > chars) return -1;
            else
            {
                if (first.name[i] < second.name[i]) return 1;
                else if (first.name[i] > second.name[i]) return -1;
            }
        }
        if (lenf < lens) return 1;
        else if (lenf > lens) return -1;

        if (first.rank < second.rank) return 1;
        else if (first.rank > second.rank) return -1;
        else return 0;
    }
}

void init(Heap* h)
{
    h->n_data = 0;
}

void insert(Heap* h, Horse horse)
{
    int i = ++(h->n_data);
    
    while(i != 1 && compare(horse, h->heap[i / 2]) == 1)
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = horse;
}

Horse delete(Heap* h)
{
    int parent = 1, child = 2;
    Horse horse = h->heap[parent], temp = h->heap[h->n_data--];

    while(child <= h->n_data)
    {
        if ((child < h->n_data) && compare(h->heap[child], h->heap[child+1]) == -1) child++;
        if ( compare(temp, h->heap[child]) != -1) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return horse;
}