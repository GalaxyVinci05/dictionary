#include "functions.h"
#include "types.h"

void inizializza()
{
    printf("--- Dizionario ---\n\n");
    printf("1. Inserire una nuova parola\n");
    printf("2. Ricercare una parola\n");
    printf("3. Esci\n");
    printf("\nSelezionare l'operazione da eseguire digitando il numero corrispondente: ");
}

void ricevi_input(char* input, int limite)
{
    fgets(input, limite, stdin);
    // scanf("%s", input);

    // Verifica che la lunghezza di input rientri nel limite: in caso contrario ripete la funzione ricevi_input
    if (strlen(input) > limite)
    {
        printf("\nLimite caratteri superato. Riprovare: ");
        ricevi_input(input, limite);
    }
}

void inserisci_parola(Parola* parola)
{
    printf("\n--- Inserimento nuova parola ---");
    printf("\nInserire la parola (max 50 caratteri): ");
    ricevi_input(parola->nome, MAX_LUNGHEZZA);
}
