#include "tadarvore.h"


/*
	Autores:
	Alex Galhardo
	Numero USP: 10408344
	Ian Castilho Caldeira Brant
	Numero USP: 10133967
	ICMC USP - São Carlos 2017
*/


// OBS: OS CODIGOS DE INSERCAO EM AVL FORAM FEITOS PELO PROFESSOR EM AULA. NAO CONSEGUIMOS IMPLEMENTAR O NOSSO PROPRIO CODIGO DE INSERCAO AVL, POR ISSO
// USAMOS OS QUE FORAM DISPONIBILIZADOS

void imprimir(NO *p);
void imprimirstring(char *v);
int EstaOrdenado(char *v);

int main(){
	
	char entrada[100],*ordem,*preordem,*posordem; // ordem, preordem e posordem sao os vetores onde serao armazenados os elementos em ordem, preordem e posordem
	int i,l,q,j=0; // i e j: variaveis de contagem ; l:tamanho da string de entrada; q: irah armazenar a quantidade de nos da arvore
	ARVORE *a,*avl;
	
	a = (ARVORE*)malloc(sizeof(ARVORE));
	CriaArvore(a);
	
	avl = (ARVORE*)malloc(sizeof(ARVORE));
	CriaArvore(avl);
	
	printf ("Digite a String com a entrada dos dados:\n");
	scanf ("%[^\n]s",entrada);
	
	l = strlen(entrada); // tamanho da string de entrada
	
	for (i=0;i<l;i++){ // insercao em largura de cada elemento da string
		InsereLargura(a,entrada[i],i);
	}
	
	for (i=0;i<l;i++){ // insercao AVL de cada elemento da string
		if (entrada[i]!=32){
			InsereAvl(&avl->raiz, &entrada[i]);
		}
		
	}
	
	q = QtdNos(a->raiz);
	
	
	
	ordem = (char*)malloc(q*sizeof(char));
	preordem = (char*)malloc(q*sizeof(char));
	posordem = (char*)malloc(q*sizeof(char));
	
	
	
	PreOrdem(a->raiz,preordem,&j); // armazenamento dos dados em preordem
	preordem[j]='\0';
	j = 0;
	PosOrdem(a->raiz,posordem,&j); // armazenamento dos dados em posordem
	posordem[j]='\0';
	j = 0;
	Ordem(a->raiz,ordem,&j); // armazenamento dos dados em ordem
	ordem[j]='\0';

	
	printf ("\nArvore Original completa:\n\n");
	imprimir(a->raiz);
	printf ("\n\n");
	
	printf ("Altura da Arvore: %d\n",Altura(a->raiz));
	printf ("\n");
	printf ("Quantidade de NOS folha: %d\n",QtdFolha(a->raiz));
	printf ("\n");
	printf ("Eh uma Arvore cheia:");
	if (EhCheia(a->raiz)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");
	printf ("\n");
	
	printf ("Eh uma Arvore Binaria de Busca:");
	if (EhBst(a->raiz)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");
	printf ("\n");
	
	
	printf ("Eh uma Arvore AVL:");
	if (EhAvl(a->raiz)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");
	printf ("\n");
	
	printf ("Os elementos ficam ordenados se apresentados em Pre-ordem:");
	if (EstaOrdenado(preordem)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");	
	imprimirstring(preordem);
	printf ("\n");
	
	printf ("Os elementos ficam ordenados se apresentados em ordem:");
	if (EstaOrdenado(ordem)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");	
	imprimirstring(ordem);
	printf ("\n");
	
	printf ("Os elementos ficam ordenados se apresentados em Pos-ordem:");
	if (EstaOrdenado(posordem)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");	
	imprimirstring(posordem);
	printf ("\n\n\n");

	j = 0;
	PreOrdem(avl->raiz,preordem,&j);
	preordem[j]='\0';
	j = 0;
	PosOrdem(avl->raiz,posordem,&j);
	posordem[j]='\0';
	j = 0;
	Ordem(avl->raiz,ordem,&j);
	ordem[j]='\0';
	
	
	printf ("\nArvore AVL:\n\n");
	imprimir(avl->raiz);
	printf ("\n\n");
	
	printf ("Altura da Arvore: %d\n",Altura(avl->raiz));
	printf ("\n");
	printf ("Quantidade de NOS folha: %d\n",QtdFolha(avl->raiz));
	printf ("\n");
	printf ("Eh uma Arvore cheia:");
	if (EhCheia(avl->raiz)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");
	printf ("\n");
	
	printf ("Eh uma Arvore Binaria de Busca:");
	if (EhBst(avl->raiz)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");
	printf ("\n");
	
	
	printf ("Eh uma Arvore AVL:");
	if (EhAvl(avl->raiz)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");
	printf ("\n");
	
	printf ("Os elementos ficam ordenados se apresentados em Pre-ordem:");
	if (EstaOrdenado(preordem)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");	
	imprimirstring(preordem);
	printf ("\n");
	
	printf ("Os elementos ficam ordenados se apresentados em ordem:");
	if (EstaOrdenado(ordem)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");	
	imprimirstring(ordem);
	printf ("\n");
	
	printf ("Os elementos ficam ordenados se apresentados em Pos-ordem:");
	if (EstaOrdenado(posordem)==1){
		printf (" SIM\n");
	} else printf (" NAO\n");	
	imprimirstring(posordem);
	printf ("\n");
	
	return 0;
}

void imprimir(NO *p) {
     if (p!=NULL) {
        printf("%c(",p->info);
        imprimir(p->esq);
        printf(",");
        imprimir(p->dir);
        printf(")");
     }
    else printf("null");
     
}

void imprimirstring(char *v){
	
	
	int l,i;
	l = strlen(v);
	printf ("%c",v[0]);
	for (i=1;i<l;i++){
		printf (" %c",v[i]);
	}
	printf ("\n");
}

int EstaOrdenado(char *v){
	
	int l,i;
	l = strlen(v);
	
	for (i=0;i<l-1;i++){
		
		if (v[i]>v[i+1]){
			return 0;
		}
		
	}
	return 1;
	
}

