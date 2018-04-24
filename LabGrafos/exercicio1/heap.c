#include <stdlib.h>
#include <stdio.h>


typedef struct NO{
	int peso;
	int vertice;
}NO;

typedef struct HEAP{
	int tam;
	NO *no;
} HEAP;


HEAP *criar_heap(int v){
	int i;
	
	HEAP *heap =  (HEAP*) malloc (sizeof(HEAP));
	NO *no = (NO*) malloc (v*sizeof(NO));
	heap->tam = 0;
	for(i=0; i< v; i++){
		 no[i].peso = 9999;
		 no[i].vertice = -1;
	}
	heap->no = no;
	return heap;
}
	
void enfileirar(HEAP *heap, int vertice, int peso){
	int i;
	
	i = (heap->tam)-1;
	while(heap->no[i].peso == 9999) i--;
	
	heap->no[i+1].peso = peso;
	heap->no[i+1].vertice = vertice;
	
	while(heap->no[i].peso < heap->no[i/2].peso || 
		(heap->no[i].peso == heap->no[i/2].peso && heap->no[i].vertice < heap->no[i/2].vertice) ){
			NO aux;
			
			aux = heap->no[i/2];
			
			heap->no[i/2] = heap->no[i];
			heap->no[i] = aux;
				
			i = i/2;
	}
	heap->tam++;
	return;
	

}
/*

NO desenfileirar(HEAP *heap){
	int i = (heap->tam)-1, j;
	while(heap->no[i].peso == -1) i--;
	
	NO ret  = heap->no[0];
	NO aux;
	heap->no[0] = heap->no[i];
	heap->no[i].peso = -1;
	heap->no[i].vertice = -1;
	j = i;
	i = 0;
	
	while( (heap->no[i].peso > heap->no[i*2].peso || heap->no[i].peso > heap->no[(i*2)+1].peso) || 
		(heap->no[i].peso == heap->no[i*2].peso && heap->no[i].vertice > heap->no[i*2].vertice) ||
		(heap->no[i].peso == heap->no[(i*2)+1].peso && heap->no[i].vertice > heap->no[(i*2)+1].vertice) ){
		
		if(heap->no[i*2].peso < heap->no[(i*2) + 1].peso){
				aux = heap->no[i*2];
			
				heap->no[i*2] = heap->no[i];
				heap->no[i] = aux;
				
				i = i*2;
		}
		
		else if( heap->no[i].peso > heap->no[(i*2)+1].peso ){
				aux = heap->no[(i*2) + 1];
			
				heap->no[(i*2)+1] = heap->no[i];
				heap->no[i] = aux;
				
				i = (i*2) + 1;
		} else if((heap->no[i].peso == heap->no[(i*2)+1].peso && heap->no[i].vertice > heap->no[(i*2)+1].vertice)){
			aux = heap->no[(i*2) + 1];
			
				heap->no[(i*2)+1] = heap->no[i];
				heap->no[i] = aux;
				
				i = (i*2) + 1;

		} else{
			aux = heap->no[i*2];
			
				heap->no[i*2] = heap->no[i];
				heap->no[i] = aux;
				
				i = i*2;
		}
			
		
		
	}
		heap->tam--;	
	return ret;
}
*/


NO desenfileirar(HEAP *heap){
	int i = (heap->tam)-1, j;
	while(heap->no[i].peso == 9999) i--;
	
	NO ret  = heap->no[0];
	NO aux;
	heap->no[0] = heap->no[i];
	heap->no[i].peso = 9999;
	heap->no[i].vertice = -1;
	j = i;
	i = 0;
	
	while( (heap->no[i].peso > heap->no[i*2].peso || heap->no[i].peso > heap->no[(i*2)+1].peso) ||
		(heap->no[i].peso == heap->no[i*2].peso && heap->no[i].vertice > heap->no[i*2].vertice) ||
		(heap->no[i].peso == heap->no[(i*2)+1].peso && heap->no[i].vertice > heap->no[(i*2)+1].vertice)){
		
		if( (heap->no[i*2].peso < heap->no[(i*2) + 1].peso )|| (heap->no[i*2].peso == heap->no[(i*2) + 1].peso && heap->no[i*2].vertice < heap->no[(i*2) + 1].vertice )){
				aux = heap->no[i*2];
			
				heap->no[i*2] = heap->no[i];
				heap->no[i] = aux;
				
				i = i*2;
		}
		
		else{
				aux = heap->no[(i*2) + 1];
			
				heap->no[(i*2)+1] = heap->no[i];
				heap->no[i] = aux;
				
				i = (i*2) + 1;
		}
			
		
		
	}
		heap->tam--;	
	return ret;
}			
		
void update(HEAP *heap, int novo_peso,int vertice){

	int i;
	for(i=0; i< heap->tam; i++){
		if(heap->no[i].vertice == vertice){
			heap->no[i].peso = novo_peso;
			break;
		}
	}
	printf("i: %d\n", i);
	printf("heap->tam: %d\n", heap->tam);

	if(heap->no[i].peso < heap->no[i/2].peso){
		printf("entrou aqui\n");
		while(heap->no[i].peso < heap->no[i/2].peso){
			NO aux;
			
			aux = heap->no[i/2];
			
			heap->no[i/2] = heap->no[i];
			heap->no[i] = aux;
				
			i = i/2;
			if(i == 0) return;
		}


	} else if(heap->no[i].peso > heap->no[i*2].peso || heap->no[i].peso > heap->no[(i*2)+1].peso ){
		printf("entrou nos filhos\n");

		while((heap->no[i].peso > heap->no[i*2].peso || heap->no[i].peso > heap->no[(i*2)+1].peso) && (i < heap->tam)){
			if(i == heap->tam - 2) return;
		if(heap->no[i*2].peso < heap->no[(i*2) + 1].peso ){

			printf("ele fala italiano\n");
				NO aux= heap->no[i*2];
			
				heap->no[i*2] = heap->no[i];
				heap->no[i] = aux;
				
				i = i*2;
		}
		
		else{
			printf("ai meu deus\n");
				NO aux = heap->no[(i*2) + 1];
			
				heap->no[(i*2)+1] = heap->no[i];
				heap->no[i] = aux;
				
				i = (i*2) + 1;
		}
		}	

	}


}

int is_Empty(HEAP* heap){
	return heap->tam == 0? 1 : 0;
}

int getCost(HEAP *heap, int vertice){
	int i;
	for(i=0; i< heap->tam; i++){
		if(heap->no[i].vertice == vertice){
			return heap->no[i].peso;
			
		}
	}
return 9999;
}

void imprimir_heap(HEAP *heap){
	for(int i=0; i< heap->tam; i++){
		printf("no[%d]->vertice: %d\nno[%d]->peso:%d\n", i, heap->no[i].vertice, i, heap->no[i].peso);
	}

}
			
	

