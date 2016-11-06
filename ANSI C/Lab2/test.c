#include <stdio.h>
#include <math.h>

int main() {
    char name;
    float a, x;
    double G, F, Y;
    printf("Введите а: ");
    scanf("%f", &a);
    getchar();
    printf("Введите а: ");
    scanf("%f", &x);
    getchar();
    printf("Выберите функцию: ");
    scanf("%c", &name);
    getchar();
    switch (name) {  /*выбирается функция,считается ее значение по введенным х и а, если это возможно*/
        case 'G':
            G = (5 * (-2 * a * a + a * x + 3 * x * x)) / (10 * a * a + 11 * a * x + 3 * x * x);
            printf("G = %f\n", G);
            break;
        case 'F':
            F = pow(2, 10 * a * a - 29 * a * x + 18 * x * x);
            printf("F = %f\n", F);
            break;
        case 'Y':
            if (((15*a*a-29*a*x+12*x*x)>-1) && (15*a*a-29*a*x+12*x*x)<1)
            {Y =0.5*log((15*a*a-29*a*x+12*x*x+1)/(1-15*a*a+29*a*x-12*x*x));
                    printf("Y = %f\n", Y);}
            else{
                printf("значение не существует");
            }
            break;
        default:
            printf("ничего не выбрано");
            break;
    }
    return 0;
}
