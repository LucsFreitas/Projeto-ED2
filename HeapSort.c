#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "HeapSort.h"
#include "Comum.h"

int mainHeapSort(){
	int vet[40], max;

	max = criarVetor(vet, 40);

	heapsort(vet, max);
	exibeHS(vet, max, 0, 2);
}

void heapsort(int a[], int n) {
	int i = n / 2, pai, filho, t;
	int max = n, flag = 1;

	for (;;) {
		if (flag == 1){
			exibeHS(a, max, n, 1);
			flag = 0;
		}
		if (i > 0) {
			i--;
			t = a[i];
		} else {
			n--;
			if (n == 0) return;
			t = a[n];
			a[n] = a[0];
			flag = 1;
		}
		pai = i;
		filho = i * 2 + 1;

		while (filho < n) {
			if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
				filho++;
			if (a[filho] > t) {
				a[pai] = a[filho];
				pai = filho;
				filho = pai * 2 + 1;
				flag = 1;
			} else {
				break;
			}
		}

		a[pai] = t;
	}
}

void exibeHS(int vet[], int max, int n, int flag){
	int i;

	system("cls");
	printf("\t\tHeap Sort\n\n");
	if (flag == 1){
		printf("Arvore Auxiliar:");
		exibirArvHS(vet, n);
	}

	if (flag == 2)
		printf("\n\nVetor Final - ");
	else
		printf("\n\nVetor - ");

	for (i = 0; i < max; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\nPressione <ENTER> para continuar...");
	while (getch() != 13);
}

void initializeHS (QueueHS *q){
	QueueHS aux;
	aux = (DescritorHS*)malloc(sizeof(DescritorHS));
	aux->inicio = NULL;
	aux->fim = NULL;
	*q = aux;
}

void enqueueHS (QueueHS *q, int n){
	NoQueueHS *aux;
	aux = (NoQueueHS*)malloc(sizeof(NoQueueHS));
	aux->info = n;

	if (isEmptyHS(*q) == TRUE){
		(*q)->inicio = aux;
		(*q)->fim = aux;
	}
	else{
		(*q)->fim->prox = aux;
		(*q)->fim = aux;
	}
	(*q)->fim->prox = NULL;
}

int dequeueHS (QueueHS *q){
	NoQueueHS *aux;
	int s;
	aux = (*q)->inicio;

	(*q)->inicio = (*q)->inicio->prox;
	if ((*q)->inicio == NULL)
		(*q)->fim = NULL;
	s = aux->info;

	free(aux);

	return s;
}

int isEmptyHS (QueueHS q){
	if (q->inicio == NULL)
		return TRUE;
	else
		return FALSE;
}

void exibirArvHS(int vet[], int max){
	QueueHS fila;
	int aux, cont = 1, temp, i;
	int coluna = 35, linha = 3, cont_val = 0;

	initializeHS(&fila);
	for (i = 0; i < max; i++)
		enqueueHS(&fila, vet[i]);

	while (isEmptyHS(fila) == FALSE){
		temp = cont;
		for (i = 0; i < temp; i++){
			if (max == 0)
				break;

			ajustar_gotoxy_simples(linha, coluna, cont_val);
			aux = dequeueHS(&fila);

			if (aux >= 0 && aux < 10)
				printf("0");

			printf("%d", aux);
			cont_val++;
			max--;
		}
		linha = linha + 2;
		cont_val = 0;
		cont = cont * 2;
		if (linha == 13)
			break;
	}
	free(fila);
}