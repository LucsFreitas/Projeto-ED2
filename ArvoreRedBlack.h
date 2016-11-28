#include "Types.h"

void rotacaoEsquerdaRB(redblack *raiz_original, redblack **ArvoreRB, redblack *noh);
void rotacaoDireitaRB(redblack *raiz_original, redblack **ArvoreRB, redblack *noh);
redblack* inserir_NovoRB(redblack **ArvoreRB, redblack *noh);
void inserirCorRB(redblack *raiz_original, redblack **ArvoreRB,redblack *noh);
redblack *removerRB(redblack **ArvoreRB, redblack *noh);
void removerCorRB(redblack **ArvoreRB, redblack *noh);
redblack* sucessorRB(redblack *noh);
redblack* maximoRB(redblack *noh);
redblack* minimoRB(redblack *noh);
redblack* criaNovoRB();
void visitarEmOrdemRB(redblack* ArvoreRB);
void mostraDadosNohRB(redblack* noh);
int calcularAlturaPretaRB(redblack *noh);
redblack* localizar_Noh_ArvoreRB(redblack* noh, int numero_arvore);

void initializeRB (QueueRB *q);
void enqueueRB (QueueRB *q, redblack *n);
redblack * dequeueRB (QueueRB *q);
redblack* headRB (QueueRB q);
int isEmptyRB (QueueRB q);
int isFullRB (QueueRB q);
void exibirRB(redblack * raiz, int flag);

void mainArvRB();