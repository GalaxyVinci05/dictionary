#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "types.h"

int main(void)
{
    bool esci = false;
    // char input[MAX_LUNGHEZZA];
    char azione;
    Parola parola;

    // Variabile di controllo per scartare caratteri indesiderati in input
    int ch;

    do
    {
        inizializza();
        azione = getchar();

        // Svuota il buffer di stdin scartando caratteri indesiderati come newline o End Of File
        while ((ch = getchar()) != '\n' && ch != EOF);

        switch (azione)
        {
            case '1':
                inserisci_parola(&parola);
                break;
            case '2':
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

    return 0;
}
