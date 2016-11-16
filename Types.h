#ifndef ESTRUTURAS
#define ESTRUTURAS

#define TRUE 1
#define FALSE 0

//	Queue + Stacks + ArvBin
typedef struct no {
	struct no *esq;
	char info;
	struct no *dir;
}TNo;

typedef struct noQueueArvBin {
	TNo *info;
	struct noQueueArvBin * prox;
}NoQueueArvBin;

typedef struct descritorArvBin {
	NoQueueArvBin * inicio, * fim;
}DescritorArvBin;

typedef DescritorArvBin * QueueArvBin;

typedef struct noPilhaArvBin {
	TNo * info;
	struct noPilhaArvBin * prox;
} NoPilhaArvBin;

typedef NoPilhaArvBin * StackArvBin;

//	Queue + Arvore AVL
typedef struct avl {
	char info;
	struct avl * dir;
	struct avl * esq;
	int fatbal;
}Tavl;

typedef struct noQueueArvAVL {
	Tavl *info;
	struct noQueueArvAVL * prox;
}NoQueueArvAVL;

typedef struct descritorArvAVL {
	NoQueueArvAVL * inicio, * fim;
}DescritorArvAVL;

typedef DescritorArvAVL * QueueAVL;


#endif