#include <iostream>

using namespace std;

int main()
{
    double number = 0.0, result = 0.0;
    int iterator = 0;

    cout << "Введите число:\n";
    cin >> number;

    result = number;
    while (result*result != number)
    {
        result = 0.5 *(result + (number / result));
        iterator++;
        if(iterator > 150)
            break;
    }

    cout << "Квадратный корень из числа " << number << " = " << result << endl;

    return 0;
}