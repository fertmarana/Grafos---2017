/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#ifndef _BUSCA_H_
#define _BUSCA_H_

int procura_vertices_adjacentes(GRAFOS *g, int valor, int **adj);
void busca_em_prof_aux(GRAFOS *g, int *pai, int *cor, int valor);
void imprime_primeiro_caminho_encontrado(int filho, int *pai);
void busca_em_prof(GRAFOS *g,int valor, int fim);

#endif