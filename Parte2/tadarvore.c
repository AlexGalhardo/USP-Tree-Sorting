#include "tadarvore.h"

/*
	Autores:
	Alex Galhardo
	Numero USP: 10408344
	Ian Castilho Caldeira Brant
	Numero USP: 10133967
	ICMC USP - São Carlos 2017
*/

/*  */

void CriaArvore(ARVORE *a){
	a->raiz = NULL;
}

void InsereLargura(ARVORE *a, char x,int i){ // i ira dizer para a funcao onde o NO devera ser inserido, de acordo com a ordem em que foi digitado

	int h,aux; // h : Sera utlizado para saber a altura em que o NO ser� inserido; aux: variavel auxiliar
	NO *p,*q; // p: NO que sera inserido; q: NO NO qual o NO sera inserido

	if (x==32){ // se o caractere for um espaco nao faz nada
		return;
	}

	p = (NO*)malloc(sizeof(NO));
	q = (NO*)malloc(sizeof(NO));
	q = a->raiz;

	p->info = x;
	p->esq = NULL;
	p->dir = NULL;

	if (i==0){ // primeira insercao, sera feita na raiz
		a->raiz = p;
		return;
	}

	h = log(i+1)/log(2); // h eh a altura onde o NO sera inserido
	i = i - pow(2,h) + 2; // i eh a posicao onde o NO sera inserido, contando da esquerda para a direita come�ando em 1
	aux = pow(2, h); // aux eh a quantidade de NOs na altura onde o NO sera inserido, sendo tambem a quantidade de opcoes de lugar para inserir o NO, sabendo a altura

	while (aux>2){  // enquanto houvrem mais de duas opcoes para inserir o NO

		if (i<=aux/2){ // se i<aux/2, o NO devera ser inserido na porcao esquerda da arvore
			q = q->esq;
			aux = aux/2;
		} else { // se nao sera inserido na porcao direita
			q = q->dir;
			aux = aux/2;
			i = i - aux;
		}
	}

	if (i==1){ // inserir a esquerda
		q->esq = p;
		return;
	} else { // inserir a direita
		q->dir = p;
		return;
	}

}

int QtdNos(NO *p){ // retorna a quantidade de NOs da arvore que comeca no NO p

	if (p==NULL){
		return 0;
	}

	return 1 + QtdNos(p->esq) + QtdNos(p->dir);

}

int QtdFolha(NO *p){ // retorna a quantidade de NOs folha da arvore que comeca no NO p

	int x = 0;

	if (p==NULL){
		return 0;
	}

	if (p->esq==NULL&p->dir==NULL){ // se ambos os filhos sao NULL eh um NO folha
		return 1;
	}

	if (p->esq!=NULL){ // soma os NOS folha a esquerda
		x = x + QtdFolha(p->esq);
	}

	if (p->dir!=NULL){ // somao os NOS folha a direita
		x = x + QtdFolha(p->dir);
	}

	return x;

}

int Altura(NO *p) { // retorna a altura da arvore a partir do NO p

	int esq,dir; // esq : altura da sub-arvore direita; dir: altura da sub-arvore esquerda

	if (p==NULL){
		return 0;
	}

	esq = 1 + Altura(p->esq);
	dir = 1 + Altura(p->dir);

	if (esq>dir){
		return esq;
	} else return dir;

}

int EhCheia(NO* p){ // verifica se a arvore eh uma arvore cheia

	int x;

	x = pow(2,Altura(p)) - 1; // x eh o numero de elemtNOs que uma arvore da altura de p deve ter para ser cheia

	if (QtdNos(p)==x){ // se a quantidade de NOs eh igual a x
		return 1;
	} else {
		return 0;
	}

}

int NosBst(NO *p){ // conta a quantidade de NOs da arovre que respeitam as regras de uma arvore BST
//(se nem todos os NOs nao respeitam o valor pode nao ser o correto, mas nao importa ja que so importa se sao todos os NOs da arvore ou nao


	int x=0;

	if (p==NULL){
		return 0;
	}

	if (p->esq==NULL&p->dir==NULL){
		return 1;
	}

	if (p->esq!=NULL&&p->esq->info<p->info){ // soma os NOS folha a esquerda
		x = 1 + x + NosBst(p->esq);
	}

	if (p->esq==NULL&&p->dir!=NULL&&p->dir->info>p->info){ // somao os NOS folha a direita
		x = 1 + x + NosBst(p->dir);
	}

	if (p->esq!=NULL&&p->dir!=NULL&&p->dir->info>p->info){ // somao os NOS folha a direita
		x =  x + NosBst(p->dir);
	}

	return x;


}

int EhBst(NO *p){ // verifica se uma arvore eh binaria de busca

		int x;

	x = QtdNos(p); // x eh o numero de NOs da arvore

	if (NosBst(p)==x){ // se a quantidade de NOs que se encaixam nas regras de bst eh igual a x
		return 1;
	} else {
		return 0;
	}

}

