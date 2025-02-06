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

void inserisci_parola(Parola *parole, int indice_parola)
{
    // La parola nuova viene ordinata appena inserita dall'utente
    int indice_ordinato = indice_parola;
    size_t n_sinonimi;

    printf("\n--- Inserimento nuova parola ---");
    printf("\nInserire la parola (max 100 caratteri): ");

    // Chiede input finche' le condizioni non sono rispettate
    while (!inserisci_nome(parole, &indice_ordinato));

    printf("Parola salvata come: %s", parole[indice_ordinato].nome);
    printf("\nInserire il significato (max 500 caratteri): ");

    ricevi_input(parole[indice_ordinato].significato, MAX_LUNGHEZZA*5);
    printf("Significato salvato come: %s", parole[indice_ordinato].significato);

    inserisci_sinonimi(parole, indice_ordinato);
    printf("Sinonimi salvati come:\n");

    n_sinonimi = sizeof(parole[indice_ordinato].sinonimi) / sizeof(parole[indice_ordinato].sinonimi[0]);
    for (int i = 0; i < n_sinonimi; i++)
    {
        printf("%s", parole[indice_ordinato].sinonimi[i]);
    }

    printf("\n*Parola aggiunta al dizionario*\n\n");
}

void inserisci_sinonimi(Parola *parole, int indice_parola)
{
    char input[2];
    int n_sinonimi;
    printf("\nInserire il numero di sinonimi (max 5): ");

    do
    {
        ricevi_input(input, 2);
        // Conversione da carattere a intero
        n_sinonimi = input[0] - '0';

        if (n_sinonimi < 1 || n_sinonimi > 5)
        {
            printf("\nInserire un numero da 1 a 5: ");
        }
    }
    while (n_sinonimi < 1 || n_sinonimi > 5);

    for (int i = 0; i < n_sinonimi; i++)
    {
        printf("\nInserire sinonimo %d: ", i+1);
        ricevi_input(parole[indice_parola].sinonimi[i], MAX_LUNGHEZZA);
    }
}

bool inserisci_nome(Parola *parole, int *indice_parola)
{
    char nome[MAX_LUNGHEZZA];
    char lettera, lettera_salvata;
    int n_parole = 0;

    ricevi_input(nome, MAX_LUNGHEZZA);
    lettera = tolower(nome[0]);

    for (int i = 0; i < *indice_parola; i++)
    {
        lettera_salvata = tolower(parole[i].nome[0]);

        // Verifica se la parola e' gia' presente nel dizionario
        if (strcmp(parole[i].nome, nome) == 0)
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

    ord_inser(parole, indice_parola, nome);
    return true;
}

void ord_inser(Parola *parole, int *n, char *nuova_parola)
{
    // Ordinamento per inserimento (si assume che il resto dell'array sia gia' ordinato)
    // Complessita' O(n)
    int i = *n-1;
    while (i >= 0 && strcmp(parole[i].nome, nuova_parola) > 0)
    {
        strcpy(parole[i+1].nome, parole[i].nome);
        i--;
    }

    // Assegna l'indice ordinato dove continuare ad inserire i dati della parola
    *n = i+1;
    strcpy(parole[*n].nome, nuova_parola);
}
