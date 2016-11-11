#include <stdio.h>
#include <stdlib.h>

int main()
{
    double value;
    char recorder[100];
    int i = 0,k = 0,p = 0,counter = 0;

    scanf("%lf", &value);
    sprintf(recorder,"%lf",value);
    for (i = 0; i < 100;i++)
    {
        if (recorder[i] == '.')
        k = i;
    }
    for (i = k+1; i < 100; i++)
    {
        if (recorder[i] != '0')
        {
            printf("Число не целое\n");
            goto end;
        }

    }
    for (i = 0; i < k; i++)
    {
        p = atoi(recorder[i]);
        if (p % 2 == 0)
            counter++;
    }
    printf("Количество четных цифр в числе: %d\n", counter);
    end:
    return 0;
}