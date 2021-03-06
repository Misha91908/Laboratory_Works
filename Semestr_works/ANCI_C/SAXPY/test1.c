#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int vector(int x_value, int n, int a, int y)
{
    int i = 0,s;
    for (i = 0; i < n; i++)
        s = a * x_value + y;
}

int main()
{
    int x_value[100000];
    double timer[100000],start,end;
    int iterator = 0, a_parametr, y_value;
    FILE *f;
    srand(time(NULL));

    a_parametr = rand()/100;
    y_value = rand()/100;

    for (iterator = 0; iterator < 100000; iterator ++)
    {
        x_value[iterator] = rand()/100;
    }

    f = fopen("/home/user/Laboratory_works/Semestr_works/ANCI_C/SAXPY/data.log","w");
    for (iterator = 0; iterator < 100000; iterator += 10000)
    {
        start = omp_get_wtime();
        vector(x_value[iterator], iterator, a_parametr, y_value);
        end = omp_get_wtime();
        timer[iterator] = end - start;
        fprintf(f, "%lf\n", timer[iterator]);
    }
    fclose(f);
    return 0;
}