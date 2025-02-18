/*
*  --- Dizionario ---
*
*  Il seguente programma, che simula la gestione di un dizionario della lingua italiana, permette all’utente di:
*  - Inserire nuove parole nel dizionario, inizialmente vuoto
*  - Ricercare le parole al suo interno una volta salvate
*
*  Insieme alle parole, l'utente dovra' inserire anche il loro significato e un massimo di 5 sinonimi.
*  La ricerca di una parola dunque, se essa esiste nel dizionario, mostrera':
*  - Il nome della parola
*  - Il suo significato
*  - I suoi sinonimi, se ve ne sono
*
*  Infine vi possono essere un massimo di 5 parole nel dizionario con la stessa iniziale.
*/

#include "../include/main.h"

int main(void)
{
    Dizionario dizionario;
    bool esci = false;
    char azione[2];

    do
    {
        // Stampa il menu iniziale e poi chiede all'utente l'azione da eseguire
        inizializza(dizionario.n_parole);
        ricevi_input(azione, 2);

        switch (azione[0])
        {
            case '1':  // Inserisci una nuova parola
                inserisci_parola(&dizionario);
                dizionario.n_parole++;
                break;
            case '2':  // Ricerca una parola
                if (dizionario.n_parole > 0)
                    ricerca_parola(&dizionario);
                else
                    printf("\nNon ci sono parole nel dizionario.\n\n");
                break;
            case '3':  // Esci
                esci = true;
                break;
            default:
                printf("\nAzione invalida, riprovare.\n\n");
                break;
        }
    }
    while (!esci);

    printf("\nArrivederci!\n");
    return 0;
}
