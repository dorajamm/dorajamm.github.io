
#include <stdlib.h>
#include <stdio.h>

/* Valuta il valore di verità della formula booleana f. Ritorna 0 se il valore
 * è falso e un intero diverso da 0 se il valore è vero. I caratteri
 * significativi sono i seguenti:
 * '(', ')'   per delimitare le sotto-espressioni
 * '&', '|'   operatori AND e OR
 * 'T', 'F'   valori vero e falso
 * Tutti gli altri caratteri sono ignorati. Per le espressioni con più di due
 * operandi l'associatività è a sinistra:
 *     V0 OP1 V1 OP2 V2 OP3 V3 ... OPk Vk è valutato come se fosse
 *     (...(((V0 OP1 V1) OP2 V2) OP3 V3) ... OPk Vk).
 * Non effettua controlli sulla correttezza sintattica della formula. Esempi:
 * T & T & F & F | T          valore vero
 * T & ((T & T) | F) | F      valore vero
 * (T & (T & (F & (F | T))))  valore falso    */

#define MAXLEN     100
struct nodo {
  char elem;
  struct nodo *next;
  };

  typedef struct nodo Nodo;
  typedef  Nodo *PNodo;


void value(PNodo *top, char v);
char boolformula(char *f);

int isEmpty(PNodo top);
char topValue(PNodo top);
void push(PNodo *top, char val);
char pop(PNodo *top);
void stampa_pila(Nodo *top);


int isEmpty(PNodo top)
{
   return top == NULL;
}

char topValue(PNodo top)
{
   return top->elem;
}
void push(PNodo *top, char val) //inserimento nella pila
{
   PNodo p;

   p = (PNodo) malloc(sizeof(Nodo));
   p->elem = val;
   p->next = *top;
   *top = p;
}



char pop(PNodo *top) //estrazione di un elemento dalla pila
{
   PNodo p;
   char valore;

   p = *top;
   valore = (*top)->elem;
   *top = (*top)->next;
   free(p);
   return valore;
}

void stampa_pila(Nodo *top) {
    if (top == NULL)
      printf("la pila e' vuota\n\n");
   else {
      printf("\nLa pila e' :\n");
      while (top != NULL) {
        printf("%c --> ", top->elem);
        top = top->next;
       }
       printf("NULL\n");
   }
  }

//Funzione ausiliaria che elabora il valore v
void value(PNodo *top, char v) {
    char op, v0;
    op = topValue(*top);
    if (op == '&' || op == '|') {  //Se il simbolo in cima alla pila è un operatore
        pop(top);             //estrai l'operatore dalla pila e
        v0 = pop(top);   //estrai anche il valore precedente
        if (op == '&')             //Calcola il valore di v op v0
            if(v == 'T' && v0 == 'T')
                 v='T';
            else
                v='F';
        else //op=='|'
            if(v == 'F' && v0 == 'F')
                  v='F';
            else
               v='T';

    }
    push(top, v);
}

char boolformula(char *f) {
    PNodo pila = NULL;
    int i;
    char v;
    int val;
    for (i = 0 ; f[i] != '\0' ; i++) {  //Legge uno ad uno i caratteri della formula
        stampa_pila(pila);

        switch (f[i]) {
            case '(': case '&': case '|':   //Caratteri da inserire nella pila (sempre)
                push(&pila, f[i]);
                break;
            case 'T': case 'F':             //Valori di verità
                value(&pila, f[i]);
                break;
            case ')':                       //Parentesi chiusa
                v = pop(&pila);  //Il valore dell'espressione tra parentesi
                pop(&pila);      //La relativa parentesi aperta
                if (isEmpty(pila)) // ho terminato e ri-inserisco v= valoreformula nella pila
                    push(&pila,v);
                else
                    value(&pila, v);
                break;
            default: ;                      //Tutti gli altri caratteri sono ignorati
        }
    }
     stampa_pila(pila);
    return topValue(pila);
}

int main() {
    char formula[MAXLEN + 1];
    char val;
    printf("Inserire una formula booleana (ad es. ((T & (F | T)) | F):\n");
    gets(formula);
    printf(" hai inserito:  %s", formula);
    val = boolformula(formula);
    printf("\n\nIl valore della formula e': ");
    if (val='T')
        printf("VERO");
    else
        printf("FALSO");

    return 0;
}
