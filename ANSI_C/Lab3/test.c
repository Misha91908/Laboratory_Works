#include <stdio.h>
#include <math.h>

int main() {
    char name;
    int change;
    float a, x, x2, step, delta;
    double function = 0.0, delta_function;
    enter:
    printf("Введите первую границу для рассчета функции: ");
    scanf("%f", &x);
    getchar();
    printf("Введите вторую границу для рассчета функции: ");
    scanf("%f", &x2);
    getchar();
    printf("Введите параметр а: ");
    scanf("%f", &a);
    getchar();
    printf("Введите шаг: ");
    scanf("%f", &step);
    getchar();
    printf("Введите разницу между значениями функций: ");
    scanf("%f", &delta);
    getchar();
    printf("Выберите функцию: ");
    scanf("%c", &name);
    getchar();

    switch (name) {  /*выбирается функция,считается ее значение по введенным х, x2 и а, если это возможно*/
        case 'G':
            while (x < x2)
            {
                if ((10 * a * a + 11 * a * x + 3 * x * x) != 0)
                {
                    function = (5 * (-2 * a * a + a * x + 3 * x * x)) / (10 * a * a + 11 * a * x + 3 * x * x);
                    printf("G = %f\n", function);
                }
                delta_function = (5 * (-2 * a * a + a * (x + step) + 3 * (x + step) * (x + step))) /
                                 (10 * a * a + 11 * a * (x + step) + 3 * (x + step) * (x + step));
                if (fabs(delta_function - function) <
                    delta)  /*если функция меняется слишком быстро(или медленно), то меняется шаг*/
                {
                    while (fabs(delta_function - function) < delta)
                    {
                        step *= 2;
                        delta_function = (5 * (-2 * a * a + a * (x + step) + 3 * (x + step) * (x + step))) /
                                         (10 * a * a + 11 * a * (x + step) + 3 * (x + step) * (x + step));
                    }
                }
                x = x + step;
                if (x >= x2)
                    break;

            }
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите любой символ.");
            scanf("%d", &change); /*если пользователь захочет посчитать еще раз,
 * то после выполнения рассчетов ему предлагается ввести контрольное значение для перехода к началу программы*/
            getchar();
            if (change == 1)
                goto enter;
            break;
        case 'F':
            while (x < x2) {
                function = pow(2, 10 * a * a - 29 * a * x + 18 * x * x);
                printf("F = %f\n", function);
                delta_function = pow(2, 10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step));
                if (delta_function - function > delta) {
                    while (delta_function - function > delta) {
                        step /= 2;
                        delta_function = pow(2, 10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step));
                    }
                }
                x = x + step;
                if (x >= x2) {
                    break;
                }
            }
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите дургой символ.");
            scanf("%d", &change);
            getchar();
            if (change == 1)
                goto enter;
            break;
        case 'Y':
            while (x < x2) {
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
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите любой символ.");
            scanf("%d", &change);
            getchar();
            if (change == 1)
                goto enter;
            break;
        default:
            printf("ничего не выбрано или некорректно введены данные");
            break;
    }
    return 0;
}