/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"
#include "busca.h"
#include "lista.h"
#define BRANCO 0
#define PRETO 1

/*Funcao responsável por criar a ordenação topológia do vertices digitados*/
void ordenacao(GRAFOS *g){
	int *cor = (int*)malloc(sizeof(int)*(g->nvertices)); //vetor que vai falar se ja foi visitado
	int *pai = (int*)malloc(sizeof(int)*(g->nvertices)); //vetor que vai conter a posicao de seu pai
	LISTA *lista = criar(); //cria a lista
		int i;
	for(i=0; i< g->nvertices;i++) cor[i]= BRANCO; //seta todo vetor para cor BRANCA
	for(i=0; i< g->nvertices;i++) pai[i]= -1;  //seta todos as posicoes apontando para uma posicao invalida

	

	for(i=0; i< g->nvertices;i++) { //percorre todos os vertices
		if(cor[i] != PRETO) { // se o vertice ainda nao foi processado
			busca_em_prof(g,i,pai, cor, lista); //realiza a busca em profundidade comecando dele
		}
		
}
	imprimir(lista); //imprime a lista
	printf("\n");

	//liberando a memoria ocupada
	 free(cor);
	 free(pai);
	 destruir(lista);
	 

}

