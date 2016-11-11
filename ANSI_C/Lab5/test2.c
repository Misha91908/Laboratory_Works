#include <stdio.h>


int main(void)
{
    char mystring[255];   /*объявляется массив символов(строка), вводится вручную и выводится на экран*/
    scanf("%s", &mystring);
    printf("%s\n", mystring);
    return 0;
}