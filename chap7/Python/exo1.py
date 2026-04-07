import os 
import signal

def send_signal(pid_fils,c):
    match c :
       case 's':
         os.kill(pid_fils, signal.SIGSTOP)
       case 'r':
         os.kill(pid_fils, signal.SIGCONT)
       case 'q':
          os.kill(pid_fils, signal.SIGTERM)

pid_fils=os.fork()

if pid_fils==0:
    i=0
    while 1:
     i+=1
else:
    c=input("Taper:\n(s) pour endormir\n(r) pour redémarrer\n(q) pour tuer\n")
    send_signal(pid_fils,c)     