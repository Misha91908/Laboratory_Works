#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *string, input[1000];
    size_t length_string;

    memset(input, 1000, 0);

    printf("Введите строку латинскими символами: ");
    scanf("%s", input);

    length_string = strlen(input);
    input[length_string] = ' ';

    string = (char *) malloc(length_string + 1 * sizeof(char));

    for (int i = 0; i < length_string; i++)
    {
        string[i] = input[i];
        if (strchr("eyuioa", string[i]) != NULL)
        {
            printf("%c", string[i]);
        }
    }

    free(string);
    return 0;
}