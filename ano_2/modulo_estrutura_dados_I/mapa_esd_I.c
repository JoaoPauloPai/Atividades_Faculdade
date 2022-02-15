// Bibliotecas
#include <math.h>
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define MAX 6
#define MAXIMO 7
int roteiros[MAX][MAX];
// Rotas 
//Rota 1 (1-2) = 2
//Rota 2 (1-3) = 0
//Rota 3 (2-4) = 0
//Rota 4 (2-5) = 1
//Rota 5 (3-2) = 2
//Rota 6 (3-5) = 1
//Rota 7 (4-5) = 2
int op;
int x;
int v = 0;
int vertices = 5;
int destino, origem = 0;
int custo, *custos = NULL;
int i, l, p, j;
// Prototipação
void mensagemNome();//Ref Sistema
void mensagemDadosI();
void mensagemMenuViagem();
void mensagemViagem();
void mensagemErro();
void mensagemSair();
void visulisarRotas();
void criaGrafo(void);
void percorreGrafo();
void verificaGrafo(int custo);
void dijkstra(int vertices,int origem,int destino,int *custos);
int main(int argc, char **argv){
    for(l=0 ;l < MAX; l++){
         for( p=0; p< MAX; p++){
            roteiros[l][p] = -1;
        }
    }
    roteiros[1][2]=2;
    roteiros[1][3]=0;
    roteiros[2][4]=0;
    roteiros[2][5]=1;
    roteiros[3][2]=2;
    roteiros[3][5]=1;
    roteiros[4][5]=2;
	setlocale(LC_ALL,"Portuguese");	  
	do{
    	mensagemNome();
    	mensagemDadosI();
    	mensagemMenuViagem();		
    	scanf("%d",&op);
		switch(op){
			case 1:
			criaGrafo();
			break;
			case 2:	
			percorreGrafo(custo);
			break;
			case 3:
			visulisarRotas();
			break;
			default :
				if(op != 0){
					mensagemNome();
					mensagemErro();
			    	}else{
			         	mensagemNome();
			         	mensagemSair();	
			    	}	
			break;	
		}	
	}while(op != 0);	
	return 0;
}//FIM DO COMANDO MAIN
    void visulisarRotas(){
     	i = 0;
     	mensagemNome();
    	mensagemDadosI();
    	mensagemViagem();
	    printf("\n");
	       for(l=0 ;l < MAX; l++){
                for( p=0; p< MAX; p++){
         	        if(roteiros[l][p] != -1){
	                    printf("           ROTA : 0%d (%d <--> %d) = %d",i+1, l,p,roteiros[l][p]*100);
	                    printf("\n");
	                    i++;
            	   }else{
		         }
               }
        }
         printf("         \n           ");
         system("pause");
   }
    void criaGrafo(void){//Criar Grafo
        int aresta = 1;
      	int i;
	    mensagemNome();
	    mensagemDadosI();
	    mensagemViagem();
           if (!custos) {
           free(custos);
         }
          custos = (int *) malloc(sizeof(int)*vertices*vertices);
              if (custos == NULL) {
              mensagemErro();
              //exit(-1);
            }
           for (i = 0; i <= vertices * vertices; i++){//Preenchendo a matriz com -1
               custos[i] = -1;
            }
     do {
     	mensagemNome();
     	mensagemDadosI();
    	mensagemViagem();
        printf("\n           ENTRE COM A %d ROTA!\n",aresta);
        do {
              printf("\n           ORIGEM  DA ROTA  ", vertices);
              scanf("%d", &origem);
             } while (origem < 0 || origem > vertices);
                 if (origem) {
                   do {
                      printf("\n           DESTINO DA ROTA (de 1 até %d, menos %d) ", vertices,origem);
                      scanf("%d", &destino);
                      } while (destino < 1 || destino > vertices || destino == origem);
                        do {
                           printf("\n           VALOR DA ROTA.  %d DÍGITO DO SEU RA PARA ROTA %d > %d ",aresta, origem, destino);
                           scanf("%d",&custo);
                           custo = custo * 100;
                          } while (custo < 0);
                          custos[(origem-1) * vertices + destino - 1] = custo;
                    }
                      aresta ++;
                     } while (aresta < MAXIMO || aresta == MAXIMO );
                     	mensagemNome();
                     	mensagemDadosI();
                        mensagemViagem();
                        printf("\n           TODOS OS ROTEIROS FORAM PREENCHIDOS!\n");
                        v =1;
                        printf("\n           ");
                        system("pause");
    }
    //Busca os menores caminhos entre os vértices
    void percorreGrafo(int custo){
    	mensagemNome();
    	mensagemDadosI();
        mensagemViagem();
        x = 1;	
	  	if(v == 1){
           for (i = 1; i <= vertices; i++) {
               for (j = 1; j <= vertices; j++) {
               		dijkstra(vertices, i,j, custos);
                }
            }
            printf("\n           ");
            system("pause");
        }
		if(v == 0){
        mensagemNome();
        mensagemErro();
		}
}
    void dijkstra(int vertices,int origem,int destino,int *custos){//Implementação do algoritmo de Dijkstra
         int i, v, cont = 0;
         int *ant, *tmp;
         int *z; /* vertices para os quais se conhece o caminho minimo */
         double min;
         double dist[vertices]; /* vetor com os custos dos caminhos */
         /* aloca as linhas da matriz */
         ant = (int*) calloc (vertices, sizeof(int *));
            if (ant == NULL) {
            	mensagemNome();
            	mensagemErro();
                printf("\n              MEMÓRIA INSUFICIENTE!!");
                exit(-1);
           }
            tmp = (int*) calloc (vertices, sizeof(int *));
                 if (tmp == NULL) {
                 	mensagemNome();
            	    mensagemErro();
                    printf("\n              MEMÓRIA INSUFICIENTE!!");
                    exit(-1);
               }
                 z = (int *) calloc (vertices, sizeof(int *));
                      if (z == NULL) {
                     	mensagemNome();
            	        mensagemErro();
                        printf("\n              MEMÓRIA INSUFICIENTE!!");
                        exit(-1);
                   }     
				       for (i = 0; i < vertices; i++) {
                            if (custos[(origem - 1) * vertices + i] !=- 1) {
                                ant[i] = origem - 1;
                                dist[i] = custos[(origem-1)*vertices+i];
                               }
                                 else {
                                      ant[i]= -1;
                                      dist[i] = HUGE_VAL;
                                    }
                                    z[i]=0;
                                }
                                z[origem-1] = 1;
                                dist[origem-1] = 0;
   do {/* Laco principal */
       min = HUGE_VAL;/* Encontrando o vertice que deve entrar em z */
           for (i=0;i<vertices;i++){
               if (!z[i]){
                     if (dist[i]>=0 && dist[i]<min) {
                          min=dist[i];v=i;
                         }         
                    }
                 }
                 if (min != HUGE_VAL && v != destino - 1) {/* Calculando as distancias dos novos vizinhos de z */
                     z[v] = 1;
                         for (i = 0; i < vertices; i++){
                              if (!z[i]) {
                                    if (custos[v*vertices+i] != -1 && dist[v]+ custos[v*vertices+i] < dist[i]) {
                                        dist[i] = dist[v] + custos[v*vertices+i];
                                         ant[i] =v;
                                        }
                                    }
                            }
                     }
    } while (v != destino - 1 && min != HUGE_VAL);
          if(origem != destino && dist[destino-1] == 0 || dist[destino -1] > 0){/* Mostra o Resultado da busca */
             i = destino;
             i = ant[i-1];
             while (i != -1) {
                 tmp[cont] = i+1;
                 cont++;
                 i = ant[i];
                }
                   for (i = cont; i > 0 ; i--) {
	                   if( dist[destino-1] == 0 || dist[destino -1] > 0 ){
		                    if(x == 1){
		                        mensagemNome();	
	                            mensagemViagem();
                         	}
	                    	if(x > 0){
		                          printf("           ROTEIRO DE VIAGÉM NÚMERO: %d \n",x);
                                  printf("           SAÍDA DO PONTO '%d' ATÉ O PONTO '%d'  (" , origem, destino);
                                  x++;
                            }
                            for (i = cont; i > 0 ; i--) {
                                printf("%d -> ", tmp[i-1]);
                            }
                            printf("%d)", destino);
                            printf(" VALOR : %d\n\n",(int) dist[destino-1]);
                       }
                   }
      }
    }
  void mensagemNome(){// Mensagem do Sistema
  	    system("cls");
	    printf("          +================================================+\n");
	    printf("          |       ALUNO-JOÃO PAULO GOMES DA SILVA          |\n");
	    printf("          |       RA-20012120-5                            |\n");
	    printf("          |       ENGENHARIA DE SOFTWARE                   |\n");
	    printf("          +================================================+\n");  
   }
  void mensagemDadosI(){
    	printf("          +================================================+\n");
   	    printf("          |               ESTRUTURA DE DADOS I             |\n"); 
   	    printf("          +================================================+\n"); 
   }
  void mensagemViagem(){
    	printf("          +================================================+\n");
   	    printf("          |                ROTEIRO DE VIAGENS              |\n"); 
   	    printf("          +================================================+\n"); 
   }
  void mensagemMenuViagem(){
        printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -      INSERIR ROTAS                   |\n");   
	    printf("          |                                                |\n");    
       	printf("          |       2 -      SELECIONAR ROTA                 |\n");
      	printf("          |                                                |\n");
       	printf("          |       3 -      VISUALIZAR ROTAS                |\n");
       	printf("          |                                                |\n");
       	printf("          |       0 -      SAIR DO SISTEMA!                |\n");
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
   	    system("color 8e");
	    printf("          +================================================+\n");
	    printf("          |                   MENSAGEM!!!                  |\n");
	    printf("          |                                                |\n");
	    printf("          |               SAINDO DO SISTEMA.               |\n");
	    printf("          +================================================+\n");
	    printf("\n          ");  
		system("pause");	
	 }
