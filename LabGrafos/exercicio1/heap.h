#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct NO{
	int peso;
	int vertice;
}NO;

typedef struct HEAP{
	int tam;
	NO *no;
} HEAP;

HEAP *criar_heap(int v);
void enfileirar(HEAP *heap, int vertice, int peso);
NO desenfileirar(HEAP *heap);
void update(HEAP *heap, int novo_peso,int vertice);
int is_Empty(HEAP *heap);
int getCost(HEAP *heap, int vertice);
void imprimir_heap(HEAP *heap);

#endif