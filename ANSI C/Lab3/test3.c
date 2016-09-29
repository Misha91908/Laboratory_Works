#include <stdio.h>
int main(void)
{
    float x,a;
    scanf("%f", &x); scanf("%f", &a);
    do /*в отличие от while, do выполняется как минимум один раз,
 * затем идет проверка условия,если верно, то цикл продолжается*/
    {
        printf("%f %f\n", x, a);
        x += 0.5;
    }
    while (x > a);
    return 0;
}

