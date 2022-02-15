//Bibliotecas
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//Constantes
#define tamanho 8
// Variáveis
int qtd;
int i,j,k;
int op;
int barracaOrdem[]={2,3,8,4,6,1,5,7};
int barracas[]={1,2,3,4,5,6,7,8};
int barraca[tamanho];
int barracaOrdenada[tamanho];
int RA[] = {2,0,0,1,2,1,2,0}; //RA-20012120-5 
//Prototipação
void mensagemNome();
void mensagemDadosII();
void mensagemMenuDadosII();
void mensagemBarraca();
void mensagemSair();
void mensagemErro();
void ordena_valores();
void inserir_valores(void);
void mostra_valores(void);
void junta_ordenado(int vec[], int tam);
int ordena_mergeSort(int bar[], int tam, int qtd);
int main(){
	setlocale(LC_ALL,"Portuguese");	  
	do{
	mensagemNome();
	mensagemDadosII();
	mensagemBarraca();
	mensagemMenuDadosII();
	qtd = 0;		
	scanf("%d",&op);
		switch(op){
			case 1:
		    mostra_valores();	
			break;
			case 2:	
			mensagemNome();
			mensagemDadosII();
			ordena_mergeSort(barracaOrdenada, tamanho, qtd);
			ordena_valores();
			break;
			default :
			mensagemNome();
			mensagemDadosII();
			if(op != 0){
    			mensagemNome();
    			mensagemErro();
			   }
			   if(op == 0){
			       	mensagemNome();
			       	mensagemSair();
		         	}
			break;	
		}	
	}while(op!=0);
	return 0;
}
//Mostrar Valores Barracas
void mostra_valores(){
	mensagemNome();
	mensagemDadosII();
	mensagemBarraca();
	for( i = 0; i < tamanho; i++){
		barraca[i] = RA[i];
		barracaOrdenada[i] = barraca[i];
	}
	j = 0;
	printf("          +===============VALORES BARRACAS=================+\n");
	for(i = 0; i < tamanho; i++){
		j = i+1;
		if(barraca[i] == 0){ 
		printf("          BARRACA  N : %d  ",j);
		printf(" VENDEU R$: %d,00  ",barraca[i]);
		printf(" NENHUM VALOR.\n");
	}
		if(barraca[i] == 1){ 
		printf("          BARRACA  N : %d  ",j);
		printf(" VENDEU R$: %d,00  ",barraca[i]);
		printf(" REAL.\n");
	}
	if(barraca[i] > 1){
		printf("          BARRACA  N : %d  ",j);
		printf(" VENDEU R$: %d,00  ",barraca[i]);
		printf(" REAIS. \n");	
	}
	}
	printf("         +================================================+\n         ");
	system("pause");
  }
//Ordena Valores Barraca
void ordena_valores(){
	mensagemNome();
	mensagemDadosII();
	mensagemBarraca();
	printf("          +===============VALORES BARRACAS=================+\n");
    j = 0;
    k = 0;
	for(i = 0; i < tamanho; i++){
		if(barracaOrdenada[i] == 0){ 
		printf("          BARRACA  N : %d  ",barracaOrdem[k]);
		printf(" VENDEU R$: %d,00  ",barracaOrdenada[j]);
		printf(" NENHUM VALOR.\n");
		j++;  k++;
	}	    
		if(barracaOrdenada[i] == 1){ 
		printf("          BARRACA  N : %d  ",barracaOrdem[k]);
		printf(" VENDEU R$: %d,00  ",barracaOrdenada[j]);
		printf(" REAL.\n");
		j++; k++;
	}
	if(barracaOrdenada[i] > 1){
		printf("          BARRACA  N : %d  ",barracaOrdem[k]);
		printf(" VENDEU R$: %d,00  ",barracaOrdenada[j]);
		printf(" REAIS. \n");
		j++; k++;	
	}
	}
	printf("         +================================================+\n         ");
    system("pause");
  }
  //Aplica o modo MergeSort
int ordena_mergeSort(int vec[], int tam, int qtd) {
	int meio;
	if (tam > 1) {
		meio = tam / 2;
		qtd = ordena_mergeSort(vec, meio, qtd);
		qtd = ordena_mergeSort(vec + meio, tam - meio, qtd);
		junta_ordenado(vec, tam);
	}
	return (qtd+1);
}
//Junta os pedaços num novo vetor ordenado
void junta_ordenado(int vec[], int tam) {
	int i, j, k;
	int meio;
	int* tmp;
	tmp = (int*) malloc(tam * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}
	meio = tam / 2;
	i = 0;
	j = meio;
	k = 0;
	while (i < meio && j < tam) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i;
		}
		else {
			tmp[k] = vec[j];
			++j;
		}
		++k;
	}
	if (i == meio) {
		while (j < tam) {
			tmp[k] = vec[j];
			++j;
			++k;
		}
	}
	else {
		while (i < meio) {
			tmp[k] = vec[i];
			++i;
			++k;
		}
	}
	for (i = 0; i < tam; ++i) {
		vec[i] = tmp[i];
	}
	free(tmp);
}
  void mensagemNome(){ //Mensagens do Sistema
        system("color 8F");
  	    system("cls");
	    printf("          +================================================+\n");
	    printf("          |       ALUNO-JOÃO PAULO GOMES DA SILVA          |\n");
	    printf("          |       RA-20012120-5                            |\n");
	    printf("          |       ENGENHARIA DE SOFTWARE                   |\n");
	    printf("          +================================================+\n");  
	 }
  void mensagemDadosII(){
    	printf("          +================================================+\n");
   	    printf("          |            ESTRUTURA DE DADOS II               |\n"); 
   	    printf("          +================================================+\n"); 
   }
  void mensagemBarraca(){
    	printf("          +================================================+\n");
   	    printf("          |              B A R R A C A S                   |\n"); 
   	    printf("          +================================================+\n"); 
   }
  void mensagemMenuDadosII(){
        printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -      FATURAMENTO DO DIA              |\n");   
	    printf("          |                                                |\n"); 
		printf("          |       2-       FATURAMENTO EM ORDEM            |\n");  
      	printf("          |                                                |\n");
       	printf("          |       0 -        SAIR DO SISTEMA!              |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
    void mensagemErro(){
   	    system("color 4e");
	    printf("          +================================================+\n");
	    printf("          |                MENSAGEM ERRO!!!                |\n");
	    printf("          |                                                |\n");
	    printf("          |                OPÇÃO INVÁLIDA.                 |\n");
	    printf("          +================================================+\n");
	    printf("\n          ");  
		system("pause");
		system("color 07");		
	 }
   void mensagemSair(){
   		system("color fc");
	    printf("          +================================================+\n");
	    printf("          |                   MENSAGEM!!!                  |\n");
	    printf("          |                                                |\n");
	    printf("          |               SAINDO DO SISTEMA.               |\n");
	    printf("          +================================================+\n");
	    printf("\n          ");  
		system("pause");	
	 }
