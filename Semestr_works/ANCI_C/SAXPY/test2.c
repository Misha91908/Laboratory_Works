#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float vector(float x_value, int n, float a, float y)
{
    int i = 0;
    float s;
    for (i = 0; i < n; i++)
        s = a * x_value + y;
}

int main()
{
    float x_value[100000];
    double timer[100000],start,end;
    int iterator = 0;
    float a_parametr, y_value;
    FILE *f;
    srand(time(NULL));

    a_parametr = (float)rand()/RAND_MAX * (float)33.0;
    y_value = (float)rand()/RAND_MAX * (float)33.0;

    for (iterator = 0; iterator < 100000; iterator ++)
    {
        x_value[iterator] = (float)rand()/99;
    }

    f = fopen("/home/user/Laboratory_works/Semestr_works/ANCI_C/SAXPY/data1.log","w");
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