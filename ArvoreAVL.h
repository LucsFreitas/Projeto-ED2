#include "Types.h"

Tavl * criarNo (int elem);
void rotacaoDirAVL (Tavl *raiz_original, Tavl **a, int *status);
void rotacaoEsqAVL (Tavl *raiz_original, Tavl **a,int *status);
void inserirNoAVL (Tavl *raiz_original, Tavl **raiz, int elem, int *status);
Tavl * maiorAVL(Tavl **raiz);
void remover_noAVL(Tavl **raiz);
void balancearemOrdemAVL (Tavl *raiz_original, Tavl **raiz);
void balancearAVL(Tavl *raiz_original, Tavl **raiz);
void remover(Tavl *raiz_original, Tavl **raiz, int elem);
int ajustarAlturaAVL (Tavl *raiz);
void initializeAVL (QueueAVL *q);
void enqueueAVL (QueueAVL *q, Tavl *n);
Tavl * dequeueAVL (QueueAVL *q);
Tavl* headAVL (QueueAVL q);
int isEmptyAVL (QueueAVL q);
int isFullAVL (QueueAVL q);
Tavl * consultarAVL(Tavl *raiz, int elem);
void exibirAVL(Tavl * raiz, int flag);

int mainArvAVL();