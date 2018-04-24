#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matriz.h"
#include "lista.h"

int main(){
	char direcionado; //variavel que vai armazenar G ou D
	char loum; // variavel que vai armazenar L ou M
	int vertices, arestas; //variaveis que vao armazenar a quantidade de vertices e arestas
	
	scanf("%c%*c%c", &direcionado, &loum); //le G ou D e L ou M

	scanf("%d%*c", &vertices);
	scanf("%d%*c", &arestas);

	GRAFOS* g = criar_grafo(direcionado,vertices,arestas);//chamada da funcao para alocar o grafo


	if(loum == 'L'){ //se for uma lista
		int contador;
		int v,a;
		int p;
		//chamada da funcao para alocar a lista
		criar_lista(g);
				g->matriz = NULL;
		//chamada de loop para ler n vezes	
		for( contador = 0; contador< g->narestas; contador++){

				scanf("%d", &a); //le a aresta
				scanf("%d", &v); //le o vertice
				scanf("%d", &p); //le o peso
				if(a < g->nvertices) { // se a aresta lida for menor que o maximo de aresta
					add_conexao(g,a,v,p); //adiciona o vertice a lista na posicao a
					if(direcionado != 'D'){ //e se nao for direcionado
				  		add_conexao(g,v,a,p); //adiciona o vertice a lista na posicao v
					}
				}	
			}
			char op[30];
			char c;
			while(scanf("%s", op) != EOF){ //enquanto a chamada da funcao nao termina
				 //se a operacao pedida for
				if(strcmp(op ,"IG")==0){ //IG => vai imprimir a lista
				ig(0, g);
				}else if(strcmp(op, "VA")==0){ //VA => vai imprimir vértices adjacentes ao vértice X 
					int vertice; //variavel que vai pedir o X
				scanf("%d%*c", &vertice); //lendo a variavel
				//chamada da funcao para imprimir vértices adjacentes ao vértice X (
				va_x_lista(vertice,g);
				} else if(strcmp(op , "AA")==0){// AA=> adicionar aresta entre os vértices X e Y com peso P
				scanf("%c",&c); 
				int x,y,peso; //variavel
				scanf("%d%*c",&x); //lendo x
				scanf("%d%*c",&y); //lendo y
				scanf("%d%*c", &peso); //lendo peso
				//chamada da funcao para adicionar aresta entre os vértices X e Y com peso P
				aa_x_y_p_lista(x, y, peso,g);
				if(direcionado != 'D' ) aa_x_y_p_lista(y, x, peso,g); //se nao for direcionado, deve-se fazer de novo a chamada para adicionar aresta entre os vértices Y e X com peso P
				} else if(strcmp(op, "RA")==0){ // RA => remover aresta entre os vértices X e Y
					scanf("%c",&c);
					int x,y;
					scanf("%d%*c",&x); //lendo x
					scanf("%d%*c",&y); //lendo y
					ra_x_y_lista(x,y, g); //chamada da funcao para remover aresta entre os vértices X e Y
					if(direcionado != 'D' ) ra_x_y_lista(y,x, g); //se nao for direcionado, deve-se fazer de novo a chamada para remover aresta entre os vértices X e Y
					
				}else if(strcmp(op,"IT")==0){ //IT => imprimir a transposta da lista original
					if(direcionado == 'D') it_lista(g); //so ocorre a chamada se for direcionado
					
				} else if(strcmp(op,"MP")==0){ //MP => imprimir aresta com menor peso 
					
					mp_lista(g); //chamada da funcao para imprimir aresta com menor peso
					scanf("%c",&c);
					
				} else{ //caso leia outra coisa
					printf("Digite novamente.\n"); 
				}
		}

	} else {
		g->lista = NULL;
		int contador;
		int v,a;
		int p;
		criar_matriz(g);
		
			for( contador = 0; contador< g->narestas; contador++){
				scanf("%d%*c", &a);
				scanf("%d%*c", &v);
				scanf("%d%*c", &p);
				g->matriz[a][v] = p;

				if(direcionado != 'D'){
					g->matriz[v][a] = p;
				}	
			}
	
		char op[30];
		char c;
	
		while(scanf("%s", op) != EOF){//enquanto a chamada da funcao nao termina
				 //se a operacao pedida for
		if(strcmp(op ,"IG")==0){  //IG => vai imprimir a lista
		
			ig(1, g);
			
		}else if(strcmp(op, "VA")==0){ //VA => vai imprimir vértices adjacentes ao vértice X 
			int vertice; //variavel que vai pedir o X
			scanf("%d%*c", &vertice);//lendo a variavel
				//chamada da funcao para imprimir vértices adjacentes ao vértice X 
			va_x_matriz(vertice,g);
		} else if(strcmp(op , "AA")==0){ // AA=> adicionar aresta entre os vértices X e Y com peso P
			scanf("%c",&c);
			int x,y,peso;
			scanf("%d%*c",&x);
			scanf("%d%*c",&y);
			scanf("%d%*c", &peso);

			 aa_x_y_p_matriz(x, y, peso,&g);
		
		} else if(strcmp(op, "RA")==0){
			scanf("%c",&c);
			int x,y;
			scanf("%d%*c",&x);
			scanf("%d%*c",&y);
			ra_x_y_matriz(x,y, &g); //chamada da funcao para remover aresta entre os vértices X e Y

		} else if(strcmp(op,"IT")==0){ //IT => imprimir a transposta da lista original
	 		if(direcionado == 'D') it_matriz(g); //so ocorre a chamada se for um digrafo
	 		scanf("%c",&c);
		} else if(strcmp(op,"MP")==0){  //MP => imprimir aresta com menor peso 
			mp_matriz(g);
			scanf("%c",&c);
		} 
		
}
	}


	free_grafo(g); //desalocando o grafo
	



	}

