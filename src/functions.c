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
    do
    {
        if (fgets(input, limite + 1, stdin) != NULL)
        {
            // Verifica che l'input non sia vuoto
            if (strlen(input) <= 1)
            {
                printf("\nErrore: nessun input inserito. Riprovare: ");
            }

            // Verifica se l'ultimo carattere di input e' un carattere newline: in caso contrario l'input e' troppo lungo
            else if (strchr(input, '\n') == NULL)
            {
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
}

void inserisci_parola(Parola **parole)
{
    printf("\n--- Inserimento nuova parola ---");
    printf("\nInserire la parola (max 50 caratteri): ");

    //while (!inserisci_nome(parole))
    //    printf("\nLa parola e' gia' presente nel dizionario. Riprovare: ");
    inserisci_nome(parole);

    printf("Parola salvata come: %s", parole[0][0].nome);
}

bool inserisci_nome(Parola **parole)
{
    char nome[MAX_LUNGHEZZA] = "shish";
    char lettera;
    int numero_parole = 0;
    
    Parola nuovaParola = { *nome };
    parole[0][0] = nuovaParola;

    ricevi_input(nome, MAX_LUNGHEZZA);
    lettera = tolower(nome[0]);

    //for (int i = 0; i < MAX_LETTERE; i++)
    //{
        // Verifica se la parola e' gia' presente nel dizionario
    //    if (strcmp(parole[i][0].nome, nome) == 0)
    //        return false;
    //}
    
    //if (strcmp(parole[0][0].nome, nome) == 0)
    //    return false;

    strcpy(parole[0][0].nome, nome);

    return true;
}
