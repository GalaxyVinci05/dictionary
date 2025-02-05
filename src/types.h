#ifndef Tipi_h
#define Tipi_h

#define MAX_LUNGHEZZA 100
#define MAX_SINONIMI 5
#define MAX_PAROLE 26*5
#define MAX_PAROLE_PER_LETTERA 5

typedef struct {
    char nome[MAX_LUNGHEZZA];
    char significato[MAX_LUNGHEZZA*5];
    char sinonimi[MAX_SINONIMI][MAX_LUNGHEZZA];
    int n_sinonimi;
} Parola;

#endif /* Tipi_h */
