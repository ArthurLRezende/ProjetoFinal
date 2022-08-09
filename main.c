/*Arthur Lima Rezende - 22050182
Alexandre Nunes Martins - 22050172*/
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaHash.c"


int main(void){
	
	int op, op1, op2, op3, op5, op6, valorI, valorE;
	
	do{
		menu();
		scanf("%d", &op);
		
		switch(op){
			case 1:
				
				do{
					printf("Insira:(1)Tabela 1\t(2)Tabela 2\n");
					scanf("%d", &op1);
					
					if(op1==1 || op1==2){
						CriarTab(op1);
					}else{
						printf("Insira apenas os valores apresentados\n");
					}
				}while(op1!=1 && op1!=2);
				
				break;
			case 2:
				
				do{
					printf("Insira:(1)Tabela 1\t(2)Tabela 2\t(3)Tabela Unida\n");
					scanf("%d", &op2);
					
					if(op2==1 || op2==2 || op2==3){
						ExibirTab(op2);
					}else{
						printf("Insira apenas os valores apresentados\n");
					}
				}while(op2!=1 && op2!=2 && op2!=3);
				break;
			case 3:
				
				do{
					printf("Insira:(1)Tabela 1\t(2)Tabela 2\t(3)Tabela Unida\n");
					scanf("%d", &op3);
					
					if(op3==1 || op3==2 || op3==3){
						CheckEx(op3);
					}else{
						printf("Insira apenas os valores apresentados\n");
					}				
				}while(op3!=1 && op3!=2 && op3!=3);
				break;
			case 4:
				UnirTabs();
				break;
			case 5:
					do{
						
						printf("Insira:(1)Tabela 1\t(2)Tabela 2\n");
						scanf("%d", &op5);
						printf("Insira o valor a ser adicionado a tabela:\n");
						scanf("%d", &valorI);
						
					if(op5==1){
						InserirElem(tab[indxHash(valorI)], valorI);
					}else if(op5==2){
						InserirElem(tab2[indxHash(valorI)], valorI);
					}else if(op5==3){
						InserirElem(tabUniao[indxHash(valorI)], valorI);
					}else{
						printf("Insira apenas os valores apresentados\n");
					}
					}while(op5!=1 && op5!=2 && op5!=3);
				break;
			case 6:
	
					do{
						
						printf("Insira:(1)Tabela 1\t(2)Tabela 2\n");
						scanf("%d", &op6);
						printf("Insira o valor a ser excluido da tabela:\n");
						scanf("%d", &valorE);
						
					if(op6==1){
						ExcluirElem(tab[indxHash(valorE)], valorE);
					}else if(op6==2){
						ExcluirElem(tab[indxHash(valorE)], valorE);
					}else if(op6==3){
						ExcluirElem(tab[indxHash(valorE)], valorE);
					}else{
						printf("Insira apenas os valores apresentados\n");
					}
					}while(op6!=1 && op6!=2 && op6!=3);
				break;
			case 7:
				printf("Finalizando...\n");
				break;
			default:
				printf("Valor invalido!\nPor favor, digite uma das opcoes listadas\n");
				system("pause");
		}
	}while(op!=7);
	
}

