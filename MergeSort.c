#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MergeSort.h"
#include "Comum.h"


void mergesort(int *vetor, int posicaoInicio, int posicaoFim) {
	int i, j, k, metadeTamanho, *vetorTemp, loop = 1;
	int tempFim = 0;

	metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

	if(posicaoInicio == posicaoFim) return;

	else if (posicaoFim - posicaoInicio != 1){
		exibirMS(vetor, posicaoInicio, posicaoFim, 1);
		
		printf("\n\nEntrando na recursividade a esquerda\n");
		mergesort(vetor, posicaoInicio, metadeTamanho);
		printf("\n\nVoltando da recursividade a esquerda\n");
		printf("\n\nEntrando na recursividade a direita\n");
		mergesort(vetor, metadeTamanho + 1, posicaoFim);
		printf("\n\nVoltando da recursividade a direita\n");
	}
	else
		exibirMS(vetor, posicaoInicio, posicaoFim, 1);

	i = posicaoInicio;
	j = metadeTamanho + 1;
	k = 0;
	vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

	while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
		if (i == metadeTamanho + 1 ) { 
			vetorTemp[k] = vetor[j];
			j++;
			k++;
		}
		else {
			if (j == posicaoFim + 1) { 
				vetorTemp[k] = vetor[i];
				i++;
				k++;
			}
			else {
				if (vetor[i] < vetor[j]) {
					vetorTemp[k] = vetor[i];
					i++;
					k++;
				}
				else {
					vetorTemp[k] = vetor[j];
					j++;
					k++;
				}
			}
		}
		tempFim++;
		printf("\n\nApos Loop %d:\n", loop);
		exibirMS(vetorTemp, 0, tempFim-1, 3);
		loop++;
	}

	for(i = posicaoInicio; i <= posicaoFim; i++) {
		vetor[i] = vetorTemp[i - posicaoInicio];
	}
	exibirMS(vetor, posicaoInicio, posicaoFim, 4);
	free(vetorTemp);
}

void exibirMS(int vet[], int inicio, int max, int flag){
	int i;

	if (flag == 0)
		printf("Vetor - ");
	else if (flag == 1)
		printf("Vetor Inicial - ");
	else if (flag == 2)
		printf("\n\nVetor Final - ");
	else if (flag == 3)
		printf("Vetor temporario - ");
	else
		printf("\n\nVetor Inicial (pos ordenacao) - ");

	for (i = inicio; i < max + 1; i++){
		printf("%d ", vet[i]);
	}
}

int mainMergeSort(){
	int vet[40], max;

	max = criarVetor(vet, 40) - 1;
	system("cls");
	printf("\t\tMerge Sort\n\n");

	mergesort(vet, 0, max);

	exibirMS(vet, 0, max, 2);

	printf("\n\nPressione < ENTER > para continuar...");
	while (getch() != 13);
}