#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "ArvoreBin.h"

TNo * consultarArvBin(TNo *raiz, char elem){
	if (raiz == NULL)
		return NULL;
	else if (elem == raiz->info)
		return raiz;
	else if (elem < raiz->info)
		return consultarArvBin(raiz->esq,elem);
	else return consultarArvBin(raiz->dir,elem);
}

void inserirArvBin(TNo **raiz, char elem){
	if (*raiz == NULL){
		*raiz = (TNo *) malloc (sizeof(TNo));
		(*raiz)->info = elem;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
	}else if (elem < (*raiz)->info)
		inserirArvBin(&((*raiz)->esq),elem);
	else inserirArvBin(&((*raiz)->dir),elem);
}

void removerArvBin(TNo **raiz, char elem){
	if (*raiz == NULL)
		printf("Elemento não encontrado.\n");
	else if (elem == (*raiz)->info)
		remover_noArvBin(&(*raiz));
	else{
		if (elem < (*raiz)->info)
			removerArvBin(&((*raiz)->esq),elem);
		else
			removerArvBin(&((*raiz)->dir),elem);
	}
}void remover_noArvBin(TNo **raiz){
	TNo * pos;
	pos = *raiz;
	if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) // Não tem filhos
		*raiz = NULL;
	else if ((*raiz)->esq == NULL) // Não tem filho a esquerda
		*raiz = (*raiz)->dir;
	else if ((*raiz)->dir == NULL) // Não tem filho a direita
		*raiz = (*raiz)->esq;
	else{ // Tem ambos os filhos
		pos = maiorArvBin(&((*raiz)->esq));
		(*raiz)->info = pos->info;
	}
	free (pos);
}TNo * maiorArvBin(TNo **raiz){
	TNo * aux;
	aux = *raiz;
	if (aux->dir == NULL){
		*raiz = (*raiz)->esq;
		return (aux);
	}
	else
		return maiorArvBin(&((*raiz)->dir));
}void enqueueArvBin (QueueArvBin *q, TNo *n){
	NoQueueArvBin *aux;
	aux = (NoQueueArvBin*)malloc(sizeof(NoQueueArvBin));
	aux->info = n;
	if (isEmptyArvBin(*q) == TRUE){
		(*q)->inicio = aux;
		(*q)->fim = aux;
	}
	else{
		(*q)->fim->prox = aux;
		(*q)->fim = aux;
	}
}

TNo * dequeueArvBin (QueueArvBin *q){
	NoQueueArvBin *aux;
	TNo* s;
	aux = (*q)->inicio;
	(*q)->inicio = (*q)->inicio->prox;
	if ((*q)->inicio == NULL)
		(*q)->fim = NULL;
	s = aux->info;
	free(aux);
	return s;
}

TNo* headArvBin (QueueArvBin q){
	return q->inicio->info;
}

int isEmptyArvBin (QueueArvBin q){
	if (q->inicio == NULL)
		return TRUE;
	else
		return FALSE;
}

int isFullArvBin (QueueArvBin q){
	return FALSE;
}

void initializeArvBin (QueueArvBin *q){	QueueArvBin aux;
	aux = (DescritorArvBin*)malloc(sizeof(DescritorArvBin));
	aux->inicio = NULL;
	aux->fim = NULL;
	*q = aux;}void exibir_por_nivel(TNo * raiz){
	QueueArvBin fila;
	TNo * aux;
	if (raiz != NULL)
	{
		initializeArvBin(&fila);
		enqueueArvBin (&fila,raiz);
		while (isEmptyArvBin(fila) == FALSE)
		{
			aux = dequeueArvBin(&fila);
			if (aux->esq != NULL)
				enqueueArvBin(&fila,aux->esq);
			if (aux->dir != NULL)
				enqueueArvBin(&fila,aux->dir);
			printf("%c \n", aux->info);
		}
	}
}
void exibir_pre_ordemArvBin (TNo * raiz){
	if (raiz != NULL)
	{
		printf("%c \n", raiz->info);
		exibir_pre_ordemArvBin(raiz->esq);
		exibir_pre_ordemArvBin(raiz->dir);
	}
}

void exibir_pos_ordemArvBin (TNo * raiz){
	if (raiz != NULL)
	{
		exibir_pos_ordemArvBin(raiz->esq);
		exibir_pos_ordemArvBin(raiz->dir);
		printf("%c \n", raiz->info);
	}
}

void exibir_em_ordemArvBin (TNo * raiz)
{
	if (raiz != NULL)
	{
		exibir_em_ordemArvBin(raiz->esq);
		printf("%c \n", raiz->info);
		exibir_em_ordemArvBin(raiz->dir);
	}
}

int mainArvBin(){
	TNo *arvbin = NULL, *retorno= NULL;
	char op, elemento;
	int op1;

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
			inserirArvBin(&arvbin, elemento);
			printf("Para para a insercao pressione space ");
			op1 = getchar();
			fflush(stdin);
		}while(op1 != ' ');
		break;
	case '2': 
		printf("Informe o elemento que deseja remover: ");
		elemento = getchar();
		fflush(stdin);
		removerArvBin(&arvbin, elemento);
		break;
	case '3':
		printf("Qual elemento deseja buscar: ");
		elemento = getchar();
		fflush(stdin);
		retorno = consultarArvBin(arvbin, elemento);
		if(retorno != NULL)
			printf("Valor nao consta na arvore!\n");
		else
			printf("Valor encontrado!\n");
	case '4':
		exibir_por_nivel(arvbin);
		break;
	case '5':
		exibir_pre_ordemArvBin(arvbin);
		break;
	case '6':
		exibir_pos_ordemArvBin(arvbin);
		break;
	case '7':
		exibir_em_ordemArvBin(arvbin);
		break;
	default: printf("Opcao invalida!");
		break;
	}
}