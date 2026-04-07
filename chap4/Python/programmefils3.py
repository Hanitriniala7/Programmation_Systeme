#!/usr/bin/env python3
import os

chaine=os.getenv("lecture")
r=int(chaine)

message_byte=os.read(r,100)

print("le message de père ",message_byte.decode())
