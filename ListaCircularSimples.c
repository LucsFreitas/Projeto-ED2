#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Types.h"
#include "ListaCircularSimples.h"

int mainCSE(){
	TLSEC *a = NULL;
	char op, t, n[50];
	do{
		printf("\t\tLista Circular Simplesmente Encadeada\n\n");
		printf("1 - Inserir valor\n2 - Listar todos\n3 - Remover valor\n");
		printf("4 - Limpar Lista\n5 - Sair\n");
		printf("\nInforme a opcao desejada: ");
		op = getchar(); fflush(stdin);
		switch (op){
		case'1':
				cadastrarCLSE(&a);
			break;
		case '2':
				listarCLSE(a);
			break;
		case'3':
				printf("Informe o valor:\n");
				gets(n); fflush(stdin);
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
	printf("Informe o valor:\n");
	gets(aux->nome); fflush(stdin);
	*novo = aux;
}

void cadastrarCLSE(TLSEC ** lista){
	TLSEC *aux, *novo;
	aux = *lista;
	criarNOCLSE(&novo);
	if (*lista == NULL){
		novo->prox = novo;
		*lista = novo;
	}
	else{
		while (aux->prox != *lista)
			aux = aux->prox;
		aux->prox = novo;
		novo->prox = *lista;
	}
}

void listarCLSE(TLSEC * lista){
	TLSEC *aux;
	aux = lista;
	if (aux == NULL)
		printf("Lista Vazia!\n");
	else{
		do{
			printf("|%s|", aux->nome);
			aux = aux->prox;
		} while (aux != lista);
	}
}

TLSEC * consultarCLSE(TLSEC * lista, char nome[]){
	TLSEC * aux = lista;
	do{
		if (strcmp(aux->nome, nome) == 0)
			return aux;
		else
			aux = aux->prox;
	} while (aux != lista);
	return NULL;
}

void removerCLSE(TLSEC **lista, char nome[]){
	TLSEC *result, *aux = *lista;
	if (*lista == NULL)
		printf("Lista Vazia\n");
	else if ((*lista)->prox == *lista){
		if (strcmp((*lista)->nome, nome) == 0){
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
			printf("Nome nao encontrado\n");
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