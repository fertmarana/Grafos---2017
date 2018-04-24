/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#ifndef _BUSCA_H_
#define _BUSCA_H_
#include "lista.h"

int procura_vertices_adjacentes(GRAFOS *g, int valor, int **adj);
void imprime(int filho, int *pai);
void busca_em_prof_aux(GRAFOS *g, int *pai, int *cor, int valor, LISTA *lista);
void busca_em_prof(GRAFOS *g,int origem, int *pai, int *cor, LISTA *list);


#endif