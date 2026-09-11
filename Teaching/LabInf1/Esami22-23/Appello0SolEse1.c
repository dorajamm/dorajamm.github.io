
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RIG 25
#define COL 15
#define MIN 11
#define MAX 99

void GeneraMatrice (int a[RIG][COL])
{
    int i,j;
    srand(time(NULL));
    for(i=0; i<RIG; i++)
    {
        for(j=0; j<COL; j++)
        {
            a[i][j]=(rand()%(MAX-MIN+1))+MIN;
        }
    }
}

void GenMat (int a[RIG][COL])
{
    srand (time(NULL));
    int i,j;
    //genero prima la prima riga e colonna e per farlo genero il primo elemento

    a[0][0]= (rand()% (MAX - MIN +1))+ MIN;

    for (i=1; i<COL; i++)
        do {
            a[0][i]=(rand()% (MAX - MIN +1))+ MIN;
        } while (a[0][i]==a[0][i-1]);


        for (i=1; i<RIG; i++)
        do {
            a[i][0]=(rand()% (MAX - MIN +1))+ MIN;
        } while (a[i][0]==a[i-1][0]);

    //genero il resto della matrice

    for (i=0; i<RIG; i++)
        for (j=0; j<COL; j++)
            do {
            a[i][j]=(rand()% (MAX - MIN +1))+ MIN;
        } while (a[i][j]==a[i-1][j] || a[i][j]==a[i][j-1]);
}



void StampaMatrice (int a[RIG][COL])
{
    int i,j;
    for(i=0; i<RIG; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}

int MaxRiga (int a[RIG][COL], int r)
{
    int i, max=a[r][0];

    for(i=1; i<COL; i++)
        if(a[r][i]>max)
                max=a[r][i];
    return max;
}

int MaxColonna (int a[RIG][COL], int c)
{
    int i, max=a[0][c];
    for(i=1; i<RIG; i++)
            if(a[i][c]>max)
                max=a[i][c];
    return max;
}

int EsisteMMax (int mat[RIG][COL], int* xMM, int* yMM)
{
    int i,j,cont=0, minMMax=100;
    int vetMaxCol[COL], vetMaxRig[RIG];

    //preparo un vettore con tutti i max di ogni riga
    for(i=0; i<RIG; i++)
        vetMaxRig[i] = MaxRiga(mat,i);

   //preparo un vettore con tutti i max di ogni riga
    for(j=0; j<COL; j++)
        vetMaxCol[j] = MaxColonna(mat,j);

    for(i=0; i<RIG; i++)
        for(j=0; j<COL; j++)
            if(vetMaxCol[j]==mat[i][j] &&vetMaxRig[i]==mat[i][j]){//il punto è un MMax
                cont++;
                if (mat[i][j]<minMMax)//aggiorno il minimo
                {   minMMax=mat[i][j];
                    *xMM=i;
                    *yMM=j;
                }
            }

    return cont;
}


//restituisce il massimo della matrice
int MaxMat(int a[RIG][COL])
{
    int i,j, Max=a[0][0];

    for (i=0; i<RIG; i++)
        for (j=0; j<COL; j++)
            if (a[i][j]>Max) Max=a[i][j];
    return Max;
}

int main ()
{
    int M[RIG][COL];
    int xMM=-1, yMM=-1, m=0, Maxmat=0, Maymat=0, r;
    GenMat(M);
    StampaMatrice(M);
    m = EsisteMMax (M, &xMM, &yMM);

    if (m==0) printf ("\nLa matrice non ammette MMax");
    else
    {
        printf ("\nLa matrice ammette %d MMax", m);
        printf ("\nIl piu' piccolo di questi sta alla riga %d e alla colonna %d e ha valore %d", xMM+1, yMM+1,M[xMM][yMM]  );
        r = MaxMat(M);
        if (M[xMM][yMM]==r) printf ("\nQuesto coincide con il massimo della matrice");
        else printf ("\nQuesto non coincide con il massimo della matrice che invece e' %d", r);
    }

}
