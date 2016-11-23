#include <stdio.h>
#include <conio.h>
#include "HeapSort.h"
#include "Comum.h"

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
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
          } else {
             break;
          }
      }
      a[pai] = t;
   }
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
	exibeHS(vet, max);
}