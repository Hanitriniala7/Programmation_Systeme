import threading

def print_tableau(arg):
    for i in range(5):
        print(arg[i])

tableau=[1,2,3,4,5]
t=threading.Thread(target=print_tableau,args=(tableau,))
t.start()
t.join()