#define MAX_LUNGHEZZA 100
#define MAX_SINONIMI 5

struct parola
{
    char nome[MAX_LUNGHEZZA];
    char significato[MAX_LUNGHEZZA];
    char sinonimi[MAX_SINONIMI][MAX_LUNGHEZZA];
};

extern struct parola parola;
