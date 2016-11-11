#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    FILE *file;

    file = (FILE *)fopen("/home/misha91908/output.txt", "w+");
    fprintf(file, "%f\n", 2.567f);  /*в текстовый фаил записывается число 2.567*/
    fclose(file);


    return 0;
}