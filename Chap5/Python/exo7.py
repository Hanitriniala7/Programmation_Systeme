import threading
import random
import time

compteur = 0
u = 1.0

sem1 = threading.Semaphore(1)
sem2 = threading.Semaphore(1)

def pro1():
    global compteur, u
    while compteur < 10:
        sem1.acquire()
        compteur += 1
        sem1.release()

        sem2.acquire()
        u = (1.0 / 4.0) * ((u - 1) * (u - 1))
        print(f"la valeur u dans T1 : {u}")
        sem2.release()

        time.sleep(random.randint(1, 5))

def pro2():
    global compteur, u
    while compteur < 10:
        sem1.acquire()
        compteur += 1
        sem1.release()

        sem2.acquire()
        u = (1.0 / 6.0) * ((u - 2) * (u - 2))
        print(f"la valeur de u dans T2 : {u}")
        sem2.release()

        time.sleep(random.randint(1, 5))

    global u
    random.seed()
    u = 1.0

    thread1 = threading.Thread(target=pro1)
    thread2 = threading.Thread(target=pro2)

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()
