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
#include "ordenacao.h"


int main(){
	int narestas, nvertices,origem,destino;
	int i=0;
	scanf("%d%*c",&nvertices);
	scanf("%d%*c",&narestas);
	GRAFOS *g = criar_grafo(nvertices, narestas); // cria o grafo e a matriz com nvertices e narestas


	while (i < narestas ){
		scanf("%d%*c",&origem); //le o numero de origem
		scanf("%d%*c",&destino); //le o numero que o numero de origem aponta
		aa_x_y_p_matriz(origem,destino,1, &g); //adiciona na linha origem e na coluna destino o valor 1 que dize que tem relacao
		i++;
	}
	//realiza a ordenacao topologia
	ordenacao(g);


	free_grafo(g); //libera o grafo



}