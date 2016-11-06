#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Point
{
    double x;
    double y;
};

typedef struct Point Point;

int main()
{
    Point massive[100];
    int i = 0,change, counter = 0;
    double radius;
    srand(time(NULL));

    printf("Введите радиус окрестности: ");
    scanf("%lf", &radius);

    change = rand() % 100;

    for (i = 0; i < 100;i++)
    {
        massive[i].x = (double)rand() / RAND_MAX * (5.0+5.0) - 5.0;
        massive[i].y = (double)rand() / RAND_MAX * (5.0+5.0) - 5.0;
    }

    for (i = 0; i < 100; i++)
    {
        if (sqrt((pow(2,massive[i].x-massive[change].x))+pow(2,massive[i].y-massive[change].y)) <= radius)
        {
            counter++;
        }
    }

    if (counter == 0)
    {
        printf("Количество точек,лежащих в окрестности: %d\n", counter);
    }
    else
    {
        printf("Количество точек,лежащих в окрестности: %d\n", counter - 1);
    }
    return 0;
}