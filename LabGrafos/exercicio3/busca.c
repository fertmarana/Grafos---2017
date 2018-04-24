/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"
#include "lista.h"
#define BRANCO 0
#define PRETO 1

int procura_vertices_adjacentes(GRAFOS *g, int valor, int **adj){ 
	int i;
	int *vetor = NULL; //vetor que vai falar quais vertices dos n vertices tem o vertice valor apontando para eles
	int contador = 0; //conta quantas posicoes foram alocadas no vetor

	for(i=0; i<g->nvertices; i++){ //loop que ocorre ate percorrer todas as posicoes do vertice
		if(g->matriz[valor][i] != -1){ //se linha valor e na coluna -1 da matriz nao for -1
			//isso mostra que o vertice valor aponta para o vertice i
			vetor = (int*)realloc(vetor,sizeof(int)*(contador+1)); //aumenta-se o tamanho do vetor
			vetor[contador] = i; //e coloca na ultima posicao alocada o numero da coluna
			contador++; //aumenta-se o tamanho do contador
		}
	}
	(*adj) = vetor; //vetor adj recebe o vetor criado
	
	return contador;  //retorna o contador


}
/*Funcao que imprime o primeiro caminho percorrido ate achar o vvertice procurado
Na primeira recursao, sera enviado como argumento o vertice procurado. Entao sera procurado quem eg seu vertice pai.
Achando ele, procura-se quem é seu vertice pai e assim por diante até chegar no vertice de partida.
Quando a funcao retornar será imprimido certinho o caminho comecando da origem ate o destino. 
*/
void imprime(int filho, int *pai){
	
	if(pai[filho] != -1){ 
		imprime(pai[filho],pai);
	}
	printf("%d ", filho);

	return;

}






/*Funcao auxiliar usada para criar o caminho de um vertice ate o outro**/
void busca_em_prof_aux(GRAFOS *g, int *pai, int *cor, int valor, LISTA *lista){
	int i;
	int *adj = NULL;
	int qtdd_adj = 0;
 	qtdd_adj = procura_vertices_adjacentes(g, valor, &adj); //o tamanho de vertices adjacentes eh obtido chamando essa funcao
	//o vetor adj tambem eh alterado pela funcao adjacentes
	

	cor[valor] = PRETO; //a cor do valor eh pintada de preto

	for(i=0; i<qtdd_adj;i++){ //loop ocorre ate chegar no fim do vetor adj
		int filho = adj[i]; // variavel filho recebe o vertice que se esta trabalhando na posicao i do vetor que tem todos os vertices que o vertice valor aponta
		if(cor[filho]!=PRETO){ // se o filho nao foi visitado ainda ele sera, se ja foi sera ignorado
			pai[filho] = valor; //no vetor pai na posicao que esta o filho, recebera o vertice valor como sendo seu pai
			busca_em_prof_aux(g,pai,cor,filho,lista); // realiza-se novamente a chamada da mesma funcao
		}

	}

	//colocando o vertice processado na pilha
	if(vazio(lista)) coloca_primeiro(lista,valor); 
	else coloca_frente(lista, valor); 
	
	if(adj!= NULL || qtdd_adj == 0) free(adj);
	
}


/*Funcao usada para criar o caminho de um vertice ate o outro*/
void busca_em_prof(GRAFOS *g,int origem, int *pai, int *cor, LISTA *list){  //recebe o valor que parte o grafo e recebe o valor destino esperado

	busca_em_prof_aux(g, pai, cor, origem,list); //faz a busca em profundidade recursiva
	
	
}
