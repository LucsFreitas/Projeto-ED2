#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "HashInt.h"
#include "Types.h"

void mainHashInt(){
	ThashInt* Hash[50];
	ThashInt *retorno;
	int j = 0, flag = 0, end;
	int dado, tam, i = 0;

	system("cls");
	printf("\tHashing por Divisao Inteira\n");
	printf("\nDefina o tamanho da tabela: ");
	scanf("%d", &tam);
	fflush(stdin);
	inicializaHashInt(Hash, tam);
	printf("\nInsercao dos valores (para parar, digite -99):\n\n");
	do {
		printf("Digite uma valor: ");
		scanf("%d", &dado);
		fflush(stdin);
		if (dado != -99){
			i++;
			retorno = buscarInt(Hash, dado, tam);
			if (retorno == NULL){
				preencherInt(Hash, tam, dado);
			}
		}
	} while (dado != -99);
	Hash[i] = '\0';

	system("cls");
	printf("\tHashing por Divisao Inteira\n\n");
	exibirTabelaInt(Hash, tam);

	printf("\n\nPressione < ENTER > para continuar..");
	while(getch() != 13);
}


void inicializaHashInt(ThashInt *tab[], int tam){
	int i;
	for (i = 0; i < tam; i++)
	{
		tab[i] = NULL;
	}
}

void exibirTabelaInt(ThashInt *tab[], int tam){
	int i;
	for (i = 0; i < tam; i++){
		printf("Endereco %d -> ", i);
		while (tab[i] != NULL){
			printf("| %d |", tab[i]->dados);
			tab[i] = tab[i]->prox;
		}
		printf("\n");
	}
}

int hashInt(int valor, int tamanhoTabela) {
	return valor % tamanhoTabela;
}

void preencherInt(ThashInt *tab[], int tam, int dado){
	ThashInt *novo, *aux, *aux1;
	int end = hashInt(dado, tam);

	if (tab[end] == NULL){
		novo = (ThashInt*)malloc(sizeof(ThashInt));
		novo->dados = dado;
		novo->prox = NULL;
		tab[end] = novo;
	}
	else{
		aux = tab[end];
		while (aux->prox != NULL){
			aux = aux->prox;
		}
		novo = (ThashInt*)malloc(sizeof(ThashInt));
		novo->dados = dado;
		novo->prox = NULL;
		aux->prox = novo;
	}
}

ThashInt* buscarInt(ThashInt *tab[], int dado, int tam){
	int i;
	ThashInt *aux;
	for (i = 0; i < tam; i++){
		aux = tab[i];
		while (aux != NULL){
			if (aux->dados == dado)
				return aux;
			else
				aux = aux->prox;

		}
	}
	return NULL;
}