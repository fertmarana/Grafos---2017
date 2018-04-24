#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>


#include "heap_estatica.h"


HEAP_ESTATICA *criar_heap(){
HEAP_ESTATICA *heap = (HEAP_ESTATICA*)malloc(sizeof(HEAP_ESTATICA));
if(heap != NULL){
	heap->fim = -1;
}	

return heap;

}



int cheia(HEAP_ESTATICA *heap){
	return (heap->fim == TAM -1);
}

int vazia(HEAP_ESTATICA *heap){
	return (heap->fim == -1);
}

void swap(HEAP_ESTATICA *heap, int i, int j){
	ITEM *aux = heap->vetor[i];
	heap->vetor[i] = heap->vetor[j];
	heap->vetor[j] = aux;
}


void fix_up(HEAP_ESTATICA *heap){
	int pos = heap->fim;
	int pai = (pos - 1)/2;
	while(pos > 0 &&  ( (heap->vetor[pos]->peso < heap->vetor[pai]->peso) || (heap->vetor[pos]->peso == heap->vetor[pai]->peso && heap->vetor[pos]->vertice < heap->vetor[pai]->vertice) ) ){
	swap(heap, pos, pai);
	pos = pai;
	pai = (pai - 1) / 2;

	}
}

void fix_down(HEAP_ESTATICA *heap){
	int pos = 0;

	while(pos <= heap->fim/2){
	int filhoesq = 2*pos +1;
	int filhodir = 2*pos + 2;

	int menorfilho;
	if(filhodir <= heap->fim && (
	(heap->vetor[filhoesq]->peso > heap->vetor[filhodir]->peso) || (heap->vetor[filhoesq]->peso == heap->vetor[filhodir]->peso && (heap->vetor[filhoesq]->vertice > heap->vetor[filhodir]->vertice) )  )  ){
	menorfilho = filhodir;
	}else{
	menorfilho = filhoesq;
	}

	if(heap->vetor[pos]->peso < heap->vetor[menorfilho]->peso){
	break;
	}
	if(heap->vetor[pos]->peso == heap->vetor[menorfilho]->peso && heap->vetor[pos]->vertice < heap->vetor[menorfilho]->vertice ){
	break;
	}
	swap(heap, pos, menorfilho);
	pos = menorfilho;
	}

}


int enfileirar(HEAP_ESTATICA *heap, ITEM *item){
	if(!cheia(heap)){
	heap->fim++;
	heap->vetor[heap->fim] = item;
	fix_up(heap);
	return 1;
	}
	return 0;
}



ITEM *desenfileirar(HEAP_ESTATICA *heap){
	if(!vazia(heap)){
	ITEM *item = heap->vetor[0];
	heap->vetor[0] = heap->vetor[heap->fim];
	heap->fim--;
	fix_down(heap);
	return item;
	}
	return NULL;
}



void imprimir_heap(HEAP_ESTATICA *heap){
	int i;
	for(i = 0; i < (heap->fim+1); i++){
		print_item(heap->vetor[i]);
	}



}



void update(HEAP_ESTATICA *heap, int novo_peso, int no_vertice){
	int i, mudou = 0;
	for(i = 0; i < (heap->fim+1); i++){
		if(heap->vetor[i]->vertice == no_vertice)
		{
		 heap->vetor[i]->peso = novo_peso;
		mudou = 1;
		break;
		}
	}
	//printf("%d\n", i);
	if(mudou == 0) return;
	int pos = i;
	int pai = (pos - 1)/2;
	int filhoesq = 2*pos +1;
	int filhodir = 2*pos + 2;
	int menorfilho;
	if(filhodir <= heap->fim && (
	(heap->vetor[filhoesq]->peso > heap->vetor[filhodir]->peso) || (heap->vetor[filhoesq]->peso == heap->vetor[filhodir]->peso && (heap->vetor[filhoesq]->vertice > heap->vetor[filhodir]->vertice) )  )  ){
	menorfilho = filhodir;
	}else{
	menorfilho = filhoesq;
	}
	
	if(pos > 0 &&  ( (heap->vetor[pos]->peso < heap->vetor[pai]->peso) || (heap->vetor[pos]->peso == heap->vetor[pai]->peso && heap->vetor[pos]->vertice < heap->vetor[pai]->vertice) ) ){
		
		while(pos > 0 &&  ( (heap->vetor[pos]->peso < heap->vetor[pai]->peso) || (heap->vetor[pos]->peso == heap->vetor[pai]->peso && heap->vetor[pos]->vertice < heap->vetor[pai]->vertice) ) ){
		swap(heap, pos, pai);
		
		pos = pai;
		pai = (pai - 1) / 2;

		}
	}
	else if ( menorfilho <= heap->fim && (heap->vetor[pos]->peso > heap->vetor[menorfilho]->peso || 
		(heap->vetor[pos]->peso == heap->vetor[menorfilho]->peso && heap->vetor[pos]->vertice > heap->vetor[menorfilho]->vertice)  )  ){
		


		swap(heap, pos, menorfilho);
		pos = menorfilho;
		while(pos <= heap->fim/2){
				filhoesq = 2*pos +1;
				filhodir = 2*pos + 2;

			if(filhodir <= heap->fim && (
			(heap->vetor[filhoesq]->peso > heap->vetor[filhodir]->peso) || (heap->vetor[filhoesq]->peso == heap->vetor[filhodir]->peso && (heap->vetor[filhoesq]->vertice > heap->vetor[filhodir]->vertice) )  )  ){
			menorfilho = filhodir;
			}else{
			menorfilho = filhoesq;
			}

			if(heap->vetor[pos]->peso >= heap->vetor[menorfilho]->peso){
			break;}
			swap(heap, pos, menorfilho);
			pos = menorfilho;

		}

	}


}

int getCost(HEAP_ESTATICA * heap, int vertice){
int i;
	for(i = 0; i < (heap->fim+1); i++){
		if(heap->vetor[i]->vertice == vertice)
		{
			//printf("v: %d peso: %d\n", heap->vetor[i]->vertice, heap->vetor[i]->peso);
		 return heap->vetor[i]->peso;
	
		}
	}
	return -1;

}




