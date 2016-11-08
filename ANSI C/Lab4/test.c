#include <stdio.h>
#include <math.h>

int main()
{
    char name;
    int change, i = 0;
    float a, x, x2, step, delta;
    double function = 0.0, delta_function, max_y = 0.0, x_max = 0.0;
    double data_y[100];
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

    switch (name)
    {  /*выбирается функция,считается ее значение по введенным х, x2 и а, если это возможно*/
        case 'G':
            while (x < x2)
            {
                function = (5 * (-2 * a * a + a * x + 3 * x * x)) / (10 * a * a + 11 * a * x + 3 * x * x);
                printf("G = %f\n", function);
                data_y[i] = function;
                if (i >= 1)
                {
                   max_y = data_y[i];
                   if (max_y<data_y[i-1])
                   {
                       max_y = data_y[i-1];
                   }
                }
                i++;
                if (i>100) /* проверка на перезаполнение массива*/
                {
                    break;
                }
                delta_function = (5 * (-2 * a * a + a * (x + step) + 3 * (x + step) * (x + step))) /
                                 (10 * a * a + 11 * a * (x + step) + 3 * (x + step) * (x + step));
                if (fabs(delta_function - function) < delta)  /*если функция меняется слишком быстро(или медленно), то меняется шаг*/
                {
                    while (fabs(delta_function - function) < delta)
                    {
                        step *= 2;
                        delta_function = (5 * (-2 * a * a + a * (x + step) + 3 * (x + step) * (x + step))) /
                                         (10 * a * a + 11 * a * (x + step) + 3 * (x + step) * (x + step));
                    }
                }
                x_max = x;
                x = x + step;
                if (x>=x2) /*ограничение для адаптивного ввода,чтобы данные не выходили за пределы заданного интервала*/
                {
                    break;
                }
            }
            if (i > 1)/*если итерация была только одна,то выводится переменная function,
 *в противном случае вывелся бы 0(ошибка)*/
            {
                printf("G(max) = %f\n",max_y);
                i = 0;
            }
            else
            {
                printf("G(max) = %f\n",function);
            }

            printf("x(max) =  %f\n",x_max);
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите другой символ.");
            scanf("%d",&change); /*если пользователь захочет посчитать еще раз,
 * то после выполнения рассчетов ему предлагается ввести контрольное значение для перехода к началу программы*/
            getchar();
            if (change == 1)
                goto enter;
            break;
        case 'F':
            while (x < x2)
            {
                function = pow(2, 10 * a * a - 29 * a * x + 18 * x * x);
                printf("F = %f\n", function);
                data_y[i] = function;
                if (i == 1)
                {
                    max_y = data_y[i];
                    if (max_y<data_y[i-1])
                    {
                        max_y = data_y[i-1];
                    }
                }
                i++;
                if (i>100)
                {
                    break;
                }
                delta_function = pow(2, 10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step));
                if (delta_function - function > delta)
                {
                    while (delta_function - function > delta)
                    {
                        step /= 3;
                        delta_function = pow(2, 10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step));
                    }
                }
                x_max = x;
                x = x + step;
                if (x>=x2)
                {
                    break;
                }
            }
            if (i > 1)
            {
                printf("F(max) = %f\n",max_y);
                i = 0;
            }
            else
            {
                printf("F(max) = %f\n",function);
            }
            printf("x(max) = %f\n ",x_max);
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите другой символ.");
            scanf("%d",&change);
            getchar();
            if (change == 1)
                goto enter;
            break;
        case 'Y':
            while (x < x2)
            {
                if ((15 * a * a - 29 * a * x + 12 * x * x) > -1 && (15 * a * a - 29 * a * x + 12 * x * x) < 1)
                {
                    function = 0.5 * log((15 * a * a - 29 * a * x + 12 * x * x + 1) /
                                           (1 - 15 * a * a + 29 * a * x - 12 * x * x));
                    printf("Y = %f\n", function);
                }
                data_y[i] = function;
                if (i >=1)
                {
                    max_y = data_y[i];
                    if (max_y<data_y[i-1])
                    {
                        max_y = data_y[i-1];
                    }
                }
                i++;
                if (i>100)
                {
                    break;
                }
                x = x + step;
            }
            if (i > 1)
            {
                printf("Y(max) = %f\n",max_y);
                i = 0;
            }
            else
            {
                printf("Y(max) = %f\n",function);
            }
            printf("x(max) = %f\n",x);
            max_y = 0;
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите другой символ.");
            scanf("%d",&change);
            getchar();
            if (change == 1)
                goto enter;
            break;
        default:
            printf("Ничего не выбрано или некорректно введены данные.");
            break;
    }
    return 0;
}