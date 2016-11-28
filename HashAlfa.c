#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "HashAlfa.h"
#include "Types.h"

void mainHashAlfa(){
	ThashAlfa* Hash[50], *Hash1[50];
	ThashAlfa *retorno, *aux;
	int j = 0, flag = 0, end, op;
	char dado[50];
	int tam, i;

	system("cls");
	printf("\tHashing por Divisao Inteira - Chaves AlfaNumericas\n");
	printf("\nDefina o tamanho da tabela: ");
	scanf("%d", &tam);
	fflush(stdin);
	inicializaHashAlfa(Hash, tam);
	printf("\nInsercao dos valores (para parar, digite '/'):\n\n");
	do{
		printf("Digite uma palavra: ");
		gets(dado);
		fflush(stdin);
		if (dado[0] != '/') {
			retorno = buscar(Hash, dado, tam);
			if (retorno == NULL){
				preencherAlfa(Hash, tam, dado, 0);
			}
		}
	} while (dado[0] != '/');

	system("cls");
	printf("\tHashing por Divisao Inteira - Chaves AlfaNumericas\n\n");
	exibirTabelaAlfa(Hash, tam);
	printf("\nDeseja realizar a permutacao nas chaves? (S = 1 / N = 0)  - ");
	scanf("%d", &op); 

	if (op == 1){
		system("cls");
		printf("\tHashing por Divisao Inteira - Chaves AlfaNumericas\n\n");
		printf("\nHashing Inicial:\n\n");
		exibirTabelaAlfa(Hash, tam);
		printf("\nHashing pos permutacao:\n\n");

		inicializaHashAlfa(Hash1, tam);
		for (i = 0; i < tam; i++){
			aux = Hash[i];
			while (aux != NULL){
				preencherAlfa(Hash1, tam, aux->dados, 1);
				aux = aux->prox;
			}
		}
		exibirTabelaAlfa(Hash1, tam);

		printf("\n\nPressione < ENTER > para continuar..");
		while(getch() != 13);
	}
}

int HDeslAlfa(char dado[], int tamanhoTabela){
	int i, soma = 0, tam = strlen(dado), aux;
	for (i = 0; i < tam; i++)
		soma = soma + dado[i] << (i % 8);
	aux = soma % tamanhoTabela;
	return (soma % tamanhoTabela);
}

void inicializaHashAlfa(ThashAlfa *tab[], int tam){
	int i;
	for (i = 0; i < tam; i++)
	{
		tab[i] = NULL;
	}
}

int hashAlfa(char dado[], int tamanhoTabela){
	int i, soma = 0, tam = strlen(dado);
	for (i = 0; i < tam; i++)
		soma = soma + dado[i];
	return (soma % tamanhoTabela);
}

void exibirTabelaAlfa(ThashAlfa *tab[], int tam){
	ThashAlfa *aux;
	int i;
	for (i = 0; i < tam; i++){
		printf("Endereco %d -> ", i);
		aux = tab[i];
		while (aux != NULL){
			printf("| %s |", aux->dados);
			aux = aux->prox;
		}
		printf("\n");
	}
}

void preencherAlfa(ThashAlfa *tab[], int tam, char dado[], int flag){
	ThashAlfa *novo, *aux, *aux1;
	int end;
	if (flag == 0 )
		end = hashAlfa(dado, tam);
	else
		end = HDeslAlfa(dado, tam);
	if (tab[end] == NULL){
		novo = (ThashAlfa*)malloc(sizeof(ThashAlfa));
		strcpy(novo->dados, dado);
		novo->prox = NULL;
		tab[end] = novo;
	}
	else{
		aux = tab[end];
		while (aux->prox != NULL){
			aux = aux->prox;
		}
		novo = (ThashAlfa*)malloc(sizeof(ThashAlfa));
		strcpy(novo->dados, dado);
		novo->prox = NULL;
		aux->prox = novo;
	}
}

ThashAlfa* buscar(ThashAlfa *tab[], char dado[], int tam){
	int i;
	ThashAlfa *aux;
	for (i = 0; i < tam; i++){
		aux = tab[i];
		while (aux != NULL){
			if (strcmp(aux->dados, dado) == 0)
				return aux;
			else
				aux = aux->prox;

		}
	}
	return NULL;
}