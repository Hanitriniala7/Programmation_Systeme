import threading
import random
import time
import sys

compteur = 0
fini = False
sem = threading.Semaphore(1)

def pro1(nombre):
    global compteur, fini
    while True:
        sem.acquire()
        compteur += 1
        if compteur == nombre:
            print("nombre atteint")
            fini = True
            sem.release()
            sys.exit(0)
        sem.release()
        time.sleep(random.randint(1, 5))

def pro2():
    global compteur, fini
    while True:
        time.sleep(2)
        sem.acquire()
        if fini:
            sem.release()
            break
        else:
            print(f"le compteur est {compteur}")
            sem.release()


    if len(sys.argv) < 2:
        print("Erreur")
        return

    nombre = int(sys.argv[1])
    random.seed()

    thread1 = threading.Thread(target=pro1, args=(nombre,))
    thread2 = threading.Thread(target=pro2)

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

