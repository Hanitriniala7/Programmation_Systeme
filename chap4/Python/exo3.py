import os

r1,w1=os.pipe()
pid=os.fork()

if pid==0:
    os.close(w1) 
    chaine=str(r1)
    arg=["./programmefils",chaine]
    os.execv("./programmefils",arg)
else :
     os.close(r1)
     message="hello, ici le père"
     os.write(w1,message.encode())
