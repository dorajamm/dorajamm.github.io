#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct nodo{
int x;
int y;
struct nodo* next;
};
typedef struct nodo N;
typedef N* pN;
void StartList(pN* s, int l){
srand(time(NULL));
int i;
for(i=0; i<l; i++){
    if((*s)!=NULL){
        pN p;
        p=(pN)malloc(sizeof(N));
        (p->x)= -100+rand()%201 ;
        (p->y)=-100+rand()%201 ;
        (p->next)=(*s);
        (*s)=p;
    }
    else{
        (*s)=(pN)malloc(sizeof(N));
        ((*s)->x)=-100+rand()%201 ;
        ((*s)->y)=-100+rand()%201 ;
        ((*s)->next)=NULL;
    }
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
        printf("(%d, %d) ->", (p->x), (p->y));

        p=(p->next);
    }
    printf("\n");
}
}

main()
{
    pN s;
    s=NULL;
    int l;
    printf("Inserire il numero di punti che saranno presenti sul piano cartesiano.\n");
    scanf("%d", &l);
    StartList(&s, l);
    printf("Questa e' la lista di partenza.\n");
    PrintList(&s);
    //InQuadrato(&s);
    printf("Questa e' la lista dei punti della  interni al quadrato piu' piccolo centrato il (0,0) e contenente il primo punto della lista di partenza.\n");
    PrintList(&s);
}
