#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int sorteios = 2000;

void imprime_vetor();
void bubble_sort_matriz(int [2][61], int);
void bubble_sort_vetor(int [6]);

int main()
{     char linha[200];
      FILE * input;

      int resultados_lidos[6];
      int matriz_resultado[sorteios][6];
      memset(matriz_resultado, 0, sizeof(int) * sorteios * 6);
      int matriz_quantidade_sorteado[2][61];
      int matriz_ordenada[6];
      memset(matriz_quantidade_sorteado, 0, sizeof(int) * 2 * 61);
      int concurso = 0, l =0;
      int valor_resultado=0;
      int i,j,k;
      int vetor_entrada[6];

      input = fopen("resultado.txt", "r"); //fopen(nome_arquivo, funcao(a-append, r-read, w-write))
      if (!input){
            printf("Erro ao abrir arquivo");
            exit(1);
      }
      while(fgets(linha,sizeof(linha), input) != NULL){

        if (sizeof(linha) > 100 && isdigit(linha[0])) {
            concurso = atoi(&linha[0]);
            if (concurso < 10){
                matriz_resultado[l][0] = atoi(&linha[13]);
                matriz_resultado[l][1] = atoi(&linha[16]);
                matriz_resultado[l][2] = atoi(&linha[19]);
                matriz_resultado[l][3] = atoi(&linha[22]);
                matriz_resultado[l][4] = atoi(&linha[25]);
                matriz_resultado[l][5] = atoi(&linha[28]);

            }
            if (concurso >= 10 && concurso < 100){
                matriz_resultado[l][0] = atoi(&linha[14]);
                matriz_resultado[l][1] = atoi(&linha[17]);
                matriz_resultado[l][2] = atoi(&linha[20]);
                matriz_resultado[l][3] = atoi(&linha[23]);
                matriz_resultado[l][4] = atoi(&linha[26]);
                matriz_resultado[l][5] = atoi(&linha[29]);
            }
            if (concurso >= 100 && concurso < 1000){
                matriz_resultado[l][0] = atoi(&linha[15]);
                matriz_resultado[l][1] = atoi(&linha[18]);
                matriz_resultado[l][2] = atoi(&linha[21]);
                matriz_resultado[l][3] = atoi(&linha[24]);
                matriz_resultado[l][4] = atoi(&linha[27]);
                matriz_resultado[l][5] = atoi(&linha[30]);
            }
              if (concurso >= 1000){
                matriz_resultado[l][0] = atoi(&linha[16]);
                matriz_resultado[l][1] = atoi(&linha[19]);
                matriz_resultado[l][2] = atoi(&linha[22]);
                matriz_resultado[l][3] = atoi(&linha[25]);
                matriz_resultado[l][4] = atoi(&linha[28]);
                matriz_resultado[l][5] = atoi(&linha[31]);
            }
            l++;
        }
    }

    for (i = 0; i < sorteios; i++){
      for (j = 0; j < 6; j++){
        for (k = 1; k < 61; k++){
          valor_resultado = 0 ;
          valor_resultado = matriz_resultado[i][j];
          if (valor_resultado == k) {
            matriz_quantidade_sorteado[0][k] = k;
            matriz_quantidade_sorteado[1][k]++;
          }
        }
      }
    }


    bubble_sort_matriz(matriz_quantidade_sorteado, 61);

    for(i = 0; i < sorteios; i++){
        for(j = 0; j < 6; j++){
            matriz_ordenada[j] = matriz_resultado[i][j];
        }
        bubble_sort_vetor(matriz_ordenada);
        for(j = 0; j < 6; j++){
            matriz_resultado[i][j] = matriz_ordenada[j];
            //printf("%d ",matriz_ordenada[j]);
        }
    }
    printf("Entre com os valores que gostaria de checar: \n");
    for(i = 0; i < 6; i++){
        scanf("%d", &vetor_entrada[i]);
    }

    //ordenando o vetor de entrada
    for(j = 0; j < 6; j++){
            matriz_ordenada[j] = vetor_entrada[j];
        }
        bubble_sort_vetor(matriz_ordenada);
        for(j = 0; j < 6; j++){
            vetor_entrada[j] = matriz_ordenada[j];
    }

    for(i = 0; i < sorteios; i++){
        if (matriz_resultado[i][0] == vetor_entrada[0] && matriz_resultado[i][1] == vetor_entrada[1] && matriz_resultado[i][2] == vetor_entrada[2] && matriz_resultado[i][3] == vetor_entrada[3] && matriz_resultado[i][4] == vetor_entrada[4] && matriz_resultado[i][5] == vetor_entrada[5])
        printf("Os numeros escolhidos foram sorteados no sorteio: %d\n",(i+1));
    }


    printf("O numero menos sorteado foi : %d sendo sorteado: %d vezes\n", matriz_quantidade_sorteado[0][1], matriz_quantidade_sorteado[1][1]+1);
    printf("O numero mais sorteado foi : %d sendo sorteado: %d vezes\n", matriz_quantidade_sorteado[0][60], matriz_quantidade_sorteado[1][60]+1);
    return 0;
}

void bubble_sort_matriz(int lista[2][61], int n){
  int c, d, temp = 0,num_armazenado=0;
  for (c = 0 ; c < ( n - 1 ); c++){
    for (d = 0 ; d < n - c - 1; d++){
        if (lista[1][d] > lista[1][d+1]){
            num_armazenado  = lista[0][d];
            temp            = lista[1][d];
            lista[0][d]     = lista[0][d+1];
            lista[1][d]     = lista[1][d+1];

          lista[0][d+1] = num_armazenado;
          lista[1][d+1] = temp;

            }
        }
    }
}

void bubble_sort_vetor(int lista[6]){
  int c, d, temp = 0,num_armazenado=0;
  for (c = 0 ; c < ( 6 - 1 ); c++){
    for (d = 0 ; d < 6 - c - 1; d++){
        if (lista[d] > lista[d+1]){
            temp         = lista[d];
            lista[d]     = lista[d+1];
            lista[d]     = lista[d+1];

          lista[d+1] = temp;

            }
        }
    }
}

