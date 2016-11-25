import matplotlib.pyplot as plt

f = open('finalLog.txt', 'r')
xx = []
yy = []
k = 0
ss = []
for line in f:
    s = line.split(':')
    x = s[2].split(' ')
    xx.append(float(x[0]))
    y = s[3].split(' ')
    yy.append(float(y[0]))
f.close()

c = 0
cc = 0

t = int(input("введите окно "))

for r in range(len(xx)-t):
    for k in range(t):
        ss.append(xx[r+k])
    for c in range(t):
        for cc in range(t):
            if ss[cc] < ss[c]:
                k = ss[c]
                ss[c] = ss[cc]
                ss[cc] = k
    if t % 2 == 0:
        xx[r] = (ss[t//2-1]+ss[t//2])/2
    else:
        xx[r] = ss[t//2]
    ss.clear()
    for k in range(t):
        ss.append(yy[r + k])
    for c in range(t):
        for cc in range(t):
            if ss[cc] < ss[c]:
                k = ss[c]
                ss[c] = ss[cc]
                ss[cc] = k
    if t % 2 == 0:
        yy[r] = (ss[t // 2 - 1] + ss[t // 2]) / 2
    else:
        yy[r] = ss[t // 2]
    ss.clear()

for r in range(t):
    xx.pop()
    yy.pop()

fig = plt.figure()
plt.subplot(211)
plt.plot(xx)
plt.title('Current')
plt.grid()

plt.subplot(212)
plt.plot(yy)
plt.title('Voltage')
plt.grid()

print(fig.axes)
plt.show()
