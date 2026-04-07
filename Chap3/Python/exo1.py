import os 
#(E) crire un programme qui crée un ﬁls. Le père doit aﬃcher “je suis le père” et le ﬁls doit aﬃcher “je suis le ﬁls”.
pid=os.fork()

if pid==0 :
    print("je suis le fils")
else :
    print("je suis le père")