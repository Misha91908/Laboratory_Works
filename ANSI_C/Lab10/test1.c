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
        sat->alt = i+2;
        sat->lat = i+3;
        sat->lon = i+4;
        printf("%lf %lf %lf\n", sat->alt, sat->lat, sat->lon);
    }

    free(sat);

    sat = NULL;

    return 0;
}