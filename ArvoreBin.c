#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Comum.h"
#include "Types.h"
#include "ArvoreBin.h"

TNo * consultarArvBin(TNo *raiz, int elem){
	if (raiz == NULL)
		return NULL;
	else if (elem == raiz->info)
		return raiz;
	else if (elem < raiz->info)
		return consultarArvBin(raiz->esq,elem);
	else return consultarArvBin(raiz->dir,elem);
}

void inserirArvBin(TNo **raiz, int elem){
	if (*raiz == NULL){
		*raiz = (TNo *) malloc (sizeof(TNo));
		(*raiz)->info = elem;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
	}else if (elem < (*raiz)->info)
		inserirArvBin(&((*raiz)->esq),elem);
	else inserirArvBin(&((*raiz)->dir),elem);
}

void removerArvBin(TNo **raiz, int elem){
	if (*raiz == NULL)
		printf("\n\tElemento nao encontrado!\n");
	else if (elem == (*raiz)->info){
		remover_noArvBin(&(*raiz));
		printf("\n\tRemocao efetuada com sucesso!");
	}
	else{
		if (elem < (*raiz)->info)
			removerArvBin(&((*raiz)->esq),elem);
		else
			removerArvBin(&((*raiz)->dir),elem);
	}
}

void remover_noArvBin(TNo **raiz){
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
}

TNo * maiorArvBin(TNo **raiz){
	TNo * aux;
	aux = *raiz;
	if (aux->dir == NULL){
		*raiz = (*raiz)->esq;
		return (aux);
	}
	else
		return maiorArvBin(&((*raiz)->dir));
}

