import os
#E) crire un programme qui crée deux ﬁls appelés ﬁls 1 et ﬁls 2. Le père doit aﬃcher “je suis le père” et le ﬁls 1 doit aﬃcher “je suis le ﬁls 1”, et le ﬁls 2 doit aﬃcher “jesuis le ﬁls 2”.*/
pid1=os.fork()

if pid1==0:
    print("Je suis le fils 1")
    os._exit(0) #quitte le fils pour ne pas creer une processus de plus
else:
     print("Je suis le père")
pid2=os.fork()

if pid2==0:
    print("Je suis le fils 2")
    os._exit(0)
else:
  print("je suis le père")    