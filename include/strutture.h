#ifndef Strutture_h
#define Strutture_h

// Strutture_h -> Definizioni di tutte le strutture dati e le costanti utilizzate nel programma

#define MAX_LUNGHEZZA 100
#define MAX_SINONIMI 5
#define MAX_PAROLE 26*5
#define MAX_PAROLE_PER_LETTERA 5

typedef struct
{
    char nome[MAX_LUNGHEZZA];
    char significato[MAX_LUNGHEZZA*5];
    char sinonimi[MAX_SINONIMI][MAX_LUNGHEZZA];
    int n_sinonimi;  // Numero di sinonimi della parola
} Parola;

typedef struct
{
    Parola parole[MAX_PAROLE];
    int n_parole;  // Numero di parole salvate nel dizionario
} Dizionario;

#endif /* Strutture_h */
