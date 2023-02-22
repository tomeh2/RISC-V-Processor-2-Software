import serial
import random

ser = serial.Serial('COM4', 115200)
ser.close()
ser.open()

rows = 16
cols = 16

f = open("test", "w")

for i in range(rows * cols):
    r = int(random.random() * 100)
    str_r = str(r)

#    for c in str_r:
#        ser.write(chr(c))
    ser.write(str_r.encode('ascii', 'ignore'))
    ser.write('s'.encode('ascii', 'ignore'))
    #print(ser.readline())
    f.write(str_r + 's')
    print(ser.readline())
    
print(ser.readline())   #mat a done
print(ser.readline())   #mat b load...
    
for i in range(rows * cols):
    r = int(random.random() * 100)
    str_r = str(r)

#    for c in str_r:
#        ser.write(chr(c))
    ser.write(str_r.encode('ascii', 'ignore'))
    ser.write('s'.encode('ascii', 'ignore'))
    #print(ser.readline())
    f.write(str_r + 's')
    print(ser.readline())
    
while (True):
    print(ser.readline())
    
f.close()
    
ser.close()