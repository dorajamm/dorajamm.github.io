

#include <stdio.h>


int ControllaVocale(char s[80], int* pos) //l'idea è che ad ogni posizione del vettore v corrisponde una vocale, a=0, e=1, o=2 ecc.
{
    int i;
    int max=-1;
    int v[5]={0};
    for(i=0; s[i]!='\0'; i++) //incremento ogni posizione in base alla vocale trovata
    {
        if(s[i]=='a')
        {
            v[0]++;
        }else if(s[i]=='e')
        {
            v[1]++;
        }else if(s[i]=='i')
        {
            v[2]++;
        }else if(s[i]=='o')
        {
            v[3]++;
        }else if(s[i]=='u')
        {
            v[4]++;
        }
    }
    for(i=0; i<5; i++) //controllo il valore maggiore e uso un puntatore *pos per ricordarmi dell'indice
        {
            if(v[i]>max) //semplicemente la funzione ritorna la prima vocale max incontrata
            {
                max=v[i];
                *pos=i;
            }
        }
    return max;
}

char vocale(int pos)
{
    if(pos==0)
        return 'a';
    if(pos==1)
        return 'e';
    if(pos==2)
        return 'i';
    if(pos==3)
        return 'o';
    if(pos==4)
        return 'u';
}

void modificaFrase(char s[80], char c)
{
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]==c)
            s[i]=c-32;
    }
}


int main()
{
    char frase[80];
    int pos;
    printf("Inserisci una frase con soli caratteri minuscoli e spazi bianchi: ");
    fgets(frase, 80, stdin);
    int max=ControllaVocale(frase, &pos);
    printf("%d", pos);
    char voc=vocale(pos);
    printf("\n\nLa vocale piu' presente e' la [%c]. Precisamente e' presente %d volte nella frase.\n\n", voc, max);
    modificaFrase(frase, voc);
    printf("La frase modificata e': %s", frase);
}
