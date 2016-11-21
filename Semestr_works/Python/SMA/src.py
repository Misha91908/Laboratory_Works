import matplotlib.pyplot as plt

f = open('finalLog.txt', 'r')
xx = []
yy = []
k = 0
ss = []
ss1 = []
for line in f:
    s = line.split(':')
    x = s[2].split(' ')
    xx.append(float(x[0]))
    y = s[3].split(' ')
    yy.append(float(y[0]))
    k = k + 1

i = 1

for t in range(int(k / 2)):
    ss.append(xx[i])
    ss1.append(yy[i])
    i = i + 2

for t in range(int(k / 2) - 5):
    i = 0
    for tt in range(5):
        i = i + 1
        ss[t] = ss[t] + ss[t + i]
        ss1[t] = ss1[t] + ss[t + i]
    ss[t] = ss[t] / 6
    ss1[t] = ss[t] / 6

fig = plt.figure()
plt.subplot(211)
plt.plot(ss)
plt.title('Current')
plt.grid()

plt.subplot(212)
plt.plot(ss1)
plt.title('Voltage')
plt.grid()

print(fig.axes)
plt.show()
