/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"
#include "fila.h"
#define BRANCO 0
#define PRETO 1
/*Funcao que imprime o primeiro caminho percorrido ate achar o vvertice procurado
Na primeira recursao, sera enviado como argumento o vertice procurado. Entao sera procurado quem eg seu vertice pai.
Achando ele, procura-se quem é seu vertice pai e assim por diante até chegar no vertice de partida.
Quando a funcao retornar será imprimido certinho o caminho comecando da origem ate o destino. 
*/
void imprime_primeiro_caminho_encontrada(int filho, int *pai){
	
	if(pai[filho] != -1){
		imprime_primeiro_caminho_encontrada(pai[filho],pai);
	}
	printf("%d ", filho);

	return;

}

int procura_vertices_adjacentes(GRAFOS *g, int valor, int **adj){
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




void busca_largura(GRAFOS *g,int origem, int destino){
	FILA *fila = criar_fila(); //cria uma fila

	int qtdd_adj = 0; // vai contar a quantidade de vertices em que um determinado valor aponta
	int i;
	int *cor = (int*)malloc(sizeof(int)*(g->nvertices)); //vetor que fala quais vertices ja foram visitados pela cor
	for(i=0; i< g->nvertices;i++) cor[i]= BRANCO; // seta todos os vertices em branco inicialmente
	int *pai = (int*)malloc(sizeof(int)*(g->nvertices)); //vetor que vai conter a posicao de seu pai
	//por exemplo se 2 for o pai de 1  e se o 1 n ter pai na posicao 2 estara o numero 1 e na posicao 1 estara -1
	for(i=0; i< g->nvertices;i++) pai[i]= -1;  //seta todos as posicoes apontando para uma posicao invalida

		cor[origem] = PRETO; // a cor do primeiro vertice fica preta para indicar que ele ja foi visitado
		enfileirar(fila,origem); //coloca a origem na fila
		
		while(fila->tamanho > 0){ // loop que ocorre ate a fila se esvaziar por completo
	
			int valor = desenfileirar(fila); // tira o primeiro valor da fila e guarda o seu numero na variavel valor
				if(valor != -1){
				int *adj = NULL;
				qtdd_adj = procura_vertices_adjacentes(g, valor, &adj); //chama a funcao que cria um vetor de vertices que sao adjacentes ao vertice da variavel valor
			
				for(i=0; i<qtdd_adj;i++){
						int filho = adj[i]; //variavel filho recebe o vertice na posicao i do vetor
					
						if(cor[filho]!=PRETO){ //se o vertice ainda nao foi visitado ele sera, caso contrario ele sera ignorado
							
							pai[filho] = valor; //guarda na posicao desse vertice seu pai que eh o vertice com valor
							cor[filho] = PRETO; // seta o vertice como visitado pela cor preta
							enfileirar(fila,filho); //coloca o filho na fila
							
						}
					}
					free(adj); 
					qtdd_adj = 0;
				}
		}
		
		if(cor[destino] != BRANCO) imprime_primeiro_caminho_encontrada(destino, pai); //se a cor do vertice procurado foi procurada chama funcao para imprimir o caminho
		printf("\n");
		free(cor);
		free(pai);
		apagar_fila(fila);
			return;
}