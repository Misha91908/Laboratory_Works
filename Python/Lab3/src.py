from math import atanh
from math import fabs

x = float(input("Введите первую границу для рассчета функции: "))
x2 = float(input("Введите вторую границу для рассчета функции: "))
a = float(input("Введите параметр: "))
step = float(input("Введите шаг: "))
delta = float(input("Введите разницу между значениями функции: "))
name = str(input("Выберите функцию: "))
i = 0

if name == 'G':
    while x < x2:
        if (10 * a * a + 11 * a * x + 3 * x * x) != 0:
            function = 5 * (-2 * a * a + a * x + 3 * x * x) / (10 * a * a + 11 * a * x + 3 * x * x)
            print("G = ", function)
        x += step
        i += 1
        if x >= x2 or i > 100:
            break
elif name == 'F':
    while x < x2:
        function = 2 ** 10 * a * a - 29 * a * x + 18 * x * x
        print("F = ", function)
        delta_function = 2 ** 10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step)
        if fabs(delta_function - function) > delta:
            while fabs(delta_function - function) > delta:
                step /= 2
                delta_function = 2 ** 10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step)
        x += step
        if x >= x2 or i > 100:
            break
elif name == 'Y':
    while x < x2:
        if (15 * a * a - 29 * a * x + 12 * x * x) > -1 and (15 * a * a - 29 * a * x + 12 * x * x) < 1:
            function = atanh(15 * a * a - 29 * a * x + 12 * x * x)
            print("Y = ", function)
        x += step
        if x >= x2 or i > 100:
            break
else:
    print("Неправильно выбрана функция, или ничего не выбрано")