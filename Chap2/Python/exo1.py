import sys

if(len(sys.argv)<3 or len(sys.argv)>3):
    print("erreur entrer deux entiers")
else :
    print(sys.argv[1],"+",sys.argv[2],"=",int(sys.argv[1])+int(sys.argv[2]))


