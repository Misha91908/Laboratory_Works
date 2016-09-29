#include <stdio.h>
#include <math.h>

int main() {
    float x1_value, x2_value, a_par, delta, x;
    double G_function, F_function, Y_function;
    scanf("%f", &x1_value);
    scanf("%f", &x2_value);
    scanf("%f", &a_par);
    scanf("%f", &delta);
    for (x = x1_value; x <= x2_value; x += delta) { /*объявляются 3 цикла, с помощью которых считаются значения функций,
 * с учетом входа х в область определения там,где это требуется, и выводятся на экран*/
        G_function = (5 * (-2 * a_par * a_par + a_par * x + 3 * x * x)) /
                     (10 * a_par * a_par + 11 * a_par * x + 3 * x * x);
        printf("%f ", G_function);
    }
    printf("\n");
    for (x = x1_value; x <= x2_value; x += delta) {
        F_function = pow(2, 10 * a_par * a_par - 29 * a_par * x + 18 * x * x);
        printf("%f ", F_function);
    }
    printf("\n");
    for (x = x1_value; x <= x2_value; x += delta) {
        if ((1 + 15 * a_par * a_par - 29 * a_par * x + 12 * x * x) / (1 -15 * a_par * a_par +29 * a_par * x + 12 * x * x)>0)
        {
            Y_function = 0.5 * log((1 + 15 * a_par * a_par - 29 * a_par * x + 12 * x * x) /
                                   (1 - 15 * a_par * a_par + 29 * a_par * x + 12 * x * x));
            printf("%f ", Y_function);
        }
    }
    return 0;
}