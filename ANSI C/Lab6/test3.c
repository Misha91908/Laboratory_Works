#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    struct
    {
        int id;
        float height;
        char color[255];
        char material[255];

    } chair;
    scanf("%d", &chair.id);  /*данные о стуле вводятся вручную*/
    scanf("%f", &chair.height);
    scanf("%s", &chair.color);
    scanf("%s", &chair.material);
    printf("The chair have: id=%d, height=%2.5f, color=%s, material=%s\n", chair.id, chair.height, chair.color, chair.material);
    return 0;
}