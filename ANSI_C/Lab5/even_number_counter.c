#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double value;
    char recorder[100],resender[100];
    long int p = 0,t = 0;
    int i = 0,k = 0,counter = 0;
    entry:
    scanf("%lf", &value);
    if (value / 100000000 >= 1)
        goto entry;
    memset(recorder,0,100);
    memset(resender,0,100);
    sprintf(recorder,"%lf",value);
    for (i = 0; i < 100;i++)
    {
        if (recorder[i] == '.')
        {
            k = i;
            break;
        }
        resender[i] = recorder[i];
    }
    for (i = k+1; i < 100; i++)
    {
        if (recorder[i] != '0' && recorder[i] != '\000')
        {
            printf("Число не целое\n");
            goto end;
        }
    }
    p = atoi(resender);
    while (p > 0)
    {
        t = p % 10;
        if (t % 2 == 0)
           counter++;
        p = p / 10;
    }
        printf("Количество четных цифр в числе: %d\n", counter);
    end:
    return 0;
}