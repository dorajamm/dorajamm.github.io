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

struct stacknode{
    PTREENODE dato;
    struct stacknode *pnext;
};
typedef struct stacknode STACKNODE;
typedef STACKNODE * PSTACKNODE;

struct queuenode{
    PTREENODE dato;
    struct queuenode *pnext;
};
typedef struct queuenode QUEUENODE;
typedef QUEUENODE * PQUEUENODE;

void IniziaRandom(PTREENODE *pTree,int h); /*genera un albero binario completo e bilanciato con numeri random*/
void StampaAlbero(PTREENODE pTree,int a);
void enqueue(PQUEUENODE *head,PQUEUENODE *tail,PTREENODE x);
void dequeue(PQUEUENODE *head,PQUEUENODE *tail);
void pop(PSTACKNODE *top);
void push(PSTACKNODE *top, PTREENODE x);
void BFS(PTREENODE pTree);
void DFS(PTREENODE pTree);

main()
{
    PTREENODE pTree = NULL; int h,i;
    do{
        printf("inserisci l'altezza dell'albero: ");
        scanf("%d", &h);
    }while(h <= 0);
    srand(time(NULL));

    IniziaRandom(&pTree,h);
    StampaAlbero(pTree,0);
    printf("\n\n");

    printf("visita in ampiezza(BFS): "); BFS(pTree); printf(("\n\n"));
    printf("visita in profondita'(DFS): "); DFS(pTree); printf(("\n\n"));

}

// genera un albero binario completo con numeri random
// nei nodi di altezza scelta dall'utente
void IniziaRandom(PTREENODE *pTree, int h)
{
    *pTree =(TREENODE*)malloc(sizeof(TREENODE));

    (*pTree)->dato = (rand()%15);
        if(h==0)
        {
            (*pTree)->pleft=NULL; (*pTree)->pright=NULL;
        }
        else
        {
            IniziaRandom(&((*pTree)->pleft),h-1);

            IniziaRandom(&((*pTree)->pright),h-1);
        }
}


// stampa come lo disegneremmo noi..
//funziona solo per alberi completi

void StampaAlbero(PTREENODE pTree, int a) {
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

void BFS(PTREENODE pTree)
{
    PQUEUENODE head,tail;
    head =(QUEUENODE*)malloc(sizeof(QUEUENODE));
    head->dato = pTree;
    head->pnext=NULL;
    tail=head;
    while((head) != NULL)
    {
        printf("%3d", head->dato->dato);
        if((head->dato->pleft) != NULL)
           {enqueue(&head,&tail, head->dato->pleft);}
        if((head->dato->pright) !=NULL)
           {enqueue(&head,&tail,head->dato->pright);}
        dequeue(&head,&tail);
    }
}

void DFS(PTREENODE pTree)
{
    PTREENODE tmp1, tmp2;
    PSTACKNODE top = NULL;
    push(&top,pTree);
    //PSTACKNODE top =(STACKNODE*)malloc(sizeof(STACKNODE));
    //top->dato = pTree; top->pnext=NULL;
    while(top!= NULL)
    {
        tmp1=((top->dato)->pright);
		tmp2=((top->dato)->pleft);
		printf("%3d",(top->dato)->dato);
		pop(&top);

        if((tmp1)!= NULL)
            push(&top,tmp1);
        if((tmp2)!=NULL)
            push(&top,tmp2);

    }
}

/*funzioni di cancellazione e inserimento su pile e code**/
void enqueue(PQUEUENODE *head,PQUEUENODE *tail,PTREENODE x)
{PQUEUENODE pnew;
 pnew=(QUEUENODE*)malloc(sizeof(QUEUENODE));
 pnew->dato = x; pnew->pnext=NULL;
 if(*head==NULL)
     *head=pnew;
 else
   {(*tail)->pnext = pnew; *tail=pnew;}}

void dequeue(PQUEUENODE *head,PQUEUENODE *tail)
{PQUEUENODE ptmp;
 ptmp = *head; *head = (*head)->pnext;
 if(*head==NULL)
    *tail = NULL;
 free(ptmp);}

void pop(PSTACKNODE *top)
{
    PSTACKNODE tmp;
        tmp=*top;
        *top= (*top)->pnext;
        free(tmp);
}
void push(PSTACKNODE *top, PTREENODE x)
{
    PSTACKNODE pnew=(STACKNODE*)malloc(sizeof(STACKNODE));
    pnew->dato = x; pnew->pnext=*top; *top=pnew;
}
