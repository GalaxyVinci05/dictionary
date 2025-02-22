#include "../include/algoritmi.h"

void scambia(Parola* parola1, Parola* parola2)
{
    Parola temp = *parola1;
    *parola1 = *parola2;
    *parola2 = temp;
}

// Funzione per l'ordinamento della nuova parola nel dizionario.
// Input: dizionario, indice_ordinato (riceve il valore del numero di parole nel dizionario), nuova_parola (la parola inserita dall'utente)
// Output: nuova parola ordinata nell'array di parole salvate, e indice_ordinato assume il valore del nuovo indice della parola
void ordina_parola(Dizionario *dizionario, int *indice_ordinato, char *nuova_parola)
{
    // Algoritmo di ordinamento per inserimento
    // Complessita' di tempo O(n) -> caso migliore (si assume che il resto dell'array sia gia' ordinato)
    int i = *indice_ordinato-1;
    while (i >= 0 && strcmp(dizionario->parole[i].nome, nuova_parola) > 0)
    {
        // Sposta la parola corrente all'indice successivo e decrementa l'indice di controllo
        // strcpy(dizionario->parole[i+1].nome, dizionario->parole[i].nome);
        scambia(&dizionario->parole[i+1], &dizionario->parole[i]);
        i--;
    }

    // Assegna il nuovo indice della parola ordinata e copia la nuova parola alla destinazione
    *indice_ordinato = i+1;
    strcpy(dizionario->parole[*indice_ordinato].nome, nuova_parola);
}

// Funzione per ricercare una parola tra quelle salvate nel dizionario.
// Input: dizionario, chiave (parola da ricercare), sx (indice da dove iniziare), dx (indice finale)
// Output: mediano risultante dalla ricerca binaria ricorsiva
int ric_bin_ric(Dizionario *dizionario, char *chiave, int sx, int dx)
{
    // Algoritmo di ricerca binaria ricorsiva
    // Complessita' di tempo O(log(n))
    int med;
    if (sx > dx)
        return -1;

    med = (sx + dx) / 2;

    if (strcmp(chiave, dizionario->parole[med].nome) == 0)
        return med;  // Il mediato risultato corrisponde all'indice della parola trovata
    else if (strcmp(chiave, dizionario->parole[med].nome) > 0)
        return ric_bin_ric(dizionario, chiave, med+1, dx);
    else
        return ric_bin_ric(dizionario, chiave, sx, med-1);
}
