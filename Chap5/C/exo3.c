#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

struct TypeTableau
{
    int taille;
    int *tab;
    int x;
};
typedef struct TypeTableau TypeTableau;
//************************************ */
void* generation_tab(void* arg) // geeration du tableau de nombre aléatoire (0,99)
{
   int taille=*(int*)arg;
   TypeTableau *p=malloc(sizeof(TypeTableau));
   p->taille=taille;
   p->tab=malloc(taille*sizeof(int));

   for(int i=0;i<p->taille;i++)
   {
      p->tab[i]=rand()%100;
   }
    return (void*)p;
}
//*********************************** */
void* recherche_x(void* arg)
{
    TypeTableau *p= (TypeTableau*)arg;
    int *resultat=malloc(sizeof(int));
    for(int i=0;i<p->taille;i++)
    {
        if(p->tab[i]==p->x)
        {
          *resultat=1;
          break;
        }
    }
    return (void*)resultat;
}
//************************************ */
int main()
{
  srand(time(NULL));
  pthread_t thread1, thread2;
  int nombre=5,x;
  TypeTableau *p;
  int *resultat;

  pthread_create(&thread1,NULL,generation_tab,&nombre);// generation du contenu du tableau
  pthread_join(thread1,(void**)&p);// attend que le tableau est generé
  printf("Entrer le nombre pour tester si elle appartient dans le tableau :");
  scanf("%d",&x);// demande x
  p->x=x;
  pthread_create(&thread2,NULL,recherche_x,p);//teste si x est parmis les éléments du tableau
  pthread_join(thread2,(void**)&resultat);// retourne le resultat 

  if(*resultat==0)
  {
    printf("%d n'est pas dans le tableau",x);
  }
  else
  {
    printf("%d est dans le tableau",x);
  }
  return(0);
}