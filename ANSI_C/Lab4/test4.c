#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j;
    int mas[10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            mas[i][j] = rand() % 100;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d\t", mas[i][j]);
        }
        printf("\n");
    }
    return 0;
}