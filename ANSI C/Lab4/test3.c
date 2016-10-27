#include <stdio.h>
int main(void)
{
    int i = 0;
    float mas[5];
    for (i = 0; i < 5; i++)
        scanf("%f", &mas[i]);
    for (i = 0; i < 5; i++)
        printf("%f\n", mas[i]);
    return 0;
}
