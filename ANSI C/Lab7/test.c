#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    FILE *f;

    struct
    {
        double G[100];
        double F[100];
        double Y[100];
    }data;

    char enter[100];
    float a, x, x2, step;
    float memory[1];
    int i = 0, k = 0;

    printf("Введите первую границу для рассчета функции: ");
    scanf("%s", enter);
    x = atof(enter);
    getchar();
    printf("Введите вторую границу для рассчета функции: ");
    scanf("%s", enter);
    x2 = atof(enter);
    getchar();
    printf("Введите параметр а: ");
    scanf("%s", enter);
    a = atof(enter);
    getchar();
    printf("Введите шаг: ");
    scanf("%s", enter);
    step = atof(enter);
    getchar();

    memory[0] = x;
    memory[1] = x2;

    while (x < x2)
    {
        data.G[i] = (5 * (-2 * a * a + a * x + 3 * x * x)) / (10 * a * a + 11 * a * x + 3 * x * x);
        i++;
        if (i > 100)
            break;
        x = x + step;
        if (x >= x2) {
            break;
        }
    }

    i = 0;
    x = memory[0];
    x2 = memory[1];

    while (x < x2)
    {
        data.F[i] = pow(2,10 * a * a - 29 * a * x + 18 * x * x);
        printf("F = %f\n", data.F[i]);
        i++;
        if (i > 100)
            break;
        x = x + step;
        if (x >= x2)
            break;

    }

    i = 0;
    x = memory[0];
    x2 = memory[1];

    while (x < x2)
    {
        if ((15 * a * a - 29 * a * x + 12 * x * x) > -1 && (15 * a * a - 29 * a * x + 12 * x * x) < 1) {
            data.Y[i] = 0.5 * log((15 * a * a - 29 * a * x + 12 * x * x + 1) /
                                  (1 - 15 * a * a + 29 * a * x - 12 * x * x));
            printf("Y = %f\n", data.Y[i]);
        }
        i++;
        if (i > 100)
            break;
        x = x + step;
        if (x >= x2)
            break;
    }

    f = fopen("output.txt","w");
    fprintf(f, "=====================================================================================================");
    for (i = 0; i < 100; i++)
    {
        fprintf(f,"| %lf | %lf | %lf |",data.G, data.F, data.Y);
        fprintf(f, "________________________________________________________________________________________________");
    }
    fclose(f);
    return 0;
}