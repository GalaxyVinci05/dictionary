#ifndef IO_h
#define IO_h

// IO_h -> Dichiarazioni delle funzioni inerenti all'input e l'output del menu del dizionario e delle parole salvate

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmi.h"
#include "strutture.h"

void inizializza(int);
void ricevi_input(char*, int);
void ricerca_parola(Dizionario*);

#endif /* IO_h */
