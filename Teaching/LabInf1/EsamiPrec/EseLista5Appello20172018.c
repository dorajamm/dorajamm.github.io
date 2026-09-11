#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
# define V 10; // numero vertici del grafo
struct nodo{
int x;
int y;
struct nodo* next;
};
typedef struct nodo N;
typedef N* pN;
void StartList(pN* s, int l){
srand(time(NULL));
int i; int a,b;
pN p;
(*s)=(pN)malloc(sizeof(N)); //  inserisco primo nodo e creo lista
a=1+ rand()%V;
do
    b=1+rand()%V
while(b==a); // per non inserire archi di tipo (v,v)
((*s)->x)=a;
((*s)->y)=b;
((*s)->next)=NULL;
for(i=1; i<l; i++){ // inserisco tutti altri nodi
        p=(pN)malloc(sizeof(N));
        a=1+ rand()%V;
        do
            b=1+rand()%V
        while(b==a); // per non inserire archi di tipo (v,v)
        (p->x)= a;
        (p->y)= b;
        (p->next)=(*s);
        (*s)=p;
    }
}
void PrintList(pN* s){
int c=0;
pN p;
p=(*s);
if((*s)==NULL){
    printf("La lista e' vuota!\n");
}
else{
    while(p!=NULL){
        printf("(%d,%d) ->", (p->x), (p->y));
        c++;
        if(c==10){
            printf("\n");
            c=0;
        }
        p=p->next;
    }
    printf("END\n");
}
}

void EliminaQuasiIsolato(pN* s){
int a,b;
pN p, tmp;
int trovatoa=0;
int trovatob=0;

p=*s;
if(p==NULL){
    printf("La lista e' vuota!\n");
    return;
}
if(p->next ==NULL){
    printf("La lista ha un solo arco e quindi i due nodi sono quasi isolati\n");
    *s=NULL; // cancello l'arco dalla lista
    return;
}else{  //p->next != NULL
    a=p->x; // metto in a e b i vertici del primo arco e passo all'arco successivo
    b=p->y;
    while (p->next != NULL){ // cerchiamo se a e b compaiono in qualche altro arco
       p=p->next;
       if ((p->x ==a) || (p->y ==a) )
          trovatoa = 1;
       if ((p->x ==b) || (p->y ==b) )
         trovatob = 1;
    }
    if (trovatoa==0 || trovatob==0){
        tmp=*s;
        *s= (*s)->next;
        free(tmp);
    }
}
}

main()
{
    pN s;
    s=NULL;
    int l;
    printf("Inserire il numero di archi nella lista\n");
    scanf("%d", &l);
    StartList(&s, l);
    printf("Questa e' la lista di partenza.\n");
    PrintList(&s);

    EliminaQuasiIsolato(&s);
    printf("\n\nQuesta e' la nuova lista.\n");
    PrintList(&s);

}
