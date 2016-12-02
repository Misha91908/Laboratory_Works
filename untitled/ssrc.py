import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as ax3d
from math import sqrt


def reading_data():  # функция, считывающая данные из фала в список
    f = open('qwe.txt', 'r')

    func_dat = []  # список, в котором обрабатываются считанные данные
    for line in f:
        if line != '\n':
            func_dat.append(line)  # считывание данных с файла, всех, кроме пустых строк
    f.close()
    return func_dat


def sort_data(func_dat):
    """
    функция, удаляющая некорректные данные из списка, при этом данные считываются в другой список
    """
    func_data = []  # список для хранения координат точек по 3 осям
    for i in range(len(func_dat) - 1):
        """
        проверка списка на символы-разделители данных,
        если одного элемента не хватает, то элемент списка удаляется
        """
        char_position = func_dat[i].find('C')
        char_position1 = func_dat[i].find('B')
        char_position2 = func_dat[i].find('A')
        if char_position == -1 or char_position1 == -1 or char_position2 == -1:
            func_dat.pop(i)

    for i in range(len(dat) - 1):
        """
        проверка списка на корректность полученных данных,
        если встречаются посторонние символы, то элемент списка удаляется
        """
        char_position = func_dat[i].find('C')
        char_position1 = func_dat[i].find('B')
        char_position2 = func_dat[i].find('A')
        for iterator in range(len(dat[i])):
            if func_dat[i][char_position + 1] not in {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}:
                func_dat.pop(i)
            elif func_dat[i][char_position1 + 1] not in {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}:
                func_dat.pop(i)
            elif func_dat[i][char_position2 + 1] not in {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}:
                func_dat.pop(i)

    for i in range(len(func_dat) - 1):  # заполнение списка для хранения координат по 3 осям
        func_dat[i] = func_dat[i].replace('A', ':')
        func_dat[i] = func_dat[i].replace('B', ':')
        func_dat[i] = func_dat[i].replace('C', ':')
        func_data.append(func_dat[i].split(':'))
        func_data[i].pop(0)
    return func_data


def filling_coord_lists(func_data):  # функция, переписывающая координаты из общего списка в 3 другоих
    func_data_x = []
    func_data_y = []
    func_data_z = []
    func_buf = []
    """
    func_data_x - список абсцисс точек
    func_data_y - список ординат точек
    func_data_z - список аппликат точек
    """

    for i in range(len(func_data) - 1):  # заполнение списков хранения точек
        func_data_x.append(data[i][0])
        func_data_y.append(data[i][1])
        func_data_z.append(data[i][2])

    for i in range(len(func_data) - 1):  # перевод значений координат точек
        func_data_z[i] = func_data_z[i].replace('\n', ' ')
        func_data_z[i] = func_data_z[i].rstrip()
        func_data_x[i] = float(func_data_x[i]) / 300
        func_data_y[i] = float(func_data_y[i]) / 300
        func_data_z[i] = float(func_data_z[i]) / 300
    func_buf.append(func_data_x)
    func_buf.append(func_data_y)
    func_buf.append(func_data_z)
    return func_buf


def calculating_the_distance(func_data_x, func_data_y, func_data_z):  # функция, рассчитывающая длину тракетории
    track = 0.0  # длина траектории перемещения
    length = 0.0  # расстояние между двумя соседними точками

    for i in range(len(func_data_x) - 2):  # вычисление длины траектории перемещения
        vector_x = func_data_x[i + 1] - func_data_x[i]
        vector_y = func_data_y[i + 1] - func_data_y[i]
        vector_z = func_data_z[i + 1] - func_data_z[i]
        length = sqrt(vector_x * vector_x + vector_y * vector_y + vector_z * vector_z)
        track = track + length
    return track


def simple_moving_average(func_data_x, func_data_y, func_data_z):  # усреднение зечений(простая скользящая средняя)
    window = 150
    buf = []  # буферная строка для промежуточных операций
    lengthList = len(func_data_x)

    for i in range(lengthList - 149):  # усреднение значений
        iterator = 0
        for iterator_1 in range(149):
            iterator += 1
            func_data_x[i] = func_data_x[i] + func_data_x[i + iterator]
            func_data_y[i] = func_data_y[i] + func_data_y[i + iterator]
            func_data_z[i] = func_data_z[i] + func_data_z[i + iterator]
        func_data_x[i] = func_data_x[i] / 150
        func_data_y[i] = func_data_y[i] / 150
        func_data_z[i] = func_data_z[i] / 150
    return func_data_x, func_data_y, func_data_z


dat = reading_data()
data = sort_data(dat)
data_buf = filling_coord_lists(data)
data_x, data_y, data_z = simple_moving_average(data_buf[0], data_buf[1], data_buf[2])
length_list = len(data_x)

print("Длина траектории = ", calculating_the_distance(data_x, data_y, data_z))

fig = plt.figure()  # график траектории перемещения
ax = ax3d.Axes3D(fig)
ax.plot(data_x, data_y, data_z, color='green')
ax.scatter(data_x[0], data_y[0], data_z[0])
ax.scatter(data_x[length_list - 1], data_y[length_list - 1], data_z[length_list - 1], color='red')

fig1 = plt.figure()  # графики изменения проекций ускорения по 3 осям
plt.subplot(311)
plt.plot(data_x)
plt.title('Axelleration(x)')
plt.grid()

plt.subplot(312)
plt.plot(data_y)
plt.title('Axelleration(y)')
plt.grid()

plt.subplot(313)
plt.plot(data_z)
plt.title('Axelleration(z)')
plt.grid()

print(fig1.axes)
plt.show()
