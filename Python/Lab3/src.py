import math

a = float(input())
x = float(input())
name = str(input())

if name == 'G':  # проверяется,какая функция выбрана,по введенным данным считается функция, и результат выводится на экран
    G = 5*(-2*a*a+a*x+3*x*x)/(10*a*a+11*a*x+3*x*x)
    print("G = ", G)
elif name == 'F':
    F = 2 ** 10*a*a-29*a*x+18*x*x
    print("F = ", F)
elif (name == 'Y') & (((1+15*a*a-29*a*x+12*x*x)/(1-15*a*a+29*a*x/12*x*x)) > 0):
    Y = math.atanh(15*a*a-29*a*x+12*x*x)
    print("Y = ", Y)
else:
    print("значение не существует")
