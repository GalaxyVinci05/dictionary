#include "../include/algoritmi.h"

// Funzione per l'ordinamento della nuova parola nel dizionario.
// Input: dizionario, n (numero di parole nel dizionario), nuova_parola (inserita dall'utente)
// Output: nuova parola ordinata nell'array di parole salvate
void ord_inser(Dizionario *dizionario, int *indice_ordinato, char *nuova_parola)
{
    // Algoritmo di ordinamento per inserimento (si assume che il resto dell'array sia gia' ordinato)
    // Complessita' di tempo O(n)
    int i = *indice_ordinato-1;
    while (i >= 0 && strcmp(dizionario->parole[i].nome, nuova_parola) > 0)
    {
        strcpy(dizionario->parole[i+1].nome, dizionario->parole[i].nome);
        i--;
    }

    // Assegna l'indice ordinato dove continuare ad inserire i dati della parola
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
        return med;
    else if (strcmp(chiave, dizionario->parole[med].nome) > 0)
        return ric_bin_ric(dizionario, chiave, med+1, dx);
    else
        return ric_bin_ric(dizionario, chiave, sx, med-1);
}
