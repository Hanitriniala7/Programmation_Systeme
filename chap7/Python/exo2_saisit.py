import os


pid_fils=os.fork()

if pid_fils==0:
    args=["./exo2_affiche"]
    os.execv("./exo2_affiche",args)
else:
    nombre=input("Entrer un nombre entier")
    fd=os.open("/tmp/text.txt",os.O_WRONLY)
    os.write(fd,nombre.encode())
    os.close(fd)
    os.kill(pid_fils,signal.SIGINT)    