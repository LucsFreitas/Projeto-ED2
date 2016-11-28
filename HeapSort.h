#include "Types.h"

void heapsort(int a[], int n);
void exibeHS(int vet[], int max, int n, int flag);
void exibirArvHS(int vet[], int max);
void initializeHS (QueueHS *q);
void enqueueHS (QueueHS *q, int n);
int dequeueHS (QueueHS *q);
int isEmptyHS (QueueHS q);
int mainHeapSort();