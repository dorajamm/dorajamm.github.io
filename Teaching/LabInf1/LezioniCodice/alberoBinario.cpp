// sono presenti due modi di generare alberi binari:
// o un albero completo di altezza fissata
// oppure un albero binario di ricerca con un numero di chiavi fissate
// I due modi vanno inseriti nel main

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

struct treenode{
    int dato;
    struct treenode *pleft;
    struct treenode *pright;
};
typedef struct treenode TREENODE;
typedef TREENODE * PTREENODE;

void IniziaRandom(PTREENODE *pTree,int h); /*genera un albero binario completo e bilanciato con numeri random*/
void CreaBST(PTREENODE *pTree);
void InserisciNodo(PTREENODE *pTree, int x);

void StampaAlbero(PTREENODE pTree,int a);

void PREorder(PTREENODE pTree);
void INorder(PTREENODE pTree);
void POSTorder(PTREENODE pTree);


main()
{
    PTREENODE pTree = NULL; int h,i;
    /*
    printf("verra' generato un albero binario completo (e bilanciato) contenente valori random...\n\n\n");
    do{
        printf("inserisci l'altezza dell'albero: ");
        scanf("%d", &h);
    }while(h <= 0);
    srand(time(NULL));

    IniziaRandom(&pTree,h);
    */
    CreaBST(&pTree);
    printf("\n\n");
    StampaAlbero(pTree,0);
    printf("\n\n");

    printf("visita in PREorder: "); PREorder(pTree); printf(("\n\n"));
    printf("visita in INorder: "); INorder(pTree); printf(("\n\n"));
    printf("visita in POSTorder: "); POSTorder(pTree); printf(("\n\n"));

}

void IniziaRandom(PTREENODE *pTree, int h)
{
    PTREENODE pcurrent;
    *pTree =(TREENODE*)malloc(sizeof(TREENODE));
    pcurrent = *pTree;

    pcurrent->dato = (rand()%100);
        if(h==0)
        {
            pcurrent->pleft=NULL; pcurrent->pright=NULL;
        }

        else
        {
            IniziaRandom(&(pcurrent->pleft),h-1);

            IniziaRandom(&(pcurrent->pright),h-1);
        }
}

void StampaAlbero(PTREENODE pTree, int a)
// stampa come lo disegneremmo noi.. ma in "orizzontale"
{
    int i;

    if (pTree != NULL)
    {
        StampaAlbero(pTree->pright,a+1);
        for (i=0;i<a;i++)
            printf("\t");
        printf("%d \n", pTree->dato);
        StampaAlbero(pTree->pleft,a+1);
    }
}

void PREorder(PTREENODE pTree)
{
    if (pTree != NULL) {
      printf("%3d", pTree->dato);
      PREorder(pTree->pleft);
      PREorder(pTree->pright);
    }
}

void INorder(PTREENODE pTree)
{
    if (pTree != NULL) {
      INorder(pTree->pleft);
      printf("%3d", pTree->dato);
      INorder(pTree->pright);
    }
}

void POSTorder(PTREENODE pTree)
{
    if (pTree != NULL) {
      POSTorder(pTree->pleft);
      POSTorder(pTree->pright);
      printf("%3d", pTree->dato);
    }
}

void CreaBST(PTREENODE *pTree){
    int item, i;
srand(time(NULL));

   /* insert random values between 1 and 15 in the tree */
   printf("I numeri generati e inseriti nell'albero sono:\n");

   for (i = 1; i <= 10; i++) {
      item = rand() % 100;
      printf("%3d", item);
      InserisciNodo(pTree, item);
   }

}


void InserisciNodo(PTREENODE *pTree, int x){
 if (*pTree == NULL) {   /* *treePtr is NULL */
      *pTree = (PTREENODE)malloc(sizeof(TREENODE));
      (*pTree)->dato = x;
      (*pTree)->pleft = NULL;
      (*pTree)->pright = NULL;
   }
   else
      if (x < (*pTree)->dato)
         InserisciNodo(&((*pTree)->pleft), x);
      else
         if (x > (*pTree)->dato)

            InserisciNodo(&((*pTree)->pright), x);
         else
            printf("dup");

}
