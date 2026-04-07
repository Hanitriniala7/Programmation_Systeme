import os

while true :
    fichier=input("Entrer le nom du fichier à ouvrir sur emacs : ")
    pid_fils=os.fork()

    if pid_fils==0 :
     os.execlp("emacs","emacs",fichier)
    else:
      os.wait()

     choix=input("Continuer ou quitter")
     
    if choix=='n':
      break
