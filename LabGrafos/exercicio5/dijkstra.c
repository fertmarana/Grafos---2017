#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0
#define INT_MAX 9999
#include "item.h"
#include "heap_estatica.h"
#include "grafo.h"
#include "lista.h"

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
/*
int menorcaminho(LISTA *l,int *pai, int origem, int vertice){

	if(pai[vertice] == origem){
		
		coloca_primeiro(l, origem);
		
		return 1;
	} else if(pai[vertice] == -1){
		return 0;
	}
	
	int flag = menorcaminho(l,pai, origem, pai[vertice]);
	if(flag){
		
		coloca_atras(l, vertice);
		
	}
	return flag;

}
*/

int na_Fila(int tam, int *a, int valor){ //verifica se esta na lista
	int i;
	for(i = 0; i< tam; i++){
		if(a[i] == valor) return 1;

	}
return 0;


}



void dijkstra(GRAFOS *g, int origem, int destino){
	HEAP_ESTATICA *heap = criar_heap();
	int qtdd_adj = 0;
	int *A = NULL;
	int tam_a = 0;

	int u,i;
	int *pai = (int*)malloc(sizeof(int)*(g->nvertices)); //vetor que vai conter a posicao de seu pai
	int *d = (int*)malloc(sizeof(int)*(g->nvertices)); 
	/*
	Inicializando antecessor(u) como –1 (NIL) para todo u
	fp=V[G]
	*/
	for(i=0; i< g->nvertices;i++){
		pai[i]= -1;
		d[i] = 999999;
	} 
	pai[origem]= -2;	
	
	//Inicializa  peso(u) como INFINITO para todo u, exceto r

	for(i=0; i< g->nvertices;i++){ 
		enfileirar(heap, criar_item( 999999, i)); 
	}
	update(heap, 0, origem);
	d[origem] = 0;
	while(!vazia(heap)){ //enquanto nao passar por todos os vertices
		//retirando o vertice de menor peso da fila de prioridade
		ITEM * aux = desenfileirar(heap);
		u = aux->vertice;
		//printf("PAI: %d\n", u);
		//printf("PAI PESO: %d\n", aux->peso);
		//guardando o vertice retirado na lista fila
		A = (int*)realloc(A,sizeof(int)*(tam_a+1));
		A[tam_a] = u;
		tam_a++;

		int *adj = NULL;
		qtdd_adj = adjacentes(g, u, &adj); //chama a funcao que cria um vetor de vertices que sao adjacentes ao vertice da variavel valor
		for(i=0; i<qtdd_adj;i++){
			int filho = adj[i];  
			int wzinho = w(u,filho,g) ;
			//int cost = getCost(heap,u); 
			//printf("D[U]: %d\n", d[u]);
			if(na_Fila(tam_a,A,filho)== 0 && d[filho] > d[u] + wzinho){
					d[filho] = d[u] + wzinho;
					pai[filho] = u; //seta novo pai	
					update(heap, d[filho], filho); //atualiza
					
			}
		}
		free(adj);
		apagar_item(&aux);
		
	}
	free(heap);
   //	printf("TERMINOUUUUU\n");
	/*
	printf("criou lista\n");
	menorcaminho(l, pai, origem, destino);
	while(!vazio(l)){
		printf("%d ", frente(l));
		retira_frente(l);
	}*/
	int dest= destino;
	LISTA *l = criar_lista();
	
	coloca_primeiro_lista(l, dest);
	
	while(pai[dest] != -2 && pai[dest] != -1){
		coloca_frente_lista(l, pai[dest]);
		dest =  pai[dest];
	}
	
	if(pai[dest] == -2) imprimir_lista(l);
	
	printf("\n");
	free(A);
}