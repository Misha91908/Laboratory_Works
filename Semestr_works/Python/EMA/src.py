import matplotlib.pyplot as plt

f = open('finalLog.txt', 'r')
xx = []
yy = []
k = 0
ss = []
ss1 = []
alpha = float(input())
for line in f:
    s = line.split(':')
    x = s[2].split(' ')
    xx.append(float(x[0]))
    y = s[3].split(' ')
    yy.append(float(y[0]))
    k = k + 1

tt = int(input())
i = 0
for t in range((int(k))-tt-1):
    e = xx[i]
    g = yy[i]
    for r in range(tt-1):
       e = alpha*xx[i+r]+(1.0 - alpha)*e
       g = alpha*yy[i+r]+(1.0 - alpha)*g
    ss.append(e)
    ss1.append(g)
    i =i+1

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
