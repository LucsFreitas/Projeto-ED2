#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Types.h"
#include "ListaDupla.h"

int mainLDE(){
	TLDE * lista = NULL;
	char descricao[100], op;
	do{
		printf("\t\tLista Duplamente Encadeada\n\n");
 		printf("1 - Inserir Elemento\n2 - Remover elemento\n3 - Exibir lista\n");
		printf("4 - Sair\n");
		op = getchar(); fflush(stdin);
		switch (op){
		case '1':
			inserirElementoLDE(&lista);
			break;
		case '2':
			printf("Informe o elemento: \n");
			gets(descricao); fflush(stdin);
			removerElementoLDE(&lista, descricao);
			break;
		case '3':
			exibir_tudoLDE(lista);
			break;
		case '4':
			limpar_listaLDE(&lista);
			break;
		default: printf("Opcao invalida.\n");
			break;
		}
	} while (op != '4');
	return 0;
}

void inserirElementoLDE(TLDE **lista){
	char descricao[100];
	TLDE *aux, *novo;

	printf("Informe o elemento: ");
	gets(descricao); fflush(stdin);

	if (*lista == NULL){
		criar_novoLDE(&novo, descricao);
		novo->ant = NULL;
		novo->prox = NULL;
		*lista = novo;
		printf("Insercao efetuada com sucesso!\n");
	}
	else{
		aux = *lista;
		while (aux != NULL){ //igual
			if (strcmp(aux->descricao, descricao) == 0){
				printf("Insercao cancelada. Descricao repetida!\n");
				return;
			}
			aux = aux->prox;
		}
		criar_novoLDE(&novo, descricao);
		aux = *lista;
		if (strcmp(novo->descricao, (*lista)->descricao) < 0){ //inicio
			novo->prox = *lista;
			novo->prox->ant = novo;
			novo->ant = NULL;
			*lista = novo;
			printf("Insercao efetuada com sucesso!\n");
		}
		else{
			while (aux != NULL){ //meio
				if (strcmp(novo->descricao, (*lista)->descricao) > 0){
					novo->ant = aux;
					novo->prox = aux->prox;
					if (novo->prox != NULL)
						novo->prox->ant = novo;
					aux->prox = novo;
					printf("Insercao efetuada com sucesso!\n");
					return;
				}
				if (aux->prox != NULL)
					aux = aux->prox;
				else
					break;
			}
			aux->prox = novo;
			novo->ant = aux;
			novo->prox = NULL;
			printf("Insercao efetuada com sucesso!\n");
		}
	}
}

void removerElementoLDE(TLDE **lista, char descricao[]){
	TLDE *aux, *aux2, *aux3;
	if (*lista == NULL)
		printf("Lista vazia\n");
	else{
		aux = *lista;
		if (strcmp((*lista)->descricao, descricao) == 0){ //se encontrar no 1 
			*lista = (*lista)->prox;
			free(aux);
			printf("Remocao realizada!\n");
		}
		else{
			while (aux != NULL){
				if (strcmp(aux->descricao, descricao) == 0){
					aux2 = aux->ant;
					aux3 = aux;
					aux2->prox = aux->prox;
					if (aux->prox != NULL){
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
}

void exibir_tudoLDE(TLDE *lista){
	if (lista == NULL)
		printf("Lista Vazia!\n");
	else{
		while (lista != NULL){
			printf("|%s|",lista->descricao);
			lista = lista->prox;
			if (lista != NULL)
				printf("%c%c",205, 205);
		}
	}
}

void limpar_listaLDE(TLDE **lista){
	TLDE *aux;
	while (*lista != NULL){
		aux = (*lista)->prox;
		free(*lista);
		*lista = aux;
	}
	printf("Lista limpa com sucesso!\n");
}

void criar_novoLDE(TLDE **no, char descricao[]){
	TLDE *aux;

	aux = (TLDE *)malloc(sizeof(TLDE));
	strcpy(aux->descricao, descricao);
	*no = aux;
}