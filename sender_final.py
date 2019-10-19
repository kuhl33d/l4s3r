#!/usr/bin/python
import binascii
import sys
import serial
import time

delay = 0.3

def text_to_bits(text, encoding='utf-8', errors='surrogatepass'):
    bits = bin(int(binascii.hexlify(text.encode(encoding, errors)), 16))[2:]
    return bits.zfill(8 * ((len(bits) + 7) // 8))

def text_from_bits(bits, encoding='utf-8', errors='surrogatepass'):
    n = int(bits, 2)
    return int2bytes(n).decode(encoding, errors)

def int2bytes(i):
    hex_string = '%x' % i
    n = len(hex_string)
    return binascii.unhexlify(hex_string.zfill(n + (n & 1)))

def prog(f):
     ser = serial.Serial(f,baudrate = 9600,timeout = 1)
     print("trying {}...".format(f))
     time.sleep(5)
     print("start sending ...")
     if len(sys.argv) > 1:
          for i in range(1,len(sys.argv)):
               for word in sys.argv[i]:
                    for letter in range(len(word)):
                         bi = text_to_bits(str(word[letter]))
                         for ch in range(len(bi)):
			      if ser.isOpen():
                               ser.write(b'{}\n'.format(bi[ch]))
                               print('{}\n'.format(bi[ch]))
                               time.sleep(delay)
          ser.close()

     else:
          print("usage: <text>")
          ser.close()

prog('/dev/ttyACM0')
print("program finished")
