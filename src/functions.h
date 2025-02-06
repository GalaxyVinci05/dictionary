#ifndef Funzioni_h
#define Funzioni_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "types.h"

void inizializza(int);
void ricevi_input(char*, int);
void inserisci_parola(Parola*, int);
bool inserisci_nome(Parola*, int*);
void inserisci_sinonimi(Parola*, int);
void ord_inser(Parola*, int*, char*);
void ricerca_parola(Parola*, int);
int ric_bin_ric(Parola*, char*, int, int);

#endif /* Funzioni_h */
