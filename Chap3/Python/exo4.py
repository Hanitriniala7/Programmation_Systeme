import os 
#(E) crire un programme avec un processus père qui engendre 5 ﬁls dans une bouble for. Les ﬁls sont nommés ﬁls 1 à ﬁls 5. Le ﬁls 1 doit aﬃcher “je suis le ﬁls 1” et le ﬁls 2 doit aﬃcher je suis le ﬁls 2, et ainsi de suite. Indication. on pourra utiliser une variable globale.*/
for i in range(5):
    pid=os.fork()
    if pid==0:
        print("fils ",i+1)
        break
    else:
         os.wait()