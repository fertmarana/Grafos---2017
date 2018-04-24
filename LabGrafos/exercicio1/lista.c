#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "lista.h"

/*Funcao que ira desalocar a lista enviada como argumento de tamanho tam*/
void apagar_lista(VERTICE **lista, int tam){ 
	VERTICE *remo,*raux;
	int i;
	for(i=0; i< tam; i++){
		raux = lista[i];
		while(raux != NULL){
			remo = raux;
			raux = raux->proximo;
			free(remo);
		}

	}
	
	free(lista);
	

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
	else if(g->lista!= NULL)apagar_lista((g->lista), g->nvertices);
	free(g);
}

/*Funcao que ira imprimir a matriz ou a lista a partir do argumento ehmatriz
se ehmatriz == 1 => imprime a matriz
se ehmatriz == 0 => imprime a lista
*/
void ig(int ehmatriz, GRAFOS *g){
	if(ehmatriz == 1){
		int i, j;
		for(i=0; i<g->nvertices; i++){
			for(j=0; j<g->nvertices; j++){
				if(g->matriz[i][j] != -1) {printf("%d ", g->matriz[i][j] );}
				else{ printf(". "); }
			}
			printf("\n");
		}
	}else{
		int i;
		VERTICE *p;
		for(i=0; i< g->nvertices; i++){
			printf("%d. ", i);
			p =  g->lista[i];
			while(p!=NULL){
				if(p->vertice >=0){
					if(p->peso != -1) printf("%d(%d) ",p->vertice, p->peso);
					else { printf(". ");}
				}
				p= p->proximo;
			}
			printf("\n");
			
		}
		
		return;
	}
	
}
/*Funcao que ira alocar a struct GRAFOS e setar os seus valores inteiros*/
GRAFOS *criar_grafo(char d, int vertices, int arestas){
	GRAFOS *g = (GRAFOS*)malloc(sizeof(GRAFOS));
	if(d == 'D') {
		g->direcionado = 1;
	}else {
		g->direcionado = 0;
	} 
	g->nvertices = vertices;
	g->narestas = arestas;

	return g;

}
/*Funcao que ira alocar uma lista. Cria-se um vetor que tera seu vertice e peso negativos, nao contando assim
como validos nas outras operacoes. Cada posicao desse vetor de struct VERTICES tera seu ponteiro proximo apontando para NULL*/
void criar_lista(GRAFOS *g){
	g->lista = (VERTICE**)malloc(sizeof(VERTICE*)*(g->nvertices));
	int i = 0;
	for(i=0; i< (g->nvertices); i++){
		g->lista[i] = (VERTICE*)malloc(sizeof(VERTICE));
		g->lista[i]->peso = -2;
		g->lista[i]->vertice = -1;
		g->lista[i]->proximo = NULL;
	}

	return;

		}
