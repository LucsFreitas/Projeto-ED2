#ifndef ESTRUTURAS
#define ESTRUTURAS

#define TRUE 1
#define FALSE 0

//	Queue + Stacks + ArvBin
typedef struct no {
	struct no *esq;
	int info;
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

//	Queue + Arvore AVL
typedef struct avl {
	int info;
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

//    Arvore Red - Black

typedef struct noRB{
    int numero_arvore;
    char cor;
    struct noRB *pai;
    struct noRB *esquerda;
    struct noRB *direita;
} redblack;

typedef struct noQueueArvRB {
	redblack *info;
	struct noQueueArvRB * prox;
}NoQueueArvRB;

typedef struct descritorArvRB {
	NoQueueArvRB * inicio, * fim;
}DescritorArvRB;

typedef DescritorArvRB * QueueRB;


//    Lista Simplesmente Encadeada

typedef struct LSE{
	char info[100];
	struct LSE *prox;
}TLSE;

//   Lista Duplamente Encadeada
typedef struct LDE{
	char descricao[100];
	struct LDE *ant;
	struct LDE *prox;
}TLDE;

//   Lista Circular Simples
typedef struct LSEC{
	char nome[50];
	struct LSEC * prox;
}TLSEC;

//   Lista Circular Dupla
typedef struct LDEC{
	char n[50];
	struct LDEC * prox;
	struct LDEC * ant;
}TLDEC;

//	Hash Int
typedef struct hashInt{
	int dados;
	struct hashInt *prox;
}ThashInt;

// Hash Chaves Alfa
typedef struct hashAlfa{
	char dados[50];
	struct hashAlfa *prox;
}ThashAlfa;

//	 Fila HeapSort
typedef struct noQueueHS {
	int info;
	struct noQueueHS * prox;
}NoQueueHS;

typedef struct descritorHS {
	NoQueueHS * inicio, * fim;
}DescritorHS;

typedef DescritorHS * QueueHS;

#endif