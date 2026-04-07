
import os

r,w=os.pipe()
os.environ["lecture"]=str(r)

pid=os.fork()

if pid==0:
    os.close(w)
    arg=["programmefils3.py"]
    os.execv("./programmefils3.py",arg)
else:
    os.close(r)
    message="hello,ici père"
    os.write(w,message.encode())    