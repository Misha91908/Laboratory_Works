#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char enter[100];
    float a, x, x2, step, delta;
    float memory[1];
    double function, delta_function;
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
    printf("Введите разницу между значениями функций: ");
    scanf("%s", enter);
    delta = atof(enter);
    getchar();

    memory[0] = x;
    memory[1] = x2;

    while (x < x2)
    {
        function = (5 * (-2 * a * a + a * x + 3 * x * x)) / (10 * a * a + 11 * a * x + 3 * x * x);
        printf("G = %f\n", function);
        delta_function = (5 * (-2 * a * a + a * (x + step) + 3 * (x + step) * (x + step))) /
                         (10 * a * a + 11 * a * (x + step) + 3 * (x + step) * (x + step));
        if (fabs(delta_function - function) <
            delta)  /*если функция меняется слишком быстро(или медленно), то меняется шаг*/
        {
            while (fabs(delta_function - function) < delta) {
                step *= 2;
                delta_function = (5 * (-2 * a * a + a * (x + step) + 3 * (x + step) * (x + step))) /
                                 (10 * a * a + 11 * a * (x + step) + 3 * (x + step) * (x + step));
            }
        }
        x = x + step;
        if (x >= x2) {
            break;
        }
    }
    printf("=============================================================================\n");

    x = memory[0];
    x2 = memory[1];

    while (x < x2)
    {
        function = a * a - 9 * a * x + 8 * x * x;
        printf("F = %f\n", function);
        delta_function = a * a - 9 * a * (x + step) + 8 * (x + step) * (x + step);
        if (delta_function - function > delta) {
            while (delta_function - function > delta) {
                step *= 2;
                delta_function = a * a - 9 * a * (x + step) + 8 * (x + step) * (x + step);
            }
        }
        x = x + step;
        if (x >= x2) {
            break;
        }
    }
    printf("=============================================================================\n");

    x = memory[0];
    x2 = memory[1];

    while (x < x2)
    {
        if ((15 * a * a - 29 * a * x + 12 * x * x) > -1 && (15 * a * a - 29 * a * x + 12 * x * x) < 1) {
            function = 0.5 * log((15 * a * a - 29 * a * x + 12 * x * x + 1) /
                                 (1 - 15 * a * a + 29 * a * x - 12 * x * x));
            printf("Y = %f\n", function);
        }
        x = x + step;
        if (x >= x2) {
            break;
        }
    }

    return 0;
}