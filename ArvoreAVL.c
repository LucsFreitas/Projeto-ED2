#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Types.h"
#include "Comum.h"
#include "ArvoreAVL.h"


Tavl * criarNoAVL (int elem) {
	Tavl * raiz;
	raiz = (Tavl *) malloc (sizeof(Tavl));
	raiz->info = elem;
	raiz->esq = NULL;
	raiz->dir = NULL;
	raiz->fatbal = 0;
	return raiz;
}

void rotacaoEsqAVL (Tavl *raiz_original, Tavl **a, int *status) {
	Tavl *b, *c;
	b = (*a)->esq;
	if (b->fatbal == -1) { // rotação simples
		ajustarAlturaAVL(raiz_original);
		exibirAVL(raiz_original, 3);
		(*a)->esq = b->dir;
		b->dir = *a;
		(*a)->fatbal = 0;
		*a = b;
	}
	else { // rotação dupla
		ajustarAlturaAVL(raiz_original);
		exibirAVL(raiz_original, 4);
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

void rotacaoDirAVL (Tavl *raiz_original, Tavl **a,int *status) {
	Tavl * b, * c;
	b = (*a)->dir;
	if (b->fatbal == 1) { // rotação simples
		ajustarAlturaAVL(raiz_original);
		exibirAVL(raiz_original, 1);
		(*a)->dir = b->esq;
		b->esq = *a;
		(*a)->fatbal = 0;
		*a = b;
	}
	else { // rotação dupla
		ajustarAlturaAVL(raiz_original);
		exibirAVL(raiz_original, 2);
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

void inserirAVL (Tavl *raiz_original, Tavl **raiz, int elem, int *status) {
	if (*raiz == NULL) {
		*raiz = criarNoAVL(elem);
		*status = 1;
	}
	else if (elem == (*raiz)->info) {
		printf ("Elemento ja consta na arvore. \n");
		return;
	}
	else if(elem < (*raiz)->info){
		inserirAVL(raiz_original, &((*raiz)->esq),elem,status);
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
				rotacaoEsqAVL(raiz_original, &(*raiz),status); 
				break;
		}
	}
	else {
		inserirAVL(raiz_original, &((*raiz)->dir),elem,status);
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
				rotacaoDirAVL(raiz_original, &(*raiz),status); 
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

void balancearemOrdemAVL (Tavl *raiz_original, Tavl **raiz){
	int status = 1;
	if (*raiz != NULL)
	{
		balancearemOrdemAVL(raiz_original, &(*raiz)->esq);
		switch ((*raiz)->fatbal) {
		case 1 : 
			(*raiz)->fatbal = 0; 
			rotacaoDirAVL(raiz_original, &(*raiz),&status);
			break;
		case 0 : 
			(*raiz)->fatbal = -1; 
			break;
		case -1 : 
			rotacaoEsqAVL(raiz_original, &(*raiz),&status); 
			break;
		}
		balancearemOrdemAVL(raiz_original, &(*raiz)->dir);
	}
}

void balancearAVL(Tavl *raiz_original, Tavl **raiz){
	int reto;
	int *status = 0;
	reto = ajustarAlturaAVL(*raiz);
	balancearemOrdemAVL(raiz_original, *(&raiz));
}

void removerAVL(Tavl *raiz_original, Tavl **raiz, int elem){
	if (*raiz == NULL)
		printf("Elemento nao encontrado!\n");
	else if (elem == (*raiz)->info){
		removerNoAVL(&(*raiz));
		printf("\tElemento removido com sucesso!\n");
	}
	else{
		if (elem < (*raiz)->info)
			removerAVL(raiz_original, &((*raiz)->esq),elem);
		else
			removerAVL(raiz_original, &((*raiz)->dir),elem);
	}
	balancearAVL(raiz_original, &(*raiz));
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

	system("cls");
	printf("\tExibicao por Nivel\n\n");
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
			printf("%d \n", aux->info);
		}
	}
	else{
		printf("\tArvore vazia!\n\n");
	}
	
	printf("Pressione << ENTER >> para continuar...");
	while (getch() != 13);
}

void exibir_pre_ordemAVL (Tavl * raiz){
	if (raiz != NULL)
	{
		printf("%d \n", raiz->info);
		exibir_pre_ordemAVL(raiz->esq);
		exibir_pre_ordemAVL(raiz->dir);
	}
}

void exibir_pos_ordemAVL (Tavl * raiz){
	if (raiz != NULL)
	{
		exibir_pos_ordemAVL(raiz->esq);
		exibir_pos_ordemAVL(raiz->dir);
		printf("%d \n", raiz->info);
	}
}

void exibir_em_ordemAVL (Tavl * raiz)
{
	if (raiz != NULL)
	{
		exibir_em_ordemAVL(raiz->esq);
		printf("%d \n", raiz->info);
		exibir_em_ordemAVL(raiz->dir);
	}
}

void initializeAVL (QueueAVL *q){
	QueueAVL aux;
	aux = (DescritorArvAVL*)malloc(sizeof(DescritorArvAVL));
	aux->inicio = NULL;
	aux->fim = NULL;
	*q = aux;
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
	(*q)->fim->prox = NULL;
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

int isFullAVL (QueueAVL q){
	return FALSE;
}

Tavl * consultarAVL(Tavl *raiz, int elem){
	if (raiz == NULL)
		return NULL;
	else if (elem == raiz->info)
		return raiz;
	else if (elem < raiz->info)
		return consultarAVL(raiz->esq,elem);
	else return consultarAVL(raiz->dir,elem);
}

void exibirAVL(Tavl * raiz, int flag){
	QueueAVL fila;
	Tavl * aux;
	int cont = 0, temp, i;
	int coluna = 34, linha = 3, cont_val = 0;

	system("cls");
	printf("\t\t\t\tArvore AVL\n");
	if (raiz != NULL)
	{
		printf("\t  Aqui sao mostrados apenas os 4 primeiros niveis da arvore");
		initializeAVL(&fila);
		enqueueAVL (&fila,raiz);
		cont++;
		while (isEmptyAVL(fila) == FALSE) {
			temp = cont;
			for (i = 0; i < temp; i++){
				ajustar_gotoxy(linha, coluna, cont_val);
				aux = dequeueAVL(&fila);
				cont--;

				if (aux != NULL){
					if (aux->info >= 0 && aux->info < 10)
						printf("0");
					printf("%d", aux->info);
					printf("(%d)", aux->fatbal);
					enqueueAVL(&fila,aux->esq); cont++;
					enqueueAVL(&fila,aux->dir); cont++;
				}
				else{
					enqueueAVL(&fila, NULL); cont++;
					enqueueAVL(&fila, NULL); cont++;
				}

				cont_val++;
			}
			linha = linha + 2;
			cont_val = 0;
			if (linha == 11)
				break;
		}		
	}
	printf("\n\n\n");
	if (flag == 1)
		printf("\t\tNecessario rotacao simples a esquerda\n");
	else if (flag == 2)
		printf("\t\tNecessario rotacao dupla a esquerda\n");
	else if (flag == 3)
		printf("\t\tNecessario rotacao simples a direita\n");
	else if (flag == 4)
		printf("\t\tNecessario rotacao dupla a esquerda\n");

	printf("\t\tPressione << ENTER >> para continuar...");
	while(getch() != 13);
	system ("cls");
}

int mainArvAVL(){
	Tavl *arvAVL = NULL, *retorno= NULL;
	char op;
	int elemento;
	int op1, status = 0;

	do{
		system("cls");
		printf("\t\tArvore AVL\n\n");
		printf("1 - Inserir\n2 - Remover\n3 - Consultar\n4 - Exibir Por Nivel\n5 - Exibir Pre Ordem\n");
		printf("6 - Exibir Pos Ordem\n7 - Exibir Em Ordem\n8 - Exibir Arvore\n9 - Voltar ao Menu Principal\n");
		printf("\nInforme a opcao desejada: ");
		op = getchar();
		fflush(stdin);
		printf("\n");

		switch (op){
		case '1': 					
			do{
				system("cls");
				printf("\t\t\tInsercao AVL\n");
				printf("\nOs valores devem ser >= 0 e <= 99 (ou seja, ter 2 digitos)");
				printf("\nPara cancelar a insercao, insira << -1 >>\n");
				printf("\nInforme o elemento a ser inserido: ");
				scanf("%d", &elemento);
				fflush(stdin);
				if (elemento != -1) {
					if (elemento < 0 || elemento > 99)
						printf("Valor invalido! O numero deve estar entre 0 e 99\n");
					else{
						inserirAVL(arvAVL, &arvAVL, elemento, &status);
						exibirAVL(arvAVL, 0);
					}
				}
			}while(elemento != -1);
			break;

		case '2': 
			printf("Informe o elemento que deseja remover: ");
			scanf("%d", &elemento);
			fflush(stdin);
			removerAVL(arvAVL, &arvAVL, elemento);
			pause(1.5);
			break;
		case '3':

			printf("Qual elemento deseja buscar: ");
			scanf("%d", &elemento);
			fflush(stdin);
			retorno = consultarAVL(arvAVL, elemento);
			if(retorno != NULL)
				printf("\tValor nao encontrado!\n");
			else
				printf("\tValor encontrado!\n");
			pause(1.5);
			break;

		case '4':
			if (arvAVL == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else
				exibir_por_nivelAVL (arvAVL);
			break;

		case '5':
			if (arvAVL == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else
				exibir_pre_ordemAVL (arvAVL);
			break;

		case '6':
			if (arvAVL == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else
				exibir_pos_ordemAVL (arvAVL);
			break;

		case '7':
			if (arvAVL == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else
				exibir_em_ordemAVL (arvAVL);
			break;

		case '8':
			if (arvAVL == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else
				exibirAVL(arvAVL, 0);
			break;

		case '9':
			break;

		default:
			printf("\tOpcao invalida!");
			pause(1.5);
			break;
		}
	} while (op != '9');
}