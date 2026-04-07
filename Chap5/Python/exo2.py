import threading
import random

tab=[]
def assignation(arg):
    for i in range(arg):
        tab.append(random.randint(0,99))

taille=5
t=threading.Thread(target=assignation,args=(taille,))
t.start()
t.join()

for i in range(5):
 print("tab[",i,"]","=",tab[i],"\n") 