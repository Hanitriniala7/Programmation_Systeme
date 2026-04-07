import os
import sys 

if len(sys.argv)<2 or len(sys.argv)>2:
    print("entrer un seul chemin")
else:
    chemin=os.getcwd()
    pid_fils=os.fork()

    if pid_fils==0 :
    os.execlp("cp","cp","-r",chemin,sys.argv[1])
    else:
    os.wait()       