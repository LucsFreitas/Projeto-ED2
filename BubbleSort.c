#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "BubbleSort.h"
#include "Comum.h"

void bubble_sort(int vet[], int max) {
	int flag, i, aux, aux_ant = -32768;

	do {
		flag = 0;
		for (i = 0; i < max-1; i++) {
			if (vet[i] > vet[i + 1]) { /* para decrescente trocar '>' por '<' */
				aux = vet[i];
				if (aux != aux_ant)
					exibirBubbleSort(vet, aux, max, 0);
				
				aux_ant = aux;
				
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;

				exibirBubbleSort(vet, aux, max, 0);
				flag = 1;				
			}
		}
	} while (flag == 1);
	exibirBubbleSort(vet, aux, max, 1);
}


void exibirBubbleSort (int vet[], int aux, int max, int flag){
	int i;
		
	if (flag == 1)
		printf("\n\nOrdenacao concluida\n");
	else
		printf("\n\nAux - %d\n", aux);
	printf("Vetor - ");
	
	for (i = 0; i < max; i++){
		printf("%d ", vet[i]);
	}
	
}

void mainBubbleSort(){
	int max, vet[40];

	system("cls");
	printf("\t\t\Ordenacao BubbleSort\n\n");
	max = criarVetor(vet, 40);

	system("cls");
	printf("\t\t\Ordenacao BubbleSort");
	bubble_sort(vet, max);

	printf("\nPressione < ENTER > para continuar...");
	while (getch() != 13);
}