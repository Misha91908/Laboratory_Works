int main(void)
{
    char mystring[255];
    int test;
    char result[255];


    scanf("%s", &mystring);
    test = atoi(mystring);  /*функция преобразования строки в целое число*/
    printf("%d\n", test);
    itoa(test,result,10);  /*функция преобразования целого числа в строку*/
    printf("%s\n", result);


    return 0;
}