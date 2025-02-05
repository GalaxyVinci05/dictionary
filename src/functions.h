#ifndef Funzioni_h
#define Funzioni_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "types.h"

void inizializza();
void ricevi_input(char*, int);
void inserisci_parola(Parola*, int);
void inserisci_sinonimi(Parola*, int);
bool inserisci_nome(Parola*, int);

#endif /* Funzioni_h */
