#include <stdio.h>
#include <stdbool.h>
#include "types.h"
#include "functions.h"

int main(void)
{
    bool esci = false;
    char input[MAX_LUNGHEZZA];
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

void inizializza()
{
    printf("--- Dizionario ---\n\n");
    printf("1. Inserire una nuova parola\n");
    printf("2. Ricercare una parola\n");
    printf("3. Esci\n");
    printf("\nSelezionare l'operazione da eseguire digitando il numero corrispondente: ");
}

void ricevi_input(char* input)
{
    scanf("%s", input);
}
