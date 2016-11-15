#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "ArvoreAVL.h"


Tavl * criarNoAVL (char elem) {
	Tavl * raiz;
	raiz = (Tavl *) malloc (sizeof(Tavl));
	raiz->info = elem;
	raiz->esq = NULL;
	raiz->dir = NULL;
	raiz->fatbal = 0;
	return raiz;
}

void rotacaoDir (Tavl **a, int *status) {
	Tavl *b, *c;
	b = (*a)->esq;
	if (b->fatbal == -1) { // rotação simples
		(*a)->esq = b->dir;
		b->dir = *a;
		(*a)->fatbal = 0;
		*a = b;
	}
	else { // rotação dupla
		c = b->dir;
		b->dir = c->esq;
		c->esq = b;
		(*a)->esq = c->dir;
		c->dir = *a;
		if (c->fatbal == -1)
			(*a)->fatbal = 1;
		else
			(*a)->fatbal = 0;
		if (c->fatbal == 1)
			b->fatbal = -1;
		else
			b->fatbal = 0;
		*a = c;
	}
	(*a)->fatbal = 0;
	*status = 0;
}

void rotacaoEsq (Tavl **a,int *status) {
	Tavl * b, * c;
	b = (*a)->dir;
	if (b->fatbal == 1) { // rotação simples
		(*a)->dir = b->esq;
		b->esq = *a;
		(*a)->fatbal = 0;
		*a = b;
	}
	else { // rotação dupla
		c = b->esq;
		b->esq = c->dir;
		c->dir = b;
		(*a)->dir = c->esq;
		c->esq = *a;
		if (c->fatbal == 1)
			(*a)->fatbal = -1;
		else
			(*a)->fatbal = 0;
		if (c->fatbal == -1)
			b->fatbal = 1;
		else
			b->fatbal = 0;
		*a = c;
	}
	(*a)->fatbal = 0;
	*status = 0;
}

void inserirAVL (Tavl **raiz, char elem, int *status) {
	if (*raiz == NULL) {
		*raiz = criarNoAVL(elem);
		*status = 1;
	}
	else if (elem == (*raiz)->info) {
		printf ("Elemento ja consta na arvore. \n");
		return;
	}
	else if(elem < (*raiz)->info){
		inserirAVL(&((*raiz)->esq),elem,status);
		if (*status == 1)
			switch ((*raiz)->fatbal) {
			case 1 : 
				(*raiz)->fatbal = 0; 
				*status = 0; 
				break;
			case 0 : 
				(*raiz)->fatbal = -1; 
				break;
			case -1 : 
				rotacaoDir(&(*raiz),status); 
				break;
		}
	}
	else {
		inserirAVL(&((*raiz)->dir),elem,status);
		if (*status == 1)
			switch ((*raiz)->fatbal) {
			case -1 : 
				(*raiz)->fatbal = 0; 
				*status = 0; 
				break;
			case 0 : 
				(*raiz)->fatbal = 1; 
				break;
			case 1 : 
				rotacaoEsq(&(*raiz),status); 
				break;
		}
	}
}

Tavl * maiorAVL(Tavl **raiz){
	Tavl * aux;
	aux = *raiz;
	if (aux->dir == NULL){
		*raiz = (*raiz)->esq;
		return (aux);
	}
	else
		return maiorAVL(&((*raiz)->dir));
}

void removerNoAVL(Tavl **raiz){
	Tavl * pos;
	pos = *raiz;
	if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) // Não tem filhos
		*raiz = NULL;
	else if ((*raiz)->esq == NULL) // Não tem filho a esquerda
		*raiz = (*raiz)->dir;
	else if ((*raiz)->dir == NULL) // Não tem filho a direita
		*raiz = (*raiz)->esq;
	else{ // Tem ambos os filhos
		pos = maiorAVL(&((*raiz)->esq));
		(*raiz)->info = pos->info;
	}
	free (pos);
}

void balancearemOrdemAVL (Tavl **raiz){
	int status = 1;
	if (*raiz != NULL)
	{
		balancearemOrdemAVL(&(*raiz)->esq);
		switch ((*raiz)->fatbal) {
			case 1 : 
				(*raiz)->fatbal = 0; 
				rotacaoEsq(&(*raiz),&status);
				break;
			case 0 : 
				(*raiz)->fatbal = -1; 
				break;
			case -1 : 
				rotacaoDir(&(*raiz),&status); 
				break;
		}
		balancearemOrdemAVL(&(*raiz)->dir);
	}
}

void balancearAVL(Tavl **raiz){
	int reto;
	int *status = 0;
	reto = ajustarAlturaAVL(*raiz);
	if(reto > 0)
		rotacaoEsq(&(*raiz), status);
	else
		rotacaoEsq(&(*raiz), status);
	balancearemOrdemAVL(*(&raiz));
}

void removerAVL(Tavl **raiz, char elem){
	if (*raiz == NULL)
		printf("Elemento não encontrado.\n");
	else if (elem == (*raiz)->info)
		removerNoAVL(&(*raiz));
	else{
		if (elem < (*raiz)->info)
			removerAVL(&((*raiz)->esq),elem);
		else
			removerAVL(&((*raiz)->dir),elem);
	}
	balancearAVL(&(*raiz));
}

