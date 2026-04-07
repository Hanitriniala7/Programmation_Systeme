import os

r1,w1=os.pipe() # fils->père
r2,w2=os.pipe() #père->fils

pid_fils=os.fork()

if pid_fils==0:
    os.close(r1)
    os.close(w2)
    mot=input("Entrer le mot :")
    os.write(w1,mot.encode()) #chaine.encode taille en bytes

    resultat_bytes=os.read(r2,4)
    resultat=int(resultat_bytes.decode()) #decode bytes->str

    if resultat==1:
        print("le mot est trouvé dans le fichier",resultat)
    else:
        print("le mot n'est pas trouvé dans le fichier",resultat)    
else:
   os.close(w1)
   os.close(r2)
   
   mot_bytes=os.read(r1,1024)
   mot=mot_bytes.decode()
   nombre=0
   fichier="test.txt"

with open(fichier, "r") as f:
    for ligne in f:
        for mot_fic in ligne.split():
            if mot == mot_fic:
              nombre =1

os.write(w2,str(nombre).encode())

    