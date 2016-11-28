#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ArvoreRedBlack.h"
#include "Comum.h"

redblack *vazio = NULL;


// Rotacao a Esquerda do No
void rotacaoEsquerdaRB(redblack *raiz_original, redblack **ArvoreRB, redblack *noh){
	redblack *y;

	if(((*ArvoreRB)->pai == vazio) && (noh->direita != vazio))
	{
		exibirRB(raiz_original, 1);
		y = noh->direita;
		noh->direita = y->esquerda;
		y->esquerda->pai = noh;
		y->pai = noh->pai;

		if(noh->pai == vazio)
		{
			*ArvoreRB = y;
		}
		else if(noh == noh->pai->esquerda)
		{
			noh->pai->esquerda = y;
		}
		else
		{
			noh->pai->direita = y;
		}
	}
	y->esquerda = noh;
	noh->pai = y;
	(*ArvoreRB)->pai = vazio;
}

//Rotacao a Direita do no
void rotacaoDireitaRB(redblack *raiz_original, redblack **ArvoreRB, redblack *noh){
	redblack *y;

	if(((*ArvoreRB)->pai == vazio) && (noh->esquerda != vazio))
	{
		exibirRB(raiz_original, 2);
		y = noh->esquerda;
		noh->esquerda = y->direita;
		y->direita->pai = noh;
		y->pai = noh->pai;

		if(noh->pai == vazio)
		{
			*ArvoreRB = y;
		}
		else if(noh == noh->pai->direita)
		{
			noh->pai->direita = y;
		}
		else
		{
			noh->pai->esquerda = y;
		}
	}
	y->direita = noh;
	noh->pai = y;
	(*ArvoreRB)->pai = vazio;
}

redblack* inserir_NovoRB(redblack **ArvoreRB, redblack *noh)// Insere na arvore
{
	redblack *y = vazio;
	redblack *x = *ArvoreRB;

	if((*ArvoreRB)== NULL)// Verifica se a arvore é NULL
	{
		*ArvoreRB = noh;
		(*ArvoreRB)->pai = vazio;
		vazio->pai = *ArvoreRB;
		(*ArvoreRB)->cor = 'P';
		return;
	}

	if((*ArvoreRB)->numero_arvore == noh->numero_arvore)
	{
		printf(" Numero duplicado, Coloque outro numero !!\n\n");
		return;
	}

	while(x != vazio)
	{
		y = x;

		if(noh->numero_arvore < x->numero_arvore){
			x = x->esquerda;
		}
		else{
			x = x->direita;
		}
	}

	noh->pai = y;

	if(noh->numero_arvore < y->numero_arvore)	{
		y->esquerda = noh;
	}
	else if(noh->numero_arvore > y->numero_arvore)
	{
		y->direita = noh;
	}
	else if(noh->numero_arvore == y->numero_arvore)
	{
		printf("Numeros iguais, Tente outro numero !!\n\n");
	}

	noh->esquerda = vazio;
	noh->direita = vazio;
	noh->cor = 'V';

	inserirCorRB(*ArvoreRB, &(*ArvoreRB), noh);
	return noh;
}

// Insere a Cor do nova e faz o balaceamento caso precisar
void inserirCorRB(redblack *raiz_original, redblack **ArvoreRB,redblack *noh)//
{
	redblack *y;

	while(noh->pai->cor == 'V')
	{
		if(noh->pai == noh->pai->pai->esquerda)
		{
			y = noh->pai->pai->direita;

			if(y->cor == 'V')
			{
				noh->pai->cor = 'P';
				y->cor = 'P';
				noh->pai->pai->cor = 'V';
				noh = noh->pai->pai;
			}
			else
			{
				if(noh == noh->pai->direita)
				{
					noh = noh->pai;
					rotacaoEsquerdaRB(raiz_original, &(*ArvoreRB), noh);
				}

				noh->pai->cor = 'P';
				noh->pai->pai->cor = 'V';
				rotacaoDireitaRB(raiz_original, &(*ArvoreRB), noh->pai->pai);
			}
		}
		else
		{
			y = noh->pai->pai->esquerda;

			if(y->cor == 'V')
			{
				noh->pai->cor = 'P';
				y->cor = 'P';
				noh->pai->pai->cor = 'V';
				noh = noh->pai->pai;
			}
			else
			{
				if(noh == noh->pai->esquerda)
				{
					noh = noh->pai;
					rotacaoDireitaRB(raiz_original, &(*ArvoreRB), noh);
				}

				noh->pai->cor = 'P';
				noh->pai->pai->cor = 'V';
				rotacaoEsquerdaRB(raiz_original, &(*ArvoreRB), noh->pai->pai);
			}
		}
	}

	(*ArvoreRB)->cor = 'P';
}

