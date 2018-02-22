#include <iostream>

using namespace std;

int main()
{
    double a = 0.0, b = 0.0, c = 0.0;
    int run = 1, control = 0;
    char operand;
    string check, variants[] = {"Да", "да", "ДА", "дА", "Yes", "Y", "+", "Д", "Lf", "y", "д", "LF", "YES"};
    do
    {
        cout << "Введите желаемое выражение:" << endl;
        cin >> a >> operand >> b;
        switch (operand)
        {
            case '+':
                c = a + b;
                control = 1;
                break;
            case '-':
                c = a - b;
                control = 1;
                break;
            case '/':
                c = a / b;
                control = 1;
                break;
            case ':':
                c = a / b;
                control = 1;
                break;
            case '*':
                c = a * b;
                control = 1;
                break;
            default:
                cout << "Некорректно введено выражение! Попробуйте еще раз.\n";
                run = 0;
        }
        if(control == 1)
        {
            cout << c << "\n";
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
    }
    while(run == 1);
    return 0;
}