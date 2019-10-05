#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100
char s[MAX_SIZE] = {"dog"};
char t[MAX_SIZE] = {"house"};
char pat1[MAX_SIZE] = {"og"};
char pat2[MAX_SIZE] = {"dor"};
int failure[MAX_SIZE];

void strnins(char*, char*, int);
int nfind(char* s, char* pat);
int pmatch(char*, char*);
void fail(char*);

int main()
{
    printf("Original string: %s\n", s);
    printf("Before inserting: %s\n", t);
    strnins(s, t, 3);
    printf("After inserting: %s\n", t);
    printf("Pattern to match: %s\n", pat1);
    printf("Finding by pattern match: %s\n", pmatch(s, pat1) ? "true" : "false");
    printf("Finding by fast pattern match: %s\n", pmatch(s, pat1) ? "true" : "false");
    printf("Pattern to match: %s\n", pat2);
    printf("Finding by pattern match: %s\n", pmatch(s, pat2) ? "true" : "false");
    printf("Finding by fast pattern match: %s\n", pmatch(s, pat2) ? "true" : "false");
    return 0;
}

void strnins(char* s, char* t, int i)
{
    char string[MAX_SIZE], *temp = string;
    
    if (i < 0 || i > strlen(s))
    {
        fprintf(stderr, "Position is out of bounds\n");
        exit(1);
    }
    if (!strlen(s))
        strcpy(s, t);
    else if (strlen(t))
        strncpy(temp, s, i);
        strcat(temp, t);
        strcat(temp, (s + i));
        strcpy(s, temp);
}

// Pattern Matching
int nfind(char* s, char* pat)
{
    int i, j, start = 0;
    int lasts = strlen(s) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;

    for(i = 0; endmatch <= lasts; endmatch++, start++)
    {
        if (s[endmatch] == pat[lastp])
            for(j = 0, i = start; j < lastp && s[i] == pat[j]; i++, j++) 
                ;
        if (j == lastp)
            return start;
    }
    return -1;
}

// Fast Pattern Matching
int pmatch(char* s, char* pat)
{
    int i = 0, j = 0;
    int lens = strlen(s);
    int lenp = strlen(pat);

    while( i < lens && j < lenp)
    {
        if (s[i] == pat[j])
        {
            i++; j++;
        }
        else if (j == 0) i++;
        else j = failure[j-1] + 1;
    }
    return ((j == lenp) ? (i - lenp) : -1);
}

void fail(char* pat)
{
    int n = strlen(pat);
    int i, j;
    failure[0] = -1;
    for (j = 1; j < n; j++)
    {
        i = failure[j - 1];
        while(pat[j] != pat[i+1] && i >= 0)
            i = failure[i];
        if (pat[j] == pat[i+1])
            failure[j] = i + 1;
        else failure[j] = -1;
    }
}