// Remove o noh da Arvore
redblack *removerRB(redblack **ArvoreRB, redblack *noh)
{
	redblack *y, *x;

	if((noh->esquerda == vazio) || (noh->direita == vazio))
	{
		y = noh;
	}
	else
	{
		y = sucessorRB(noh);
	}

	if(y->esquerda != vazio)
	{
		x = y->esquerda;
	}
	else
	{
		x = y->direita;
	}

	x->pai = y->pai;


	if(y->pai == vazio)
	{
		*ArvoreRB = x;
	}
	else if(y == y->pai->esquerda)
	{
		y->pai->esquerda = x;
	}
	else
	{
		y->pai->direita = x;
	}

	if(y != noh)
	{
		noh->numero_arvore = y->numero_arvore;        //Aqui os dados são transferidos
	}

	if(y->cor == 'P')
	{


		if((*ArvoreRB)->direita == vazio && (*ArvoreRB)->esquerda->direita != vazio)
		{

			rotacaoEsquerdaRB(*ArvoreRB, &(*ArvoreRB), (*ArvoreRB)->esquerda);
			removerCorRB(&(*ArvoreRB), (*ArvoreRB)->esquerda);
			rotacaoDireitaRB(*ArvoreRB, &(*ArvoreRB), (*ArvoreRB));
		}
		else
		{

			if((*ArvoreRB)->esquerda == vazio && (*ArvoreRB)->direita->esquerda != vazio)
			{

				rotacaoDireitaRB(*ArvoreRB, &(*ArvoreRB), (*ArvoreRB)->direita);
				removerCorRB(&(*ArvoreRB), (*ArvoreRB)->direita);
				rotacaoEsquerdaRB(*ArvoreRB, &(*ArvoreRB), (*ArvoreRB));
			}
		}
		removerCorRB(&(*ArvoreRB), x);
	}
	return y;
	free(y);
	free(x);

}

// Faz o balaceamento da cor caso tenha alguma incosistencia
void removerCorRB(redblack **ArvoreRB, redblack *noh)
{
	redblack *aux;

	while(((*ArvoreRB) != noh) && (noh->cor == 'P'))
	{
		if(noh == noh->pai->esquerda)
		{
			aux = noh->pai->direita;

			if(aux->cor == 'V')
			{
				aux->cor = 'P';
				noh->pai->cor = 'V';
				rotacaoEsquerdaRB(*ArvoreRB, &(*ArvoreRB), noh->pai);
				aux = noh->pai->direita;
			}

			if((aux->esquerda->cor == 'P') && (aux->direita->cor == 'P'))
			{
				aux->cor = 'V';
				noh = noh->pai;
			}
			else if(aux->direita->cor == 'P')
			{
				aux->esquerda->cor = 'P';
				aux->cor = 'V';
				rotacaoDireitaRB(*ArvoreRB, &(*ArvoreRB), aux);
				aux = noh->pai->direita;
				aux->cor = noh->pai->cor;
				noh->pai->cor = 'P';
				aux->direita->cor = 'P';
				rotacaoEsquerdaRB(*ArvoreRB, &(*ArvoreRB), noh->pai);
				noh = *ArvoreRB;
			}
		}
		else
		{
			aux = noh->pai->esquerda;

			if(aux->cor == 'V')
			{
				aux->cor = 'P';
				noh->pai->cor = 'V';
				rotacaoDireitaRB(*ArvoreRB, &(*ArvoreRB), noh->pai);
				aux = noh->pai->esquerda;
			}

			if((aux->esquerda->cor == 'P') && (aux->direita->cor == 'P'))
			{
				aux->cor = 'V';
				noh = noh->pai;
			}
			else if(aux->esquerda->cor == 'P')
			{
				aux->direita->cor = 'P';
				aux->cor = 'V';
				rotacaoEsquerdaRB(*ArvoreRB, &(*ArvoreRB), aux);
				aux = noh->pai->esquerda;
				aux->cor = noh->pai->cor;
				noh->pai->cor = 'P';
				aux->esquerda->cor = 'P';
				rotacaoDireitaRB(*ArvoreRB, &(*ArvoreRB), noh->pai);
				noh = *ArvoreRB;
			}
		}
	}
	noh->cor = 'P';
}

// Sucessor do noh para o balaceamento
redblack* sucessorRB(redblack *noh)
{
	redblack *aux;

	if(noh->direita != vazio)
	{
		return minimoRB(noh->direita);
	}

	aux = noh->pai;

	while((aux != vazio) && (noh == aux->direita))
	{
		noh = aux;
		aux = aux->pai;
	}

	return aux;
}

