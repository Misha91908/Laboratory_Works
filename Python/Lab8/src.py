from math import sqrt
import random
"""
import matplotlib.pyplot as plt
import matplotlib.patches as ptch
import matplotlib.axes as ax
"""

x = []
y = []


def massive_generation():  # заполнение массива генератором случайных чисел
    for i in range(100):
        x.append(random.uniform(-5, 5))
        y.append(random.uniform(-5, 5))


def belong_to_locality(x_coord, y_coord, rad, changingpoint_x, changingpoint_y):
    # функция, определяющая принадлежность окрестности
    distance = sqrt((changingpoint_x - x_coord) ** 2 + (changingpoint_y - y_coord) ** 2)
    if distance <= rad:
        return 1
    else:
        return 0

def changepoint():
    change = random.randint(0,99)
    return change

def points_quantity(rad,change):  # функция, считающая число точек, входящих в окрестность
    counter = 0
    massive_generation()
    for i in range(100):
        if belong_to_locality(x[i], y[i], rad, x[change], y[change]) == 1:
            counter += 1
    return counter


radius = float(input("Введите радиус окрестности: "))
change = changepoint()
count = points_quantity(radius,change)
print("X = ", x)
print("Y = ", y)
print("Кол-во точек в окрестности: ", count)
"""
fig = plt.figure()
plt.scatter(x, y)
plt.scatter(x[change], y[change],color = 'red')
circle = ptch.Circle((x[change],y[change]),radius,color = "black")
plt.grid()

print(fig.axes)
plt.show()
"""
