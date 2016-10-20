#include <stdio.h>
#include <math.h>

double f(double x)
{
    double f;
    f = (10*x*x+12)/(3*x*x+3*x+8);
    return f;
}

int main()
{
    double a, b, c, accuration, epsilon;
    int iterator = 0;

    printf("Введите первую границу интервала: ");
    scanf("%lf",&a);
    printf("Введите вторую границу интервала: ");
    scanf("%lf",&b);
    printf("Введите точность: ");
    scanf("%lf",&accuration);
    printf("Введите невязку: ");
    scanf("%lf",&epsilon);

    if (f(a)*f(b) < 0)
    {
        printf("Решений на заданном интервале нет, либо оно не единственное");
    }
    else
    {
        retry:
        c = (a + b)/2;
        iterator++;
        if (iterator>150) {
            goto end;
        }
        if (f(a)*f(c)<0)
            a = c;
        else
        {
            if (f(c)*f(b)<0)
                b = c;
        }
        if (fabs(b-a)<accuration && fabs(f(c))<epsilon)
            end:
            printf("x = %f",c);
        else
            goto retry;

    }
    return 0;
}