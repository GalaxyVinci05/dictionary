#include "../include/io.h"

// Stampa il menu iniziale del dizionario.
// Input: n_parole (numero di parole salvate nel dizionario)
// Output: stampa del testo del menu
void inizializza(int n_parole)
{
    printf("--- Dizionario ---\n\n");
    printf("Parole salvate: %d\n\n", n_parole);
    printf("1. Inserire una nuova parola\n");
    printf("2. Ricercare una parola nel dizionario\n");
    printf("3. Esci\n");
    printf("\nSelezionare l'operazione da eseguire digitando il numero corrispondente: ");
}

// Funzione generica per ricevere input dall'utente entro un limite di caratteri
// Input: input (puntatore a una stringa), limite (limite di caratteri concessi)
// Output: 'input' assume il valore dell'input inserito dall'utente, non vuoto ed entro il 'limite' definito
void ricevi_input(char* input, int limite)
{
    do
    {
        if (fgets(input, limite + 1, stdin) != NULL)
        {
            // Verifica che l'input non sia vuoto
            if (strlen(input) <= 1)
                printf("\nErrore: nessun input inserito. Riprovare: ");

            // Verifica se l'ultimo carattere di input e' un carattere newline: in caso contrario l'input e' troppo lungo
            else if (strchr(input, '\n') == NULL)
            {
                // Rimuove caratteri newline residui
                while (getchar() != '\n');
                printf("\nErrore: limite caratteri superato. Riprovare: ");
            }
        }
        else
        {
            // Se fgets restituisce NULL, vuol dire che e' stato incontrato EOF
            printf("\nTerminato dall'utente.\n");
            exit(0);
        }
    } while (strchr(input, '\n') == NULL || strlen(input) <= 1);

    // Rimuovi il carattere newline dalla stringa finale
    input[strcspn(input, "\n")] = '\0';
}

// Ricerca una parola all'interno del dizionario.
// Input: dizionario
// Output: stampa la parola ricercata con il suo significato e sinonimi
void ricerca_parola(Dizionario *dizionario)
{
    char chiave[MAX_LUNGHEZZA];
    int indice;

    printf("\n--- Ricerca parola ---");
    printf("\nInserire la parola da cercare: ");

    do
    {
        ricevi_input(chiave, MAX_LUNGHEZZA);
        indice = ric_bin_ric(dizionario, chiave, 0, dizionario->n_parole-1);

        if (indice == -1)
            printf("\nParola non trovata. Riprovare: ");

    } while (indice == -1);
    
    printf("\n*Parola trovata*\n");
    printf("\nParola: '%s'", dizionario->parole[indice].nome);
    printf("\nSignificato: '%s'", dizionario->parole[indice].significato);
    printf("\nSinonimi: ");

    // Se la parola contiene sinonimi, li stampa
    if (dizionario->parole[indice].n_sinonimi > 0)
    {
        for (int i = 0; i < dizionario->parole[indice].n_sinonimi; i++)
            printf("'%s' ", dizionario->parole[indice].sinonimi[i]);
    }
    else
    {
        printf("(nessuno)");
    }

    printf("\n\n");
}
