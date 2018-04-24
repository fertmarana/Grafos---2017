#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"
#include "heap_estatica.h"



int adjacentes(GRAFOS *g, int valor, int **adj){
	int i;
	int *vetor = NULL;//vetor que vai falar quais vertices dos n vertices tem o vertice valor apontando para eles
	int contador = 0; //conta quantas posicoes foram alocadas no vetor
	

	for(i=0; i<g->nvertices; i++){ //loop que ocorre ate percorrer todas as posicoes do vertice
		if(g->matriz[valor][i] != -1){ //se linha valor e na coluna -1 da matriz nao for -1
			//isso mostra que o vertice valor aponta para o vertice i
			vetor = (int*)realloc(vetor,sizeof(int)*(contador+1)); //aumenta-se o tamanho do vetor
			vetor[contador] = i; //e coloca na ultima posicao alocada o numero da coluna
			contador++; //aumenta-se o tamanho do contador
		}
	}
	(*adj) = vetor;

	return contador;
}





int na_Fila(int tam, int *a, int valor){
	int i;
	for(i = 0; i< tam; i++){
		if(a[i] == valor) return 1;

	}
return 0;


}


void prim_tree(GRAFOS *g, int origem){
/*
Inicialize a fila de Prioridades fp com todos os nós 
exceto r
Inicializa  peso(u) como INFINITO para todo u, exceto r
Inicializa  peso(r) como 0
*/
HEAP_ESTATICA *heap = criar_heap(g->nvertices);

int qtdd_adj = 0;
//LISTA *lista = criar();
//printf("Criou lista\n");
/*
Inicialize antecessor(u) como –1 (NIL) para todo u
%fp=V[G]
*/
ITEM * aux;
int u,i;
int *pai = (int*)malloc(sizeof(int)*(g->nvertices)); //vetor que vai conter a posicao de seu pai
for(i=0; i< g->nvertices;i++) pai[i]= -1;
	//printf("setou pai\n");

for(i=0; i< g->nvertices;i++){ 
	 
	enfileirar(heap, criar_item( 9999, i)); 
	
	
}
update(heap, 0, 0);
//printf("enfileirou\n");

int *A = NULL;
int tam_a = 0;


	while(!vazia(heap)){
	//	printf("desenfileirando\n");
		aux = desenfileirar(heap);
		u = aux->vertice;
		
		A = (int*)realloc(A,sizeof(int)*(tam_a+1));
		A[tam_a] = u;
		tam_a++;

		int *adj = NULL;
		qtdd_adj = adjacentes(g, u, &adj); //chama a funcao que cria um vetor de vertices que sao adjacentes ao vertice da variavel valor
		for(i=0; i<qtdd_adj;i++){
			int filho = adj[i]; 
			int wzinho = w(u,filho,g) ;
			int cost = getCost(heap,filho);
			
			if(na_Fila(tam_a,A,filho)== 0 && wzinho < cost && cost != -1){
				
				update(heap, wzinho, filho);
				pai[filho] = u;
				
			
				
			}
		

		}
		
		
	}

	int j;
	for(j=1; j< tam_a; j++){
		if( pai[A[j]] <  A[j]) printf("(%d,%d) ", pai[A[j]], A[j]);
		else printf("(%d,%d) ", A[j], pai[A[j]]);
	}
	printf("\n");



}