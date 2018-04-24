#ifndef _HEAP_ESTATICA_H_
#define _HEAP_ESTATICA_H_

#include "item.h"

typedef struct heap_estatica HEAP_ESTATICA;

#define TAM 100000

struct heap_estatica {
ITEM * vetor[TAM];
int fim;
};

HEAP_ESTATICA *criar_heap();
int cheia(HEAP_ESTATICA *heap);
int vazia(HEAP_ESTATICA *heap);
void swap(HEAP_ESTATICA *heap, int i, int j);
void fix_up(HEAP_ESTATICA *heap);
void fix_down(HEAP_ESTATICA *heap);
int enfileirar(HEAP_ESTATICA *heap, ITEM *item);

ITEM *desenfileirar(HEAP_ESTATICA *heap);

void imprimir_heap(HEAP_ESTATICA *heap);
void update(HEAP_ESTATICA *heap, int novo_peso, int no_vertice);
int getCost(HEAP_ESTATICA * heap, int vertice);
#endif