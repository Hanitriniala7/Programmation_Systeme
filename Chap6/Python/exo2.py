import os
import sys

def select_fic(path):
    fic=os.stat(path)
    taille=fic.st_size

    if taille>1048576:
        print("->",path,"appartenant",fic.st_uid)

if(len(sys.argv)<2):
    print("erreur")
    sys.exit(1)
else:
 for dossier in sys.argv[1:]:
    for fichier in os.listdir(dossier):
        chemin=os.path.join(dossier,fichier)
        select_fic(chemin)

         
