#include <stdio.h>
#include <stdlib.h>
/* malloc과 같지만, 실패 시 에러 출력 및 종료 기능을 붙임 */
#define MALLOC(p, s) if (!((p) = malloc(s))) {\
                        fprintf(stderr, "Insufficient memory");\
                        exit(EXIT_FAILURE);\
                    }

int main(void)
{
    int i, n, *list;
    printf("Enter the number of number to generate: ");
    scanf("%d", &n);
    if (n < 1)
    {
        fprintf(stderr, "Improper value of n");
        exit(EXIT_FAILURE);
    }
    
    MALLOC(list, n * sizeof(int));

    for (i = 0; i < n; i++)
        list[i] = rand() % 50;
    for (i = 0; i < n; i++)
        printf("%d\n", list[i]);
}