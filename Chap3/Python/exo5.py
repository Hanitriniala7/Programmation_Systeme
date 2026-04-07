import os
import random
import time 
#(E) crire un programme qui crée deux ﬁls appelés ﬁls 1 et ﬁls 2. Chaque ﬁls
#doit attendre un nombre de secondes aléatoire entre 1 et 10, en utilisant la fonction sleep.
#Le programme attend que le ﬁls le plus long se termine et aﬃche la durée totale. On pourra
#utiliser la fonction time de la bibliothèque time.h, qui retourne le nombre de secondes depuis
#le premier janvier 1970 à 0h (en temps universel).*/
debut=time.time()
pid1=os.fork()

if pid1==0:
    time.sleep(random.randint(1,10))
    os._exit(0)

pid2=os.fork()

if pid2==0:
    time.sleep(random.randint(1,10))
    os._exit(0)
os.wait()
os.wait()

fin=time.time()
print("la durée du programme est ",fin-debut)
