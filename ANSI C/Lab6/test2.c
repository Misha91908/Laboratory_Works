#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    struct  /*объявляется структура, в которой хранится информация о стуле: ID, высота, цвет, материал*/
    {
        int id;
        float height;
        char color[255];
        char material[255];

    } chair;


    chair.id = 42;
    chair.height = 2.54;
    strcpy(chair.color, "green");
    strcpy(chair.material, "wood");

    printf("The chair have: id=%d, height=%2.5f, color=%s, material=%s\n", chair.id, chair.height, chair.color, chair.material);
    return 0; /*на экран выводятся данные о стуле*/
}