//Bibliotecas em uso
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<string.h>
#include<windows.h>
//Constantes Dados I e II
#define tamanho 10
#define tamAr 100
#define MAX 6
#define MAXIMO 7
// Rotas 
//Rota 1 (1-2) = 2
//Rota 2 (1-3) = 0
//Rota 3 (2-4) = 0
//Rota 4 (2-5) = 1
//Rota 5 (3-2) = 2
//Rota 6 (3-5) = 1
//Rota 7 (4-5) = 2
int roteiros[MAX][MAX];
//Estrururas (Structs)
typedef struct tpilha{// PILHAS
	int dados[tamanho];
	int inc;
	int fim;
}tpilha; 
typedef struct lista{
  int tabuada;
  struct lista *prox;
}no1;
//Variaveis Dados II
int li = 0;
char titulo[30];
int lista[tamanho];
int lista2[tamanho];
int ordenado[tamanho];
int troca[tamanho];
int grafo[tamanho][tamanho];
int numero;
int tc = 0;
int tempo = 0;
int opt = -1;
int opt_1 = -1; 
int opt_2 = -1;
int opt_3 = -1;
int opt_4 = -1;
int opt_5 = -1;
int qtd;
int i, j, k, y, x, l, p;
int contArv = 0;
int lado, temp;
char pai, no;
//Variaveis Dados I
int vertices = 5;
int destino, origem = 0;
int custo, *custos = NULL;
int cand1, cand2, cand3, cand4;
int votos, branco, nulo;
int vertices;
int voto = 1;
int pop = 0;
int push = 0;
int opt1 = -1;
int opt1_1 = -1;
int opt1_2 = -1;
int opt1_3 = -1;
int opt1_4 = -1;
int opt1_5 = -1;
int opt1_6 = -1;
int n_1, n_2;
//int *p;
int t_1;
int v = 0;
struct tpilha pilha;
//Prototipação 
//Ref Sistema                      
void mensagemNome();
void mensagemSair();
void mensagemErro();
void estruturaDados();
void menuPrincipal();
void dadosII();
void dadosI();
void menuEstrturaDadosI();
void mensagemMenuViagem();
void mensagemViagem();
//Dados II
void menuEstruturasII();
void menuOrdenacao();
void menuLista();
void tecnicaOrdenacao();
void ordenadoBulbbesort();
void ordenadoSelectionsort();
void ordenadoInsertionsort();
void menuModeloOrdenacao();          
void menu_mostrar(void);
void menuArvoresBinarias();
void trocar(int* a, int* b);
void procura_arvore(char dado);
void mostra_arvore();
void insere_arvore(int pai, char dado, int lado);
void arvoresBinarias();
void lista_mostrar();
void lista_gerar();
void lista_inserir_valores();
void lista_ler();
void lista_prepara();
void lista_ordenada();
void chamaModoOrdenado();
void lista_gerar_ordenado();
void insertionsort();
void bulbblesort();
void selectionsort();
//Dados I
void menuAtividadeI();
void menuAlocacoesI();
void alocacoesDadosI();
void menuCalculador();
void menuPilhas();
void menuPonteiros();
void menuUrnaEletronica();
void menuCandidatos();
void atividadeI();
void funcaoPop();
void funcaoPush();
void tabuadaDadosI();
void tabuadaDI();
void numeroTabuadaDI();
void menuAresta();
void inserir(int x, no1 *p);
void imprimir(no1 *le, int valor  );
void calculadoraDadosI();
void calcularDadosI();
void ponteiros();
void chamarPonteiros();
void alocarVetorPonteiro();
void alcoolGasolina();
void funcaoDisplay();
void alocarMemoria(); 
void imprimirAlocacao();
void pilhas();
void mostraPilha();
void inserirDadosPilha();
void retiraDadosPilha();
void desenhaGrafo();
void defineGrafico(); 
void inserirAresta();
void removerAresta();
void urnaEletronica();
void cabineEletronica(); 
void apuracaoVotos(int cand1, int cand2, int cand3, int cand4, int branco);
void criaGrafo(void);
void percorreGrafo(int custo);
void dijkstra(int vertices,int origem,int destino,int *custos);
void visulisarRotas();
//Funcao Principal
int main(int argc, char **argv){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	do{
		mensagemNome();
		estruturaDados();
		menuPrincipal();
		scanf("%d",&opt);
		switch(opt){//Swith 1.
		case 1:  //case 1.
		do{ //Dados I Inicio 
		    mensagemNome();
		    dadosI();
		    menuEstrturaDadosI();
		    scanf("%d",&opt1);
		    switch(opt1){ //swith 1.1
		    case 1:	      //Case 1.1.A
		     do{
		        mensagemNome();
		        dadosI();
		        alocacoesDadosI();
		        menuAlocacoesI();
		        scanf("%d",&opt1_1);
		        switch(opt1_1){
			    case 1:
			    mensagemNome();
				dadosI();
				alocacoesDadosI();
				tabuadaDI();
			    tabuadaDadosI();
			   	break;
			    case 2:
			    mensagemNome();
				dadosI();
				calculadoraDadosI();
				calcularDadosI();	
			    break;
			    case 3:
				alcoolGasolina();	
			   	break;
			   	case 4:
			   		do{
				     mensagemNome();
		             dadosI();
		             ponteiros();
		             menuPonteiros();
		             scanf("%d",&opt1_3);
		             switch(opt1_3){
			         case 1:      
			     	chamarPonteiros();
			     	break;
			     	case 2:
			        alocarVetorPonteiro();
			     	break;
			     	case 3:
			     		do{	 
			     	mensagemNome();
			     	urnaEletronica();
			     	menuUrnaEletronica();
			     	 scanf("%d",&opt1_5);
		             switch(opt1_5){
			         case 1:
			         cabineEletronica();
			     	break;
			     	case 2:
			        apuracaoVotos(cand1, cand2, cand3, cand4, branco);
			     	break;
			     	default:
			     	if(opt1_5 != 0){
    		         	mensagemNome();
    		    	    mensagemErro();
			       }
			       else{
		         	}
			     	break;
			        }
			       }while(opt1_5 != 0);
			       opt1_3 = 0;
			       opt1_1 = 0;
			       opt1 = 0;
			     	break;
			    	default :
			   		if(opt1_3 != 0){
    		    	mensagemNome();
    		    	mensagemErro();
			       }
			       else{
		         	}
			   	break;
			   }
			   }while(opt1_3 != 0);
			   opt1_1 = -0;
			   opt1 = 0;
			   	break;
			    default:
			    if(opt1_1 != 0){
    		    	mensagemNome();
    		    	mensagemErro();
			   }
			   else{
		         	}
			    break;
		     	}
		       }while(opt1_1 != 0);
		       opt1 = 0;
		    break;
		    case 2:
		    do{	
		        mensagemNome();
		        pilhas();
		        menuPilhas();
		        scanf("%d",&opt1_1);
		        switch(opt1_1){
			    case 1:
			            mensagemNome();
			            pilhas();	
		                mostraPilha();
		            break;
		            case 2:
		             	mensagemNome();
		             	pilhas();
		                inserirDadosPilha();
		         	break;
		         	case 3:
		             	mensagemNome();
		             	pilhas();
		             	retiraDadosPilha();
		         	break;
		         	case 4:
		         		do{
		                	mensagemNome();
		                	pilhas();
		        	        menuAtividadeI();
		                 	scanf("%d",&opt1_2);
		                	switch(opt1_2){
		                		case 1:
		                		mensagemNome();
								atividadeI();
								funcaoPop();	
		                		break;
		                		case 2:
		                		mensagemNome();
								atividadeI();
							    funcaoPush();
		                		break;
		                		case 3:
		                		mensagemNome();
								atividadeI();
								funcaoDisplay();
		                		break;		                		
		                	}
		            }while(opt1_2 != 0);
		            opt1_1 = 0;
		            opt1 = 0;
		         	break;
	    	        }
	        }while(opt1_1 != 0);
	        opt1 = 0;
            break;
			case 3:
				do{
				mensagemNome();
			    menuAresta();
			    scanf("%d",&opt1_4);
			    switch(opt1_4){
			    	case 1:
			     	defineGrafico();
			     	break;
			        	case 2 :
		         	    inserirAresta();
			        	break;
			            	case 3:
			                removerAresta();
			                break;
			                   case 4:
			            	   desenhaGrafo();
			                    break;
			                  	default:
				             	if(opt1_4 != 0){
    		                    	mensagemNome();
    		                    	mensagemErro();
			                         }
			                   else{
		                      	}
			                	break;
			                 	}
				}while(opt1_4 != 0);
				opt1 = 0;
			break; 
			case 4:
				do{
				    mensagemNome();
                    dadosI();
                 	mensagemMenuViagem();		
                	scanf("%d",&opt1_6);
	             	switch(opt1_6){
		         	case 1:
		         	criaGrafo();
		         	break;	
		         	case 2:
		         	percorreGrafo(custo);
		         	break;
					case 3:
					visulisarRotas();
					break;	
		         }
			}while(opt1_6 != 0);
			opt1 = 0;
			break;	
			default:
				 if(opt1 != 0){
    		    	mensagemNome();
    		    	mensagemErro();
			   }
			   else{
		         	}
			    break;
		}//Fim Switch Dados I	
    	}while(opt1 != 0);
	    break;     // Fim Dados I	
		case 2://Innioco case 2 Principal
	    	mensagemNome();//Inicio Dados II
	    	dadosII();
	    	menuEstruturasII();
	    	scanf("%d",&opt_3);
		    switch(opt_3){	
			case 1:
			do{
			mensagemNome();
			tecnicaOrdenacao();
			menuOrdenacao();
			scanf("%d",&opt_1);	
				switch(opt_1){
				case 1:
					lista_gerar();
				break;
			    	case 2:
				   	mensagemNome();
					tecnicaOrdenacao();
					menuLista();
					scanf("%d",&opt_4);
				        if(opt_4 == 1){
				         lista_mostrar();
				     	}
				    	if(opt_4 == 2){
				    	chamaModoOrdenado();
				     	}
			     	break;
				case 3:
			    	lista_inserir_valores();
				break;
				case 4:
			        mensagemNome();
			        tecnicaOrdenacao();
		            menuModeloOrdenacao();
		            scanf("%d",&opt_2);	
					if(opt_2 == 1){
				     	bulbblesort(qtd);			
			         	}
			    	    if(opt_2 == 2){
			    	      	insertionsort();
			             	}
				         	if(opt_2 == 3){
					         	mensagemNome();
					        	tecnicaOrdenacao();
					        	selectionsort();
				             	}
				            	if(opt_2 != 1 ||opt_2 != 2 ||opt_2 != 3 ||opt_2 != 0){
					         	mensagemNome();
		                        mensagemErro();	
				             	}
			    	break;              
				}
			}while(opt_1 !=0);
			break; //Aqui o final
			default:
			mensagemNome();
			mensagemErro();	
		break;	
		}//Aqui comecaii
    	break;
    	default:
    		if(opt != 0){
    			mensagemNome();
    			mensagemErro();
			   }
			   if(opt == 0){
			       	mensagemNome();
			       	mensagemSair();
		         	}
        break;
	}	//Fim Switch 01
	}while(opt!=0);//Fim do laço Principal'do'
	return 0;
}//Fim do Comando Main
//DADO I    *FUNÇÂO POP ATIDADE I
   void funcaoPop(){//Funcao POP remove
   	pop = pop +1;
	if(pilha.inc == pilha.fim){
       	printf("           PILHA NÃO TEM NENHUM VALOR PARA RETIRAR!!!\n\n           ");
       	printf(" \n            VOCE CHAMOU A FUNCAO  POP : %d X \n            ",pop);
       	system("pause");
        }
        else{
            pilha.dados[pilha.fim-1] = 0;
            pilha.fim --;
            }
    }
    void funcaoPush(){//Funcao PUSH adiciona
    	if(pilha.fim < tamanho){
    	pilha.dados[pilha.fim] = rand() %99;
    	pilha.fim ++;
	    push = push +1;
    	printf(" \n            VOCE CHAMOU A FUNCAO  PUSH : %d X \n            ",push);
    	system("pause");
        }
	}		
   void funcaoDisplay(){//FUNÇÂO DYSPLAY ATIDADE I
		printf("\n          +====================  P I L H A ================+\n");
	    printf("           [  ");
        	for(i = 0; i < tamanho; i++){
	    	printf("%d ",pilha.dados[i]);
         	}
       	printf(" ] ");
     	printf("\n          +================================================+\n");
    	printf("\n\n   ");
    	system("pause");
   }	 
   void inserirDadosPilha(){//inseri dados na Pilha
        if(pilha.fim == tamanho){
            printf("\n          +==================== P I L H A =================+\n");
         	printf("\n          +=================== ESTA CHEIA !! ==============+\n");
         	printf("\n          +================================================+\n");
         	system("pause");	
     	   }
        	if(pilha.fim > 0 && pilha.fim < tamanho){
            	printf("\n          +====================  P I L H A ================+\n");
            	printf("              DIGITE OUTRO VALOR A SER EMPILHADO !!  \n");
            	printf("              VALOR : ");
                scanf("%d",&pilha.dados[pilha.fim]);
                pilha.fim ++;	
            	}
            	if(pilha.fim == 0){
                	printf("\n          +====================  P I L H A ================+\n");
                 	printf("              DIGITE O VALOR A SER EMPILHADO !!  \n");
                	printf("              VALOR : ");
                    scanf("%d",&pilha.dados[pilha.fim]);
                     pilha.fim ++;	
             	}	
        }
    void retiraDadosPilha(){//Retirar dados da Pilha
        	if(pilha.inc == pilha.fim){
            	printf("           PILHA NÃO TEM NENHUM VALOR PARA RETIRAR!!!\n\n           ");
	            system("pause");
                }
                else{
                     pilha.dados[pilha.fim-1] = 0;
                     pilha.fim --;
             	}	
           }
    void mostraPilha(){ // Imprimir Pilha
        	printf("\n          +====================  P I L H A ================+\n");
        	printf("           [  ");
         	for(i = 0; i < tamanho; i++){
	         	printf("%d ",pilha.dados[i]);
            	}
             	printf(" ] ");
             	printf("\n          +================================================+\n");
             	printf("\n           ");
            	system("pause");
          	}
   void visulisarRotas(){
   	    for(l=0 ;l < MAX; l++){
             for( p=0; p< MAX; p++){
             roteiros[l][p] = -1;
        }
         roteiros[1][2]=2;
         roteiros[1][3]=0;
         roteiros[2][4]=0;
         roteiros[2][5]=1;
         roteiros[3][2]=2;
         roteiros[3][5]=1;
         roteiros[4][5]=2;
    }
     	i = 0;
     	mensagemNome();
    	dadosI();
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
   //Busca os menores caminhos entre os vértices
    void percorreGrafo(int custo){
    	mensagemNome();
    	dadosI();
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
   void criaGrafo(void){//Criar Grafo
        int aresta = 1;
      	int i;
	    mensagemNome();
	    dadosI();
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
     	dadosI();
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
                     	dadosI();
                        mensagemViagem();
                        printf("\n           TODOS OS ROTEIROS FORAM PREENCHIDOS!\n");
                        v =1;
                        printf("\n           ");
                        system("pause");
    }
    void cabineEletronica(){//Votação Eletrônica
         int cand_op;
         mensagemNome();
         urnaEletronica();
         menuCandidatos();
         scanf("%d",&cand_op);
             if(cand_op == 0){
      	         mensagemNome();
    	         urnaEletronica();
    	         branco = branco + voto;
    	         votos = votos + voto;
             	}
                 if(cand_op == 1){
                  	mensagemNome();
                 	urnaEletronica();
                 	cand1 = cand1 + 1;
                 	votos = votos + voto;
                    }
                    if(cand_op == 2){
                     	mensagemNome();
                     	urnaEletronica();
                     	cand2 = cand2 + voto;
                     	votos = votos + voto;	
                     	}
     	                if(cand_op == 3){
                         	mensagemNome();
                         	urnaEletronica();
                         	cand3 = cand3 + voto;
                         	votos = votos + voto;
			             	}
              	            if(cand_op == 4){
                             	mensagemNome();
                             	urnaEletronica();
                    	        cand4 = cand4 + voto;
                             	votos = votos + voto;	
                    	        }
                             	if(cand_op > 4 || cand_op < 0){
                             		mensagemNome();
                    	         	urnaEletronica();
                             		mensagemErro();
					              	}
        printf("\n          SEU VOTO FOI REGISTRADO COM SUCESSO!\n          ");   
        system("pause");            
       }
    void apuracaoVotos(int cand1, int cand2, int cand3, int cand4, int branco){
     	mensagemNome();
     	urnaEletronica();
	 	printf("               TOTAL DE VOTOS \n");
       	printf("          Dr JOSÉ A. SOUZA             : %d\n",cand1);
       	printf("          PROF.  MARIA L. GOMES        : %d\n",cand2);
	    printf("          CAP MARCOS SILVA             : %d\n",cand3);
	 	printf("          DONA IZA DA FARMÁCIA         : %d\n",cand4);
	    printf("          VOTOS EM BRANCOS E NULOS     : %d\n          ",branco);
        	system("pause");
    }
    void inserirAresta(){
     	mensagemNome();
     	int num1, num2;
         printf("\n         ESCOLHA O VÉRTICE DE ORIGEM ENTRE '0' E '%d':",vertices-1);         
         scanf("%d",&num1);
         printf("\n         ESCOLHA O VÉRTICE DE DESTINO ENTRE '0' E '%d':",vertices-1);     
         scanf("%d",&num2);  
             if (num1 > vertices-1 || num2 > vertices-1 || num1 <0  || num2 <0){ 
                mensagemNome();
                printf("\n         OS VALORES PRECISAM ESTAR ENTRE '0' E '%d'\n\n",vertices-1);   
               	printf("        ");           
                system("pause");
                }
                else {
                     grafo[num1][num2]=1;
                     grafo[num2][num1]=1;     
                 }
    } 
    void removerAresta(){
         mensagemNome();
         int num1, num2;
         if(vertices != 0){
             printf("\n         ESCOLHA O VÉRTICE DE ORIGEM ENTRE '0' E '%d':",vertices-1);         
             scanf("%d",&num1);
             printf("\n         ESCOLHA O VÉRTICE DE DESTINO ENTRE '0' E '%d':",vertices-1);     
             scanf("%d",&num2);
             }
                 if (num1 > vertices-1 || num2 > vertices-1 || num1 <0  || num2 <0){ 
                 mensagemNome();
                 mensagemErro(); 
                 }
                  else {
                         grafo[num1][num2]=0;
                         grafo[num2][num1]=0;     
                }
    } 
    void defineGrafico(){//Função para desenhar a matriz de arestas
         mensagemNome();
         printf("           DIGITE O NÚMERO DE VÉRTICES : ");
         scanf("%d", &vertices); 
         if(vertices <= 0 || vertices > tamanho){
  	         mensagemErro();
            } 
                if(vertices > 0 && vertices < tamanho){
                 	desenhaGrafo();
                   }
    }
    void desenhaGrafo(){ //Desenhando matriz de adjacência
         if(vertices != 0){
   	         mensagemNome();
  	         int j;
  	         printf("                MATRIZ DE ADJACÊNCIAS\n\n ");  
             printf("            ");
             for (j = 0; j < vertices; j++){
  	             printf("  %d", j);          
                }
                     printf("  \n");       
                        for (i = 0; i < vertices; i++){
  	                        printf("\n          ");
  	                        printf("%d", i);
  	                        printf("  ");
                                for (j = 0; j < vertices; j++){
                                     printf("  %d", grafo[i][j]);          
                                   }
                                        printf("\n");             
                            }
                                 printf("\n          ");    
                                 system("pause");
        }else{
            mensagemNome();
            mensagemErro();
          }  
    }	
    void alocarVetorPonteiro(){
     	mensagemNome();
     	dadosI();
    	int i;
	    int tam;
    	int *vetor;
     	printf("\n            DIGITE O TAMANHO DO VETOR : ");
	    scanf("%d",&tam);
    	fflush(stdin);
     	vetor = (int *) malloc(sizeof(int)*tam);
        	for(i = 0; i < tam; i++){
		        vetor[i] = rand() %99;
	         	printf("\n            POSIÇÃO DO VETOR = %d, VALOR DO VETOR = %d", i, vetor[i]);
	           }
	           printf("\n\n              ");
	           system("pause");
    }
    void chamarPonteiros(){//Chama Ponteiros
     	int vlr;
	    int *ptr_vlr;
	    ptr_vlr = &vlr;
	    int *ptr_vlr1;
	    ptr_vlr1 = (int *)malloc(sizeof(int));
	    mensagemNome();
	    dadosI();
     	ponteiros();
	    printf("\n            DIGITE O VALOR : ");
     	scanf("%d",&vlr);
     	fflush(stdin);
     	printf("\n            VALOR DIGITADO = : %d",vlr);
    	printf("\n            ENDEREÇO DE VALOR &valor = : %p",&vlr);
     	printf("\n            ENDEREÇO DE PTR_vlr =  : %p",ptr_vlr);
    	printf("\n            VALOR DE *PTR_vlr: %d", *ptr_vlr);
        printf("\n            ENDEREÇO DE *PTR_vlr1 =  : %p",ptr_vlr1);
    	printf("\n\n           ");
    	system("pause");
    }
    void alcoolGasolina(){//Alcool ou Gasolina
     	float al, ga, rsl;
     	mensagemNome();
    	dadosI();
     	alocacoesDadosI();
    	printf("\n            DIGITE O PREÇO DO ALCOOL : ");
    	scanf("%f",&al);
    	fflush(stdin);
     	mensagemNome();
    	dadosI();
    	calculadoraDadosI();
    	printf("\n            DIGITE O PREÇO DA GASOLINA : ");
    	scanf("%f",&ga);
     	fflush(stdin);
    	rsl = al / ga;
     	if(rsl < 0.73){
	     	printf("\n            É MELHOR USAR O ALCOOL!!!");
        	}
         	else{
	         	printf("\n            É MELHOR USAR A GASOLINA!!! ");
            	}
    printf("\n\n          ");  
   	system("pause");	
    }
    void calcularDadosI(){//CALCULADORA
     	float num1, num2, reslt;
	    int c;
     	printf("\n            DIGITE O PRIMEIRO NÚMERO : ");
    	scanf("%f",&num1);
	    fflush(stdin);
	    mensagemNome();
	    dadosI();
	    calculadoraDadosI();
	    printf("\n            DIGITE O SEGUNDO NÚMERO : ");
	    scanf("%f",&num2);
     	fflush(stdin);
     	mensagemNome();
	    dadosI();
	    calculadoraDadosI();
    	menuCalculador();
     	scanf("%d",&c);
     	if(c == 1){
	     	mensagemNome();
	     	dadosI();
	    	calculadoraDadosI();
	    	reslt = num1 + num2;
	    	printf("\n           SOMA DOS NÚMEROS: %.2f COM  %.2f = %.2f\n\n",num1, num2, reslt);		
         	}
         	if(c == 2){
             	mensagemNome();
	         	dadosI();
	    	    calculadoraDadosI();
     	     	reslt = num1 * num2;
	         	printf("\n           A MULTIPLICAÇÃO DO NÚMERO: %.2f VEZES %.2f = %.2f\n\n",num1, num2, (float)reslt);		
	          	}
	          	if(c == 3){
	    	     	mensagemNome();
	    	        dadosI();
	            	calculadoraDadosI();
     	         	reslt = num1 / num2;
	             	printf("\n           A DIVISÃO DOS NÚMERO: %.2f DIVIDIDO POR %.2f = %.2f\n\n",num1, num2, reslt);	
		        	 }
		         	 if(c == 4){
		     	     	mensagemNome();
	    	            dadosI();
	                 	calculadoraDadosI();
     	             	reslt = num1 - num2;
	                	printf("\n           A SUBTRAÇÃO DOS NÚMERO: %.2f MENOS %.2f = %.2f\n\n",num1, num2, reslt);
			        	  }
				          if(c < 1 || c > 4){
				             	mensagemNome();
				             	dadosI();
				  	            calculadoraDadosI();
				             	mensagemErro();
				                 }
	    printf("\n          ");  
	 	system("pause");	  
    }
    void tabuadaDadosI(){//Chama a funcao TABUADA
	    no1 *le;
      	int i;
      	int valor;	
     	numeroTabuadaDI();
     	scanf("%d",&valor);
     	if(valor > 0 && valor < 11) {
             le = malloc(sizeof(no1));
             le->prox = NULL;
             for(i = 0; i <= 10; i++){
                 inserir(valor*i, le);
               }
                mensagemNome();
                dadosI();
               	alocacoesDadosI();
                imprimir(le, valor);
            }
             if(valor < 1 | valor > 10){
               	mensagemErro();
               }
        free(le);
    }
    void inserir(int x, no1 *p){//Dados I lista TABUADA
         no1 *novo;
         novo = malloc(sizeof(no1));
         novo->tabuada = x;
         novo ->prox = p->prox;
         p->prox = novo;
    }
    void imprimir(no1 *le, int valor  ){
        int i = 10;	
        no1 *p;
       	printf("\n            TABUADA DO NÚMERO: %d \n\n", valor);
        for (p = le; p != NULL; p = p->prox){
         	if(p->tabuada == 0){	
	        }
            if(p->tabuada > 0){
             	printf("               %d X %d = ", valor, i+1);
                printf("%d \n", p->tabuada);
                }
                 i--;
        }
        printf("\n               ");
        system("pause");
        i = 0;
    }
    void selectionsort(){//SELECTIONSORT    // metodos de Ordenação
        mensagemNome();
     	tecnicaOrdenacao();
        printf("\n          ORDENANDO SELECTIONSORT....      \n");
        printf("\n          ");
        system("pause");
     	int i, j, min, qtd=0;
      	for (i = 0; i < (tamanho-1); i++){
	     	min = i;
	     	for (j = (i+1); j < tamanho; j++) {
		     	if(lista[j] < lista[min]) {
			     	min = j;
			    }
			     qtd ++;
	      	}
	      	if (i != min) {
		     	trocar(&lista[i], &lista[min]);
	       	}
    	}
		tc = 3;	
		tempo = qtd;
    }
    void trocar(int* a, int* b){// Função genérica trocar valores
     	int tmp;
     	tmp = *a;
     	*a = *b;
    	*b = tmp;
    }
    void bulbblesort(){//   BULBBLESORT
     	if(li == 0){
     	mensagemNome();	
		mensagemErro();
     	}else{
        mensagemNome();
       	tecnicaOrdenacao();
        printf("\n          ORDENANDO BULBBLESORT....      \n");
        printf("\n          ");
        system("pause");
    	int i, j, tmp;
     	qtd = 0;
     	for(i = 0; i < tamanho -1; i++){
	     	for(j = i+1;j< tamanho; j++){
		     	if(lista[i]>lista[j]){
		      	trocar(&lista[i], &lista[j]);
		    	}
		        qtd ++;	
	    	}
	    }
	    tc = 1;
	    tempo = qtd;
	    li = 0;
    }
     opt_2 = 0;
}
void insertionsort(){
	if(li == 0){
		mensagemErro();
     	}else{
            printf("\n          ORDENANDO INSERTIONSORT....      \n");
            printf("\n          ");
            system("pause");
            int i, k, y;
            qtd = 0;
            for (k = 1; k < tamanho; k++){
                 y = lista[k];
                for (i = k-1; i >= 0 && y < lista[i]; i--){
                    lista[i+1] = lista[i];
                    qtd ++;
                }
           lista[i+1] = y;
            } 
        tc = 2; 
        tempo = qtd;
       	li = 0;
       }
   }
void lista_gerar(){//Gerar Lista
	mensagemNome();
	tecnicaOrdenacao();
	printf("\n\n           GERANDO LISTA ALEATÓRIA ....\n");
	for (i = 0; i < tamanho; i++){
		lista2[i] = rand() %50;
		lista[i] = lista2[i];		
     	}
  	printf("\n           ");
	system("pause");
	li = 1;
}
void lista_inserir_valores(void){ //inserir valores na lista          
	for(i = 0; i < tamanho; i++){
		mensagemNome();
		tecnicaOrdenacao();
		printf("\nDIGITE O VALOR PARA A POSIÇÃO %d:  DA LISTA  ",i);
		scanf("%d",&lista[i]);
		fflush(stdin);
		lista2[i] = lista[i];

}
}
//Mostar Conteudo da Lista
void lista_mostrar(){
	mensagemNome();
	tecnicaOrdenacao();	
	printf("\n          +===============LISTA NÃO ORDENADA===============+\n");
	printf("           [  ");
	for(i = 0; i < tamanho; i++){
		printf("%d  ",lista2[i]);
	}
	printf(" ] ");
	printf("\n          +================================================+\n");
	printf("\n\n        ");
	system("pause");
    }
    void chamaModoOrdenado(){
    	mensagemNome();
    		if(tc == 1 && tempo != 0){
     	    ordenadoBulbbesort();
     	    lista_ordenada();
		    }
		     if(tc == 2 && tempo != 0){
		     	ordenadoInsertionsort();
		       lista_ordenada();
		        }
		        if(tc == 3 && tempo != 0){
		        	ordenadoSelectionsort();
		         	 lista_ordenada();
				}
				if(tc == 0 || tempo == 0){
					mensagemErro();
				}
    tc = 0;	
	}
    void lista_ordenada(){//Mostrar Lista Ordenada
	    printf("\n          +=================LISTA ORDENADA=================+\n");
     	printf("          [  ");
	    for(i = 0; i < tamanho; i++){
		     printf("%d  ",lista[i]);
            }
         	printf(" ] ");
    	    printf("\n          +================================================+\n");
     	    printf("\n             Tempo = %d Interações ", tempo);
    	    printf("\n\n        ");
    	    system("pause");
    }
    void lista_preparar(void){//Prepara lista para ordenar
	for (i = 0; i < tamanho; i++){
		ordenado[i] = lista[i];
    	}
    }
   void mensagemNome(){
   	    system("cls");
	    printf("          +================================================+\n");
	    printf("          |       ALUNO-JOÃO PAULO GOMES DA SILVA          |\n");
	    printf("          |       RA-20012120-5                            |\n");
	    printf("          |       ENGENHARIA DE SOFTWARE                   |\n");
	    printf("          +================================================+\n");  
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
   void mensagemViagem(){
    	printf("          +================================================+\n");
   	    printf("          |                ROTEIRO DE VIAGENS              |\n"); 
   	    printf("          +================================================+\n"); 
   }
   void mensagemSair(){
	    printf("          +================================================+\n");
	    printf("          |                   MENSAGEM!!!                  |\n");
	    printf("          |                                                |\n");
	    printf("          |               SAINDO DO SISTEMA.               |\n");
	    printf("          +================================================+\n");
	    printf("\n          ");  
		system("pause");	
	 }
	void arvoresBinarias(){
    	printf("          +================================================+\n");
   	    printf("          |                ÁRVORES BINÁRIAS                |\n"); 
   	    printf("          +================================================+\n"); 
   } 
   void estruturaDados(){
    	printf("          +================================================+\n");
   	    printf("          |              ESTRUTURA DE DADOS                |\n"); 
   	    printf("          +================================================+\n"); 
   }
   void urnaEletronica(){
    	printf("          +================================================+\n");
   	    printf("          |                URNA ELETRÔNICA                 |\n"); 
   	    printf("          +================================================+\n"); 
   }
    void pilhas(){
    	printf("          +================================================+\n");
   	    printf("          |                   PILHAS                       |\n"); 
   	    printf("          +================================================+\n"); 
   }
    void calculadoraDadosI(){
    	printf("          +================================================+\n");
   	    printf("          |                  CALCULADORA                   |\n"); 
   	    printf("          +================================================+\n"); 
   }
    void numeroTabuadaDI(){
    	printf("          +================================================+\n");
   	    printf("          |          DIGITE O NÚMERO DA TABUADA            |\n"); 
   	    printf("          +================================================+\n"); 
   	   	printf("\n\n                                                  ");    
   }
    void atividadeI(){
    	printf("          +================================================+\n");
   	    printf("          |                  ATIVIDADE I                   |\n"); 
   	    printf("          +================================================+\n"); 
   }
   void dadosII(){
    	printf("          +================================================+\n");
   	    printf("          |                    DADOS  II                   |\n"); 
   	    printf("          +================================================+\n"); 
   }
   void dadosI(){
    	printf("          +================================================+\n");
   	    printf("          |                     DADOS  I                   |\n"); 
   	    printf("          +================================================+\n"); 
   }
   void alocacoesDadosI(){
    	printf("          +================================================+\n");
   	    printf("          |                   ALOCAÇÕES                    |\n"); 
   	    printf("          +================================================+\n"); 
   }
   void tabuadaDI(){
    	printf("          +================================================+\n");
   	    printf("          |                   TABUADAS                     |\n"); 
   	    printf("          +================================================+\n"); 
   }
   void ponteiros(){
    	printf("          +================================================+\n");
   	    printf("          |                   PONTEIROS                    |\n"); 
   	    printf("          +================================================+\n"); 
   }
   void menuPonteiros(){
        printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -     CHAMAR PONTEIROS                 |\n");   
	  	printf("          |                                                |\n");    
      	printf("          |       2 -     ALOCAR PPONTEIROS                |\n");
        printf("          |                                                |\n");
        printf("          |       3 -     URNA ELETRONICA                  |\n");
    	printf("          |                                                |\n");
    	printf("          |       0 -    VOLTAR AO MENU PRINCIPAL.         |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
    void menuUrnaEletronica(){
    	printf("          +================================================+\n");
	    printf("          |                                                |\n");
    	printf("          |       1 -      VOTAR                           |\n");   
	   	printf("          |                                                |\n");    
       	printf("          |       2 -      VER RESULTADO                   |\n");
       	printf("          |                                                |\n");
       	printf("          |       0 -      VOLTAR AO MENU PRINCIPAL.       |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
	void menuPrincipal(){
    	printf("          +================================================+\n");
	    printf("          |                                                |\n");
    	printf("          |       1 -      ESTRUTURAS I                    |\n");   
	   	printf("          |                                                |\n");    
       	printf("          |       2 -      ESTRUTURAS II                   |\n");
       	printf("          |                                                |\n");
       	printf("          |       0 -      SAIR DO SISTEMA.                |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
    void menuCalculador(){
        printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -     SOMAR  OS NÚMEROS                |\n");   
	  	printf("          |                                                |\n");    
      	printf("          |       2 -     MULTIPLICAR OS NÚMEROS           |\n");
        printf("          |                                                |\n");
        printf("          |       3 -     DIVIDIR OS NÚMEROS               |\n");
       	printf("          |                                                |\n");
       	printf("          |       4 -     SUBTRAIR OS NÚMEROS              |\n");
    	printf("          |                                                |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
       void menuCandidatos(){
        printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -     Dr JOSÉ A. SOUZA                 |\n");   
	  	printf("          |                                                |\n");    
      	printf("          |       2 -     PROF. MARIA L. GOMES             |\n");
        printf("          |                                                |\n");
        printf("          |       3 -     CAP. MARCOS SILVA                |\n");
       	printf("          |                                                |\n");
       	printf("          |       4 -     DONA IZA DA FARMÁCIA             |\n");
    	printf("          |                                                |\n");
       	printf("          |       0 -     VOTAR EM BRANCO.                 |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
    void menuLista(){
        printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -     LISTA ALEATÓRIA                  |\n");   
	  	printf("          |                                                |\n");    
      	printf("          |       2 -     LISTA ORDENADA                   |\n");
    	printf("          |                                                |\n");
       	printf("          |       0 -     VOLTAR AO MENU PRINCIPAL.        |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
	void menuEstruturasII(){
        printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -       TÉCNICAS DE ORDENAÇÃO          |\n");   
	   	printf("          |                                                |\n");
       	printf("          |       0 -       VOLTAR MENU PRINCIPAL.         |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
    void menuPilhas(){
	    printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -  MOSTRA PILHA                        |\n");   
    	printf("          |                                                |\n");    
       	printf("          |       2 -  INSERIR DADOS NA PILHA              |\n");
       	printf("          |                                                |\n");
       	printf("          |       3 -  RETIRA DADOS DA PILHA               |\n");;
      	printf("          |                                                |\n");
       	printf("          |       4 -  ATIVIDADE I                         |\n");
      	printf("          |                                                |\n");
       	printf("          |       0 -  VOLTAR MENU PRINCIPAL               |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");
       }
   void menuAtividadeI(){
	    printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -  FUNÇÃO (POP)                        |\n");   
    	printf("          |                                                |\n");    
       	printf("          |       2 -  FUNÇÃO (PUSH)                       |\n");
       	printf("          |                                                |\n");
       	printf("          |       3 -  FUNÇÃO (DISPLAY)                    |\n");
      	printf("          |                                                |\n");
       	printf("          |       0 -  VOLTAR MENU PRINCIPAL               |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");
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
       	printf("          |       0 -      VOLTAR MENU PRINCIPAL           |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");      
    }
    void menuAresta(){
	    printf("          +================================================+\n");
	    printf("          |                                                |\n");
	    printf("          |       1 -  INSERIR GRAFO                       |\n");   
	   	printf("          |                                                |\n");
        printf("          |       2 -  INSERIR ARESTA                      |\n");   
    	printf("          |                                                |\n");    
       	printf("          |       3 -  REMOVER ARESTA                      |\n");
       	printf("          |                                                |\n");
       	printf("          |       4 -  VISUALIZAR GRAFO                    |\n");
      	printf("          |                                                |\n");
       	printf("          |       0 -  VOLTAR MENU PRINCIPAL               |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");
       }
   void menuEstrturaDadosI(){
	    printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -  ALOCAÇÕES                           |\n");   
    	printf("          |                                                |\n");    
       	printf("          |       2 -  PILHAS                              |\n");
       	printf("          |                                                |\n");
       	printf("          |       3 -  GRAFOS                              |\n");
       	printf("          |                                                |\n");
       	printf("          |       4 -  MAPA                                |\n");
        printf("          |                                                |\n");
       	printf("          |       0 -  VOLTAR MENU PRINCIPAL               |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");
       }
    void menuAlocacoesI(){
	    printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -  TABUADA                             |\n");   
    	printf("          |                                                |\n");    
       	printf("          |       2 -  CALCULADORA                         |\n");
       	printf("          |                                                |\n");
       	printf("          |       3 -  MELHOR COMBUSTÍVEL                  |\n");
      	printf("          |                                                |\n");
       	printf("          |       4 -  PONTEIROS                           |\n");
      	printf("          |                                                |\n");
       	printf("          |       0 -  VOLTAR MENU PRINCIPAL               |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");
       }
   void tecnicaOrdenacao(){
        printf("          +================================================+\n");
   	    printf("          |              TÉCNICAS DE ORDENAÇÃO             |\n"); 
   	    printf("          +================================================+\n"); 
   }
    void ordenadoBulbbesort(){
        printf("          +================================================+\n");
   	    printf("          |               ORDENADO BULBBSORT               |\n"); 
   	    printf("          +================================================+"); 
   }
    void ordenadoInsertionsort(){
        printf("          +================================================+\n");
   	    printf("          |             ORDENADO INSERTIONSORT             |\n"); 
   	    printf("          +================================================+"); 
   }
    void ordenadoSelectionsort(){
        printf("          +================================================+\n");
   	    printf("          |              ORDENADO SELECTIONSORT            |\n"); 
   	    printf("          +================================================+"); 
   }
    void menuOrdenacao(){
        printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -   GERAR LISTA ALEATÓRIA              |\n");   
      	printf("          |                                                |\n");    
       	printf("          |       2 -   MOSTRAR LISTA                      |\n");
        printf("          |                                                |\n");
       	printf("          |       3 -   GERAR LISTA MANUAL                 |\n");;
       	printf("          |                                                |\n");
       	printf("          |       4 -   ORDENADAR LISTA                    |\n");
    	printf("          |                                                |\n");
       	printf("          |       0 -   VOLTAR MENU PRINCIPAL              |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");
            }
   void menuModeloOrdenacao(){
	    printf("          +================================================+\n");
	    printf("          |                                                |\n");
        printf("          |       1 -    ORDENAR BOLBBLESORT               |\n");   
	   	printf("          |                                                |\n");    
       	printf("          |       2 -    ORDENAR INSERTIONSORT             |\n");
       	printf("          |                                                |\n");
       	printf("          |       3 -    ORDENAR SELECTIONSORT             |\n");
    	printf("          |                                                |\n");
       	printf("          |       0 -    VOLTAR MENU PRINCIPAL             |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a opção desejada! ");
            }
