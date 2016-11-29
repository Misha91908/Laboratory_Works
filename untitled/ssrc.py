import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as ax3d
from math import sqrt

f = open('qwe.txt', 'r')

dat = []  # список, в котором обрабатываются считанные данные
data = []  # список для хранения координат точек по 3 осям

for line in f:
    if line != '\n':
        dat.append(line)  # считывание данных с файла, всех, кроме пустых строк
f.close()

for i in range(len(dat) - 1):
    # проверка списка на символы-разделители данных, если одного элемента не хватает, то элемент списка удаляется
    k = dat[i].find('C')
    k1 = dat[i].find('B')
    k2 = dat[i].find('A')
    if k == -1 or k1 == -1 or k2 == -1:
        dat.pop(i)

for i in range(len(dat) - 1):
    """
    проверка списка на корректность полученных данных,
    если встречаются посторонние символы, то элемент списка удаляется
    """
    k = dat[i].find('C')
    k1 = dat[i].find('B')
    k2 = dat[i].find('A')
    for j in range(len(dat[i])):
        if dat[i][k+1] not in {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}:
            dat.pop(i)
        elif dat[i][k1 + 1] not in {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}:
            dat.pop(i)
        elif dat[i][k2 + 1] not in {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}:
            dat.pop(i)

for i in range(len(dat) - 1):  # заполнение списка для хранения координат по 3 осям
    dat[i] = dat[i].replace('A', ':')
    dat[i] = dat[i].replace('B', ':')
    dat[i] = dat[i].replace('C', ':')
    data.append(dat[i].split(':'))
    data[i].pop(0)

data_x = []  # список абсцисс точек
data_y = []  # список ординат точек
data_z = []  # список аппликат точек

for i in range(len(dat) - 1):  # заполнение списков хранения точек
    data_x.append(data[i][0])
    data_y.append(data[i][1])
    data_z.append(data[i][2])

for i in range(len(dat) - 1):  # перевод значений координат точек
    data_z[i] = data_z[i].replace('\n', ' ')
    data_z[i] = data_z[i].rstrip()
    data_x[i] = float(data_x[i])/300
    data_y[i] = float(data_y[i])/300
    data_z[i] = float(data_z[i])/300

track = 0.0  # длина траектории перемещения
length = 0.0  # расстояние между двумя соседними точками

for i in range(len(dat) - 2):  # вычисление длины траектории перемещения
    vector_x = data_x[i+1] - data_x[i]
    vector_y = data_y[i + 1] - data_y[i]
    vector_z = data_z[i + 1] - data_z[i]
    length = sqrt(vector_x*vector_x+vector_y*vector_y+vector_z*vector_z)
    track = track + length

print("общее расстояние =", track)

p = len(data_x)
window = int(input("Введите окно: "))
buf = []

for i in range(p - 99):  # усреднение значений
    for k in range(window):
        buf.append(data_x[i + k])
    for c in range(window):
        for cc in range(window):
            if buf[cc] < buf[c]:
                k = buf[c]
                buf[c] = buf[cc]
                buf[cc] = k
    if window % 2 == 0:
        data_x[i] = (buf[window // 2 - 1] + buf[window // 2]) / 2
    else:
        data_x[i] = buf[window // 2]
    buf.clear()
    for k in range(window):
        buf.append(data_y[i + k])
    for c in range(window):
        for cc in range(window):
            if buf[cc] < buf[c]:
                k = buf[c]
                buf[c] = buf[cc]
                buf[cc] = k
    if window % 2 == 0:
        data_y[i] = (buf[window // 2 - 1] + buf[window // 2]) / 2
    else:
        data_y[i] = buf[window // 2]
    buf.clear()

fig = plt.figure()  # график траектории перемещения
ax = ax3d.Axes3D(fig)
ax.plot(data_x, data_y, data_z, color='green')
ax.scatter(data_x[0], data_y[0], data_z[0])
ax.scatter(data_x[p-1], data_y[p-1], data_z[p-1], color='red')

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
