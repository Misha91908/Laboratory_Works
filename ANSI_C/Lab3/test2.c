#include <stdio.h>
int main(void)
{
    float x,a;

    scanf("%f", &x); scanf("%f", &a);
    while (x < a) /*пока выполняется условие, цикл прибавляет 0.5 к х*/
    {
        x += 0.5;
        printf("%f\n", x);
    }
    return 0;
}


