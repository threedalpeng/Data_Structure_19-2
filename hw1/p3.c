#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 51

typedef struct
{
    char* str;
    int count;
} Word;

int cmp_dict(Word s1, Word s2)
{
    return strcmp(s1.str, s2.str);
}

int cmp_count(Word s1, Word s2)
{
    if (s1.count < s2.count)
        return 1;
    else if (s1.count > s2.count)
        return -1;
    else
        return strcmp(s1.str, s2.str);
}

void quicksort(Word* arr, int first, int last, int (*comp)(Word s1, Word s2))
{
	int left, right;
	Word tmp, pivot;
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
    Word* words = (Word*)malloc(sizeof(Word) * N);
    int* count_arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        words[i].str = (char*)malloc(sizeof(char) * MAX_SIZE);
        scanf("%s", words[i].str);
        words[i].count = 0;
        //printf("%s\n", s_arr[i]);
    }
    quicksort(words, 0, N-1, cmp_dict);
    int prev = 0;
    ++(words[0].count);
    for (int i = 1; i < N; i++)
    {
        if (strcmp(words[prev].str, words[i].str) == 0)
        {
            ++(words[prev].count);
            words[i].count = -1;
        }
        else
        {
            ++(words[i].count);
            prev = i;
        }
        //printf("%s\n", words[i].str);
    }
    quicksort(words, 0, N-1, cmp_count);
    int idx = 0;
    while(idx < N && words[idx].count >= 0)
    {
        printf("%s\n", words[idx++].str);
    }
}