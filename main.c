#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "hash.h"

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