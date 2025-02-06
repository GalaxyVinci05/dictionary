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
bool inserisci_nome(Parola*, int*);
void inserisci_sinonimi(Parola*, int);
void ord_inser(Parola*, int*, char*);

#endif /* Funzioni_h */
