#include <stdio.h>
int main(void)
{
    int a;
    scanf("%d", &a);
    switch (a)
    {
        case 1:
            printf("Vy vveli \"1\"\n");
            break;
        case 2:
            printf("Vy vveli \"2\"\n");
            break;
        default:
            printf("Vy vveli ne \"1\" i ne \"2\"");
            break;
    }
    return 0;
}

