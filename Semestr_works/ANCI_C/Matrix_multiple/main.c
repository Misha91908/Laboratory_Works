#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matrix1[3][3], matrix2[3][3], matrix_result[3][3];
    int i, j, k = 0, buf = 0, counter = 0;

    srand(time(NULL));

    for (i = 0; i < 3; i++)  /*заполнение матриц-исходников*/
    {
        for (j = 0; j < 3; j++)
        {
            matrix1[i][j] = rand()/10000000;
            matrix2[i][j] = rand()/10000000;
        }
    }
    printf("\n");

    for (i = 0; i < 3; i++)  /*очистка пока что не заполненной матрицы от случайных данных*/
    {
        for (j = 0; j < 3; j++)
        {
            matrix_result[i][j] = 0;
        }
    }

    while(counter < 9)  /*умножение матриц путем сложения произведений элементов i строки j столбца*/
    {
        while (i < 3)
        {
            for (k = 0; k < 3; k++)
            {
                for (j = 0; j < 3; j++)
                {
                    buf += matrix1[i][j] * matrix2[j][k];
                }
                matrix_result[i][k] = buf;
                counter++;
                buf = 0;
            }
            i++;
        }
        i = 0;
    }

    for (i = 0; i < 3; i++)  /*вывод матрицы-результата на экран*/
    {
        for (j = 0; j < 3; j++)
        {
             printf("%d ", matrix_result[i][j]);
        }
        printf("\n");
    }
    return 0;
}