#include "Types.h"

TNo * consultarArvBin(TNo *raiz, int elem);
void inserirArvBin(TNo **raiz, int elem);
void removerArvBin(TNo **raiz, int elem);
void remover_noArvBin(TNo **raiz);
TNo * maiorArvBin(TNo **raiz);
void enqueueArvBin (QueueArvBin *q, TNo *n);
TNo * dequeueArvBin (QueueArvBin *q);
TNo* headArvBin (QueueArvBin q);
int isEmptyArvBin (QueueArvBin q);
int isFullArvBin (QueueArvBin q);
void initializeArvBin (QueueArvBin *q);
void exibir_por_nivelArvBin(TNo * raiz);
void exibir_pre_ordemArvBin (TNo * raiz);
void exibir_pos_ordemArvBin (TNo * raiz);
void exibir_em_ordemArvBin (TNo * raiz);
void exibirArvBin(TNo * raiz);

void ajustar_gotoxy_ArvBin(int linha, int coluna, int cont_val);
void exibirArvBin(TNo * raiz);

int mainArvBin();