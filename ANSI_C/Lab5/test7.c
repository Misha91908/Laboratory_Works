#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char mystring1[255];
    char mystring2[255];
    scanf("%s", &mystring1);
    scanf("%s", &mystring2);
    printf("%d\n", strcmp(mystring1, mystring2));  /*функция,сравнивающая 2 строки на совпадение, возвращает 0 при
 * полном совпадении строк, положительное число,если первая строка больше,отрицательное,если меньше*/
    return 0;
}