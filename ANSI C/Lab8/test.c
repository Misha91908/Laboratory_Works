#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Point
{
    double x[100];
    double y[100];
};

struct changing_point
{
    double changing_x;
    double changing_y;
};

typedef struct changing_point point;

typedef struct Point Point;

Point massive_generation(void)
{
    Point massive;
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < 100; i++) {
        massive.x[i] = (double) rand() / RAND_MAX * (5.0 + 5.0) - 5.0;
        massive.y[i] = (double) rand() / RAND_MAX * (5.0 + 5.0) - 5.0;
    }
    return massive;
}

int belong_to_interval(point massive, point mass,double rad)
{
    double distance;
    distance = sqrt((pow(2,mass.changing_x-massive.changing_x))+pow(2,mass.changing_y-massive.changing_y));
    if (distance <= rad)
        {
            return 1;
        }
    else
        {
            return 0;
        }

}
int points_quantity(Point massive, double rad)
{
    point po, po_for_func;
    Point mass;
    int counter;
    int i = 0, change;
    srand(time(NULL));

    change = rand() % 100;

    mass = massive_generation();
    mass.x[change] = po.changing_x;
    mass.y[change] = po.changing_y;

    for (i = 0; i < 100; i++)
    {
        po_for_func.changing_x = mass.x[i];
        po_for_func.changing_y = mass.y[i];
        if (belong_to_interval(po,po_for_func,rad) == 1)
        {
            counter++;
        }
    }
    if (counter != 0)
    {
       counter = counter - 1;
    }
    return counter;
}

int main()
{
    double radius;

    printf("Введите радиус окрестности: ");
    scanf("%lf", &radius);

    printf("Количество точек в заданной окрестности: %d", points_quantity(radius));
    return 0;
}