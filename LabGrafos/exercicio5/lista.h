/*
Nome: Fernanda Tostes Marana
Numero Usp: 4471070
*/
#ifndef _LISTA_H_
#define _LISTA_H_


//definindo antesiamente as structs NO e LISTA pelo typedef
typedef struct NO NO; 
typedef struct LISTA LISTA;


struct NO { //struct NO que tera:
	NO *prox; //ponteiro que aponta para proxima posicao do NO
	NO *antes; //ponteiro que aponta para posicao anterior do NO
	int elem;	//elemento armazenado nesse NO especifico

};

struct LISTA //struct LISTA que tera:
{
	NO *primeiro; //ponteiro que aponta para primeira posicao do LISTA
	NO *ultimo; //ponteiro que aponta para primeira posicao do LISTA
	int size;//int que indica o tamanho atual do LISTA
};

void imprimir_lista(LISTA *lista);
NO *criar_no_lista(int c) ;
char *readLine();
LISTA *criar_lista();
void limpar_lista(LISTA *list);
void destruir_lista(LISTA *list);
void coloca_primeiro_lista(LISTA *list, int c);
void coloca_frente_lista(LISTA *list, int c);
void coloca_atras_lista(LISTA *list,int  c);
int frente_lista(LISTA *list);
int atras_lista(LISTA *list);
int size(LISTA *list);
int vazio_lista(LISTA *list);
void retira_frente_lista(LISTA *list);
void retira_atras_lista(LISTA *list);
void print(NO *aux);
void string_para_LISTA(LISTA *list, char *word, int n);

#endif