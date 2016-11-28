#include "Types.h"

void exibirTabelaInt(ThashInt *tab[], int tam);
int hashInt(int valor, int tamanhoTabela);
void preencherInt(ThashInt **tab[], int tam, int dado);
ThashInt* buscarInt(ThashInt *tab[], int dado, int tam);
void inicializaHashInt(ThashInt *tab[], int tam);
void mainHashInt();