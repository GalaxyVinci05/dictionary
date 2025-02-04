#include "functions.h"
#include "types.h"
#include <stdio.h>

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
    bool input_vuoto = false;

    fgets(input, limite + 1, stdin);

    // Verifica che la lunghezza di input rientri nel limite: in caso contrario ripete la funzione ricevi_input
    while (strlen(input) > limite && !input_vuoto)
    {
        fputs("\nErrore: limite caratteri superato. Riprovare: ", stdout);
        fgets(input, limite, stdin);
    }
}

void inserisci_parola(Parola* parola)
{
    printf("\n--- Inserimento nuova parola ---");
    printf("\nInserire la parola (max 50 caratteri): ");
    ricevi_input(parola->nome, MAX_LUNGHEZZA);
    printf("Parola salvata come: %s", parola->nome);
}
