import math

x = float(input())

if (x>=-1) and (x<=1): # если введенный х принадлежит промежутку [-1;1], то считатет функцию
    f = math.acos(x)
    print("f = ",f)
