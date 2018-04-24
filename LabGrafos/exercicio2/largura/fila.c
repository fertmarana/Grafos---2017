/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070

*/
#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "fila.h"


/*Funcao que vai criar alocar um tipo FILA e setar seus ponteiros para NULL*/
FILA *criar_fila(){
	FILA  *fila = (FILA*)malloc(sizeof(FILA));
	fila->ultimo = NULL;
	fila->primeiro = NULL;
	fila->tamanho =0;


	return fila;
}
/*Funcao que vai imprimir cada no da fila*/
void print_fila(FILA *fila){
	NO *no = fila->primeiro;
	while(no != NULL){
		printf("%d ",no->valor );
		no = no->proximo;
	}

}


/*Funcao que vai apagar a fila*/
void apagar_no(NO **no){
	(*no)->anterior = NULL;
	(*no)->proximo = NULL;
	free(*no);
	return;
}
/*Funcao que vai criar um no*/
NO *criar_no(int valor){
	NO *no = (NO*)malloc(sizeof(NO));
	no->anterior = NULL;
	no->proximo = NULL;
	no->valor = valor;



	return no;
}

/*Funcao que vai adicionar um novo no na fila na ultima posicao. Assim o no ultimo sera esse novo no adicionado*/
void enfileirar(FILA *fila,int valor){
	NO * no = criar_no(valor);
	if(fila->ultimo == NULL && fila->primeiro == NULL){ //em caso da fila estar vazia, o novo no sera o primeiro e ultimo da fila
		//printf("Entrou aqui\n");
		fila->primeiro = no;
		fila->ultimo = no;

	}else{ //em caso da fila nao estar sozinha, ele sera adicionado atras do ultimo no
		fila->ultimo->proximo = no;
		no->anterior = fila->ultimo;
		fila->ultimo = no;
	}
	fila->tamanho++; //incrementa-se o tamanho da fila
	return;

}

/*Funcao que vai retirar um no da fila. O no retirado sera sempre o primeiro da fila. Assim seu segundo sera o primeiro da fila depois da retirada*/
int desenfileirar(FILA *fila){
	int valor;
	if(fila->primeiro != NULL){
		
		NO *no = fila->primeiro; 
		valor = no->valor; //variavel valor recebe o numero do vertice que sera retirado
		if(fila->primeiro == fila->ultimo) fila->ultimo = NULL; // caso so tenha um unico no na fila, os ponteiros primeiro e ultimo vao parar de apontar para ele
		fila->primeiro = fila->primeiro->proximo;
		if(fila->primeiro != NULL) fila->primeiro->anterior = NULL;
		
		apagar_no(&no); //desaloca o espaco da memoria neste no
		fila->tamanho--; // decrementa-se o tamanho da fila
		return valor; //retorna o valor retirado
	}	
	return -1; //caso nao de para retirar retorna -1
}

void apagar_fila(FILA *fila){
	NO *no = fila->primeiro;
	while(no != NULL){
		NO *rem = no;
		no = no->proximo;
		free(rem);
	}
	free(fila);
return;
}