void enqueueArvBin (QueueArvBin *q, TNo *n){
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
	(*q)->fim->prox = NULL;
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

void initializeArvBin (QueueArvBin *q){
	QueueArvBin aux;
	aux = (DescritorArvBin*)malloc(sizeof(DescritorArvBin));
	aux->inicio = NULL;
	aux->fim = NULL;
	*q = aux;
}

void exibir_por_nivel(TNo * raiz){
	QueueArvBin fila;
	TNo * aux;

	initializeArvBin(&fila);
	enqueueArvBin (&fila,raiz);
	while (isEmptyArvBin(fila) == FALSE)
	{
		aux = dequeueArvBin(&fila);
		if (aux->esq != NULL)
			enqueueArvBin(&fila,aux->esq);
		if (aux->dir != NULL)
			enqueueArvBin(&fila,aux->dir);
		printf("%d  ", aux->info);
	}
}

void exibir_pre_ordemArvBin (TNo * raiz){
	if (raiz != NULL)
	{		
		printf("%d  ", raiz->info);
		exibir_pre_ordemArvBin(raiz->esq);
		exibir_pre_ordemArvBin(raiz->dir);
	}
}

void exibir_pos_ordemArvBin (TNo * raiz){
	if (raiz != NULL)
	{
		exibir_pos_ordemArvBin(raiz->esq);
		exibir_pos_ordemArvBin(raiz->dir);
		printf("%d  ", raiz->info);
	}
}

void exibir_em_ordemArvBin (TNo * raiz)
{
	if (raiz != NULL)
	{
		exibir_em_ordemArvBin(raiz->esq);
		printf("%d  ", raiz->info);
		exibir_em_ordemArvBin(raiz->dir);
	}
}

void ajustar_gotoxy_ArvBin(int linha, int coluna, int cont_val){
	if (linha == 5)
		coluna = 19 + cont_val * 32 + 1;
	else if (linha == 7)
		coluna = 11 + cont_val * 16 + 1;
	else if (linha == 9)
		coluna = 7 + cont_val * 8 + 1;
	else if (linha == 11)
		coluna = 5 + cont_val * 4 + 1;

	gotoxy(coluna, linha);
}

void exibirArvBin(TNo * raiz){
	QueueArvBin fila;
	TNo * aux;
	int cont = 0, temp, i;
	int coluna = 35, linha = 3, cont_val = 0;

	system("cls");
	printf("\t\t\t\tArvore Binaria\n");
	if (raiz != NULL)
	{
		printf("\t   Aqui sao mostrados apenas os 5 primeiros niveis da arvore");
		initializeArvBin(&fila);
		enqueueArvBin (&fila,raiz);
		cont++;
		while (isEmptyArvBin(fila) == FALSE) {
			temp = cont;
			for (i = 0; i < temp; i++){
				ajustar_gotoxy_simples(linha, coluna, cont_val);
				aux = dequeueArvBin(&fila);
				cont--;

				if (aux != NULL){
					if (aux->info >= 0 && aux->info < 10)
						printf("0");
					printf("%d", aux->info);
					enqueueArvBin(&fila,aux->esq); cont++;
					enqueueArvBin(&fila,aux->dir); cont++;
				}
				else{
					enqueueArvBin(&fila, NULL); cont++;
					enqueueArvBin(&fila, NULL); cont++;
				}

				cont_val++;
			}
			linha = linha + 2;
			cont_val = 0;
			if (linha == 13)
				break;
		}		
	}
	free(fila);
	printf("\n\n\t\t\tPressione << ENTER >> para continuar...");
	while(getch() != 13);
	system ("cls");
}

int mainArvBin(){
	TNo *arvbin = NULL, *retorno= NULL;
	char op;
	int elemento;

	do{
		system("cls");
		printf("\t\tArvore Binaria\n\n");
		printf("1 - Inserir\n2 - Remover\n3 - Consultar\n4 - Exibir Por Nivel\n");
		printf("5 - Exibir Pre Ordem\n6 - Exibir Pos Ordem\n7 - Exibir Em Ordem\n");
		printf("8 - Exibir Arvore\n9 - Voltar ao Menu Principal\n");
		printf("\nDigite a opcao que deseja: ");
		op = getchar();
		fflush(stdin);
		printf("\n");
		switch (op){
		case '1':
			system("cls");
			printf("\t\tInserir - Arvore Binaria\n\n");
			printf("Os valores devem ser >= 0 e <= 99 (ou seja, ter 2 digitos)\n");
			printf("Para cancelar a insercao, insira << -1 >>\n\n");

			do{
				printf("Informe o elemento a ser inserido: ");
				scanf("%d", &elemento);
				fflush(stdin);
				if (elemento != -1){
					if (elemento < 0 || elemento > 99)
						printf("\t\tValor invalido! O numero deve estar entre 0 e 99\n");
					else
						inserirArvBin(&arvbin, elemento);
				}
			} while (elemento != -1);
			break;
		case '2': 
			printf("Informe o elemento que deseja remover: ");
			scanf("%d", &elemento);
			fflush(stdin);
			removerArvBin(&arvbin, elemento);
			pause(1.5);
			break;
		case '3':
			printf("Qual elemento deseja buscar: ");
			scanf("%d", &elemento);
			fflush(stdin);
			retorno = consultarArvBin(arvbin, elemento);
			if(retorno == NULL)
				printf("\n\tElemento nao encontrado!\n");
			else
				printf("\n\tValor encontrado!\n");
			pause (1.5);
			break;
		case '4':
			if (arvbin == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else{
				system("cls");
				printf("\tExibicao por Nivel\n\n");
				exibir_por_nivel(arvbin);
				printf("\n\nPressione << ENTER >> para continuar...");
				while (getch() != 13);
			}
			break;
		case '5':
			if (arvbin == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else{
				system("cls");
				printf("\tExibicao Pre Ordem\n\n");
				exibir_pre_ordemArvBin(arvbin);
				printf("\n\nPressione << ENTER >> para continuar...");
				while (getch() != 13);
			}
			break;
		case '6':
			if (arvbin == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else{
				system("cls");
				printf("\tExibicao Pos Ordem\n\n");
				exibir_pos_ordemArvBin(arvbin);
				printf("\n\nPressione << ENTER >> para continuar...");
				while (getch() != 13);
			}
			break;
		case '7':
			if (arvbin == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else{
				system("cls");
				printf("\tExibicao em Ordem\n\n");
				exibir_em_ordemArvBin(arvbin);
				printf("\n\nPressione << ENTER >> para continuar...");
				while (getch() != 13);
			}
			break;
		case '8':
			if (arvbin == NULL){
				printf("\tArvore Vazia!");
				pause(1.5);
			}
			else
				exibirArvBin(arvbin);
			break;
		case '9':
			break;
		default:
			printf("\tOpcao invalida!");
			pause (1.5);
			break;
		}
	} while (op != '9');
}