#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MergeSort.h"
#include "Comum.h"

/*
p = posição inicial do vetor
r = ate qual posicao iremos ordenar
v = vetor a ser ordenado
q = meio do vetor				*/

void mergesort(int p, int r, int v[]){
	int q;
	if (p < r - 1){
		q = (p + r) / 2;
		exibirMS(v, p, r);
		mergesort(p, q, v);
		exibirMS(v, p, r);
		mergesort(p, q, v);
		exibirMS(v, p, r);
		intercalar(p, q, r, v);
		exibirMS(v, p, r);
	}
}

void intercalar(int p, int q, int r, int v[]){
	int i = p, j = q, k = 0, *w;
	w = (int *) malloc((r - p) * sizeof(int));
	while (i < q && j < r){
		if (v[i] <= v[j])
			w[k++] = v[i++];
		else
			w[k++] = v[j++];
	}
	while (i < q)
		w[k++] = v[i++];
	while (j < r)
		w[k++] = v[j++];
	for (i = p; i < r; i++)
		v[i] = w[i - p];
	free(w);
}

void exibirMS(int vet[], int inicio, int max){
	int i;

	printf("Vetor - ");

	for (i = inicio; i < max; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\nPressione <ENTER> para continuar...");
	while (getch() != 13);
}

int mainMergeSort(){
	int vet[40], max;

	max = criarVetor(vet, 40);
	mergesort(0, max, vet);
}