// Maximo da Arvore
redblack* maximoRB(redblack *noh)
{
	while(noh->direita != vazio)
	{
		noh = noh->direita;
	}
	return noh;
}

// Minimo da Arvore
redblack* minimoRB(redblack *noh)
{
	while(noh->esquerda != vazio)
	{
		noh = noh->esquerda;
	}
	return noh;
}

// Cria o no para a Arvore
redblack* criaNovoRB()
{
	redblack *novo;
	int n;
	novo = (redblack*)malloc(sizeof(redblack));
	do{
		printf("\nInforme o valor a ser inserido (deve ser entre 0 e 99): ");
		scanf("%d", &n);
		if(n < 0 || n > 99)
		{
			printf("Numero Invalido! Tente Novamente !!!\n");
		}
	} while(n < 0 || n > 99);
	novo->numero_arvore = n;
	novo->cor = 'V'; // todo novo noh é vermelho
	novo->pai = vazio;
	novo->direita = vazio;
	novo->esquerda = vazio;

	return novo;
}

// Função de Listagem dos dados
void visitarEmOrdemRB(redblack* ArvoreRB)
{
	if (ArvoreRB != vazio)
	{
		printf("%d (%c)", ArvoreRB->numero_arvore, ArvoreRB->cor);
		visitarEmOrdemRB(ArvoreRB->esquerda);
		visitarEmOrdemRB(ArvoreRB->direita);
	}
}

// Mostra os dados da Arvore
void mostraDadosNohRB(redblack* noh)
{
	printf("Endereco do noh....................: %p\n", noh);
	printf("Valor do noh.......................: %d\n", noh->numero_arvore);
	printf("Cor do noh.........................: %c\n\n", noh->cor);
	printf("Pai do noh.........................: %p\n", noh->pai);
	printf("Filho da esquerda..................: %p\n", noh->esquerda);
	printf("Filho da direita...................: %p\n\n", noh->direita);
	printf("\n\n");
}

// Calculo do balaceamento
int calcularAlturaPretaRB(redblack *noh){
	int alt_esquerda = 0, alt_direita = 0;

	if(!noh)
	{
		return 0;
	}

	if (noh == vazio)
	{
		return 1;
	}

	if (noh->cor == 'P')
	{
		alt_esquerda += calcularAlturaPretaRB(noh->esquerda);
		alt_direita +=  calcularAlturaPretaRB(noh->direita);
	}
	else
	{
		calcularAlturaPretaRB(noh->esquerda);
		calcularAlturaPretaRB(noh->direita);
	}

	if (alt_esquerda > alt_direita)
	{
		return alt_esquerda + 1;
	}
	else
	{
		return alt_direita + 1;
	}
}

// Localizar o noh da Arvore para devidas alterações ou remoções
redblack* localizar_Noh_ArvoreRB(redblack* noh, int numero_arvore)
{
	if ((noh == vazio) || (noh->numero_arvore == numero_arvore))
	{
		return noh;
	}

	if (numero_arvore < noh->numero_arvore)
	{
		return localizar_Noh_ArvoreRB(noh->esquerda, numero_arvore);
	}
	else
	{
		return localizar_Noh_ArvoreRB(noh->direita, numero_arvore);
	}
}


void initializeRB (QueueRB *q){
	QueueRB aux;
	aux = (DescritorArvRB*)malloc(sizeof(DescritorArvRB));
	aux->inicio = NULL;
	aux->fim = NULL;
	*q = aux;
}

void enqueueRB (QueueRB *q, redblack *n){
	NoQueueArvRB *aux;
	aux = (NoQueueArvRB*)malloc(sizeof(NoQueueArvRB));
	aux->info = n;

	if (isEmptyRB(*q) == TRUE){
		(*q)->inicio = aux;
		(*q)->fim = aux;
	}
	else{
		(*q)->fim->prox = aux;
		(*q)->fim = aux;
	}
	(*q)->fim->prox = NULL;
}

redblack * dequeueRB (QueueRB *q){
	NoQueueArvRB *aux;
	redblack * s;
	aux = (*q)->inicio;

	(*q)->inicio = (*q)->inicio->prox;
	if ((*q)->inicio == NULL)
		(*q)->fim = NULL;
	s = aux->info;

	free(aux);

	return s;
}

redblack* headRB (QueueRB q){
	return q->inicio->info;
}

int isEmptyRB (QueueRB q){
	if (q->inicio == NULL)
		return TRUE;
	else
		return FALSE;
}

int isFullRB (QueueRB q){
	return FALSE;
}

