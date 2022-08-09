#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bibliotecaHash.h"
#define TAM 50

Lista *tab[TAM];
Lista *tab2[TAM];
Lista *tabUniao[TAM];

typedef struct campo{
	int valor;
	struct campo *prox;
}No;

typedef struct campoVetor{
	No *pont;
	int tam;
}Lista;

void menu(){
	printf("===============================================\n");
	printf("\t\tTABELA HASH\n");
	printf("===============================================\n");
	printf("1 - Criar tabela \n2 - Exibir Tabela\n3 - Checar tabela\n4 - Unir tabelas\n5 - Inserir Elemento\n6 - Excluir Elemento\n7 - Sair\n");
	
}

void inicializarLista(Lista *L){
	L->pont = NULL;
	L->tam=0;
}

int indxHash(int valor){
	int indice;
	indice=valor%TAM;
	return indice;
}

void CriarTab(int op){//Crio vetor do tipo lista
	int valorIndx;
	int valor;
	
	srand(time(NULL));
	
	if(op==1){
	
		for(int i=0; i<TAM; i++){
		
			tab[i] = malloc(sizeof(Lista));
			inicializarLista(tab[i]);
		}
		for(int o=0;o<TAM;o++){
		int indice;
		int valor;
		
		valor=rand()%100;
		indice=indxHash(valor);
			if(o=indice){
				InserirElem(tab[o], valor);
			}	
		}
	printf("Tabela 1 Criada!\n");
	}else if(op==2){
		for(int i=0; i<TAM; i++){
		
			tab2[i] = malloc(sizeof(Lista));
			inicializarLista(tab2[i]);
		}
		for(int o=0;o<TAM;o++){
		int indice;
		int valor;
		
		valor=rand()%100;
		indice=indxHash(valor);
			if(o=indice){
				InserirElem(tab2[o], valor);
			}	
		}
	printf("Tabela 2 Criada!\n");
	}
	
}

void ExibirTab(int op){
	if(op==1){
	
			for(int i=0; i<TAM; i++){
				printf("%d %p TAM%d", (i+1), &tab[i], tab[i]->tam);// a tabela precisa ser uma variavel global
				imprimeNo(tab[i]->pont);//passar o endereço armazenado no pont da lista
				printf("\n");
			}
	}else if(op==2){
		
			for(int i=0; i<TAM; i++){
				printf("%d %p TAM%d", (i+1), &tab2[i], tab2[i]->tam);// a tabela precisa ser uma variavel global
				imprimeNo(tab2[i]->pont);//passar o endereço armazenado no pont da lista
				printf("\n");
			}
			
	}else{
			for(int i=0; i<TAM; i++){
				printf("%d %p TAM%d", (i+1), &tabUniao[i], tabUniao[i]->tam);// a tabela precisa ser uma variavel global
				imprimeNo(tabUniao[i]->pont);//passar o endereço armazenado no pont da lista
				printf("\n");
			}
	}
	
}

int CheckEx(int op){
	if(op==1){
		for(int i=0;i<TAM; i++){
			if(tab[i]->pont!=NULL){
				printf("A tabela 1 existe!\n");
				break;
			}
		}
	}else if(op==2){
			for(int i=0;i<TAM; i++){
				if(tab2[i]->pont!=NULL){
					printf("A tabela 2 existe!\n");
					break;
				}
			}
	}else{
			for(int i=0;i<TAM; i++){
				if(tabUniao[i]->pont!=NULL){
					printf("A tabela Uniao existe!\n");
					break;
				}
			}
		
	}
	
}

void UnirTabs(){
	
	for(int i=0; i<TAM; i++){
		tabUniao[i]=malloc(sizeof(Lista));
		inicializarLista(tabUniao[i]);
	}
	
	for(int o=0; o<TAM; o++){
		No* aux = tab[o]->pont;
		No* aux2 = tab2[o]->pont;
		while(aux!=NULL){
			InserirElem(tabUniao[o], aux->valor);
			aux=aux->prox;
		}
		while(aux2!=NULL){
			InserirElem(tabUniao[o], aux2->valor);
			aux2=aux2->prox;
		}
	}
	printf("Tabelas Unidas!\n");
}

void InserirElem(Lista *L, int valor){//precisa ser o endereço da lista em especifico(posição)
	
 	No* no =malloc(sizeof(No));//no esta recebendo o endereço da estrutura que foi alocada dentro dele
	
	if(L->pont==NULL){// pont é do tipo no, logo recebe o endereco do no
		L->tam++;
		L->pont=no;
		no->valor=valor;
		no->prox=NULL;
	}else{
		no->valor=valor;
		no->prox=L->pont;
		L->tam++;
		L->pont=no;
	}
	
 }

void ExcluirElem(Lista *L, int valor){
	printf("Chamou a excluirElem\n");
	
	No *no = buscaElem(L->pont, valor);// deve retornar o endereco do no para ser excluido
	
	if(no==NULL){
		printf("Nao ha elementos inseridos na lista!");
	}
	
	int valorzk=no->valor;
	
	if(no->prox= NULL){
		free(no);
		printf("Valor excluido %d com sucesso\n", valorzk);
		L->tam--;
	}else {/*Devo percorrer desde o inicio até o prox ser equivalente ao valor de no*/
	
		No *no2 = buscaElem2(L->pont, no);
		no2->prox=no->prox;
		free(no);
		L->tam--;
		printf("Valor excluido %d com sucesso\n", valorzk);
		
	}
}

void imprimeNo(No* aux){
		while(aux!=NULL){
			printf("\t -> %d", aux->valor);
			aux=aux->prox;
		}
}

No *buscaElem2(No* aux1, No* aux2){  //Busca no pelo endereço
	
	if (aux1==NULL){
		printf("Nao ha elementos inseridos na lista!");
		return NULL;
	}else{
		if(aux1->prox=aux2){
			return aux1;
		}else{
			buscaElem2(aux1->prox, aux2);
		}
	}
}

No *buscaElem(No* aux, int valor){	//Busca No pelo valor
	
	if(aux==NULL){
		return NULL;
	}else{
		if(aux->valor=valor){
			return aux;
		}else{
			buscaElem(aux->prox, valor);
		}
		
	}
	
}

