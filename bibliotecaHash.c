#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaHash.h"

typedef struct campo{
	int valor;
	struct campo *prox;
}campo;

void menu(){
	printf("\n================================================\n");
	printf("1 - Criar tabela \n2 - Checar exixtencia\n3 - Unir tabelas\n4 - Sair\n");
	
}

void inserir(){
	printf("chamou a inserir");
}

void checkEx(){
	printf("chamou a check de existencia");
}

void unirTabs(){
	printf("chamou a UnirTabs");
}
