#include <stdio.h>
#include <string.h>
#include <stdlib.h>


float fadd(float a_firstValue, float a_secondValue)
{
    float a_resultValue = a_firstValue + a_secondValue; /*функция, считающая значение суммы двух переменных*/
    return a_resultValue;
}


int main(void)
{
    float m_firstValue = 41.0f, m_secondValue = 1.0f;
    float m_resultValue;


    m_resultValue = fadd(m_firstValue, m_secondValue); /*обращение и использование заданной функции*/


    printf("%lf\n", m_resultValue);


    return 0;
}