#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
	Autores:
	Alex Galhardo
	Numero USP: 10408344
	Ian Castilho Caldeira Brant
	Numero USP: 10133967
	ICMC USP - São Carlos 2017
*/

typedef struct bloco {
	int info;
	int pos;
	struct bloco *prox, *ant;
}NO;

typedef struct {
	NO *inicio,*fim;
}LISTA;

void CriaLista(LISTA *L);
void Insere(LISTA *L,int x,int *erro);
NO *RetornaPos(LISTA *L,int pos,int *erro);
void CopiaLista (LISTA *a,LISTA *b);

int InsertionSort (LISTA *L, LISTA *lord);
int BubbleSort (LISTA *L, LISTA *lord);
int MergeSort (LISTA *lord,int p,int r);
void Merge (LISTA *lord,int p,int q,int r);






