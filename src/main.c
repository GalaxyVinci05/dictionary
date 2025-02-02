#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

int main(void)
{
    bool esci = false;
    // char input[MAX_LUNGHEZZA];
    char azione;

    do
    {
        inizializza();
        ricevi_input(&azione);

        switch (azione)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                esci = true;
                break;
            default:
                printf("\nAzione invalida, riprovare.\n\n");
        }
    }
    while (!esci);

    return 0;
}
