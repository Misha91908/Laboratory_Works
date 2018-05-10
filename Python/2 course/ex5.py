from collections import Counter
import matplotlib.pyplot as plt
import numpy

xspam_data = {}


def file_parser():
    from_data = []
    with open('mbox.txt', 'r') as file:
        for line in file:
            counter = str.find(line, "From:")
            if counter == 0:
                buf = line.split(' ')
                buf = buf[1].split('\n')
                from_data.append(buf[0])
            k = str.find(line, "X-DSPAM-Confidence:")
            if k == 0 and xspam_data.get(buf[0]) is None:
                buf_xspam = line.split(' ')
                xspam_data[buf[0]] = (float(buf_xspam[1]))
            elif k == 0 and xspam_data.get(buf[0]) is not None:
                buf_xspam = line.split(' ')
                buffer = xspam_data.get(buf[0])
                xspam_data[buf[0]] = (float(buf_xspam[1])) + buffer
    return from_data, xspam_data


def create_new_massives(from_data):
    buf = Counter(from_data)
    dict_buf = dict(buf)
    list_buf = list(buf)
    return dict_buf, list_buf


def parse_massive(dict_buf, list_buf):
    key, value, xspam = [], [], []
    for element in list_buf:
        key.append(element)
        value.append(dict_buf[element])
        xspam.append(xspam_data[element] / dict_buf[element])
    return key, value, xspam


def draw_graphs(key, value, xspam):
    print(key, xspam[1])
    plt.title('Количество писем')
    plt.bar(numpy.arange(len(key)), value, align='center')
    plt.xticks(numpy.arange(len(key)), key, rotation=90)
    plt.savefig("1.png", figsize=(10, 6))
    plt.show()

    plt.title('Средний показатель спама по каждому отправителю')
    plt.bar(numpy.arange(len(key)), xspam, align='center')
    plt.xticks(numpy.arange(len(key)), key, rotation=90)
    plt.savefig("2.png", figsize=(10, 6))

    plt.show()


def main():
    from_data, xspam = file_parser()
    dict_buf, list_buf = create_new_massives(from_data)
    key, value, xspam = parse_massive(dict_buf, list_buf)
    draw_graphs(key, value, xspam)


if __name__ == "__main__":
    main()
