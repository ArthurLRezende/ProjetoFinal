#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaHash.c"


int main(void){
	
	int op;
	
	do{
		menu();
		scanf("%d", &op);
		
		switch(op){
			case 1:
				inserir();
				break;
			case 2:
				checkEx();
				break;
			case 3:
				unirTabs();
				break;
			case 4:
				printf("Finalizando...\n");
				break;
			default:
				printf("Valor invalido!\nPor favor, digite uma das opcoes listadas\n");
				system("pause");
		}
	}while(op!=4);
	
}