int NosAvl(NO *p){// conta a quantidade de NOs da arovre que respeitam as regras de uma arvore AVL
//(se nem todos os NOs nao respeitam o valor pode nao ser o correto, mas nao importa ja que so importa se sao todos os NOs da arvore ou nao


	int x=0;

	if (p==NULL){
		return 0;
	}

	if (p->esq==NULL&p->dir==NULL){
		return 1;
	}

	if ((p->esq!=NULL&&p->dir==NULL)&&abs(Altura(p->dir)-Altura(p->esq))<2){
		x = 1 + x + NosAvl(p->esq);
	}

	if ((p->esq==NULL&&p->dir!=NULL)&&abs(Altura(p->dir)-Altura(p->esq))<2){
		x = 1 + x + NosAvl(p->dir);
	}

	if ((p->esq!=NULL&&p->dir!=NULL)&&abs(Altura(p->dir)-Altura(p->esq))<2){
		x =  1 + NosAvl(p->dir) + NosAvl(p->esq);
	}

	return x;


}

int EhAvl(NO *p){ // verifica se uma arvore eh avl

	int x;

	if (EhBst(p)==0){
		return 0;
	}

	x = QtdNos(p); // x eh o numero de NOs da arvore

	if (NosAvl(p)==x){ // se a quantidade de NOs que se encaixam nas regras de bst eh igual a x
		return 1;
	} else {
		return 0;
	}

}

void PreOrdem(NO *p,char *v,int *i) { // armazena em um vetor os elementos em pre ordem a partir de um no
     if (p!=NULL) {
        v[*i] = p->info;
        *i = *i+1;
        PreOrdem(p->esq,v,i);
        PreOrdem(p->dir,v,i);
     }
}

void PosOrdem(NO *p,char *v,int *i) { // armazena em um vetor os elementos em pos ordem a partir de um no
     if (p!=NULL) {
        PosOrdem(p->esq,v,i);
        PosOrdem(p->dir,v,i);
        v[*i] = p->info;
        *i = *i+1;
     }
}

void Ordem(NO *p,char *v,int *i) { // armazena em um vetor os elementos em ordem a partir de um no
     if (p!=NULL) {
        Ordem(p->esq,v,i);
         v[*i] = p->info;
        *i = *i+1;
        Ordem(p->dir,v,i);
     }
}


// CODIGOS DE INSERCAO EM AVL FEITOS PELO PROFESSOR EM AULA. NAO CONSEGUIMOS IMPLEMENTAR O NOSSO PROPRIO CODIGO DE INSERCAO AVL

void EE(NO **r) {
     NO *pai=*r;
     NO *filho=pai->esq;
     pai->esq=filho->dir;
     filho->dir=pai;
     pai->fb=0;
     filho->fb=0;
     *r=filho;
}

void DD(NO **r) {
     NO *pai=*r;
     NO *filho=pai->dir;
     pai->dir=filho->esq;
     filho->esq=pai;
     pai->fb=0;
     filho->fb=0;
     *r=filho;
}

void ED(NO **r) {
     NO *pai=*r;
     NO *filho=pai->esq;
     NO *neto=filho->dir;
     pai->esq=neto->dir;
     filho->dir=neto->esq;
     neto->esq=filho;
     neto->dir=pai;
     switch (neto->fb) {
            case -1:
                 pai->fb=1;
                 filho->fb=0;
                 break;
            case 0:
                 pai->fb=0;
                 filho->fb=0;
                 break;
            case 1:
                 pai->fb=0;
                 filho->fb=-1;
                 break;
     }
     neto->fb=0;
     *r=neto;
}

void DE(NO **r) {
     NO *pai=*r;
     NO *filho=pai->dir;
     NO *neto=filho->esq;
     filho->esq=neto->dir;
     pai->dir=neto->esq;
     neto->esq=pai;
     neto->dir=filho;
     switch (neto->fb) {
            case -1:
                 pai->fb=0;
                 filho->fb=1;
                 break;
            case 0:
                 pai->fb=0;
                 filho->fb=0;
                 break;
            case 1:
                 pai->fb=-1;
                 filho->fb=0;
                 break;
     }
     neto->fb=0;
     *r=neto;
}

int aux_insere(NO **p, char *x, int *cresceu) {
    if (*p==NULL) {
       *p=(NO*) malloc(sizeof(NO));
       (*p)->info=*x;
       (*p)->fb=0;
       (*p)->esq=NULL;
       (*p)->dir=NULL;
       *cresceu=1;
       return 1;
    }
    else if (*x==(*p)->info)
         return 0;
    else if (*x<(*p)->info) {
         if (aux_insere(&(*p)->esq,x,cresceu)) {
            if (*cresceu) {
	           switch ((*p)->fb) {
	                  case -1:
	                       if ((*p)->esq->fb==-1)
	                          EE(p);
                           else ED(p);
	                       *cresceu=0;
	                       break;
	                  case 0:
	                       (*p)->fb=-1;
	                       *cresceu=1;
	                       break;
                      case 1:
	                       (*p)->fb=0;
	                       *cresceu=0;
	                       break;
               }
            }
            return 1;
         }
         else return 0;
    }
    else {
         if (aux_insere(&(*p)->dir,x,cresceu)) {
            if (*cresceu) {
	           switch ((*p)->fb) {
	                  case -1:
	                       (*p)->fb=0;
                           *cresceu=0;
	                       break;
                      case 0:
	                       (*p)->fb=1;
	                       *cresceu=1;
	                       break;
                      case 1:
	                       if ((*p)->dir->fb==1)
	                          DD(p);
                           else DE(p);
	                       *cresceu=0;
	                       break;
               }
            }
            return 1;
         }
         else return 0;
    }
}

int InsereAvl(NO **p, char *x) {
  int cresceu;
  return aux_insere(p, x, &cresceu);
}
