import threading
import time
import random

s1 = threading.Semaphore(0)
s2 = threading.Semaphore(0)

def T1():
    for i in range(10):
        time.sleep(2)
        print("T1 fini")

        s2.release()
        s1.acquire()

def T2():
    for i in range(10):
        time.sleep(random.randint(4, 9))
        print("T2 fini")

        s1.release()
        s2.acquire()


    random.seed()

    th1 = threading.Thread(target=T1)
    th2 = threading.Thread(target=T2)

    th1.start()
    th2.start()

    th1.join()
    th2.join()

