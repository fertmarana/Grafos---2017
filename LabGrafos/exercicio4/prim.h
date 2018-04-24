#ifndef _PRIM_H_
#define _PRIM_H_

#include "heap_estatica.h"

int adjacentes(GRAFOS *g, int valor, int **adj);

void prim_tree(GRAFOS *g, int origem);
int na_Fila(int tam, int *a, int valor);

#endif