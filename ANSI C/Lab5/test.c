#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char name;
    char entry[100], output[1000], pattern[100];
    int change, n = 0, i = 0,k = 0;
    float a, x, x2, step;
    double function;
    enter:
    printf("Введите первую границу для рассчета функции: ");
    scanf("%s", entry);
    x = atof(entry);
    getchar();
    printf("Введите вторую границу для рассчета функции: ");
    scanf("%s", entry);
    x2 = atof(entry);
    getchar();
    printf("Введите параметр а: ");
    scanf("%s", entry);
    a = atof(entry);
    getchar();
    printf("Введите шаг: ");
    scanf("%s", entry);
    step = atof(entry);
    getchar();
    printf("Ведиите шаблон: ");
    scanf("%s", pattern);
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
                sprintf(entry, "%lf", function);
                strcat(output,entry);
                x = x + step;
                if (x>=x2) /*ограничение для адаптивного ввода,чтобы данные не выходили за пределы заданного интервала*/
                {
                    break;
                }
            }
            printf("%s\n",output);
            while (n<strlen(output))
            {
                if (strstr(output, pattern) - output + 1 < strlen(output))
                {
                    i++;
                    n = strstr(output, pattern) - output + 1;
                    while (k != n)
                    {
                        output[k] = ' ';
                        k++;
                    }
                    k = 0;
                }
                if (strstr(output,pattern) == 0)
                    break;
            }
            printf("Найдено совпадений: %d\n",i);
            i = 0;
            n = strlen(output);
            while (n != 0)
            {
                for (k = 0; k<n;k++)
                {
                    output[k] = output[k+1];
                }
                n--;
            }
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите любой символ.\n");
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
                sprintf(entry, "%lf", function);
                strcat(output,entry);
                x = x + step;
                if (x>=x2)
                {
                    break;
                }
            }
            printf("%s\n",output);
            while (n<strlen(output))
            {
                if (strstr(output, pattern) - output + 1 < strlen(output))
                {
                    i++;
                    n = strstr(output, pattern) - output + 1;
                    while (k != n)
                    {
                        output[k] = ' ';
                        k++;
                    }
                    k = 0;
                }
                if (strstr(output,pattern) == 0)
                    break;
            }
            printf("Найдено совпадений: %d\n",i);
            i = 0;
            n = strlen(output);
            while (n != 0)
            {
                for (k = 0; k<n;k++)
                {
                    output[k] = output[k+1];
                }
                n--;
            }
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите дургой символ.");
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
                    sprintf(entry, "%lf", function);
                    strcat(output,entry);
                }
                x = x + step;
            }
            printf("%s\n",output);
            while (n<strlen(output))
            {
                if (strstr(output, pattern) - output + 1 < strlen(output))
                {
                    i++;
                    n = strstr(output, pattern) - output + 1;
                    while (k != n)
                    {
                        output[k] = ' ';
                        k++;
                    }
                    k = 0;
                }
                if (strstr(output,pattern) == 0)
                    break;
            }
            printf("Найдено совпадений: %d\n",i);
            i = 0;
            n = strlen(output);
            while (n != 0)
            {
                for (k = 0; k<n;k++)
                {
                    output[k] = output[k+1];
                }
                n--;
            }
            printf("Хотите посчитать другую функцию? Введите 1,если хотите, в противном случае введите любой символ.");
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