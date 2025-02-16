#include "../include/gestione.h"


// Inserisce una nuova parola fornita dall'utente nel dizionario.
// Input: dizionario
// Output: inserisce la parola nel dizionario con il suo significato e sinonimi
void inserisci_parola(Dizionario *dizionario)
{
    // Indice prototipo che verra' utilizzato per ordinare la nuova parola nel dizionario
    int indice_ordinato = dizionario->n_parole;

    printf("\n--- Inserimento nuova parola ---");
    printf("\nInserire la parola (max 100 caratteri): ");

    // Chiede input finche' le condizioni non sono rispettate
    while (!inserisci_nome(dizionario, &indice_ordinato));

    printf("\nParola salvata.");
    printf("\n\nInserire il significato (max 500 caratteri): ");

    ricevi_input(dizionario->parole[indice_ordinato].significato, MAX_LUNGHEZZA*5);
    printf("\nSignificato salvato.");

    inserisci_sinonimi(dizionario, indice_ordinato);
    printf("\nSinonimi salvati.");

    printf("\n\n*Parola aggiunta al dizionario*\n\n");

    printf("Parola: '%s'\n", dizionario->parole[indice_ordinato].nome);
    printf("Significato: '%s'\n", dizionario->parole[indice_ordinato].significato);
    printf("Sinonimi: ");

    for (int i = 0; i < dizionario->parole[indice_ordinato].n_sinonimi; i++)
        printf("'%s' ", dizionario->parole[indice_ordinato].sinonimi[i]);

    printf("\n\n");
}

// Inserisce il nome della nuova parola nel dizionario, e poi procede ad ordinarla al suo interno.
// Input: dizionario, indice_ordinato (non ancora ordinato)
// Output: aggiunge la nuova parola al dizionario con il suo nome, e modifica 'indice_ordinato' per ordinare la parola
bool inserisci_nome(Dizionario *dizionario, int *indice_ordinato)
{
    char nome[MAX_LUNGHEZZA];
    char lettera, lettera_salvata;
    int n_parole = 0;

    ricevi_input(nome, MAX_LUNGHEZZA);
    lettera = tolower(nome[0]);

    for (int i = 0; i < *indice_ordinato; i++)
    {
        lettera_salvata = tolower(dizionario->parole[i].nome[0]);

        // Verifica se la parola e' gia' presente nel dizionario
        if (strcmp(dizionario->parole[i].nome, nome) == 0)
        {
            printf("\nLa parola e' gia' presente nel dizionario. Riprovare: ");
            return false;
        }

        // Se esiste una parola con la stessa iniziale, incrementa il contatore
        else if (lettera == lettera_salvata)
            n_parole++;
    }

    if (n_parole >= MAX_PAROLE_PER_LETTERA)
    {
        printf("\nCi sono gia' 5 parole salvate con questa iniziale. Riprovare: ");
        return false;
    }

    ord_inser(dizionario, indice_ordinato, nome);
    return true;
}


// Inserisce i sinonimi della nuova parola durante l'operazione di inserimento parola.
// Input: dizionario, indice_ordinato
// Output: modifica la nuova parola nel dizionario aggiungendo i sinonimi
void inserisci_sinonimi(Dizionario *dizionario, int indice_ordinato)
{
    char input[2];
    int n_sinonimi;
    printf("\n\nInserire il numero di sinonimi (max 5): ");

    do
    {
        ricevi_input(input, 2);
        // Conversione da carattere a intero
        n_sinonimi = input[0] - '0';

        if (n_sinonimi < 1 || n_sinonimi > 5)
            printf("\nInserire un numero da 1 a 5: ");
    }
    while (n_sinonimi < 1 || n_sinonimi > 5);

    for (int i = 0; i < n_sinonimi; i++)
    {
        printf("\nInserire sinonimo %d: ", i+1);
        ricevi_input(dizionario->parole[indice_ordinato].sinonimi[i], MAX_LUNGHEZZA);
    }

    dizionario->parole[indice_ordinato].n_sinonimi = n_sinonimi;
}
