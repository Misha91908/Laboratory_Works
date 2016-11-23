import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as ax3d
from math import sqrt

f = open('qwe.txt', 'r')

dat = []
data  = []

for line in f:
    if line != '\n':
        dat.append(line)
f.close()

i = 0

for i in range(len(dat) - 1):
    k = dat[i].find('C')
    k1 = dat[i].find('B')
    k2 = dat[i].find('A')
    if k == -1 or k1 == -1 or k2 == -1:
        dat.pop(i)

for i in range(len(dat) - 1):
    k = dat[i].find('C')
    k1 = dat[i].find('B')
    k2 = dat[i].find('A')
    for j in range(len(dat[i])):
        if (dat[i][k+1] not in {'1','2','3','4','5','6','7','8','9','0'}):
            dat.pop(i)
        elif (dat[i][k1 + 1] not in {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}):
            dat.pop(i)
        elif (dat[i][k2 + 1] not in {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}):
            dat.pop(i)

ttt = []
tt = []
t = []

for i in range(len(dat) - 1):
    dat[i] = dat[i].replace('A',':')
    dat[i] = dat[i].replace('B', ':')
    dat[i] = dat[i].replace('C', ':')
    data.append(dat[i].split(':'))
    data[i].pop(0)

for i in range(len(dat) - 1):
    t.append(data[i][0])
    tt.append(data[i][1])
    ttt.append(data[i][2])

for i in range(len(dat) - 1):
    ttt[i] = ttt[i].replace('\n',' ')
    ttt[i] = ttt[i].rstrip()
    t[i] = float(t[i])/300
    tt[i] = float(tt[i])/300
    ttt[i] = float(ttt[i])/300

track = 0.0
length = 0.0

for i in range(len(dat) - 2):
    vecx = t[i+1] - t[i]
    vecy = tt[i + 1] - tt[i]
    vecz = ttt[i + 1] - ttt[i]
    length = sqrt(vecx*vecx+vecy*vecy+vecz*vecz)
    track = track + length

print("общее расстояние =",track)
p = len(t)

for kk in range(p - 99):
    i = 0
    for tp in range(99):
        i = i+1
        t[kk] = t[kk] + t[kk + i]
        tt[kk] = tt[kk] + tt[kk + i]
        ttt[kk] = ttt[kk] + ttt[kk + i]
    t[kk] = t[kk] / 100
    tt[kk] = tt[kk] / 100
    ttt[kk] = ttt[kk] / 100

fig = plt.figure()
ax = ax3d.Axes3D(fig)
ax.plot(t,tt,ttt,color='green')
ax.scatter(t[0],tt[0],ttt[0])
ax.scatter(t[p-1],tt[p-1],ttt[p-1],color='red')

fig1 = plt.figure()
plt.subplot(311)
plt.plot(t)
plt.title('Axelleration(x)')
plt.grid()

plt.subplot(312)
plt.plot(tt)
plt.title('Axelleration(y)')
plt.grid()

plt.subplot(313)
plt.plot(ttt)
plt.title('Axelleration(z)')
plt.grid()

print(fig1.axes)
plt.show()