void exibirRB(redblack * raiz, int flag){
	QueueRB fila;
	redblack * aux;
	int cont = 0, temp, i;
	int coluna = 34, linha = 3, cont_val = 0;

	system("cls");
	printf("\t\t\t\tArvore AVL\n");
	if (raiz != NULL)
	{
		printf("\t  Aqui sao mostrados apenas os 4 primeiros niveis da arvore");
		initializeRB(&fila);
		enqueueRB (&fila,raiz);
		cont++;
		while (isEmptyRB(fila) == FALSE) {
			temp = cont;
			for (i = 0; i < temp; i++){
				ajustar_gotoxy_composto(linha, coluna, cont_val);
				aux = dequeueRB(&fila);
				cont--;

				if (aux != NULL && (aux->numero_arvore >= 0 && aux->numero_arvore <= 99)){
					if (aux->numero_arvore >= 0 && aux->numero_arvore < 10)
						printf("0");
					printf("%d (%c)", aux->numero_arvore, aux->cor);
					enqueueRB(&fila,aux->esquerda); cont++;
					enqueueRB(&fila,aux->direita); cont++;
				}
				else{
					enqueueRB(&fila, NULL); cont++;
					enqueueRB(&fila, NULL); cont++;
				}

				cont_val++;
			}
			linha = linha + 2;
			cont_val = 0;
			if (linha == 11)
				break;
		}		
	}
	printf("\n\n\n");
	if (flag == 1)
		printf("\t\tNecessario rotacao a esquerda\n");
	else if (flag == 2)
		printf("\t\tNecessario rotacao a direita\n");

	printf("\t\tPressione << ENTER >> para continuar...");
	while(getch() != 13);
	system ("cls");
}

void mainArvRB(){
	redblack *ArvoreRB = NULL;
	redblack *aux;
	int valor, altura, opc;
	vazio = (redblack*)malloc(sizeof(redblack));
	vazio->pai = ArvoreRB;
	vazio->direita = vazio->esquerda = vazio;

	do {
		system("cls");
		printf("\t\tArvore Red-Black\n\n");
		printf("1 - Inserir\n2 - Passeio em Ordem\n3 - Calcular altura preta\n");
		printf("4 - Remover\n5 - Alterar\n6 - Exibir Arvore\n7 - Voltar ao Menu de Arvores\n");
		printf("\nInforme a opcao desejada: ");
		scanf("%d", &opc); fflush(stdin);

		switch (opc) {
		case 1:
			inserir_NovoRB(&ArvoreRB, criaNovoRB());
			exibirRB(ArvoreRB, 0);
			break;
		case 2:
			printf("Exibicao de nos da arvore \n\n");
			if(ArvoreRB != NULL)
				visitarEmOrdemRB(ArvoreRB);
			else
				printf("Sem Elementos na Arvore \n");
			getch();
			break;
		case 3:
			if(ArvoreRB != NULL){
				altura = calcularAlturaPretaRB(ArvoreRB);
				printf("Altura preta da arvore: %d\n", altura);
			}else
				printf("Sem Elementos na Arvore \n");
			break;
		case 4:
			if(ArvoreRB != NULL){
				printf("Digite o numero da Arvore para Remocao ?   \n");
				scanf("%d", &valor);
				aux = localizar_Noh_ArvoreRB(ArvoreRB, valor);
				if (aux->numero_arvore == valor)
				{
					mostraDadosNohRB(aux);
					removerRB(&ArvoreRB, aux);
				}
				else
				{
					printf("\nO numero %d nao encontrada!\n\n", valor);
				}
				if(ArvoreRB == vazio)
				{
					vazio = (redblack*)malloc(sizeof(redblack));
					vazio->pai = ArvoreRB = NULL;
					vazio->direita = vazio->esquerda = vazio;
				}
			}
			else
			{
				printf("Sem Elementos na Arvore \n");
			}
			break;
		case 5:
			if(ArvoreRB != NULL)
			{
				printf("Qual noh deseja alterar\n ");
				scanf("%d", &valor);
				aux = localizar_Noh_ArvoreRB(ArvoreRB, valor);
				if (aux->numero_arvore == valor)
				{
					mostraDadosNohRB(aux);
					inserir_NovoRB(&(ArvoreRB),criaNovoRB());
					removerRB(&ArvoreRB, aux);

				}
				else
				{
					printf("O numero %d nao encontrada!\n\n", valor);
				}
			}
			else
			{
				printf("Sem Elementos na Arvore \n");
			}

			break;
		case 6:
			exibirRB(ArvoreRB, 0);
			break;
		case 7:
			break;
		}
	}
	while (opc != 0);
}