#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int *p;
    int N;

    printf("Введите количество чисел: ");
    scanf("%d", &N);
    N++;
    p = NULL;

    p = (int *) malloc(N * sizeof(int));

    for (int i = 1; i < N; i++)
    {
        p[i] = i;
    }

    for (int i = 1; i < N; i++)
    {
        printf("%d ", p[i]);
    }

    printf("\n");

    for (int i = 1; i < N; i++)
    {
        printf("%d ", p[i]*p[i]);
    }

    printf("\n");

    free(p);

    p = NULL;

    return 0;
}