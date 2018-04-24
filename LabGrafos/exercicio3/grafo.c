/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"
/*Funcao que criará um grafo e uma matriz com n vertices e n arestas.*/
GRAFOS *criar_grafo(int vertices, int arestas){
	GRAFOS *g = (GRAFOS*)malloc(sizeof(GRAFOS));
	g->nvertices = vertices;
	g->narestas = arestas;
	criar_matriz(g);
	

	return g;

}

/*Funcao que criará uma matriz e setará os valores para -1.*/
 void criar_matriz(GRAFOS *g){ 
 	g->matriz = (int**)malloc(sizeof(int*)*(g->nvertices));
 	int i = 0;
 	int j;
 	for(i = 0; i< g->nvertices; i++){
 		j = 0;
 		g->matriz[i] = (int*)malloc(sizeof(int)*(g->nvertices));
 		for(j=0; j< g->nvertices;j++){
 			g->matriz[i][j] = -1;
 		}
 	}

}
 	/*Funcao que adicionara um outro vertice a matriz.*/
void aa_x_y_p_matriz(int x, int y, int peso, GRAFOS **g){
	if(peso < 0) return; //caso queira-se adicionar um peso invalido, retorna sem fazer nada
	(*g)->matriz[x][y] = peso; //se for direcionado so ocorre uma vez
	return;
}
/*Funcao que apenas imprime a matriz. Foi usada apenas para auxiliar no exercicio*/
void ig( GRAFOS *g){
	
		int i, j;
		for(i=0; i<g->nvertices; i++){
				printf("%d: ", i);
			for(j=0; j<g->nvertices; j++){

				if(g->matriz[i][j] != -1) {printf("%d ", g->matriz[i][j] );}
				else{ printf(". "); }
			}
			printf("\n");
		}
	
}
/*Funcao que ira desalocar a matriz enviada como argumento de tamanho v*/
void apagar_matriz(int **m, int v){
	int i;
	for(i=0;i<v; i++){
		free(m[i]);
		}
		free(m);
	}
/*Funcao que ira apagar a matriz e/ou a lista e desalocar a struct GRAFOS*/
void free_grafo(GRAFOS *g){
	if(g->matriz != NULL)apagar_matriz((g->matriz), g->nvertices);
	free(g);
}
