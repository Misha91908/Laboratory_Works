#include <stdio.h>
#include <math.h>

int main() {
    char name;
    float a, x;
    double G, F, Y;
    scanf("%f %f %c", &a, &x, &name);
    getchar();
    switch (name) {
        case 'G':
            G = (5 * (-2 * a * a + a * x + 3 * x * x)) / (10 * a * a + 11 * a * x + 3 * x * x);
            printf("G = %f\n", G);
            break;
        case 'F':
            F = pow(2, 10 * a * a - 29 * a * x + 18 * x * x);
            printf("F = %f\n", F);
            break;
        case 'Y':
            if ((15*a*a-29*a*x+12*x*x+1)/(1-15*a*a+29*a*x-12*x*x)>0)
            {Y =0.5*log((15*a*a-29*a*x+12*x*x+1)/(1-15*a*a+29*a*x-12*x*x));
                    printf("Y = %f\n", Y);}
            else{
                printf("значение не существует");
            }
            break;
        default:
            printf("ничего не выбрано");
    }
    return 0;
}