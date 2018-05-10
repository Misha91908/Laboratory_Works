output = []
memory = []
iterator = []
i = 0

x = float(input("Введите первую границу для рассчета функции: "))
memory.append(x)
x2 = float(input("Введите вторую границу для рассчета функции: "))
memory.append(x2)
a = float(input("Введите параметр: "))
step = float(input("Введите шаг: "))

while x < x2:
    if (10 * a * a + 11 * a * x + 3 * x * x) != 0:
        function = 5 * (-2 * a * a + a * x + 3 * x * x) / (10 * a * a + 11 * a * x + 3 * x * x)
        output.append(str(function))
    x += step
    i += 1
    if x >= x2 or i > 100:
        break

x = memory[0]
x2 = memory[1]
iterator.append(i)
i = 0

while x < x2:
    function = 2 ** (10 * a * a - 29 * a * x + 18 * x * x)
    output.append(str(function))
    x += step
    i += 1
    if x >= x2 or i > 100:
        break

x = memory[0]
x2 = memory[1]
iterator.append(i)

f = open("/home/misha91908/output.txt","w")  #данные записываются с помощью write
f.write("===================================================================================================\n")
for k in range(iterator[0]+iterator[1]):
    f.write("|" + output[k] + "|\n")
    f.write("_______________________________________________________________________________________________\n")
f.write("===================================================================================================\n")
f.close()
f1 = open("/home/misha91908/output.txt","r")  #данные считываются из файла с помощью цикла
for line in f1:
    print(line)
f1.close()
