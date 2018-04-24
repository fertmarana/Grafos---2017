#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "grafo.h"

int adjacentes(GRAFOS *g, int valor, int **adj);
int na_Fila(int tam, int *a, int valor); 
void dijkstra(GRAFOS *g, int origem, int destino);


#endif