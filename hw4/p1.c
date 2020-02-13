#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 51

typedef struct
{
    int suit;
    int rank;
} Card;

char shape[4] = {'C', 'D', 'H', 'S'};
const char* num[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

int cmp(Card c1, Card c2)
{
    if (c1.suit < c2.suit)
		return -1;
	else if (c1.suit > c2.suit)
		return 1;
	else
	{
		if (c1.rank < c2.rank)
			return -1;
		else if (c1.rank > c2.rank)
			return 1;
	}
	return 0;
}

void quicksort(Card* arr, int first, int last, int (*comp)(Card s1, Card s2))
{
	int left, right;
	Card tmp, pivot;
	if (first < last)
	{
		left = first - 1;
		right = last + 1;
		pivot = arr[(first + last) / 2];
		while (1) {
			while (comp(arr[++left], pivot) < 0);
			while (comp(arr[--right], pivot) > 0);
			if (left >= right) break;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
		quicksort(arr, first, left - 1, comp);
		quicksort(arr, right + 1, last, comp);
	}
}

int main()
{
    int N;
    scanf("%d", &N);
    Card* cards = (Card*)malloc(sizeof(Card) * N);
    char s, r[3] = {};
    for (int i = 0; i < N; i++)
    {
		scanf(" %c %s", &s, r);
		for(int j = 0; j < 4; j++)
			if (s == shape[j])
			{
				cards[i].suit = j;
				break;
			}
		for(int j = 0; j < 13; j++)
			if (strcmp(r , num[j]) == 0)
			{
				cards[i].rank = j;
				break;
			}
    }
	quicksort(cards, 0, N-1, cmp);
    for (int i = 0; i < N; i++)
    {
		printf("%c %s\n", shape[cards[i].suit], num[cards[i].rank]);
    }
}