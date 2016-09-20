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

for t in range(int(k)-tt-1):

    for r in range(tt-1):
        x[r+1] = alpha*x[r+1]+(1.0 - alpha)*x[r]

fig = plt.figure()
plt.subplot(211)
plt.plot(ss)
plt.title('Current')
plt.grid()

plt.subplot(212)
plt.plot(yy)
plt.plot(ss1)
plt.title('Voltage')
plt.grid()

print(fig.axes)
plt.show()
