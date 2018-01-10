import numpy
import matplotlib.pyplot
import scipy.interpolate

pressure = numpy.arange(100010, 110, -10)
pressure1 = numpy.arange(100000, 100, -10)
t11 = numpy.arange(20, -75, -0.0178)
t12 = numpy.arange(20.0178, -75.0178, -0.0178)
t21 = numpy.arange(-75, -80, -0.00374)
t22 = numpy.arange(-75.00374, -80.00374, -0.00374)
t31 = numpy.arange(-80, -44.8692, 0.0106)
t32 = numpy.arange(-80.053, -44.9364, 0.0106)
latitude = numpy.linspace(53.0567, 54.5678, 9990)

temperature = []
temperature1 = []

for i in range(len(t11)):
    temperature.append(t11[i])
for i in range(len(t21)):
    temperature.append(t21[i])
for i in range(len(t31)):
    temperature.append(t31[i])

for i in range(len(t12)):
    temperature1.append(t12[i])
for i in range(len(t22)):
    temperature1.append(t22[i])
for i in range(len(t32)):
    temperature1.append(t32[i])

print(len(pressure), len(pressure1), len(temperature), len(temperature1), len(latitude))

z = []
z1 = []

for i in range(len(temperature) - 1):
    z.append(18336 * (1 + 0.002845 * numpy.cos(2 * latitude[i])) * (1 + ((temperature[i] + temperature1[i])/500)) *
             numpy.log10(pressure[i]/pressure1[i]))
    z1.append(18401.2 * (1 * 0.003665 * temperature[i]) * (1 + 0.378 * (1199.9 / pressure1[i])) *
              (1 + 0.00265 * numpy.cos(2 * latitude[i])) *
              (1 + 0.00265 * 250) * numpy.log10(pressure1[i]/pressure[i]))

h = [z[0]]
h1 = [z1[0]]

for i in range(len(z) - 1):
    h.append(h[i] + z[i + 1])
    h1.append(h1[i] + z1[i + 1])

time = numpy.arange(0, len(h), 1)
divergency = []

for i in range(len(h)):
    divergency.append(numpy.abs(h1[i] - h[i]))

inter = scipy.interpolate.interp1d(time, divergency)
xnew = numpy.arange(1000, 9000, 2)

matplotlib.pyplot.subplot(311)
matplotlib.pyplot.plot(time, h, '-', time, h1, '--')
matplotlib.pyplot.grid()
matplotlib.pyplot.xlabel('time, second')
matplotlib.pyplot.ylabel('height, metres')
matplotlib.pyplot.subplot(312)
matplotlib.pyplot.plot(time, divergency, '-')
matplotlib.pyplot.grid()
matplotlib.pyplot.xlabel('time, second')
matplotlib.pyplot.ylabel('divergency in calculation, metres')
matplotlib.pyplot.subplot(313)
matplotlib.pyplot.plot(inter(xnew), '-')
matplotlib.pyplot.grid()

matplotlib.pyplot.show()
