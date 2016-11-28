#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "QuickSort.h"
#include "Comum.h"

void exibirQS(int vet[], int max, int pivo, int flag){
	int i;

	if (flag == 0)
		printf("\n\nPivo - %d\n", pivo);
	else if (flag == 1)
		printf("\n\nOrdenacao concluida\n");

	printf("Vetor - ");
	for (i = 0; i <= max; i++){
		printf("%d ", vet[i]);
	}
}

void quick(int vetor[], int inicio, int fim){
	int pivo, aux, i, j, meio, flag = 0;

	i = inicio;
	j = fim;

	meio = (int)((i + j) / 2);
	pivo = vetor[meio];

	do{
		while (vetor[i] < pivo)
			i = i + 1;
		while (vetor[j] > pivo)
			j = j - 1;

		if (i <= j){
			aux = vetor[i];
			exibirQS(vetor, fim, pivo, 0);

			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
			flag = 1;
		}
		if (flag == 0)
			exibirQS(vetor, fim, pivo, 0);
	} while (j > i);

	if (inicio < j){
		printf("\n\nSubVetor Esquerdo");
		quick(vetor, inicio, j);
		printf("\nVoltando da recursividade");
	}
	if (i < fim){
		printf("\n\nNovo loop");
		quick(vetor, i, fim);
		printf("\nVoltando da recursividade");
	}
}

int mainQuickSort(){
	int vet[40], max;

	max = criarVetor(vet, 40);
	system("cls");
	printf("\t\t\Ordenacao BubbleSort");

	quick(vet, 0, max-1);
	exibirQS(vet, max, 0, 1);

	printf("\nPressione < ENTER > para continuar...");
	while (getch() != 13);
}