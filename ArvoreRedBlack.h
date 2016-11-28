#include "Types.h"

// Rotacao a Esquerda do No
void rotacaoEsquerdaRB(redblack *raiz_original, redblack **ArvoreRB, redblack *noh);

//Rotacao a Direita do no
void rotacaoDireitaRB(redblack *raiz_original, redblack **ArvoreRB, redblack *noh);

redblack* inserir_NovoRB(redblack **ArvoreRB, redblack *noh);

// Insere a Cor do nova e faz o balaceamento caso precisar
void inserirCorRB(redblack *raiz_original, redblack **ArvoreRB,redblack *noh);

// Remove o noh da Arvore
redblack *removerRB(redblack **ArvoreRB, redblack *noh);

// Faz o balaceamento da cor caso tenha alguma incosistencia
void removerCorRB(redblack **ArvoreRB, redblack *noh);

// Sucessor do noh para o balaceamento
redblack* sucessorRB(redblack *noh);

// Maximo da Arvore
redblack* maximoRB(redblack *noh);

// Minimo da Arvore
redblack* minimoRB(redblack *noh);

// Cria o no para a Arvore
redblack* criaNovoRB();

// Função de Listagem dos dados
void visitarEmOrdemRB(redblack* ArvoreRB);

// Mostra os dados da Arvore
void mostraDadosNohRB(redblack* noh);

// Calculo do balaceamento
int calcularAlturaPretaRB(redblack *noh);

// Localizar o noh da Arvore para devidas alterações ou remoções
redblack* localizar_Noh_ArvoreRB(redblack* noh, int numero_arvore);


void initializeRB (QueueRB *q);

void enqueueRB (QueueRB *q, redblack *n);

redblack * dequeueRB (QueueRB *q);

redblack* headRB (QueueRB q);

int isEmptyRB (QueueRB q);

int isFullRB (QueueRB q);

void exibirRB(redblack * raiz, int flag);

void mainArvRB();