import matplotlib.pyplot as plt

f = open('finalLog.txt','r')
xx = []
yy = []
for line in f:
     s = line.split(':')
     x = s[2].split(' ')
     xx.append(x[0])
     y = s[3].split(' ')
     yy.append(y[0])

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
