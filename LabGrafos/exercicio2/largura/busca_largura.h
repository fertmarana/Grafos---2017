/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#ifndef _BUSCA_LARGURA_H_
#define _BUSCA_LARGURA_H_

#include "fila.h"

int procura_vertices_adjacentes(GRAFOS *g, int valor, int **adj);
void iimprime_primeiro_caminho_encontrada(int filho, int *pai);
void busca_largura(GRAFOS *g,int origem, int destino);
#endif