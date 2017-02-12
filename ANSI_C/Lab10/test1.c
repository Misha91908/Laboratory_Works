#include <stdio.h>
#include <stdlib.h>

struct data
{
    float alt;
    float lat;
    float lon;
};

typedef struct data Telemetry;

int main(void)
{

    int N;
    Telemetry *sat;

    printf("Введите количество пакетов: ");
    scanf("%d", &N);
    N++;
    sat = NULL;

    sat = (Telemetry *) malloc(N * (sizeof(float)*3));

    for (int i = 1; i < N; i++)
    {
        sat[i].alt = i+2;
        sat[i].lat = i+3;
        sat[i].lon = i+4;
    }

    for (int i = 1; i < N; i++)
    {
        printf("%lf %lf %lf\n",sat[i].alt,sat[i].lat,sat[i].lon);
    }

    free(sat);

    return 0;
}