int ajustarAlturaAVL (Tavl *raiz) {
	int he, hd;
	if (raiz != NULL) {
		he = ajustarAlturaAVL (raiz->esq);
		hd = ajustarAlturaAVL (raiz->dir);
		raiz->fatbal = hd - he;

		if (he > hd)
			return he + 1;
		else
			return hd + 1;
	}
	else
		return 0;
}

void exibir_por_nivelAVL(Tavl * raiz){
	QueueAVL fila;
	Tavl * aux;
	if (raiz != NULL)
	{
		initializeAVL(&fila);
		enqueueAVL (&fila,raiz);
		while (isEmptyAVL(fila) == FALSE)
		{
			aux = dequeueAVL(&fila);
			if (aux->esq != NULL)
				enqueueAVL(&fila,aux->esq);
			if (aux->dir != NULL)
				enqueueAVL(&fila,aux->dir);
			printf("%c \n", aux->info);
		}
	}
}

void initializeAVL (QueueAVL *q){
	QueueAVL aux;
	aux = (DescritorArvAVL*)malloc(sizeof(DescritorArvAVL));
	aux->inicio = NULL;
	aux->fim = NULL;
	*q = aux;
}

void exibir_pre_ordemAVL (Tavl * raiz){
	if (raiz != NULL)
	{
		printf("%c \n", raiz->info);
		exibir_pre_ordemAVL(raiz->esq);
		exibir_pre_ordemAVL(raiz->dir);
	}
}

void exibir_pos_ordemAVL (Tavl * raiz){
	if (raiz != NULL)
	{
		exibir_pos_ordemAVL(raiz->esq);
		exibir_pos_ordemAVL(raiz->dir);
		printf("%c \n", raiz->info);
	}
}

void exibir_em_ordemAVL (Tavl * raiz)
{
	if (raiz != NULL)
	{
		exibir_em_ordemAVL(raiz->esq);
		printf("%c \n", raiz->info);
		exibir_em_ordemAVL(raiz->dir);
	}
}

void enqueueAVL (QueueAVL *q, Tavl *n){
	NoQueueArvAVL *aux;
	aux = (NoQueueArvAVL*)malloc(sizeof(NoQueueArvAVL));
	aux->info = n;
	if (isEmptyAVL(*q) == TRUE){
		(*q)->inicio = aux;
		(*q)->fim = aux;
	}
	else{
		(*q)->fim->prox = aux;
		(*q)->fim = aux;
	}
}

Tavl * dequeueAVL (QueueAVL *q){
	NoQueueArvAVL *aux;
	Tavl * s;
	aux = (*q)->inicio;
	(*q)->inicio = (*q)->inicio->prox;
	if ((*q)->inicio == NULL)
		(*q)->fim = NULL;
	s = aux->info;
	free(aux);
	return s;
}

Tavl* headAVL (QueueAVL q){
	return q->inicio->info;
}

int isEmptyAVL (QueueAVL q){
	if (q->inicio == NULL)
		return TRUE;
	else
		return FALSE;
}

int isFullAAVL (QueueAVL q){
	return FALSE;
}



Tavl * consultarAVL(Tavl *raiz, char elem){
	if (raiz == NULL)
		return NULL;
	else if (elem == raiz->info)
		return raiz;
	else if (elem < raiz->info)
		return consultarAVL(raiz->esq,elem);
	else return consultarAVL(raiz->dir,elem);
}

int mainAVL(){
	Tavl *arvAVL = NULL, *retorno= NULL;
	char op, elemento;
	int op1, status = 0;

	printf("Digite a opcao que deseja:\n");
	printf("1 - Inserir\n2 - Remover\n3 - Consultar\n4 - Exibir Por Nivel\n5 - Exibir Pre Ordem\n6 - Exibir Pos Ordem\n7 - Exibir Em Ordem\n");
	op = getchar();
	fflush(stdin);
	switch (op){
	case '1': 		
		do{
			printf("Informe o elemento a ser inserido: ");
			scanf("%c", &elemento);
			fflush(stdin);
			inserirAVL(&arvAVL, elemento, &status);
			printf("Para para a insercao pressione space ");
			op1 = getchar();
			fflush(stdin);
		}while(op1 != ' ');
		break;
	case '2': 
		printf("Informe o elemento que deseja remover: ");
		elemento = getchar();
		fflush(stdin);
		removerAVL(&arvAVL, elemento);
		break;
	case '3':
		printf("Qual elemento deseja buscar: ");
		elemento = getchar();
		fflush(stdin);
		retorno = consultarAVL(arvAVL, elemento);
		if(retorno != NULL)
			printf("Valor nao consta na arvore!\n");
		else
			printf("Valor encontrado!\n");
	case '4':
		exibir_por_nivelAVL (arvAVL);
		break;
	case '5':
		exibir_pre_ordemAVL (arvAVL);
		break;
	case '6':
		exibir_pos_ordemAVL (arvAVL);
		break;
	case '7':
		exibir_em_ordemAVL (arvAVL);
		break;
	default:
		printf("Opcao invalida!");
		break;
	}
}