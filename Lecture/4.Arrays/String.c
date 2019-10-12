#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_SIZE 100
char s[MAX_SIZE] = {"dog"};
char t[MAX_SIZE] = {"house"};
char pat1[MAX_SIZE] = {"og"};
char pat2[MAX_SIZE] = {"dor"};
char speed_test[MAX_SIZE] = {"wpvnpoewnewjpfjwpeocpoewoingoewnwienfvbndksjdovbekwbxut,nbzdwkpwmpoecweonfopnwepgrngvwnpcvmlxck"};
char speed_test_pat[MAX_SIZE] = {"asdfsdfa"};
int failure[MAX_SIZE];

void strnins(char*, char*, int);
int nfind(char* s, char* pat);
int pmatch(char*, char*);
void fail(char*);

int main()
{
    LARGE_INTEGER start1, start2, end1, end2, freq;
    QueryPerformanceFrequency(&freq);

    printf("Original string: %s\n", s);
    printf("String to insert: %s\n", t);
    strnins(s, t, 3);
    printf("After inserting: %s\n", s);
    printf("Pattern to match: %s\n", pat1);
    printf("Finding by pattern match: %s\n", nfind(s, pat1) + 1 ? "true" : "false");
    printf("Finding by fast pattern match: %s\n", pmatch(s, pat1) + 1  ? "true" : "false");
    printf("Pattern to match: %s\n", pat2);
    printf("Finding by pattern match: %s\n", nfind(s, pat2) + 1 ? "true" : "false");
    printf("Finding by fast pattern match: %s\n", pmatch(s, pat2) + 1 ? "true" : "false");
    
    printf("\nSpeed test\n");

    QueryPerformanceCounter(&start1);
    nfind(speed_test, speed_test_pat);
    QueryPerformanceCounter(&end1);
    double d1 = (double)(end1.QuadPart - start1.QuadPart) / freq.QuadPart * 1000000;

    QueryPerformanceCounter(&start2);
    pmatch(speed_test, speed_test_pat);
    QueryPerformanceCounter(&end2);
    double d2 = (double)(end2.QuadPart - start2.QuadPart) / freq.QuadPart * 1000000;

    printf("Pattern match duration: %.4lf us\n", d1);
    printf("Fast pattern match duration: %.4lf us\n", d2);

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
        else j = failure[j-1];
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