#include <stdio.h>
int main(void)
{
    float x, a;
    scanf("%f", &x);
    scanf("%f", &a);
    if (x > a)  /*сравнивается х и а*/
    {
        printf("x bolshe, chem a\n");
    }
    else
    {
        printf("x ne bolshe, chem a\n");
    }
    return 0;
}

