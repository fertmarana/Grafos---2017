/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#ifndef _FILA_H_
#define _FILA_H_



typedef struct NO NO;
typedef struct FILA FILA;


struct NO{
	NO *anterior;
	NO *proximo;
	int valor;
};

struct FILA{
	NO *ultimo;
	NO *primeiro;
	int tamanho;
};



NO *criar_no(int valor);
void apagar_no(NO **no);
void print_fila(FILA *fila);
FILA *criar_fila();
void enfileirar(FILA *fila,int valor);
void apagar_fila(FILA *fila);
int desenfileirar(FILA *fila);


#endif