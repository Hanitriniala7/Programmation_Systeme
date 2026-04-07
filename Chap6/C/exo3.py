import os
import struct

def remplissage(taille):
    tab=[]
    for i in range(taille):
      tab.append(int(input(f"t[{i}]"))) #f insère la variable dans une chaine
    return tab

def sauvegarde_tab(tab,taille):
     nom_fichier="sauvegarde_tab"
     fd=os.open(nom_fichier, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, int(oct(624)))
     for i in range(taille):
      data=struct.pack(f"{len(tab)}i", *tab)#struct.pack convertit en bytes 
      os.write(fd, data) #sauvegarde dans le fichier sous forme binaire
  os.close(fd)
    
taille=int(input("Entrer la taille "))
tab=remplissage(taille)
sauvegarde_tab(tab)    