#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "lista.h"
#include "matriz.h"


/*Funcao que ira imprimir vértices adjacentes ao vértice X.*/
void va_x_matriz(int x, GRAFOS *g){
	int i;
	//a partir do x dado, le-se toda fileira de nvertices inteiros
	for(i = 0; i< g->nvertices; i++){
		//mas so imprime aqueles que cujo peso nao eh -1
		if(g->matriz[x][i] >= 0) printf("%d ", i);
	}

	printf("\n");


}
/*Funcao que adicionara um outro vertice a lista.*/
void aa_x_y_p_matriz(int x, int y, int peso, GRAFOS **g){
	if(peso < 0) return; //caso queira-se adicionar um peso invalido, retorna sem fazer nada
	if((*g)->direcionado == 1){(*g)->matriz[x][y] = peso; } //se for direcionado so ocorre uma vez
	else { //se nao for ocorre duas vezes trocando o x pelo y e o y pelo x na segunda vez
		(*g)->matriz[x][y] = peso;
		(*g)->matriz[y][x] = peso;
	}
}

/*Funcao para remover aresta entre os vértices X e Y;*/
void ra_x_y_matriz(int x, int y, GRAFOS** g){
	//seta-se o peso para -1
	if((*g)->direcionado == 1){(*g)->matriz[x][y] = -1;} //se for direcionado so ocorre uma vez
	else { //se nao for ocorre duas vezes trocando o x pelo y e o y pelo x na segunda vez
		(*g)->matriz[x][y] = -1;
		(*g)->matriz[y][x] = -1;
	}

}





/*Funcao que imprime a transposta de uma lista*/
void it_matriz(GRAFOS *g){
		int i, j;
		for(i=0; i<g->nvertices; i++){
			for(j=0; j<g->nvertices; j++){
				if(g->matriz[j][i] >= 0)printf("%d ", g->matriz[j][i] );
				else printf(". ");
			}
			printf("\n");
		}

}
/*Funcao que acha o menor inteiro de uma lista que esteja numa posicao valida e a imprima*/
void mp_matriz(GRAFOS *g){
	int menor = INT_MAX;
	int i, j,si = 0, sj = 0;
	
	//percorre-se toda matriz a procura de um valor menor que a variavel menor determinada 
	for(i=0; i< g->nvertices; i++){
		for(j=0; j< g->nvertices; j++){
			if(g->matriz[i][j] < menor && g->matriz[i][j]>=0){ //caso ache
				menor = g->matriz[i][j]; //menor recebe o novo valor de peso
				si = i; //salva-se as posicao i
				sj = j; //salva-se a posicao j
			}
		}
	}
	if(si > sj){
		printf("%d %d\n", sj, si );
	} else
	{
	printf("%d %d\n", si, sj );
}
}

/*Funcao para alocar a matriz e setar seus valores para -1 inicialmente*/
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
/*Funcao para ler uma string*/
 char *readLine(){
 	char c, *string = NULL;
 	int counter = 0;
 	do {
 		c = fgetc(stdin);
 		string = (char *)realloc(string, sizeof(char)*counter+1);
 		string[counter++] = c;

 	} while (c != 10 && c != 11 && c!= 12 && c != 13 && c!= EOF);
 	string[counter-1] = '\0';
 	return string;
 }

