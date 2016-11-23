#include <stdio.h>
#include <windows.h>
#include <time.h>
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

void pause (float delay1) {
 
    float inst1=0, inst2=0;
    
    if (delay1<0.001) return;
     
 
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
 
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
 
   return;
 
}

void ajustar_gotoxy(int linha, int coluna, int cont_val){
	if (linha == 5)
		coluna = 14 + cont_val * 32 + 4;
	else if (linha == 7)
		coluna = 5 + cont_val * 16 + 4;
	else if (linha == 9)
		coluna = 1 + cont_val * 8 + 4;

	gotoxy(coluna, linha);
}