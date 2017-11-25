#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
	Autores:
	Alex Galhardo
	Numero USP: 10408344
	Ian Castilho Caldeira Brant
	Numero USP: 10133967
	ICMC USP - São Carlos 2017
*/

typedef struct no {
	struct no *esq,*dir;
	int fb;
	char info;
}NO;

typedef struct {
	NO *raiz;
}ARVORE;

void CriaArvore(ARVORE *a); // cria uma arvore
void InsereLargura(ARVORE *a, char x,int i); // insercao do elemento x da posicao i em largura
int QtdNos(NO *p); // retorna a quantidade de nos a partir de um no
int QtdFolha(NO *p); // retorna a quantidade de nos folha a partir de um no
int Altura(NO *p); // retorna a altura a partir de um no
int EhCheia(NO* p); // retorna 1 se a arvore eh cheia, 0 se nao
int EhBst(NO *p); // retorna 1 se a arvore eh Binaria de busca, 0 se nao
int NosBst(NO *p); // retorna a quantidade de nos que seguem as regras de binaria de busca a partir de um no
int NosAvl(NO *p); // retorna a quantidade de nos que seguem as regras de avl a partir de um no
int EhAvl(NO *p); // retorna 1 se a arvore eh AVL, 0 se nao
void PreOrdem(NO *p,char *v,int *i); // armazena em um vetor os elementos em pre ordem a partir de um no
void PosOrdem(NO *p,char *v,int *i); // armazena em um vetor os elementos em pos ordem a partir de um no
void Ordem(NO *p,char *v,int *i); // armazena em um vetor os elementos em ordem a partir de um no
void EE(NO **r); // rotacao esquerda-esquerda
void DD(NO **r); // rotacao direita-direita
void ED(NO **r); // rotacao esquerda-direita
void DE(NO **r); // rotacao direita-esquerda
int aux_insere(NO **p, char *x, int *cresceu); // funcao auxiliar da insercao em AVL
int InsereAvl(NO **p, char *x); // insercao em AVL
