#include "Types.h"

Tavl * criarNo (char elem);
void rotacaoDir (Tavl **a, int *status);
void rotacaoEsq (Tavl **a,int *status);
void inserirNo (Tavl **raiz, char elem, int *status);
Tavl * maior(Tavl **raiz);
void remover_no(Tavl **raiz);
void balancearemOrdem (Tavl **raiz);
void balancear(Tavl **raiz);
void remover(Tavl **raiz, char elem);
int ajustar_altura (Tavl *raiz);
void initializeAVL (QueueAVL *q);
void enqueueAVL (QueueAVL *q, Tavl *n);
Tavl * dequeueAVL (QueueAVL *q);
Tavl* headAVL (QueueAVL q);
int isEmptyAVL (QueueAVL q);
int isFullAAVL (QueueAVL q);
Tavl * consultarAVL(Tavl *raiz, char elem);

int mainArvAVL();