import matplotlib.pyplot as plt
from random import random


def SMA(input_data, window):
    output_data = []
    for i in range(window):
        output_data.append(None)

    for i in range(len(input_data) - window):
        val = input_data[i + window]
        for j in input_data[i+1:i+window]:
            val += j
        val /= window
        output_data.append(val)

    return output_data


def generate_data(length):
    array = []

    for i in range(length):
        array.append(random())

    return array


data = generate_data(int(input('Введите количество данных: ')))
win = int(input('Введите окно: '))
filt_data = SMA(data, win)
plt.plot(data, 'g')
plt.plot(filt_data)
plt.show()
