import os
#Exercice 2.3 (E) crire un programme qui crée 5 ﬁls en utilisant une boucle for. On remarquera que pour que le ﬁls ne crée pas lui-même plusieurs ﬁls, il faut interompre la boucle parun break dans le ﬁls.*/

for i in range(5):
    pid=os.fork()
    if pid==0:
        print("Processus",i)
        break
    else:
         os.wait()
