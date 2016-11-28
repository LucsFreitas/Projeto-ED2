#include "Types.h"

void mainHashAlfa();
int HDeslAlfa(char dado[], int tamanhoTabela);
void inicializaHashAlfa(ThashAlfa *tab[], int tam);
int hashAlfa(char dado[], int tamanhoTabela);
void exibirTabelaAlfa(ThashAlfa *tab[], int tam);
void preencherAlfa(ThashAlfa *tab[], int tam, char dado[], int flag);
ThashAlfa* buscar(ThashAlfa *tab[], char dado[], int tam);