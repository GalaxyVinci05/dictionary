#include "../include/main.h"

int main(void)
{
    Dizionario dizionario;
    bool esci = false;
    char azione[2];

    do
    {
        inizializza(dizionario.n_parole);
        ricevi_input(azione, 2);

        switch (azione[0])
        {
            case '1':
                inserisci_parola(&dizionario);
                dizionario.n_parole++;
                break;
            case '2':
                if (dizionario.n_parole > 0)
                    ricerca_parola(&dizionario);
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
