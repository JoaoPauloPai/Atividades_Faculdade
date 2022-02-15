
#include <stdio.h>


int main()
{
	int op;
	float num1, num2;

	


	
		printf("Escolha o seu Lanche: \n 1 - X-Bacan \n 2 - X-Salada ");
	scanf("%d", &op);
	
	if (op == 1){
		
		printf(" X-Bacon - Preco: R$ 18.00 ");
	} 
		if(op == 2 ){
		
		
			printf(" X-Salada - Preco: 15:00");
		}
			if(op >=3 ){
			
			printf(" Operecao invalida \n Digite um numero valido para continuar ");
		}
		
       return (0);		
		
		}
	
