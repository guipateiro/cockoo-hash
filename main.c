#include <string.h>
#include "hash.h"

int main(){
	hash tabela1[TAM];
	hash tabela2[TAM];
	
	cockoo_h hash;
	int i;
	char op[1];

	inicia_cockoo(&hash);

	while(!feof(stdin)){
		if (scanf("%s %i", op, &i) != 2)
			break;
		printf("> %s %d \n", op, i);
		if (!strcmp(op, "i"))
			insere(i, &hash);
		else if	(!strcmp(op, "r"))
			exclui(i, &hash);
	}
	
	imprime_tabelas(tabela1,tabela2);

	return(0);
}