#include "tadsort.h"

/*
	Autores:
	Alex Galhardo
	Numero USP: 10408344
	Ian Castilho Caldeira Brant
	Numero USP: 10133967
	ICMC USP - São Carlos 2017
*/

void Imprime (LISTA *L);

int main (){
	
	
	int i,n,repeticoes,erro,count=1;
	LISTA *ord,*dsord,*ale,*lord;
	int tinsord=0,tinsdsord=0,tinsale=0,tbubord=0,tbubdsord=0,tbubale=0,tmerord=0,tmerdsord=0,tmerale=0;

	lord = (LISTA*)malloc(sizeof(LISTA));
	
	ord = (LISTA*)malloc(sizeof(LISTA));
	dsord = (LISTA*)malloc(sizeof(LISTA));
	ale = (LISTA*)malloc(sizeof(LISTA));
	
	srand(10133967);
	
	printf ("Digite o tamanho da lista:\n");
	scanf ("%d",&n);
	printf ("Digite o numero de repeticoes:\n");
	scanf ("%d",&repeticoes);

	
	
	CriaLista(ord);
	CriaLista(dsord);
	CriaLista(ale);
	CriaLista(lord);
	
	
	for (i=1;i<=n;i++){
		Insere(ord,i,&erro);
		Insere(dsord,n-i+1,&erro);
		Insere(ale,rand(),&erro);
		Insere(lord,0,&erro);
	}	
	

	while(count<=repeticoes){
		
	tinsord = tinsord + InsertionSort(ord,lord);
	tinsdsord = tinsdsord + InsertionSort(dsord,lord);
	tinsale = tinsale + InsertionSort(ale,lord);
	tbubord = tbubord + BubbleSort(ord,lord);
	tbubdsord = tbubdsord + BubbleSort(dsord,lord);
	tbubale = tbubale + BubbleSort(ale,lord);
	CopiaLista(ord,lord);
	tmerord = tmerord + MergeSort(lord,lord->inicio->pos,lord->fim->pos);
	CopiaLista(dsord,lord);
	tmerdsord = tmerdsord + MergeSort(lord,lord->inicio->pos,lord->fim->pos);
	CopiaLista(ale,lord);
	tmerale = tmerale + MergeSort(lord,lord->inicio->pos,lord->fim->pos);
		
		count++;
		
	
	}

	
	printf ("CONJUNTO ORDENADO:\n\n");
	printf ("Media InsertionSort: %d Milisegundos    Media BubbleSort: %d Milisegundos   Media MergeSort: %d Milisegundos\n\n",tinsord/repeticoes,tbubord/repeticoes,tmerord/repeticoes);
	
	printf ("CONJUNTO DESORDENADO:\n\n");
	printf ("Media InsertionSort: %d Milisegundos    Media BubbleSort: %d Milisegundos    Media MergeSort: %d Milisegundos\n\n",tinsdsord/repeticoes,tbubdsord/repeticoes,tmerdsord/repeticoes);
	
	printf ("CONJUNTO ALEATORIO:\n\n");
	printf ("Media InsertionSort: %d Milisegundos    Media BubbleSort: %d Milisegundos    Media MergeSort: %d Milisegundos\n\n",tinsale/repeticoes,tbubale/repeticoes,tmerale/repeticoes);
	
	
	
	return 0;
}

void Imprime (LISTA *L){
	
	NO *p;
	p = (NO*)malloc(sizeof(NO));
	p = L->inicio;
	while (p!=NULL){
		printf ("%d: %d\n",p->pos,p->info);
		p = p->prox;
	}
	
 	printf ("\n");	
}



