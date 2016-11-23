#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MergeSort.h"
#include "Comum.h"


void mergesort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergesort(vetor, posicaoInicio, metadeTamanho);
    mergesort(vetor, metadeTamanho + 1, posicaoFim);


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

    }

    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void exibirMS(int vet[], int inicio, int max){
	int i;

	printf("Vetor - ");

	for (i = inicio; i < max + 1; i++){
		printf("%d ", vet[i]);
	}
}

int mainMergeSort(){
	int vet[40], max;

	max = criarVetor(vet, 40) - 1;
	mergesort(vet, 0, max);
	exibirMS(vet, 0, max);
}