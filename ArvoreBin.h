#include "Types.h"

TNo * consultarArvBin(TNo *raiz, char elem);
void inserirArvBin(TNo **raiz, char elem);
void removerArvBin(TNo **raiz, char elem);
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

void ajustar_gotoxy(int linha, int coluna, int cont_val);
void initializeStackArvBin (StackArvBin *s);
int isEmptyStackArvBin(StackArvBin s);
void pushStackArvBin(StackArvBin *s, TNo * no);
TNo * popArvBin (StackArvBin *s);
void exibirArvBin(TNo * raiz);

int mainArvBin();