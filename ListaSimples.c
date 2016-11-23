#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Types.h"
#include "ListaSimples.h"

int mainLSE(){

	TLSE * ptr = NULL;
	char n[100];
	char op;
	do{
		system("cls");
		printf("\tLista Simplesmente Encadeada\n\n");
		printf("1 - Adicionar elemento\n");
		printf("2 - Remover elemento\n");
		printf("3 - Exibir lista\n");
		printf("4 - Alterar elemento\n");
		printf("5 - Limpar agenda\n");
		printf("6 - Voltar ao Menu de Listas\n\n");
		printf("Escolha uma opcao: ");
		op = getchar(); fflush(stdin);
		switch (op){
		case'1':
			printf("Informe o elemento:\n");
			gets(n); fflush(stdin);
			adicionarNovoLSE(&ptr, n);
			break;
		case'2':
			printf("Informe o elemento:\n");
			gets(n); fflush(stdin);
			removerElementoLSE(&ptr, n);
			break;
		case '3':
			exibirListaLSE(ptr);
			break;
		case '4':
			printf("Informe o elemento:\n");
			gets(n); fflush(stdin);
			alterarLSE(&ptr, n);
			break;
		case '5':
			limparLSE(&ptr);
			break;
		case '6':
			break;
		default: printf("Opcao Invalida!\n");
			break;
		}
	} while (op != '6');
	return 0;
}

void criarNovo(TLSE **lista, char n[]){
	TLSE *aux;
	aux = (TLSE*)malloc(sizeof(TLSE));
	strcpy(aux->info, n);
	aux->prox = NULL;
	*lista = aux;
}

void adicionarNovoLSE(TLSE **lista, char n[]){
	TLSE *novo, *aux1, *aux2;
	int flag = 0;
	if (*lista == NULL){ //Caso 1: Lista Vazia
		criarNovo(&novo, n);
		novo->prox = NULL;
		*lista = novo;
	}
	else if (strcmp((*lista)->info, n)==0) //Nome repetido no 1º
		printf("Elemento repetido, insercao nao realizada!\n");
	else if (strcmp((*lista)->info, n) > 0) { //Caso 2: Inserir no INICIO
		criarNovo(&novo, n);
		novo->prox = *lista;
		*lista = novo;
	}
	else { //Caso 3: Inserir no MEIO
		aux1 = *lista;
		aux2 = (*lista)->prox;
		while (aux2 != NULL){
			if (strcmp(aux2->info, n) == 0){ //Nome repetido a partir do 2º
				flag = 1;
				break;
			}
			else if (strcmp(aux2->info, n) > 0){
				criarNovo(&novo, n);
				aux1->prox = novo;
				novo->prox = aux2;
				flag = 2;
				break;
			}
			else{
				aux1 = aux2;
				aux2 = aux2->prox;
			}
		}
		if (flag == 0){ //Caso 4: Inserir no FINAL
			criarNovo(&novo, n);
			aux1->prox = novo;
			novo->prox = NULL;
		}
		else if (flag == 1)
			printf("Elemento repetido, insercao nao realizada!\n");
		else
			printf("Elemento inserido com sucesso!\n");
	}
}

void removerElementoLSE(TLSE**lista, char n[]){
	TLSE *aux, *aux2;
	if (*lista == NULL)
		printf("Lista vazia!\n");
	else{
		if (strcmp((*lista)->info, n) == 0){
			aux = *lista;
			*lista = (*lista)->prox;
			free(aux);
			printf("Remocao Efetuada!\n");
		}
		else{
			aux = *lista;
			while (aux != NULL && (strcmp(aux->info, n) != 0)){
				aux2 = aux;
				aux = aux->prox;
			}
			if (aux == NULL)
				printf("Elemento nao encontrado!\n");
			else{
				aux2->prox = aux->prox;
				free(aux);
				printf("Remocao Efetuada\n");
			}
		}
	}
}

void exibirListaLSE(TLSE *lista){
	if (lista == NULL)
		printf("Lista Vazia\n");
	else if (lista != NULL){
		while (lista != NULL){
			printf("|%s|", lista->info);
			lista = lista->prox;
			if (lista != NULL)
				printf("%c", 196);
		}
	}
	printf("\n");
}

TLSE *procurarLSE(TLSE *lista, char n[]){
	TLSE *aux = lista;
	while (aux != NULL){
		if (strcmp(aux->info, n) == 0)
			break;
		else
			aux = aux->prox;
	}
	return aux;
}

void alterarLSE(TLSE **lista, char n[]){
	TLSE *aux;
	char op;
	if (lista == NULL)
		printf("Lista Vazia!\n");
	else{
		aux = procurarLSE(*lista, n);
		if (aux == NULL)
			printf("Elemento nao consta na lista!\n");
		else{
				printf("Digite o novo elemento: \n");
				gets(aux->info); fflush(stdin);
		}
	}
}

void limparLSE(TLSE**lista){
	TLSE *aux = *lista;
	while (aux != NULL){
		aux = (*lista)->prox;
		free(*lista);
		*lista = aux;
		printf("Agenda limpa com sucesso!\n");
	}
}