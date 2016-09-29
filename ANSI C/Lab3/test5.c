#include <stdio.h>
int main(void)
{
    float x,a;
    scanf("%f", &x); scanf("%f", &a);
    for(;;)
    {
        printf("%f %f\n", x, a);
        x += 0.5; /*цикл выполняется до тех пор, пока условие не станет ложным*/
        if ((x < 5)) continue;
        else break;
    }
    return 0;
}

