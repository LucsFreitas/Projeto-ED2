#include <stdio.h>
#include <windows.h>
#include "comum.h"

int criarVetor(int vet[], int qtd){
	int i;

	printf("Tamanho maximo do vetor = %d\n", qtd);
	printf("Digite -999 para encerrar a insercao antecipadamente\n\n");
	for (i = 0; i < qtd; i++){
		printf("Informe o valor %d: ", i + 1);
		scanf("%d", &vet[i]); fflush(stdin);
		if (vet[i] == -999)
			break;
	}

	// O retorno e a qtd de valores adicionados
	return i;
}

void gotoxy(int coluna, int linha){
        COORD point;
        point.X = coluna; point.Y = linha;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}