/*Funcao que alocará a struct VERTICE e irá setar suas variaveis*/
VERTICE *criar_vertice(int peso, int vertice){
	VERTICE *v = (VERTICE*)malloc(sizeof(VERTICE));
	v->proximo = NULL;
	v->vertice = vertice;
	v->peso = peso;
	return v;

}
/*Funcao que ira adicionar numa lista um novo vertice.
Cria-se um vertice novo e procura a posicao que ele ira ser inserido de forma
que os vertices fiquem organizados de forma crescente para facilitar em outras
operacoes*/
void add_conexao(GRAFOS *g, int v1, int v2, int p){
	VERTICE *novo = criar_vertice(p,v2);
	VERTICE *aux = g->lista[v1];
	
	if(aux->proximo == NULL){ //se novo for o primeiro vertice valido
		g->lista[v1]->proximo = novo; //so adiciona ele
	} else{//caso contrario
		VERTICE *antes = aux;
		while(aux != NULL && novo->vertice > aux->vertice){ //loop ate que aux fique entre um numero menor que ele e/ou um numero maior que ele
			antes = aux; 
			aux = aux->proximo;
		}
		if(aux == NULL){ //se for NULL quer dizer que ele sera o ultimo vertice a ser add
			antes->proximo = novo;
			novo->proximo = aux;
		}else { //se nao for, ele esta entre um numero menor que ele e outro maior que ele
			if(novo->vertice == aux->vertice){
				aux->peso = novo->peso;
				free(novo);
			}else{
				antes->proximo = novo;
			novo->proximo = aux;
			}
		}
			
	}

}
/*Funcao que ira imprimir vértices adjacentes ao vértice X. 
Como os vertices ja estao em ordem crescente apenas passa-se o x
e imprime a posicao g->lista[x];*/
void va_x_lista(int vertice,GRAFOS *g){
	VERTICE *paux = g->lista[vertice];

	while (paux != NULL){
		
		if(paux->vertice >=0) printf("%d ", paux->vertice);
		paux=paux->proximo;
	}

	printf("\n");
}
/*Funcao que adicionara um outro vertice a lista. Chama a funcao add_conexao*/
void aa_x_y_p_lista(int x,int y,int p,GRAFOS *g){
	add_conexao(g,x,y,p);
	return;
}
/*FUNCAO que ira remover um vertice da lista.
Procura-se o ponteiro a ser removido e manipula-se os ponteiros ao redor dele
de maneira que quando der o free nao acha Falha de Segmentação*/
void ra_x_y_lista(int x, int y, GRAFOS* g){
	VERTICE *paux = g->lista[x];
	VERTICE *pantes = paux;
	if(paux->proximo == NULL) return; 
	if(paux->proximo->vertice == y){ //se ja no primeiro vertice valido encontrar o y
		//faz a manipulacao de ponteiros
		paux = paux->proximo;
		g->lista[x]->proximo = paux->proximo;
		paux->proximo = NULL;
		free(paux); //desaloca o ponteiro
		return;
	}
	//se nao achar ja no primeiro vertice valido
	while(paux != NULL && paux->vertice != y){ //ocorre um loop ate achar ou ate acabarem os vertices
		pantes=paux;
		paux = paux->proximo;
	}
	if(paux == NULL) return; //se acabarem os vertices, nao há nada para se remover
	//caso contrario, novamente ha a manipulacao de ponteiros
	pantes->proximo = paux->proximo;
	paux->proximo = NULL;
	free(paux);
	return;


	}
/*Funcao que acha o menor inteiro de uma lista que esteja numa posicao valida e a imprima*/
void mp_lista(GRAFOS *g){
	VERTICE *menor = criar_vertice(INT_MAX,-1); //cria-se um vertice menor cujo peso sera INT_MAX e o vertice -1
	int i,si= -1;
	VERTICE *paux = NULL;
	
	for(i=0; i< g->nvertices; i++){
		paux = g->lista[i];
		while(paux != NULL){ 
			if(paux->peso < menor->peso  && paux->peso>=0 && paux->vertice >=0){ //se achou algum vertice com peso menor troca-se o peso e o vertice da struct VERTICE menor
				menor->vertice = paux->vertice;
				menor->peso = paux->peso;
				si = i;	//serve para armazena a aresta
				
			}
		paux = paux->proximo;
		}
		
	}
	
	if(g->direcionado == 0){
		if(si > menor->vertice){
			printf("%d %d\n", menor->vertice, si );
		} else{
		printf("%d %d\n", si, menor->vertice );
	}
	}else{
		printf("%d %d\n", si, menor->vertice );
	}	

	free(menor);
}
/*Funcao que imprime a transposta de uma lista*/
void it_lista(GRAFOS* g){
	GRAFOS *novo = criar_grafo('D',g->nvertices, g->narestas); //cria-se um novo grafo
	criar_lista(novo); //cria-se uma nova lista desse novo grafo
	int i;
	VERTICE *paux = NULL;
	for(i=0; i< g->nvertices; i++){ //percorre todos os nvertices do grafo original
		paux = g->lista[i]; //comeca-se sempre do vertice -1 
		while(paux != NULL){ 
			//se houver um vertice valido, chama-se a funcao para adicionar um vertice ao grafo novo, mas dessa vez substituindo 
			//a posicao onde eh o x do grafo original pelo y desse grafo original
			//e a posicao de onde eh o y do grafo original pelo x dele mesmo
			if(paux->vertice >=0) add_conexao(novo,paux->vertice,i,paux->peso);
			paux = paux->proximo; //vai para o proximo vertice
		}

	}
	ig(0,novo); //imprime essa lista nova formada
	apagar_lista(novo->lista,novo->nvertices); //chama a funcao para apaga-la
	free(novo); //desaloca o grafo novo



}

