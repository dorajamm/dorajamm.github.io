/* Programma delle Torri di Hanoi, con richiesta del numero di dischi, della
sorgente e della destinazione da input. */

#include <stdio.h>


void muoviUnDisco(int sorgente, int destinazione)
{
printf(" muovi un disco da %2d a %2d\n", sorgente, destinazione);
} /* muoviUnDisco */


void muovi(int n, int sorgente, int destinazione, int ausiliario)
{
if (n == 1)
muoviUnDisco(sorgente, destinazione);
else {
muovi(n-1, sorgente, ausiliario, destinazione);
muoviUnDisco(sorgente, destinazione);
muovi(n - 1, ausiliario, destinazione, sorgente);
}
} /* muovi */


int main(void)
{
int dischi; /* numero di dischi */
int s, d; /* pali sorgente e destinazione */

printf("Numero di dischi? ");
scanf("%d", &dischi);
printf("\nPalo sorgente = 1 ");
printf("\nPalo destinazione = 3 ");

printf("\nPalo ausiliario = 2");
printf("\n\nPer %d dischi le mosse richieste sono:\n", dischi);
muovi(dischi, 1, 3, 2);
putchar('\n');

return 0;
} /* main */

