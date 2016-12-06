#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double vector(double x_value, int n, double a, double y)
{
    int i = 0;
    double s;
    for (i = 0; i < n; i++)
        s = a * x_value + y;
}

int main()
{
    double x_value[100000];
    double timer[100000],start,end;
    int iterator = 0;
    double a_parametr, y_value;
    FILE *f;
    srand(time(NULL));

    a_parametr = (double)rand()/RAND_MAX * (double)33.0;
    y_value = (double)rand()/RAND_MAX * (double)33.0;

    for (iterator = 0; iterator < 100000; iterator ++)
    {
        x_value[iterator] = (double)rand()/99;
    }

    f = fopen("/home/user/Laboratory_works/Semestr_works/ANCI_C/SAXPY/data2.log","w");
    for (iterator = 0; iterator < 100000; iterator += 10000)
    {
        start = omp_get_wtime();
        vector(x_value[iterator], iterator, a_parametr, y_value);
        end = omp_get_wtime();
        timer[iterator] = end - start;
        fprintf(f, "%f\n", timer[iterator]);
    }
    fclose(f);
    return 0;
}