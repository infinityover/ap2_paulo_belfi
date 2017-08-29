#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

const int sorteios = 2000;

void imprime_vetor();
void bubble_sort(int [2][61], int);

int main()
{     char linha[200];
      FILE * input;
      
      int resultados_lidos[6];
      int matriz_resultado[sorteios][6];
      memset(matriz_resultado, 0, sizeof(int) * sorteios * 6);
      int matriz_quantidade_sorteado[2][61];
      memset(matriz_quantidade_sorteado, 0, sizeof(int) * 2 * 61);
      int concurso = 0, l =0;
      int valor_resultado=0;

      input = fopen("resultado.txt", "r"); //fopen(nome_arquivo, funcao(a-append, r-read, w-write))
      if (!input){
            printf("Erro ao abrir arquivo");
            exit(1);
      }
      while(fgets(linha,sizeof(linha), input) != NULL){
        
        if (sizeof(linha) > 100 && isdigit(linha[0])) {
            concurso = atoi(&linha[0]);
            //if (concurso < 10){
                matriz_resultado[l][0] = atoi(&linha[14]);
                matriz_resultado[l][1] = atoi(&linha[18]);
                matriz_resultado[l][2] = atoi(&linha[22]);
                matriz_resultado[l][3] = atoi(&linha[26]);
                matriz_resultado[l][4] = atoi(&linha[30]);
                matriz_resultado[l][5] = atoi(&linha[34]);
                printf("%s\n", &linha[14]);
            //}
            //if (concurso >= 10 && concurso < 100){
            //    matriz_resultado[l][0] = atoi(&linha[14]);
            //    matriz_resultado[l][1] = atoi(&linha[18]);
            //    matriz_resultado[l][2] = atoi(&linha[22]);
            //    matriz_resultado[l][3] = atoi(&linha[26]);
            //    matriz_resultado[l][4] = atoi(&linha[30]);
            //    matriz_resultado[l][5] = atoi(&linha[34]);
            //}
            //if (concurso >= 100 && concurso < 1000){
            //    matriz_resultado[l][0] = atoi(&linha[15]);
            //    matriz_resultado[l][1] = atoi(&linha[19]);
            //    matriz_resultado[l][2] = atoi(&linha[23]);
            //    matriz_resultado[l][3] = atoi(&linha[27]);
            //    matriz_resultado[l][4] = atoi(&linha[31]);
            //    matriz_resultado[l][5] = atoi(&linha[35]);
            //}
            //  if (concurso >= 1000){
            //    matriz_resultado[l][0] = atoi(&linha[16]);
            //    matriz_resultado[l][1] = atoi(&linha[20]);
            //    matriz_resultado[l][2] = atoi(&linha[24]);
            //    matriz_resultado[l][3] = atoi(&linha[28]);
            //    matriz_resultado[l][4] = atoi(&linha[32]);
            //    matriz_resultado[l][5] = atoi(&linha[36]);
            //}
            l++;
        }
        
	}
  /* até aqui os valores estão OK*/

	//lendo vetor para comparação
	//printf("Digite as dezenas que deseja buscar:");
    //for(int i =0; i < 6; i++){
    //	scanf(" %d \n", &resultados_lidos[i]);
   	//}
    //for (int i = 1; i < 61; i++){
    //  printf("%d - %d \n",matriz_resultado[i][1] , matriz_resultado[i][2]);
    //}

   	for (int i = 0; i < 2000; i++){
   		for (int j = 0; j < 6; j++){
   			for (int k = 1; k < 61; k++){
          valor_resultado = 0 ;
   				valor_resultado = matriz_resultado[i][j];
   				if (valor_resultado == k) {
   					matriz_quantidade_sorteado[0][k] = k;
            //printf("k = %d valor = %d \n", k, valor_resultado);
   					matriz_quantidade_sorteado[1][k]++;
   				}
   			}
   		}
   	}


   	bubble_sort(matriz_quantidade_sorteado, 61);
   	//for (int i = 1; i < 61; i++){
   	//	printf("%d - %d \n",matriz_quantidade_sorteado[0][i] , matriz_quantidade_sorteado[1][i]);
   	//}
    printf("O numero menos sorteado foi : %d sendo sorteado: %d vezes\n", matriz_quantidade_sorteado[0][1], matriz_quantidade_sorteado[1][1]);
    printf("O numero mais sorteado foi : %d sendo sorteado: %d vezes\n", matriz_quantidade_sorteado[0][60], matriz_quantidade_sorteado[1][60]);
}

void imprime_vetor(int vetor[3000][6]){
	for (int i = 0; i < 3000; i++){
		printf("Vetor \n");
		printf("%d \n",vetor[i][0]);
		printf("%d \n",vetor[i][1]);
		printf("%d \n",vetor[i][2]);
		printf("%d \n",vetor[i][3]);
		printf("%d \n",vetor[i][4]);
		printf("%d \n",vetor[i][5]);
	}
}

void bubble_sort(int lista[2][61], int n){
	int c, d, temp = 0,num_armazenado=0;

	for (c = 0 ; c < ( n - 1 ); c++){
    	for (d = 0 ; d < n - c - 1; d++){
      		if (lista[1][d] > lista[1][d+1]){
      			num_armazenado 	= lista[0][d];
        		temp          	= lista[1][d];
        		lista[0][d]	  	= lista[0][d+1];
        		lista[1][d]   	= lista[1][d+1];

        		lista[0][d+1] = num_armazenado;
        		lista[1][d+1] = temp;
      		}
    	}
  	}
}	