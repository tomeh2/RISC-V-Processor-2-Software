import serial
import random
import numpy as np
import keyboard

ser = serial.Serial('COM4', 576000, timeout = 1)
ser.close()
ser.open()

rows = 48
cols = 48

x = np.arange(rows * cols)
x.shape = (rows, cols)

y = np.arange(rows * cols)
y.shape = (rows, cols)

f = open("test", "w")

for i in range(rows):
    for j in range(cols):
        r = int(random.random() * 100)
        str_r = str(r)
        x[i, j] = r

    #    for c in str_r:
    #        ser.write(chr(c))
        ser.write(str_r.encode('ascii', 'ignore'))
        ser.write('s'.encode('ascii', 'ignore'))
        #print(ser.readline())
        f.write(str_r + 's')
        #print(ser.readline())
    
print(ser.readline())   #mat a done
print(ser.readline())   #mat b load...
    
for i in range(rows):
    for j in range(cols):
        r = int(random.random() * 100)
        str_r = str(r)
        y[i, j] = r

    #    for c in str_r:
    #        ser.write(chr(c))
        ser.write(str_r.encode('ascii', 'ignore'))
        ser.write('s'.encode('ascii', 'ignore'))
        #print(ser.readline())
        f.write(str_r + 's')
        #print(ser.readline())
    
while (True):
    print(ser.readline())
    
    if (keyboard.is_pressed('f')):
        break
    
print("\n\n NUMPY RESULTS \n\n")
print(np.matmul(x, y))
    
f.close()
    
ser.close()