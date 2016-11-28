#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Comum.h"
#include "Types.h"
#include "ListaCircularDupla.h"

int mainCDE(){
	TLDEC * a = NULL;
	TLDEC *result;
	char op;
	int valor;

	do{
		system("cls");
		printf("\t\tLista Circular Duplamente Encadeada\n\n");
		printf("1 - Inserir valor\n2 - Listar todos\n3 - Remover valor\n4 - Limpar Lista\n");
		printf("5 - Sair\n");
		printf("\nInforme a opcao desejada: ");
		op = getchar(); fflush(stdin);
		switch (op){
		case'1':

			do{
				printf("Valor deve ser entre 0 e 99\n");
				printf("Informe o valor: ");
				scanf("%d", &valor); fflush(stdin);
				if (valor < 0 || valor > 99)
					printf("\tValor invalido");
				else{
					preencherTLDEC(&a, valor);
					printf("\n\nValor Inserido com Sucesso!\n");
					printf("\nPressione < ENTER > para continuar...");
					while (getch() != 13);
				}
			} while (valor < 0 || valor > 99);
			break;
		case '2':
			exibirTLDEC(a);
			printf("\nPressione < ENTER > para continuar...");
			while (getch() != 13);
			break;
		case'3':
			printf("Informe o valor: ");
			scanf("%d", &valor); fflush(stdin);
			removerNoTLDEC(&a, valor);
			printf("\nPressione < ENTER > para continuar...");
			while (getch() != 13);
			break;
		case '4':
			limparNOTLDEC(&a);
			break;
		case '5':
			break;
		default: printf("Opcao invalida\n");
		}
	} while (op != '5');
	return 0;
}

void preencherTLDEC(TLDEC **lista, int n){
	TLDEC *fim, *novo;
	int qtd = 0;

	novo = (TLDEC *)malloc(sizeof(TLDEC));

	novo->n = n;
	if (*lista == NULL){
		novo->prox = novo;
		novo->ant = novo;
		*lista = novo;
	}
	else{
		qtd++;
		fim = *lista;
		while (fim->prox != *lista){
			fim = fim->prox;
			qtd++;
			if (qtd == 10){
				printf("\n\nValor maximo de insercoes atingido");
				free(novo);
				return;
			}
		}
		novo->prox = *lista;
		novo->ant = fim;
		fim->prox = novo;
		(*lista)->ant = novo;
	}
}

void criarNOTLDEC(TLDEC **novo, int n){
	TLDEC *aux;
	aux = (TLDEC*)malloc(sizeof(TLDEC));
	aux->n = n;
	*novo = aux;
}

void exibirVoltaD (int coluna, int qtd){
	int linha = 3;

	printf("%c", 205);
	
	coluna += 1 + qtd;

	printf("%c", 188);
	gotoxy(coluna, linha);
	printf("%c", 187);

	for (coluna = coluna - 1; coluna > 0; coluna--){
		gotoxy(coluna, linha);
		printf("%c", 205);
	}
	gotoxy(coluna, linha);
	printf("%c", 201);
	linha++;
	gotoxy(coluna, linha);
	printf("%c", 200);
	printf("%c", 205);
	printf("%c", 205);
}

void exibirTLDEC(TLDEC * lista){
	TLDEC *aux = lista;
	int qtd = 0;
	int coluna = 3;
	int flag = 0;

	system("cls");
	printf("\tExibicao Lista Circular Duplamente Encadeada");

	if (lista == NULL)
		printf("\n\nLista Vazia");
	else{
		gotoxy(coluna, 4);
		do{
			qtd++;
			if (flag == 1){			
				if (aux->n >= 0 && aux->n < 10)
					printf(" %c |0%d|", 205, aux->n);
				else
					printf(" %c |%d|", 205, aux->n);
				coluna += 6;
			}
			else{
				if (aux->n >= 0 && aux->n < 10)
					printf("|0%d|", aux->n);
				else
					printf("|%d|", aux->n);
				coluna += 3;
			}

			flag = 1;
			aux = aux->prox;
		} while (aux != lista);
		exibirVoltaD(coluna, qtd);
	}
}

void removerNoTLDEC(TLDEC**lista, int n){
	TLDEC *aux, *aux2, *aux3, *fim;
	if (*lista == NULL)
		printf("Lista vazia\n");
	else{
		aux = *lista;
		fim = (*lista)->ant;
		if ((*lista)->n == n){ //se encontrar no 1 
			*lista = (*lista)->prox;
			(*lista)->ant = fim;
			fim->prox = *lista;
			free(aux);
			printf("Remocao realizada!\n");
		}
		else{
			aux = aux->prox;
			while (aux != *lista){
				if (aux->n == n){
					aux2 = aux->ant;
					aux3 = aux;
					aux2->prox = aux->prox;
					if (aux->prox != NULL && aux->prox != *lista){
						aux = aux->prox;
						aux->ant = aux2;
					}
					free(aux3);
					printf("Remocao realizada!\n");
					return;
				}
				aux = aux->prox;
			}
			printf("Elemento nao encontrado!\n");
		}
	}

	return 0;
}

void limparNOTLDEC(TLDEC **lista){
	TLDEC *aux = *lista;
	while (aux != *lista){
		aux = (*lista)->prox;
		free(*lista);
		*lista = aux;
	}
	free(aux);
	*lista = NULL;
	printf("limpa!\n");
}