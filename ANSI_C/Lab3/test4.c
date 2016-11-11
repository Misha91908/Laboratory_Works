#include <stdio.h>
int main(void)
{
    float x,a;
    scanf("%f", &x); scanf("%f", &a);
    for(;;) /*в данном случае задан бесконечный цикл, который ограничен при помощи опретаора break,
если условие выполнится в цикле, то цикл останавливатеся*/
    {
        printf("%f %f\n", x, a);
        x += 0.5;
        if (x > 5) break;
    }
    return 0;
}


