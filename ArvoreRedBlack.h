#include "Types.h"

redblack* criaNovoRB();
void rotacaoEsquerdaRB(redblack **ArvoreRB, redblack *noh);
void rotacaoDireitaRB(redblack **ArvoreRB, redblack *noh);
redblack* inserir_NovoRB(redblack **ArvoreRB, redblack *noh);
void inserirCorRB(redblack **ArvoreRB, redblack *noh);
void removerCorRB(redblack **ArvoreRB, redblack *noh);
redblack* sucessorRB(redblack *noh);
redblack* maximoRB(redblack *noh);
redblack* minimoRB(redblack *noh);
void EmOrdemRB(redblack* ArvoreRB);
void mostraDadosNohRB(redblack* noh);
void visitarEmOrdemRB(redblack* Arvore);
int calcularAlturaPretaRB(redblack*noh);
redblack* localizar_Noh_ArvoreRB(redblack* noh, int numero_arvore);
redblack* rotacaoDireitaEsquerdaRB(redblack* arvore);
redblack* rotacaoEsquerdaDireitaRB(redblack*arvore);
redblack *removerRB(redblack **ArvoreRB, redblack *noh);

void initializeRB (QueueRB *q);
void enqueueRB (QueueRB *q, redblack *n);
redblack * dequeueRB (QueueRB *q);
redblack* headRB (QueueRB q);
int isEmptyRB (QueueRB q);
int isFullRB (QueueRB q);
void exibirRB(redblack * raiz, int flag);

void mainArvRB();