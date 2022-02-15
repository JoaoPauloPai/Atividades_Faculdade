#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define MAX 500
#define NUM 100
typedef struct ObrasArquiteto{ 
	char tipo[10];
   	char titulo[30];
   	int edicao;
   	char nomeAutor[30];
   	char editora[30];
   	int ISBN;
   	int quantidade;
   	int nCaixa;
	int obraN;
	int obra_L_R;//0 para Livros 1 para Revistas    	
   }obra;
    void listarObras(int cod, obra obras[]);
    void cadastrarObras(obra obras[]);
    int ler_arquivo(obra obras[]);
    void listarObraPorCaixa(int caixa, obra obras[]);
    void MensagemMenu1();
    void MensagemMenu();
    void MensagemErro();
    void MensagemNome();
    void MensagemPesquisar();
    int i,j = 0;
    int t;
    int cod;
    int caixa; 
    int main(){
		setlocale(LC_ALL,"Portuguese");
		obra obras[MAX];
    	int op, op1;	
	    char resp = 's';   
        do{
        	system("cls");
        	MensagemNome();
        	MensagemMenu();        
	        scanf("%d",&op);
        	switch(op){
    	    	case 1:
    	    		system("cls"); 	
    	    		MensagemNome();
    	        	 MensagemMenu1();  
				    scanf("%d",&op1); 
    	         	switch(op1){
    	   	        	case 1:
    	   	        	system("cls");
    	   	   	    	MensagemNome(); 
    	   	   	    	resp ='s';
			        	while((resp=='S') || (resp=='s')){
				        t = 0;
				   	    printf("          +==============CADASTRO DE LIVROS=============+");
						strcpy(obras[i].tipo,"LIVRO");    
					    cadastrarObras(obras);  
			            printf("\n\n\n           Deseja cadastrar novo Livro? \n");
	                    printf("           Digite 's' para sim e 'n' para não.\n");
		                printf("\n           [s] - SIM  [n] - NÃO ");  
		                fflush(stdin);
		                scanf("%c", &resp);
	                	if((resp == 's') || (resp == 'S'));	
	                	system("cls");
	                	MensagemNome(); 
			         	}
					    break;
    	   	         	case 2:
    	   	         	system("cls");
    	   	   	    	MensagemNome(); 
    	   	   	    	resp ='s';
			        	while((resp=='S') || (resp=='s')){
				   	    printf("          +=============CADASTRO DE REVISTAS============+");
				   	    strcpy(obras[i].tipo,"REVISTA");     
				   	    t = 1;
					    cadastrarObras(obras); 
			            printf("\n\n\n           Deseja cadastrar nova Revista? \n");
	                    printf("           Digite 's' para sim e 'n' para não.\n");
		                printf("\n           [s] - SIM  [n] - NÃO ");  
		                fflush(stdin);
		                scanf("%c", &resp);
	                	if((resp == 's') || (resp == 'S'));	
	                	system("cls");
						MensagemNome();  
    	   	         }
    	    	    break;
    	        	default:
    	       	        system("cls");
    	  	         	MensagemNome();
    	  	  	        MensagemErro();
			            system("pause");
    	         	break;
    	           }//FIM DO SWITCH INTERNO
    	        break;
    	    	case 2:
				    system("cls");
				   	MensagemNome();
    	            printf("          +==================LISTA DE LIVROS===============+"); 
    	            cod = 0;
    	            listarObras(cod, obras);  
    	    	break;
    	    	case 3:
				    system("cls"); 
    	        	MensagemNome();
    	         	 printf("          +================LISTA DE REVISTAS===============+"); 
    	            cod = 1;
    	            listarObras(cod, obras);  
    	    	break;
    	    	case 4:
			     	system("cls"); 
    	    	    MensagemNome(); 
    	    	    MensagemPesquisar();
					listarObraPorCaixa(caixa, obras);        
    	    	break;
    	    	case 5:
					system("cls"); 
    	        	MensagemNome();
    	  	    	printf("\n");
			        printf("\n          SAINDO DO SISTEMA!\n");
    	    	break;
    	    	default:
    	    		system("cls");
    	  	    	MensagemNome();
    	  	  	    MensagemErro();
			        system("pause");    
    	    	break;
        }
   }while(op!=5);
   return 0;      
    }//FIM DO COMANDO MAIN
    void cadastrarObras(obra obras[]){
   	FILE * arq;
	arq = fopen("dadosObras1.txt", "a+");
	if(arq != NULL){
	     printf("\n          OBRA N°:%d \n", i+1);
	     obras[i].obra_L_R = t;
	     printf("          DIGITE O TÍTULO      : ");
	     obras[i].obraN = i +1;
         fflush(stdin);
         gets(obras[i].titulo); 
         printf("          DIGITE O AUTOR       : ");
         fflush(stdin);
         gets(obras[i].nomeAutor);
         printf("          DIGITE A EDITORA     : ");
         fflush(stdin);
         gets(obras[i].editora);
         printf("          DIGITE A EDIÇÃO      : ");
         fflush(stdin);
         scanf("%d",&obras[i].edicao);
         printf("          DIGITE O NÚMERO ISBN : ");
         fflush(stdin);
         scanf("%d", &obras[i].ISBN);
         printf("          QUANT DE EXEMPLARES  : ");
         fflush(stdin);
         scanf("%d",&obras[i].quantidade);
         printf("          NÚMERO DA CAIXA      : ");
         fflush(stdin);
         scanf("%d",&obras[i].nCaixa);
       	 
       	fwrite(&obras[i], sizeof(obra), 1, arq);
		fclose(arq); // aborta o programa
		}
		else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
int ler_arquivo(obra obras[])
{
	FILE * arq = fopen("dadosObras1.txt", "r");
	if(arq != NULL)
	{
		int i = 0;
		while(1)
		{
			obra t;
			size_t r = fread(&t, sizeof(obra), 1, arq);
			if(r < 1)
				break;
			else
				obras[i++] = t;
		}
		fclose(arq); // fecha o arquivo
		return i;
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
 void listarObras(int cod, obra obras[]){
	FILE *arq; 	
	arq = fopen ("dadosObras1.txt", "r");
	fread(obras, sizeof (int), 10, arq); 	
	int len_vet = ler_arquivo(obras);	
	int j;
	for(j = 0; j < len_vet; j++){
		if(cod == obras[j].obra_L_R){
      	printf("\n          | OBRA N° : %d ", j+1);printf("     EDITORA : %s ",obras[j].editora);
       	printf("          OBRA TIPO : %s \n",obras[j].tipo);
	 	printf("          | TÍTULO  : %s            ",obras[j].titulo);
		printf("              AUTOR  : %s           \n",obras[j].nomeAutor);
		printf("          | EDIÇÃO Nº :%d ",obras[j].edicao);
		printf("           ISBN Nº :%d ",obras[j].ISBN);
		printf("           QUANTIDADE: %d ",obras[j].quantidade);
	    printf("           ENDEREÇO CAIXA Nº: %d\n",obras[j].nCaixa); 
	    printf("          +================================================+==================");
	}
	}
	fclose(arq);
	getch();
}
 void listarObraPorCaixa(int caixa, obra obras[]){
 	system("cls"); 
    MensagemNome();
 	FILE *arq; 	
	arq = fopen ("dadosObras1.txt", "r");
	fread(obras, sizeof (int), 10, arq); 	
	int len_vet = ler_arquivo(obras);	
	int j;
	for(j = 0; j < len_vet; j++){
		if(caixa == obras[j].nCaixa){
		printf("          +=================LISTA POR CAIXA================+"); 	
      	printf("\n          | OBRA N° : %d ", j+1);printf("     EDITORA : %s ",obras[j].editora);
       	printf("          OBRA TIPO : %s \n",obras[j].tipo);
	 	printf("          | TÍTULO  : %s            ",obras[j].titulo);
		printf("              AUTOR  : %s           \n",obras[j].nomeAutor);
		printf("          | EDIÇÃO Nº :%d ",obras[j].edicao);
		printf("           ISBN Nº :%d ",obras[j].ISBN);
		printf("           QUANTIDADE: %d ",obras[j].quantidade);
	    printf("           ENDEREÇO CAIXA Nº: %d\n",obras[j].nCaixa); 
	    printf("          +================================================+==================");
	}
 	
 }
 	fclose(arq);
	getch();
}
               void MensagemMenu1(){
	            printf("\n\n\n          +================================================+");
	            printf("\n          |                                                |");
    	        printf("\n          |                                                |");   
	           	printf("\n          |                                                |");    
             	printf("\n          |       1 - INCLUIR REGISTROS DOS LIVROS         |");
            	printf("\n          |                                                |");
            	printf("\n          |                                                |");
            	printf("\n          |                                                |");
            	printf("\n          |                                                |");
    	    	printf("\n          |       2 - INCLUIR REGISTROS DAS REVISTAS       |");
             	printf("\n          |                                                |");
             	printf("\n          |                                                |");
            	printf("\n          +================================================+");
            	printf("\n\n                    Entre com a opção desejada! ");
	}  
	 void MensagemMenu(){
    	    printf("\n          +================================================+");
	        printf("\n          |                                                |");
    	    printf("\n          |       1 - INCLUIR REGISTROS DAS OBRAS          |");   
	    	printf("\n          |                                                |");    
        	printf("\n          |       2 - LISTAR TODOS OS LIVROS               |");
        	printf("\n          |                                                |");
        	printf("\n          |       3 - LISTAR TODAS AS REVISTAS             |");
        	printf("\n          |                                                |");
        	printf("\n          |       4 - LISTAR AS OBRAS POR CAIXA            |");
    		printf("\n          |                                                |");
          	printf("\n          |       5 - SAIR DO SISTEMA.                     |");
           	printf("\n          |                                                |");
        	printf("\n          +================================================+");
        	printf("\n\n                    Entre com a opção desejada! ");      
    }
     void MensagemErro(){
	    printf("\n\n          +================================================+");
	    printf("\n          |                                                |");
        printf("\n          |                MENSAGEM DE ERRO!               |");   
	   	printf("\n          |                                                |");    
       	printf("\n          |             DIGITE UM NÚMERO VÁLIDO            |");
       	printf("\n          |                                                |");
       	printf("\n          |             SISTEMA NÃO RECONHECEU             |");
       	printf("\n          |                                                |");
       	printf("\n          |                       O                        |");
    	printf("\n          |                                                |");
       	printf("\n          |               COMANDO DIGITADO.                |");
       	printf("\n          |                                                |");
       	printf("\n          +================================================+");
        printf("\n\n\n          Erro...  ");
	 }
	 void MensagemNome(){
	    printf("          +================================================+\n");
	    printf("          |       ALUNO-JOÃO PAULO GOMES DA SILVA          |\n");
	    printf("          |       RA-20012120-5                            |\n");
	    printf("          |       ENGENHARIA DE SOFTWARE                   |\n");
	    printf("          +================================================+\n");  
	 }
	  void MensagemPesquisar(){
	    printf("          +================================================+\n");
	    printf("          |                 PARA PESQUISAR                 |\n");
	    printf("          |                                                |\n");
	    printf("          |           DIGITE O NÚMERO DA CAIXA             |\n");
	    printf("          +================================================+\n");
	    printf("\n                                ");
		fflush(stdin);
	    scanf("%d", &caixa);  
	 }





