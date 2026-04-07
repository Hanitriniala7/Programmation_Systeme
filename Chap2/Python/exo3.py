import os

fichier=input("Entrer le nom du fichier à editer sur emacs  : ")
pid_fils=os.fork()

if pid_fils==0:
    os.execl("/usr/bin/emacs","emacs",fichier)
else:
    os.wait()