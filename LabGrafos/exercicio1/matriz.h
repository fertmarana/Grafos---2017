#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include "lista.h"




void va_x_matriz(int vertice, GRAFOS *g);

void aa_x_y_p_matriz(int x, int y, int peso, GRAFOS **g);
void ra_x_y_matriz(int x, int y, GRAFOS** g);
void it_matriz(GRAFOS *g);
void mp_matriz(GRAFOS *g);
void criar_matriz(GRAFOS *g);
char *readLine();

#endif

