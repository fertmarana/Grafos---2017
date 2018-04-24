/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#ifndef _GRAFO_H_
#define _GRAFO_H_

typedef struct GRAFOS GRAFOS;
typedef struct VERTICE VERTICE;

struct GRAFOS
{
	
	int **matriz;
	int nvertices;
	int narestas;
};

GRAFOS *criar_grafo(int vertices, int arestas);
void criar_matriz(GRAFOS *g);
void aa_x_y_p_matriz(int x, int y, int peso, GRAFOS **g);
void ig( GRAFOS *g);
void free_grafo(GRAFOS *g);
void apagar_matriz(int **m, int v);
int w(int x, int y, GRAFOS *g);


#endif