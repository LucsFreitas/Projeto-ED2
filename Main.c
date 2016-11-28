#include <stdio.h>
#include <Windows.h>
#include "ArvoreAVL.h"
#include "ArvoreBin.h"
#include "ArvoreRedBlack.h"
#include "BubbleSort.h"
#include "Comum.h"
#include "HashAlfa.h"
#include "HashInt.h"
#include "HeapSort.h"
#include "ListaCircularDupla.h"
#include "ListaCircularSimples.h"
#include "ListaDupla.h"
#include "ListaSimples.h"
#include "Main.h"
#include "MergeSort.h"
#include "QuickSort.h"

int main(){
	int op;

	do{
		system("cls");
		printf("\tMenu Principal\n\n");
		printf("1 - Acessar Modulo de Arvores\n");
		printf("2 - Acessar Modulo de Ordenacoes\n");
		printf("3 - Acessar Modulo de Listas\n");
		printf("4 - Acessar Modulo de Hash\n");
		printf("5 - Sair do Programa\n\n");

		printf("Informe a opcao desejada: ");
		scanf("%d", &op); fflush(stdin);

		switch(op){
		case 1:
			moduloArvores();
			break;
		case 2:
			moduloOrdenacao();
			break;
		case 3:
			moduloListas();
			break;
		case 4:
			moduloHash();
			break;
		case '5':
				break;
		default:
			printf("\n\tOpcao invalida!");
			pause(1.5);
		}
	} while (op != 5);

	return 0;
}

void moduloArvores(){
	int op;

	do{
		system("cls");
		printf("\tModulo de Arvores\n\n");
		printf("1 - Arvore Binaria\n");
		printf("2 - Arvore AVL\n");
		printf("3 - Arvore Red-Black\n");
		printf("4 - Voltar ao Menu Principal\n\n");

		printf("Informe a opcao desejada: ");
		scanf("%d", &op); fflush(stdin);

		switch(op){
		case 1:
			mainArvBin();
			break;
		case 2:
			mainArvAVL();
			break;
		case 3:
			mainArvRB();
			break;
		case 4:
			break;
		default:
			printf("\n\tOpcao invalida!");
			pause(1.5);
		}
	} while (op != 4);
}

void moduloOrdenacao(){
	int op;

	do{
		system("cls");
		printf("\tModulo de Ordenacao\n\n");
		printf("1 - BubbleSort\n");
		printf("2 - HeapSort\n");
		printf("3 - MergeSort\n");
		printf("4 - QuickSort\n");
		printf("5 - Voltar ao Menu Principal\n\n");

		printf("Informe a opcao desejada: ");
		scanf("%d", &op); fflush(stdin);

		switch(op){
		case 1:
			mainBubbleSort();
			break;
		case 2:
			mainHeapSort();
			break;
		case 3:
			mainMergeSort();
			break;
		case 4:
			mainQuickSort();
			break;
		case 5:
			break;
		default:
			printf("\n\tOpcao invalida!");
			pause(1.5);
		}
	} while (op != 5);
}

void moduloListas(){
	int op;

	do{
		system("cls");
		printf("\tModulo de Listas\n\n");
		printf("1 - Simplesmente Encadeada\n");
		printf("2 - Duplamente  Encadeada\n");
		printf("3 - Circular Simplesmente Encadeada\n");
		printf("4 - Circular Duplamente Encadeada\n");
		printf("5 - Voltar ao Menu Principal\n\n");

		printf("Informe a opcao desejada: ");
		scanf("%d", &op); fflush(stdin);

		switch(op){
		case 1:
			mainLSE();
			break;
		case 2:
			mainLDE();
			break;
		case 3:
			mainCSE();
			break;
		case 4:
			mainCDE();
			break;
		case 5:
			break;
		default:
			printf("\n\tOpcao invalida!");
			pause(1.5);
		}
	} while (op != 5);
}

void moduloHash(){
	int op;

	do{
		system("cls");
		printf("\tModulo de Hash\n\n");
		printf("1 - Hashing por Divisao Inteira\n");
		printf("2 - Hashing por Divisao Inteira para Chaves Alfanumericas\n");
		printf("3 - Voltar ao Menu Principal\n\n");

		printf("Informe a opcao desejada: ");
		scanf("%d", &op); fflush(stdin);

		switch(op){
		case 1:
			mainHashInt();
			break;
		case 2:
			mainHashAlfa();
			break;
		case 3:
			break;
		default:
			printf("\n\tOpcao invalida!");
			pause(1.5);
		}
	} while (op != 3);
}