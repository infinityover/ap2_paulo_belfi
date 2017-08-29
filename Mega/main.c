#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

const int sorteios = 2000;

void imprime_vetor();	
int main()
{     char linha[200];
      FILE * input;
      
      int resultados_lidos[6];
      int matriz_resultado[sorteios][6];
      int matriz_quantidade_sorteado[61];
      int concurso = 0, l =0;

      input = fopen("resultado.txt", "r"); //fopen(nome_arquivo, funcao(a-append, r-read, w-write))
      if (!input){
            printf("Erro ao abrir arquivo");
            exit(1);
      }
      while(fgets(linha,sizeof(linha), input) != NULL){
        
        if (sizeof(linha) > 100 && isdigit(linha[0])) {
            concurso = atoi(&linha[0]);
            if (concurso < 10){
                matriz_resultado[l][0] = atoi(&linha[15]);
                matriz_resultado[l][1] = atoi(&linha[19]);
                matriz_resultado[l][2] = atoi(&linha[23]);
                matriz_resultado[l][3] = atoi(&linha[27]);
                matriz_resultado[l][4] = atoi(&linha[31]);
                matriz_resultado[l][5] = atoi(&linha[35]);
            }
            if (concurso >= 10 && concurso < 100){
                matriz_resultado[l][0] = atoi(&linha[16]);
                matriz_resultado[l][1] = atoi(&linha[20]);
                matriz_resultado[l][2] = atoi(&linha[24]);
                matriz_resultado[l][3] = atoi(&linha[28]);
                matriz_resultado[l][4] = atoi(&linha[32]);
                matriz_resultado[l][5] = atoi(&linha[36]);
            }
            if (concurso >= 100 && concurso < 1000){
                matriz_resultado[l][0] = atoi(&linha[17]);
                matriz_resultado[l][1] = atoi(&linha[21]);
                matriz_resultado[l][2] = atoi(&linha[25]);
                matriz_resultado[l][3] = atoi(&linha[29]);
                matriz_resultado[l][4] = atoi(&linha[33]);
                matriz_resultado[l][5] = atoi(&linha[37]);
            }
              if (concurso >= 1000){
                matriz_resultado[l][0] = atoi(&linha[18]);
                matriz_resultado[l][1] = atoi(&linha[22]);
                matriz_resultado[l][2] = atoi(&linha[26]);
                matriz_resultado[l][3] = atoi(&linha[30]);
                matriz_resultado[l][4] = atoi(&linha[34]);
                matriz_resultado[l][5] = atoi(&linha[38]);
            }
            l++;
        }
        
	}
	//lendo vetor para comparação
	//printf("Digite as dezenas que deseja buscar:");
    //for(int i =0; i < 6; i++){
    //	scanf(" %d \n", &resultados_lidos[i]);
   	//}
   	for (int i = 0; i < 2000; i++){
		//printf("%d\n",i);
   		for (int j = 0; j < 6; j++){
   			for (int k = 1; k < 61; k++){
   					//printf("k = %d\n", k);
   					//printf("sort = %d\n", matriz_quantidade_sorteado[k]);
   				if (matriz_resultado[i][j] == k) {
   					matriz_quantidade_sorteado[k]++;
   				}
   			}
   			//printf("%d \n", j);
   		}

   	}
	//printf("oi");
   	for (int i = 1; i < 61; i++){
   		printf("%d - %d \n",i , matriz_quantidade_sorteado[i]);
   	}
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