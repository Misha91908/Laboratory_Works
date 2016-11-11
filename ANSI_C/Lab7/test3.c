#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    float floatVar;
    FILE *file;

    file = (FILE *)fopen("test.txt", "r");
    fscanf(file, "%f", &floatVar); /*с файла считывается значение переменной floatVar и выводится на экран*/
    fclose(file);


    printf("%f\n", floatVar);


    return 0;
}