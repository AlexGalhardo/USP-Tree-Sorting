#include "tadsort.h"

/*
	Autores:
	Alex Galhardo
	Numero USP: 10408344
	Ian Castilho Caldeira Brant
	Numero USP: 10133967
	ICMC USP - São Carlos 2017
*/

void CriaLista(LISTA *L){
	
	L->inicio = NULL;
	L->fim = NULL;
}


void Insere(LISTA *L,int x,int *erro){
	
	NO *p;
	
	p = (NO*)malloc(sizeof(NO));
	
	if(p==NULL){
		*erro = 1;
		return;
	} else *erro = 0;
	
	p->info = x;
	p->prox = NULL;
	p->ant = L->fim;
	
	
	if (L->inicio == NULL){
		p->ant = NULL;
		p->pos = 0;
		L->inicio = p;
		L->fim = p;
	} else {
  		p->pos = L->fim->pos + 1;
		L->fim->prox = p;
		L->fim = p;
	}
	
	
}

NO *RetornaPos(LISTA *L,int pos,int *erro){
	
	NO *p;
	p = (NO*)malloc(sizeof(NO));
	p = L->inicio;
	
	while (p!=NULL){
		if (p->pos == pos){
			*erro = 0;
			return p;
		}
		p = p->prox;	
	}
	*erro = 1;
	return NULL;
	
}

void CopiaLista (LISTA *a,LISTA *b){
	
	NO *p,*q;
	p = (NO*)malloc(sizeof(NO));
	q = (NO*)malloc(sizeof(NO));
	p = a->inicio;
	q = b->inicio;
	
	while (p!=NULL){
		q->info = p->info;
		p = p->prox;
		q = q->prox;
	}
	
	
}

int InsertionSort (LISTA *L, LISTA *lord){

	int aux;
	NO *i,*I,*J;
	
	i = (NO*)malloc(sizeof(NO));
	I = (NO*)malloc(sizeof(NO));
	J = (NO*)malloc(sizeof(NO));
	
	i = L->inicio;
	I = lord->inicio;
	
	while (i!=NULL){
		I->info = i->info;
		I=I->prox;	
		i = i->prox;
	}
	
	
 	clock_t tempoInicial, tempoFinal;

	tempoInicial = clock();	
	
	
	I = lord->inicio->prox;
	
	while (I!=NULL){
	
		aux = I->info;
		J = I->ant;
		
		while (J!=NULL&&aux<J->info){
			J->prox->info=J->info;
			J = J->ant;
		}
	
		if (J==NULL){
			lord->inicio->info = aux;
		} else{
		
		J->prox->info=aux;
		}
		
		I = I->prox;	
	}

	tempoFinal = clock();
	
	
   	return (tempoFinal-tempoInicial);

	
}

int BubbleSort (LISTA *L, LISTA *lord){
	
	int aux,troca=1;
	NO *i,*I;
	
	i = (NO*)malloc(sizeof(NO));
	I = (NO*)malloc(sizeof(NO));

	
	i = L->inicio;
	I = lord->inicio;
	
	while (i!=NULL){

		I->info = i->info;
		I=I->prox;
		i = i->prox;		
	}
	

 	clock_t tempoInicial, tempoFinal;

	tempoInicial = clock();	
	
	while (troca==1){
	
	troca = 0;

	I = lord->inicio;

	
	while (I->prox!=NULL){
	
			
		if (I->info>I->prox->info){
			aux = I->info;
			I->info = I->prox->info;
			I->prox->info= aux;
			troca = 1;
		}
		
		I = I->prox;
		}

	}

	tempoFinal = clock();
	
	
   	return (tempoFinal-tempoInicial);

}

int MergeSort (LISTA *lord,int p,int r){
	
	int q,t;
	
	clock_t tempoInicial, tempoFinal;

	tempoInicial = clock();
	
	if (p<r){
		
		q = (p+r)/2;
		t = MergeSort(lord,p,q);
		t = MergeSort(lord,q+1,r);
		Merge(lord,p,q,r);
		
	}

	tempoFinal = clock();
	
	
   	return (tempoFinal-tempoInicial);;
	
}

void Merge (LISTA *lord,int p,int q,int r){
	
	
	NO *P;
	int i,j,k,n1,n2,*left,*right,erro;
	n1 = q - p + 1;
	n2 = r - q;

	P = (NO*)malloc(sizeof(NO));
	left = (int*)malloc((n1+1)*sizeof(int));
	right = (int*)malloc((n2+1)*sizeof(int));
	
	P = RetornaPos(lord,p,&erro);
	for (i=0;i<n1;i++){
		left[i] = P->info;
		P = P->prox;
	}
	
	P = RetornaPos(lord,q+1,&erro);
	for (j=0;j<n2;j++){
		right[j] = P->info;
		P = P->prox;
	}



	left[n1] = INT_MAX;
	right[n2] = INT_MAX;

	i = 0;
	j = 0;
	
	P = RetornaPos(lord,p,&erro);
	for (k=p;k<=r;k++){
		if (left[i]<=right[j]){
			P->info = left[i];
			i = i + 1;
			P = P->prox;
		} else {
			P->info = right[j];
			j = j + 1;
			P = P->prox;
		}
	}	
}
