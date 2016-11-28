#include "Types.h"

int mainCSE();
void criarNOCLSE(TLSEC ** novo);
void cadastrarCLSE(TLSEC ** lista);
void exibirVoltaS (int coluna, int flag);
void listarCLSE(TLSEC * lista);
TLSEC * consultarCLSE(TLSEC * lista, int nome);
void removerCLSE(TLSEC **lista, int nome);
void limparNOCLSE(TLSEC **lista);