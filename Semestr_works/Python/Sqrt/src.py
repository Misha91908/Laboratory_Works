digit = float(input("Введите число: "))

iterator = 0

x_value = digit

while x_value*x_value != digit:
    x_value = 0.5 * (x_value + (digit / x_value))
    iterator += 1
    if iterator > 150:
        break

print("Квадратный корень из введенного числа равен ", x_value)
