from math import atanh
from math import fabs

x = float(input("Введите первую границу для рассчета функции: "))
x2 = float(input("Введите вторую границу для рассчета функции: "))
a = float(input("Введите параметр: "))
step = float(input("Введите шаг: "))
delta = float(input("Введите разницу между значениями функции: "))
name = str(input("Выберите функцию: "))
y = []
i = 0

if name == 'G':
    while x < x2:
        if (10 * a * a + 11 * a * x + 3 * x * x) != 0:
            function = 5 * (-2 * a * a + a * x + 3 * x * x) / (10 * a * a + 11 * a * x + 3 * x * x)
            print("G = ", function)
            y.append(function)
        if i > 0:
            if y[i] > y[i - 1]:
                y_max = y[i]
            else:
                y_max = y[i - 1]
        x += step
        i += 1
        if x >= x2 or i > 100:
            break
    print(y)
    if i == 1:
        print("У(max) = ", y[0])
    else:
        print("У(max) = ", y_max)
    print("X(max) = ", x)
elif name == 'F':
    while x < x2:
        function = 2 ** (10 * a * a - 29 * a * x + 18 * x * x)
        print("F = ", function)
        y.append(function)
        if i > 0:
            if y[i] > y[i - 1]:
                y_max = y[i]
            else:
                y_max = y[i - 1]
        delta_function = 2 ** (10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step))
        if fabs(delta_function - function) > delta:
            while fabs(delta_function - function) > delta:
                step /= 2
                delta_function = 2 ** (10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step))
        x += step
        i += 1
        if x >= x2 or i > 100:
            break
    print(y)
    if i == 1:
        print("У(max) = ", y[0])
    else:
        print("У(max) = ", y_max)
    print("X(max) = ", x)
elif name == 'Y':
    while x < x2:
        if 15 * a * a - 29 * a * x + 12 * x * x > -1 and 15 * a * a - 29 * a * x + 12 * x * x < 1:
            function = atanh(15 * a * a - 29 * a * x + 12 * x * x)
            print("Y = ", function)
            y.append(function)
        if i > 0:
            if y[i] > y[i - 1]:
                y_max = y[i]
            else:
                y_max = y[i - 1]
        x += step
        i += 1
        if x >= x2 or i > 100:
            break
        print(y)
        if i == 1:
            print("У(max) = ", y[0])
        else:
            print("У(max) = ", y_max)
        print("X(max) = ", x)
else:
    print("Неправильно выбрана функция, или ничего не выбрано")
