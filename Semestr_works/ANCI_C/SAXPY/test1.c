#include <omp.h>
#include <stdio.h>

int main()
{
    double y_value[100000], x_value[100000], s_result[100000],a_parameter[100000];
    double timer[100000],start,end;
    int iterator = 0;

    x_value[0] = 0.2;
    y_value[0] = 0.2;
    a_parameter[0] = 0.2;

    for (iterator = 0; iterator < 100000; iterator++)
    {
        start = omp_get_wtime();
        s_result[iterator] = a_parameter[iterator]*x_value[iterator]+y_value[iterator];
        end = omp_get_wtime();
        timer[iterator] = end - start;
        if ((iterator+1) >= 10000)
            break;
        else
        {
            x_value[iterator+1] = x_value[iterator] + 0.2;
            y_value[iterator+1] = y_value[iterator] + 0.2;
            a_parameter[iterator+1] = a_parameter[iterator] + 0.2;
        }
        printf("%lf %lf\n",timer[iterator],s_result[iterator]);
    }
    return 0;
}