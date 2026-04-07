import random
import threading

class TypeTableau: #definition de la classe typetableau
    def __init__(self, taille):#constructeur de l'objet en se basant sur la taille
        self.taille = taille
        self.tab = [0] * taille
        self.x = None

def generation_tableau(obj):
   for i in range(obj.taille):
    obj.tab[i] = random.randint(0, 99)

def rechercher_x(obj, resultat):
    if obj.x in obj.tab:
        resultat=1
    else:
        resultat=0

obj=TypeTableau(10)
t1=threading.Thread(target=generation_tableau, args=(obj,))
t1.start()
obj.x=int(input("Entrer x : "))
t1.join()

resultat=-1
t2 = threading.Thread(target=rechercher_x, args=(obj, resultat))
t2.start()
t2.join()

print("Résultat :", resultat)        