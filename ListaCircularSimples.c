#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Types.h"
#include "Comum.h"
#include "ListaCircularSimples.h"

int mainCSE(){
	TLSEC *a = NULL;
	char op, t;
	int n;

	do{
		system("cls");
		printf("\t\tLista Circular Simplesmente Encadeada\n\n");
		printf("1 - Inserir valor\n2 - Listar todos\n3 - Remover valor\n");
		printf("4 - Limpar Lista\n5 - Sair\n");
		printf("\nInforme a opcao desejada: ");
		op = getchar(); fflush(stdin);
		switch (op){
		case'1':
			cadastrarCLSE(&a);
			printf("\nPressione < ENTER > para continuar...");
			while (getch() != 13);
			break;
		case '2':
			listarCLSE(a);
			printf("\nPressione < ENTER > para continuar...");
			while (getch() != 13);
			break;
		case'3':
			printf("Informe o valor: ");
			scanf("%d", &n); fflush(stdin);
			removerCLSE(&a, n);
			break;
		case '4':
			limparNOCLSE(&a);
			break;
		case '5':
			printf("Programa encerrado!\n");
			break;
		default: printf("Opcao invalida\n");
		}
	} while (op != '5');
	return 0;
}

void criarNOCLSE(TLSEC ** novo){
	TLSEC *aux;

	aux = (TLSEC*)malloc(sizeof(TLSEC));
	do{
		printf("Valor deve estar entre 0 e 99\n");
		printf("Informe o valor: ");
		scanf("%d", &(aux->nome)); fflush(stdin);
	} while (aux->nome < 0 || aux->nome > 99);

	*novo = aux;
}

void cadastrarCLSE(TLSEC ** lista){
	TLSEC *aux, *novo;
	int qtd = 0;

	aux = *lista;
	criarNOCLSE(&novo);
	if (*lista == NULL){
		novo->prox = novo;
		*lista = novo;
	}
	else{
		qtd++;
		while (aux->prox != *lista){
			aux = aux->prox;
			qtd++;
			if (qtd == 10){
				printf("\n\nValor maximo de insercoes atingido");
				free(novo);
				return;
			}
		}
		aux->prox = novo;
		novo->prox = *lista;
	}
}

void exibirVoltaS (int coluna, int qtd){
	int linha = 3;

	printf("%c", 196);
	
	coluna += 1 + qtd;

	printf("%c", 217);
	gotoxy(coluna, linha);
	printf("%c", 191);

	for (coluna = coluna - 1; coluna > 0; coluna--){
		gotoxy(coluna, linha);
		printf("%c", 196);
	}
	gotoxy(coluna, linha);
	printf("%c", 218);
	linha++;
	gotoxy(coluna, linha);
	printf("%c", 192);
	printf("%c", 196);
	printf(">");
}

void listarCLSE(TLSEC * lista){
	TLSEC *aux = lista;
	int qtd = 0;
	int coluna = 3;
	int flag = 0;

	system("cls");
	printf("\tExibicao Lista Circular Simplesmente Encadeada");

	if (lista == NULL)
		printf("\n\nLista Vazia");
	else{
		gotoxy(coluna, 4);
		do{
			qtd++;
			if (flag == 1){			
				if (aux->nome >= 0 && aux->nome < 10)
					printf(" %c |0%d|", 196, aux->nome);
				else
					printf(" %c |%d|", 196, aux->nome);
				coluna += 6;
			}
			else{
				if (aux->nome >= 0 && aux->nome < 10)
					printf("|0%d|", aux->nome);
				else
					printf("|%d|", aux->nome);
				coluna += 3;
			}

			flag = 1;
			aux = aux->prox;
		} while (aux != lista);
		exibirVoltaS(coluna, qtd);
	}
}

TLSEC * consultarCLSE(TLSEC * lista, int nome){
	TLSEC * aux = lista;
	do{
		if (aux->nome == nome)
			return aux;
		else
			aux = aux->prox;
	} while (aux != lista);
	return NULL;
}

void removerCLSE(TLSEC **lista, int nome){
	TLSEC *result, *aux = *lista;
	if (*lista == NULL)
		printf("Lista Vazia\n");
	else if ((*lista)->prox == *lista){
		if ((*lista)->nome == nome){
			free(*lista);
			*lista = NULL;
		}
	}
	else{
		result = consultarCLSE(*lista, nome);
		if (result != NULL){
			if (result == *lista)
				*lista = (*lista)->prox;
			while (aux->prox != result)
				aux = aux->prox;
			aux->prox = result->prox;
			free(result);
		}
		else
			printf("Valor nao encontrado\n");
	}
}

void limparNOCLSE(TLSEC **lista){
	TLSEC*aux = *lista;
	while (aux != *lista){
		aux = (*lista)->prox;
		free(*lista);
		*lista = aux;
	}
	free(aux);
	*lista = NULL;
	printf("limpa!\n");
}