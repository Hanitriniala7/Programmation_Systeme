import os

rep_courant=os.gctwd()

while true :
    repertoire=input("Entrer le répertoire: ")
    pid_fils=os.fork()

    if pid_fils==0:
     os.execlp("cp","cp","-r",rep_courant,repertoire)
    else:
    os.wait()

    choix=input("Continuer(y) ou quitter(n)")
    if choix=='n':
      break
