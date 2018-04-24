#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct GRAFOS GRAFOS;
typedef struct VERTICE VERTICE;

struct GRAFOS
{
	VERTICE **lista;
	int **matriz;
	int direcionado;
	int nvertices;
	int narestas;
};

struct VERTICE
{
	int vertice;
	int peso;
	VERTICE *proximo;
	
};

GRAFOS *criar_grafo(char d, int vertices, int arestas);
void criar_lista(GRAFOS *g);
VERTICE *criar_vertice(int peso, int vertice);
void add_conexao(GRAFOS *g, int v1, int v2, int p);

void ig(int matriz, GRAFOS *g);
void va_x_lista(int vertice,GRAFOS *g);
void aa_x_y_p_lista(int x,int y,int p,GRAFOS *g);
void ra_x_y_lista(int x, int y, GRAFOS* g);
void mp_lista(GRAFOS *g);
void it_lista(GRAFOS* g);


void apagar_lista(VERTICE **lista, int tam);
void apagar_matriz(int **m, int a);
void free_grafo(GRAFOS *g);





#endif