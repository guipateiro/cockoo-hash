#include "hash.h"

void iniciatabela(hash *tabela){
	int temp;

	for(temp = 0 ; temp <= TAM ; temp++){
		tabela[temp].excluido = 1;
		tabela[temp].elemento = -1;
	}
}

void inicia_cockoo(cockoo_h *tabela){
	iniciatabela(tabela->t1);
	iniciatabela(tabela->t2);
}

int imprime_tabelas(cockoo_h *tabela){
	int i,j;
	int k1,k2;
	hash t1temp = {0,1};
	hash t2temp = {0,1};

	for (j = 0; j < TAM*2; j++){
		k1 = -1;
		k2 = -1;
		t1temp.elemento = INT_MAX;
		t2temp.elemento = INT_MAX;
		for (i = 0; i < TAM; i++){
			if (tabela->t1[i].excluido == 0 && tabela->t1[i].elemento <= t1temp.elemento){
				t1temp.elemento = tabela->t1[i].elemento;
				k1 = i;
			}
			if (tabela->t2[i].excluido == 0 && tabela->t2[i].elemento <= t2temp.elemento){
				t2temp.elemento = tabela->t2[i].elemento;
				k2 = i;
			}
		}
		if (t1temp.elemento <= t2temp.elemento && k1 != -1){
			printf("%i,T1,%i\n",t1temp.elemento, k1);
			tabela->t1[k1].excluido = 1;
		}
		else if (t1temp.elemento > t2temp.elemento && k2 != -1){
			printf("%i,T2,%i\n",t2temp.elemento, k2);
			tabela->t2[k2].excluido = 1;
		}	
		else 
			return ERRO;	
	}
	return OPERACAO_REALIZADA;
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
	return ERRO;
}

int exclui_tabela(int valor, hash* tabela, int (*funcao_hash)()){
	int index = funcao_hash(valor);
	if(tabela[index].elemento == valor){
		tabela[index].excluido = 1;
		return OPERACAO_REALIZADA;
	}
	return ERRO;
}

int insere (int valor, cockoo_h *tabela){
	int resposta;
	resposta = insere_tabela(valor, tabela->t1, h1);
	if(resposta == ERRO){
		hash item = (tabela->t1)[h1(valor)];
		insere_tabela(item.elemento, tabela->t2, h2);
		exclui_tabela(item.elemento, tabela->t1, h1);
		insere_tabela(valor, tabela->t1, h1);
	}
	return OPERACAO_REALIZADA;
}

int exclui (int valor, cockoo_h *tabela){
	int resposta;
	resposta = exclui_tabela(valor, tabela->t1, h1);
	if(resposta == ERRO){
		exclui_tabela(valor, tabela->t2, h2);
	}
	return OPERACAO_REALIZADA;
}
