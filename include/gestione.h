#ifndef Gestione_h
#define Gestione_h

// IO_h -> Dichiarazioni delle funzioni inerenti alla gestione del dizionario, dunque l'inserimento delle parole

#include <stdbool.h>
#include <ctype.h>
#include "io.h"
#include "strutture.h"

void inserisci_parola(Dizionario*);
bool inserisci_nome(Dizionario*, int*);
void inserisci_sinonimi(Dizionario*, int);

#endif /* Gestione_h */
