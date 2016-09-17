import matplotlib.pyplot as plt
import numpy as np

def movingaverage (values, window):
    weights = np.repeat(1.0, window)/window
    sma = np.convolve(values, weights, 'valid')
    return sma

f = open('finalLog.txt','r')
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
     k = k+1
i = 1

for t in range(2403):
     ss.append(xx[i])
     i = i + 2

xMA = movingaverage(ss,89)

fig = plt.figure()
plt.subplot(211)
plt.plot(ss[len(ss)-len(xMA):],color="red")
plt.title('Current')
plt.grid()

plt.subplot(212)
plt.plot(yy)
plt.plot(ss1)
plt.title('Voltage')
plt.grid()

print(fig.axes)
plt.show()