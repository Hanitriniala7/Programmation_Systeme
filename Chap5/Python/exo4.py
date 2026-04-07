import threading
import random
import time
import sys

class Tab:
    def __init__(self):
        self.tab1 = []
        self.tab2 = []
        self.taille1 = 0
        self.taille2 = 0

def assignation_tab(taille, result, index):
    tableau = []
    for _ in range(taille):
        time.sleep(1)
        tableau.append(random.randint(0, 99))
    result[index] = tableau

def test_inclusion(t):
    compteur = 0
    for i in range(t.taille1):
        for j in range(t.taille2):
            if t.tab1[i] == t.tab2[j]:
                compteur += 1
                break
    if compteur == t.taille1:
        print("le tableau T1 est inclus dans T2")

def wait():
    c = input()
    if c == 'A':
        print("Programme annulé")
        sys.exit(0)


    taille1 = 5
    taille2 = 6

    result = [None, None]
    t = Tab()

    random.seed()

    thread1 = threading.Thread(target=assignation_tab, args=(taille1, result, 0))
    thread2 = threading.Thread(target=assignation_tab, args=(taille2, result, 1))
    thread3 = threading.Thread(target=wait)

    thread1.start()
    thread2.start()
    thread3.start()

    thread1.join()
    thread2.join()

    tab1 = result[0]
    tab2 = result[1]

    t.tab1 = tab1
    t.tab2 = tab2
    t.taille1 = taille1
    t.taille2 = taille2

    thread4 = threading.Thread(target=test_inclusion, args=(t,))
    thread4.start()
    thread4.join()