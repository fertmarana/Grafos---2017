#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM ITEM;

struct ITEM
{
	int peso;
	int vertice;
	
};

ITEM *criar_item(int peso,  int vertice){
	ITEM *item = (ITEM*)malloc(sizeof(ITEM));

	if(item != NULL){
		item->peso = peso;
		item->vertice = vertice;
		
	}

return item;
}

void apagar_item(ITEM **item){
if(*item != NULL && item != NULL){
		free(*item);
		*item= NULL;
	}
	return;
}

void print_item(ITEM *item){
	if(item != NULL){
		printf("vertice: %d\n", item->vertice);
		printf("peso: %d\n", item->peso);
		
		
	}
	return;
}