data = []

inp = open("out.txt", "r")
for line in inp:
    data.append(line)
inp.close()
for i in range(len(data)):
    data[i] = data[i].replace('.', ',')
out = open("out.txt", "w")
for i in range(len(data)):
    out.write(data[i])
out.close()
