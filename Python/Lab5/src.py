from math import atanh
from math import fabs

change = 1

while change == 1:
    enter = input("Введите первую границу для рассчета функции: ")
    x = float(enter)
    enter = input("Введите вторую границу для рассчета функции: ")
    x2 = float(enter)
    enter = input("Введите параметр: ")
    a = float(enter)
    enter = input("Введите шаг: ")
    step = float(enter)
    enter = input("Введите разницу между значениями функции: ")
    delta = float(enter)
    enter = input("Введите шаблон: ")
    name = input("Выберите функцию: ")
    i = 0
    output = str()
    counter = 0

    if name == 'G':
        while x < x2:
            if (10 * a * a + 11 * a * x + 3 * x * x) != 0:
                function = 5 * (-2 * a * a + a * x + 3 * x * x) / (10 * a * a + 11 * a * x + 3 * x * x)
                print("G = ", function)
                output = output + str(function)
            x += step
            i += 1
            if x >= x2 or i > 100:
                break
        print(output)
        output1 = output.split(enter)
        print(output1)
        k = len(output1)-1
        print(k)
        output = ' '
    elif name == 'F':
        while x < x2:
            function = 2 ** (10 * a * a - 29 * a * x + 18 * x * x)
            print("F = ", function)
            output = output + str(function)
            delta_function = 2 ** (10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step))
            if fabs(delta_function - function) > delta:
                while fabs(delta_function - function) > delta:
                    step /= 2
                    delta_function = 2 ** (10 * a * a - 29 * a * (x + step) + 18 * (x + step) * (x + step))
            x += step
            i += 1
            if x >= x2 or i > 100:
                break
        print(output)
        output1 = output.split(enter)
        print(output1)
        k = len(output1) - 1
        print(k)
        y = ' '
    elif name == 'Y':
        while x < x2:
            if 15 * a * a - 29 * a * x + 12 * x * x > -1 and 15 * a * a - 29 * a * x + 12 * x * x < 1:
                function = atanh(15 * a * a - 29 * a * x + 12 * x * x)
                print("Y = ", function)
                output = output + str(function)
            x += step
            i += 1
            if x >= x2 or i > 100:
                break
        print(output)
        output1 = output.split(enter)
        k = len(output1) - 1
        print(k)
        output = ' '
    else:
        print("Неправильно выбрана функция, или ничего не выбрано")
    change = int(input("Хотите посчитать другую функцию? Введите 1, если да, в противном случае - любой другой символ"))
