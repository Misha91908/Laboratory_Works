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

for i in range(len(dat) - 1):
    t = dat[i].split('A')
    t = t[1].split('B')
    t[1] = t[1].split('C')
    tt.append(t[0])
    tt.append(t[1][0])
    tt.append(t[1][1])
print(data)
