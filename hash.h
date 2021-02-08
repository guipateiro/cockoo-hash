#ifndef __HASH__
#define __HASH__

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
	int elemento;
	int excluido;
} hash;


void iniciatabela(hash *tabela);

void imprime_tabelas(hash *tabela1, hash *tabela2);



#endif 