#include "functions.h"
#include "types.h"

int main(void)
{
    bool esci = false;
    char azione[2];

    Parola parole[MAX_PAROLE];
    int indice_parola = 0;

    do
    {
        inizializza(indice_parola);
        ricevi_input(azione, 2);

        switch (azione[0])
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
                printf("\nAzione invalida, riprovare.\n\n");
                break;
        }
    }
    while (!esci);

    printf("\nArrivederci!\n");
    return 0;
}
