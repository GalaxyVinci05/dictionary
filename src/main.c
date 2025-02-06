#include "functions.h"
#include "types.h"

int main(void)
{
    bool esci = false;
    char azione;

    Parola parole[MAX_PAROLE];
    int indice_parola = 0;

    do
    {
        inizializza(indice_parola);
        azione = getchar();

        // Previene cicli infiniti causati dall'aver incontrato EOF, ad esempio nel caso in cui l'utente preme Ctrl+D o Ctrl+Z
        if (azione == EOF)
        {
            printf("\nTerminato dall'utente.\n");
            exit(0);
        }

        // Svuota il buffer di stdin scartando caratteri newline residui
        while (getchar() != '\n');

        switch (azione)
        {
            case '1':
                inserisci_parola(parole, indice_parola);
                indice_parola++;
                break;
            case '2':
                if (indice_parola > 0)
                    ricerca_parola(parole, indice_parola);
                else
                    printf("\nNon ci sono parole nel dizionario.\n\n");
                break;
            case '3':
                esci = true;
                break;
            default:
                printf("\nErrore: azione invalida, riprovare.\n\n");
                break;
        }
    }
    while (!esci);

    printf("\nArrivederci!\n");
    return 0;
}
