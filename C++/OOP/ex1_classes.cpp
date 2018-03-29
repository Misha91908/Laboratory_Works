#include <string>
#include "ex1_classes.h"

using namespace std;

float calculator::calculate(int status)
{
    float first_val = 0.0, second_val = 0.0;
    char operand;

    cin >> first_val >> operand >> second_val;
    switch (operand)
    {
        case '+':
            result = first_val + second_val;
            status = 1;
            return status;
        case '-':
            result = first_val - second_val;
            status = 1;
            return status;
        case '/':
            result = first_val / second_val;
            status = 1;
            return status;
        case ':':
            result = first_val / second_val;
            status = 1;
            return status;
        case '*':
            result = first_val * second_val;
            status = 1;
            return status;
        default:
            cout << "Некорректно введено выражение! Попробуйте еще раз.\n";
            status = 0;
            return status;
    }
}

loop_manager::loop_manager(calculator c)
{
    calc = c;
}

void loop_manager::start()
{
    string variants[] = {"Да", "да", "ДА", "дА", "Yes", "Y", "+", "Д", "Lf", "y", "д", "LF", "YES"};

    do
    {
        cout << "Введите желаемое выражение:" << endl;
        control = calc.calculate(control);
        if(control == 1)
        {
            cout << calc.result << endl;
            cout << "Желаете продолжить рассчеты? Введите Да, если хотите.\n";
            cin >> check;
            control = 0;
            for (int i = 0; i < sizeof(variants) / sizeof(variants[0]); i++)
            {
                if(check == variants[i])
                    control = 1;
            }
            if(control == 1)
                run = 1;
            else
            {
                run = 0;
                control = 0;
            }
        }
        else
            loop_manager.stop();
    }
    while(run == 1);
}