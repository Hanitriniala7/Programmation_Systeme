import os
import struct

def chargement_en_memoire(fichier,reference):
    tab=[]
    fd=os.open(fichier,os.O_RDONLY)
    data=os.read(fd, 4)
    while data:
      nombre=struct.unpack("i", data)[0] #convertit bytes en int   
      tab.append(nombre)
      data=os.read(fd, 4)
    os.close(fd)        
    return tab


fichier=input("Entrer le nom du fichier binaire à charger en mémoire :")
taille=input("Entrer le nombre d'élement que vous vouliez voir :")
tab=chargement_en_memoire(fichier,reference)
for i in range(taille):
   print(tab[i],"\n")