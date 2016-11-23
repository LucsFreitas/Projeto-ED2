#include "Types.h"

int mainCSE();
void criarNOCLSE(TLSEC ** novo);
void cadastrarCLSE(TLSEC ** lista);
void listarCLSE(TLSEC * lista);
TLSEC * consultarCLSE(TLSEC * lista, char nome[]);
void removerCLSE(TLSEC **lista, char nome[]);
void limparNOCLSE(TLSEC **lista);