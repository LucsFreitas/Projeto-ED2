#include "Types.h"

int mainLSE();
void criarNovo(TLSE **lista, char n[]);
void adicionarNovoLSE(TLSE **lista, char n[]);
void removerElementoLSE(TLSE**lista, char n[]);
void exibirListaLSE(TLSE *lista);
TLSE *procurarLSE(TLSE *lista, char n[]);
void alterarLSE(TLSE **lista, char n[]);
void limparLSE(TLSE**lista);