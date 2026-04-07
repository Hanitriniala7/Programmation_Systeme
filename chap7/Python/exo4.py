import sys

def remplissage(taille):
    tab = []
    for i in range(taille):
        val = int(input(f"t[{i}] = "))
        tab.append(val)
    return tab


    taille = int(input("Entrer le nombre d'éléments du tableau : "))
    tab = remplissage(taille)

    try:
        nombre = int(input("Entrer l'indice de l'élément que vous voulez voir : "))
        print(f"tab[{nombre}] = {tab[nombre]}")
    except IndexError:
        print("Erreur : indice invalide")
        # Simulation du comportement du signal SIGSEGV
        print("Entrer l'indice : ")
        nombre = int(input())
        if 0 <= nombre < len(tab):
            print(f"tab[{nombre}] = {tab[nombre]}")
        else:
            print("Indice toujours invalide")