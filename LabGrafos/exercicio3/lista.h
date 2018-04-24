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
	char elem;	//elemento armazenado nesse NO especifico

};

struct LISTA //struct LISTA que tera:
{
	NO *primeiro; //ponteiro que aponta para primeira posicao do LISTA
	NO *ultimo; //ponteiro que aponta para primeira posicao do LISTA
	int size;//int que indica o tamanho atual do LISTA
};

void imprimir(LISTA *lista);
NO *criar_no(char c) ;
char *readLine();
LISTA *criar();
void limpar(LISTA *list);
void destruir(LISTA *list);
void coloca_primeiro(LISTA *list, char c);
void coloca_frente(LISTA *list, char c);
void coloca_atras(LISTA *list, char c);
char frente(LISTA *list);
char atras(LISTA *list);
int size(LISTA *list);
int vazio(LISTA *list);
void retira_frente(LISTA *list);
void retira_atras(LISTA *list);
void print(NO *aux);
void string_para_LISTA(LISTA *list, char *word, int n);

#endif