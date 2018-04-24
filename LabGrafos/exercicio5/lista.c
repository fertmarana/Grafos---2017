/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070
*/
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#define ENTER 10
#include "lista.h"

void imprimir_lista(LISTA *lista){
	int i;
	while(lista->size != 1){
	
		i = frente_lista(lista);
		retira_frente_lista(lista);
		printf("%d ", i);
	}
	if(lista->size == 1){
		i = frente_lista(lista);
		printf("%d ", i);
	}
	
}


NO *criar_no_lista(int c) { //criando um NO
    NO *no=NULL;
    no = (NO *) malloc (sizeof(NO)); //alocando NO
 
    no->elem = c; //no recebera o char mandado como argumento pela funcao
    no->antes = NULL; //o ponteiro antes do novo no por enquanto aponta para NULL
    no->prox = NULL; //o ponteiro prox do novo NO por enquanto aponta para NULL
 
    return no; //retornando NO criado e alocado
}

char *readLine() { //le uma string
	char c; // char
	char *string = NULL;  //ponteiro de char
	int counter = 0;//contador

	do {
		c = fgetc(stdin);
		// o caracter e lido pela funcao fgetc(fp) do arquivo trazido pelo ponteiro de arquivo;
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		// aloca-se espaco para esse caracter
		string[counter++] = c; 
		// o caracter e armazenado na posicao counter da string
	} while (c != ENTER);
	// isso se repete ate ele encontrar uma quebra de linha. Ai ele roda mais uma vez
	string[counter-1] = '\0';
	 // no lugar do enter essa string recebe '\0' para indicar seu final

	return string; // retorno o ponteiro de char lido e alocado
}
/* Aloca um LISTA vazio na Heap. */
LISTA *criar_lista(){
	LISTA *list= (LISTA*)malloc(sizeof(LISTA));//alocando-se espaco na HEAP para o LISTA
	list->primeiro = NULL;
	list->ultimo = NULL;
	list->size = 0;
	return list; //retornando LISTA alocado e vazio
}

/* Remove todos os elementos do LISTA. */
void limpar_lista(LISTA *list){
	NO *atual = list->primeiro; //criando o NO que vai percorrer o LISTA
	NO *anterior; //criando esse NO anterior para que eu possa ir liberando
	//os NOs enquanto atual percorre o LISTA

	while(atual != NULL){ //enquanto atual nao chega no final do LISTA
		anterior = atual; //o NO anterior recebera o NO em que atual esta 
		atual = atual->prox; //atual vai para o proximo NO
		free(anterior); //libera-se o NO em que anterior esta 
	}
	
	list->primeiro =NULL;
	list->ultimo = NULL;

}

/* Remove todos os elementos e desaloca o LISTA. */
void destruir_lista(LISTA *list){
	limpar_lista(list); //chama  a funcao limpar para remover os elementos do list
	free(list); //desaloca o LISTA usado
}

/* Insere o elemento no LISTA vazio. */
void coloca_primeiro_lista(LISTA *list, int c){
	NO *new; 
	new = criar_no_lista(c); //cria-se um novo NO
		list->primeiro = list->ultimo = new; 
		//como ele eh o primeiro tanto o ultimo como primeiro serao ele
		list->size=1; //o tamanho do vetor eh incrementado para 1
}

/* Insere um elemento na frente (na cabeça) do LISTA. */
void coloca_frente_lista(LISTA *list, int c){
	NO *new = criar_no_lista(c);//cria-se um novo NO
	//como ele sera colocado na cabeca do list
	list->primeiro->antes = new; //o primeiro NO do list tera seu antes apontado para o novo NO
	new-> prox = list->primeiro;//o ponteiro prox do NO sera apontado para a primeira posicao do list
	list->primeiro = new;// a primeira posicao do list apontara agora para o novo NO
	list->size++; //o tamanho do list eh incrementado 

}
/* Insere um elemento atrás (na cauda) do LISTA. */
void coloca_atras_lista(LISTA *list, int c){ 
	NO *new = criar_no_lista(c);//cria-se um novo NO
	//como ele sera colocado na cauda do list

	list->ultimo->prox= new;//o ultimo NO do list tera seu ponteiro prox apontado para o novo NO
	new->antes = list->ultimo;//o ponteiro antes do NO sera apontado para a ultima posicao do list
	list -> ultimo = new;// a ultima posicao do list apontara agora para o novo NO
	
	list->size++;//o tamanho do list eh incrementado 
}
/* Retorna o elemento armazenado na frente do LISTA. */
int frente_lista(LISTA *list){
	return list->primeiro->elem;
}
/* Retorna o elemento armazenado atrás do LISTA. */
int atras_lista(LISTA *list){
	return list->ultimo->elem;
}

/* Retorna a quantidade de elementos do LISTA. */
int size(LISTA *list){
	return list->size; 
}

int vazio_lista(LISTA *list){ //checa se o LISTA esta vazio a partir de seu tamanho
return size(list) == 0 ? 1 : 0 ;
}

/* Remove o elemento da frente do LISTA. */
void retira_frente_lista(LISTA *list){
	NO *rem = list->primeiro;//NO rem recebe o primeiro NO do list
	rem->prox->antes = rem->antes;//o NO depois do rem vai ter seu antes apontando para NULL
	list->primeiro = rem->prox;//o primeiro NO do list vai estar agora apontado para 
	list->size--;
	free(rem);
//o NO posterior ao rem
}
/* Remove o elemento de trás do LISTA. */
void retira_atras_lista(LISTA *list){
	NO *rem = list->ultimo; //NO rem recebe o ultimo NO do list
	rem->antes->prox = rem->prox; //o NO antes do rem vai ter seu prox apontando para NULL
	list->ultimo = rem->antes; //o ultimo NO do LISTA vai estar agora apontado para 
	list->size--;
	free(rem);
//o NO anterior ao rem
}

/* Imprime o LISTA a partir da recursividade  */
void print(NO *aux){

	if(aux == NULL) return; //se nao tiver LISTA retorna sem fazer mais nada
	printf("%c", aux->elem); //imprimindo o elemento do NO
		print(aux->prox);//chamando novamente a funcao de imprimir com o proximo NO
	
}


/* Funcao que transforma strings em LISTA */
void string_para_LISTA(LISTA *list, char *word, int n){
	int i; //indice
	
	coloca_primeiro_lista(list,word[0]); //colocando a primeira letra ja no LISTA primeiro
	for(i=1; i<n; i++){ //enquanto nao estiver a string inteiramente preenchida
		coloca_atras_lista(list, word[i]);//coloque as letrar uma na frente da outra 
		//como na string original`
	}

}
