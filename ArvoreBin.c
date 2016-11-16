#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Comum.h"
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
		(*q)->fim->prox = NULL;
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

void initializeStackArvBin (StackArvBin *s){
	*s = NULL;
}

int isEmptyStackArvBin(StackArvBin s){
	if (s == NULL)
		return TRUE;
	else
		return FALSE;
}

void pushStackArvBin(StackArvBin *s, TNo * no){
	StackArvBin aux;
	aux = (NoPilhaArvBin *) malloc (sizeof (NoPilhaArvBin));
	aux->info = no;
	aux->prox = *s;
	*s = aux;
}

TNo * popArvBin (StackArvBin *s){
	StackArvBin aux;
	TNo * r;

	aux = *s;
	*s = (*s)->prox;
	r = aux->info;
	free(aux);

	return r;
}

void ajustar_gotoxy(int linha, int coluna, int cont_val){
	if (linha == 5)
		coluna = 19 + cont_val * 32;
	else if (linha == 7)
		coluna = 11 + cont_val * 16;
	else if (linha == 9)
		coluna = 7 + cont_val * 8;
	else if (linha == 11)
		coluna = 5 + cont_val * 4;
	else if (linha == 13)
		coluna = 3 + cont_val * 2;

	gotoxy(coluna, linha);
}

void exibirArvBin(TNo * raiz){
	QueueArvBin fila;
	TNo * aux;
	int cont = 0, temp, i;
	int coluna = 35, linha = 3, cont_val = 0;

	system("cls");
	printf("\t\t\t\tArvore Binaria");
	if (raiz != NULL)
	{
		initializeArvBin(&fila);
		enqueueArvBin (&fila,raiz);
		cont++;
		while (isEmptyArvBin(fila) == FALSE) {
			temp = cont;
			for (i = 0; i < temp; i++){
				ajustar_gotoxy(linha, coluna, cont_val);
				aux = dequeueArvBin(&fila);
				cont--;

				if (aux != NULL){
					printf("%c ", aux->info);
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
			if (linha == 15)
				break;
		}
		printf("\n\nPressione << ENTER >> para continuar...");
		while(getch() != 13);
	}
}

/*
void exibirArvBin(TNo * raiz){
StackArvBin s;
TNo *aux = raiz;
int coluna = 35, linha = 3, cont = 0, aux_col = 0;
int flag_volta = 0;

initializeStackArvBin (&s);

system("cls");
printf("\t\t\tArvore Binaria");
do{
while (aux != NULL){
if (cont == 0){
if (flag_volta == 1){
aux_col = aux_col - 9;
gotoxy(coluna + aux_col, linha + 1);
}
if (flag_volta == 0){
gotoxy(coluna, linha);
aux_col = aux_col - 16;
}
}
else if (cont == 1){
if (flag_volta == 1){
aux_col = aux_col - 5;
gotoxy(coluna + aux_col, linha + 2);
}
if (flag_volta == 0){
gotoxy(coluna + aux_col, linha + 1);
aux_col = aux_col - 8;
}
}
else if (cont == 2){
if (flag_volta == 1){
aux_col = aux_col - 31;
gotoxy(coluna + aux_col, linha + 3);
}
if (flag_volta == 0){
gotoxy(coluna + aux_col, linha + 2);
aux_col = aux_col - 4;
}
}
else if (cont == 3){
gotoxy(coluna + aux_col, linha + 3);
aux_col = aux_col - 2;
}
else if (cont == 4)
gotoxy(coluna + aux_col, linha + 4);
printf("%c", aux->info);

pushStackArvBin(&s, aux);
aux = aux->esq;
cont++;
}
if (!isEmptyStackArvBin(s)){
aux = popArvBin(&s);
aux = aux->dir;

if (cont == 0){
if (flag_volta == 0){
aux_col = aux_col + 64;
flag_volta = 1;
}
else if (flag_volta == 1)
aux_col = aux_col + 48;
gotoxy(coluna, linha);
}
else if (cont == 1){
if (flag_volta == 0){
aux_col = aux_col + 32;
flag_volta = 1;
}
else if (flag_volta == 1)
aux_col = aux_col + 24;
gotoxy(coluna + aux_col, linha + 1);
}
else if (cont == 2){
if (flag_volta == 0){
aux_col = aux_col + 16;
flag_volta = 1;
}
else if (flag_volta == 1)
aux_col = aux_col + 12;
gotoxy(coluna + aux_col, linha + 2);
}
else if (cont == 3){
if (flag_volta == 0){
aux_col = aux_col + 8;
flag_volta = 1;
}
else if (flag_volta == 1)
aux_col = aux_col + 6;
gotoxy(coluna + aux_col, linha + 3);
}
else if (cont == 4){
aux_col + 4;
flag_volta = 1;
gotoxy(coluna + aux_col, linha + 4);
}
if (aux != NULL)
printf("%c", aux->info);
else
cont--;
}
} while (!isEmptyStackArvBin(s) || aux != NULL);
//printf("\n\nPressione << ENTER >> para continuar..."); 
while (getch() != 13);
}*/

int mainArvBin(){
	TNo *arvbin = NULL, *retorno= NULL;
	char op, elemento;

	do{
		printf("\t\tArvore Binaria\n\n");
		printf("1 - Inserir\n2 - Remover\n3 - Consultar\n4 - Exibir Por Nivel\n");
		printf("5 - Exibir Pre Ordem\n6 - Exibir Pos Ordem\n7 - Exibir Em Ordem\n");
		printf("8 - Exibir Arvore\n9 - Voltar ao Menu Principal\n");
		printf("\nDigite a opcao que deseja: ");
		op = getchar();
		fflush(stdin);
		switch (op){
		case '1':
			printf("\nPara cancelar a insercao, insira << SPACE >>\n");
			do{
				printf("Informe o elemento a ser inserido: ");
				elemento = getchar();
				fflush(stdin);
				if (elemento != ' ') 
					inserirArvBin(&arvbin, elemento);
			}while(elemento != ' ');
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
		case '8':
			exibirArvBin(arvbin);
			break;
		default:
			printf("Opcao invalida!");
			break;
		}
		printf("\n\n");
	} while (op != 8);
}

