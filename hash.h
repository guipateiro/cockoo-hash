#ifndef __HASH__
#define __HASH__

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "hash.h"
#define TAM 11

#define OPERACAO_REALIZADA 1
#define ERRO 2

typedef struct {
	int elemento;
	int excluido;
} hash;

typedef struct {
	hash t1[TAM];
	hash t2[TAM];
} cockoo_h;


void inicia_cockoo(cockoo_h *tabela);

int imprime_tabelas(cockoo_h *tabela);

int exclui (int valor, cockoo_h *tabela);

int insere (int valor, cockoo_h *tabela);

#endif 