

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
//#include "hash.h"
#define TAM 11

typedef struct {
	int elemento;
	int excluido;
} hash;

void iniciatabela(hash *tabela){
	int temp;

	for(temp = 0 ; temp <= TAM ; temp++){
		tabela[temp].excluido = 1;
		tabela[temp].elemento = 0;
	}
}

void imprime_tabelas(hash *tabela1, hash *tabela2){
	int temp;
	hash t1temp = {INT_MAX,1};
	hash t2temp = {INT_MAX,1};

	for(temp = 0 ; temp <= TAM ; temp++){
		if((tabela1[temp].excluido == 0) && (tabela1[temp].elemento <= t1temp.elemento)){
			tabela1[temp] = t1temp;
		}
		if((tabela2[temp].excluido == 0) && (tabela2[temp].elemento <= t2temp.elemento)){ 
			tabela2[temp] = t2temp;
		}

	}
}	


int main(){
	hash tabela1[TAM];
	hash tabela2[TAM];
	int i;
	char c;
	iniciatabela(tabela1);
	iniciatabela(tabela2);

	if(scanf("%c %i", &c, &i) != 2){
		fprintf(stderr,"Entrada inválida");
        exit(1);
	}
	while(scanf("%c %i", &c, &i) == 2 && !feof(stdin)){
		if (c == 'i')
			insere(i, tabela1, tabela2);
		else if	(c == 'r')
			exclui(i, tabela1, tabela2);
	}
	
	imprime_tabelas(tabela1,tabela2);

	return(0);
}