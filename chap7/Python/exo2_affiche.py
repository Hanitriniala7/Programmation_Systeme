import os
import time

def print_int(sig,frame):
    fd=open("/tmp/text.txt",os.O_RDONLY)
    nombre=os.read(fd,10)
    nombre1=int(nombre.decode())
    print("le nombre tapé est ",nombre1)

signal.signal(signal.SIGINT, print_int)

while (1):
    time.sleep(2)
