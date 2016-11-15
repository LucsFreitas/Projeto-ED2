#include <stdio.h>
#include <conio.h>
#include "HeapSort.h"
#include "Comum.h"

void heap (int v [ ] , int n, int r) {
	int i, h, troca;
	char auxkey;
	i = r; troca = 1;
	while (troca == 1) {
		troca = 0;
		if (keyval(v, n, 2*i+1) > keyval(v, n, 2*i+2))
			h = 2*i+1;
		else
			h = 2*i+2;
		if (v[i] < keyval(v, n, h)) {
			auxkey = v[i]; v[i] = v[h]; v[h] = auxkey; i = h; troca = 1;
		}
	}
}

void heapsort(int v[], int n){
	int i, r, n1;
	char auxkey;
	i = n / 2 - 1;

	printf("\n");
	exibeHS(v, n);
	printf("\n");
	for (r = i; r >= 0; r--) {
		heap (v, n, r);
	}
	exibeHS(v, n);
	printf("\n");
	for (n1 = n-2; n1 >= 0; n1--) {
		auxkey = v [0];
		v[0] = v[n1+1];
		v[n1+1] = auxkey;
		heap (v, n1, 0);
	}
	exibeHS(v, n);
}

int keyval (int v [ ], int n, int i) {
	if (i > n)
		return  -32768;
	else
		return v[i];
}

void exibeHS(int vet[], int max){
	int i;

	printf("Vetor - ");

	for (i = 0; i < max; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\nPressione <ENTER> para continuar...");
	while (getch() != 13);
}

int mainHeapSort(){
	int vet[40], max;

	max = criarVetor(vet, 40);
	heapsort(vet, max);
}