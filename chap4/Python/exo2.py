import os

r1,w1=os.pipe() #fils->père
r2,w2=os.pipe()#père->fils

pid=os.fork()

if pid==0:
    mot=input("Entrer le mot")
    os.dup2(r1,STDIN_FILENO)
    os.dups(w2,STDOUT_FILENO)
else:
    mot=input()
    fichier="test.txt"
    nombre=0
    with open(fichier, "r") as f:
        for ligne in f:
            for mot_fic in ligne.split():
              if mot == mot_fic:
                nombre=1 
print("le résultat ",nombre)                