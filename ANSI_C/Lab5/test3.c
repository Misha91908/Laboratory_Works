#include <stdio.h>
#include <string.h>
/*библиотека для работы со строками*/
int main(void)
{
    char mystring[255];


    scanf("%s", &mystring);
    printf("%d\n", strlen(mystring)); /*выводится доина строки*/
    return 0;
}