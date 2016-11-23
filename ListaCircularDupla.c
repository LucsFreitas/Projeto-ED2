#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Types.h"
#include "ListaCircularDupla.h"

int mainCDE(){
	TLDEC * a = NULL;
	TLDEC *result;
	char op, valor[100];
	printf("Se quiser parar Digite um valor negativo \n");
	do{
		printf("\t\tLista Circular Duplamente Encadeada\n\n");
		printf("1 - Inserir valor\n2 - Listar todos\n3 - Remover valor\n4 - Limpar Turma\n");
		printf("5 - Sair\n");
		printf("\nInforme a opcao desejada: ");
		op = getchar(); fflush(stdin);
		switch (op){
		case'1':
			printf("Informe o valor:\n");
			gets(valor); fflush(stdin);
			preencherTLDEC(&a, valor);
			break;
		case '2':
			exibirTLDEC(a);
			break;
		case'3':
			printf("Informe o valor:\n");
			gets(valor); fflush(stdin);
			removerNoTLDEC(&a, valor);
			break;
		case '4':
			limparNOTLDEC(&a);
			break;
		case '5':
			printf("Programa encerrado!\n");
			break;
		default: printf("Opcao invalida\n");
		}
	} while (op != '5');
	return 0;
}

void preencherTLDEC(TLDEC **lista, char n[]){
	TLDEC *fim, *novo;
	novo = (TLDEC *)malloc(sizeof(TLDEC));
	strcpy(novo->n, n);
	if (*lista == NULL){
		novo->prox = novo;
		novo->ant = novo;
		*lista = novo;
	}
	else{
		fim = *lista;
		while (fim->prox != *lista)
			fim = fim->prox;
		novo->prox = *lista;
		novo->ant = fim;
		fim->prox = novo;
		(*lista)->ant = novo;
	}
}

void criarNOTLDEC(TLDEC **novo, char n[]){
	TLDEC *aux;
	aux = (TLDEC*)malloc(sizeof(TLDEC));
	strcpy(aux->n, n);
	*novo = aux;
}

void exibirTLDEC(TLDEC * lista){
	TLDEC *aux = lista;
	do{
		printf("|%s|", aux->n);
		aux = aux->prox;
	} while (aux != lista);
}

void removerNoTLDEC(TLDEC**lista, char n[]){
	TLDEC *aux, *aux2, *aux3, *fim;
	if (*lista == NULL)
		printf("Lista vazia\n");
	else{
		aux = *lista;
		fim = (*lista)->ant;
		if (strcmp((*lista)->n, n) == 0){ //se encontrar no 1 
			*lista = (*lista)->prox;
			(*lista)->ant = fim;
			fim->prox = *lista;
			free(aux);
			printf("Remocao realizada!\n");
		}
		else{
			aux = aux->prox;
			while (aux != *lista){
				if (strcmp(aux->n,n) == 0){
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