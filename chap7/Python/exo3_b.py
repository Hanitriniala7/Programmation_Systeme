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
def print_message(sig,frame)
    print("signal recu ",sig)

pid[5]
for i in range(5):
    pid[i]=os.fork()

    if pid[i]==0
       i=0
       signal.signal(signal.SIGCONT, print_message)
       signal.signal(signal.SIGSTOP, print_message)
       signal.signal(signal.SIGTERM, print_message)
       while(1):
        i+=1


while(1)
    c=input("Taper:\n(s) pour endormir un fils \n(r) pour redémarrer un fils \n(q) pour tuer un fils\n");
    nombre_string=input("Entrer le numéro du processus que vous voulez envoyer ce siganl :");
    nombre=input(nombre_string)
    send_signal(c,pid[nombre]);