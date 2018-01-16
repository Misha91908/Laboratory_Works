import numpy
import matplotlib.pyplot
import scipy.interpolate
import random

pressure = list(numpy.arange(100010, 100, -10))
pressureEarth = 100011.6567
temperatureEarth = 21.35356
t11 = numpy.arange(20, -75, -0.0178)
t21 = numpy.arange(-75, -80, -0.00374)
t31 = numpy.arange(-80, -44.8692, 0.0106)
latitude = numpy.linspace(53.0567, 55.0678, 19980)
pm = 0.0

temperature = []

for i in range(len(t11)):
    temperature.append(t11[i])
for i in range(len(t21)):
    temperature.append(t21[i])
for i in range(len(t31)):
    temperature.append(t31[i])

for i in range(9990):
    temperature.append(temperature[9989 - i])
    pressure.append(pressure[9989 - i])

for i in range(len(temperature)):
    temperature[i] += random.random()
    pressure[i] += random.random()

for i in range(len(pressure)):
    pm += pressure[i]

pm /= len(pressure)

print(len(pressure), len(temperature), len(latitude))

z = []
z1 = []

for i in range(len(temperature) - 1):
    z.append(18336 * (1 + 0.002845 * numpy.cos(2 * latitude[i])) * (1 + ((temperature[i] + temperatureEarth)/500)) *
             numpy.log10(pressureEarth/pressure[i]))
    z1.append(18401.2 * (1 * 0.003665 * temperature[i]) * (1 + 0.378 * (1199.9 / pm)) *
              (1 + 0.00265 * numpy.cos(2 * latitude[i])) *
              (1 + 0.00265 * 250) * numpy.log10(pressure[i]/pressureEarth))

h = [z[0]]
h1 = [z1[0]]

for i in range(len(z) - 1):
    h.append(h[i] + z[i + 1])
    h1.append(h1[i] + z1[i + 1])

pressure.pop()
pressure.pop()

time = numpy.arange(0, len(h), 1)
divergency = []

for i in range(len(h)):
    divergency.append(numpy.abs(z1[i] - z[i]))

inter = scipy.interpolate.interp1d(time[:8000], z[:8000], fill_value="extrapolate")
xnew = numpy.arange(0, 20000, 1)

matplotlib.pyplot.subplot(411)
matplotlib.pyplot.plot(pressure, z, '-', pressure, z1, '--')
matplotlib.pyplot.grid()
matplotlib.pyplot.xlabel('pressure, pascal')
matplotlib.pyplot.ylabel('height, metres')
matplotlib.pyplot.subplot(412)
matplotlib.pyplot.plot(time, z1, '-')
matplotlib.pyplot.grid()
matplotlib.pyplot.xlabel('time, second')
matplotlib.pyplot.ylabel('height, metres')
matplotlib.pyplot.subplot(413)
matplotlib.pyplot.plot(time, z, '-')
matplotlib.pyplot.grid()
matplotlib.pyplot.xlabel('time, second')
matplotlib.pyplot.ylabel('height, metres')
matplotlib.pyplot.subplot(414)
matplotlib.pyplot.plot(time, divergency, '-')
matplotlib.pyplot.grid()
matplotlib.pyplot.xlabel('time, second')
matplotlib.pyplot.ylabel('divergency, metres')

matplotlib.pyplot.show()
