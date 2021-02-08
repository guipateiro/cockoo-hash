#include "hash.h"

void imprime_debug(cockoo_h *tabela){
	printf("|    T1    |  |    T2    |\n");
	printf("|ee      d |  | e      d |\n");
	for (int i=0; i < TAM; i++) {
		hash item = tabela->t1[i];
		hash item2 = tabela->t2[i];
		if(item.elemento < 10) printf("| %d", item.elemento);
		else printf("|%d", item.elemento);
		printf("      %d |  ", item.excluido);
		if(item2.elemento < 10) printf("| %d", item2.elemento);
		else printf("|%d", item2.elemento);
		printf("      %d |\n", item2.excluido);
	}
}


void iniciatabela(hash *tabela){
	int temp;

	for(temp = 0 ; temp <= TAM ; temp++){
		tabela[temp].excluido = 1;
		tabela[temp].elemento = 0;
	}
}

void inicia_cockoo(cockoo_h *tabela){
	iniciatabela(tabela->t1);
	iniciatabela(tabela->t2);

	// imprime_debug(tabela);
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

int h1(int valor) { return valor % TAM; }

int h2(int valor){ return (int) floor(TAM *((valor*0.9) - (floor(valor *0.9)))); }

int insere_tabela(int valor, hash* tabela, int (*funcao_hash)()){
	int index = funcao_hash(valor);
	if(tabela[index].excluido == 1){
		tabela[index].elemento = valor;
		tabela[index].excluido = 0;
		return OPERACAO_REALIZADA;
	}
	return ERRO_POSICAO_OCUPADA;
}

int exclui_tabela(int valor, hash* tabela, int (*funcao_hash)()){
	int index = funcao_hash(valor);
	if(tabela[index].elemento == valor){
		tabela[index].excluido = 1;
		return OPERACAO_REALIZADA;
	}
	return ERRO_POSICAO_OCUPADA;
}

int insere (int valor, cockoo_h *tabela){
	int resposta;
	resposta = insere_tabela(valor, tabela->t1, h1);
	if(resposta == ERRO_POSICAO_OCUPADA){
		hash item = (tabela->t1)[h1(valor)];
		insere_tabela(item.elemento, tabela->t2, h2);
		exclui_tabela(item.elemento, tabela->t1, h1);
		insere_tabela(valor, tabela->t1, h1);
	}

	imprime_debug(tabela);
	return 0;
}

int exclui (int valor, cockoo_h *tabela){
	printf("exclui");

	return 0;
}