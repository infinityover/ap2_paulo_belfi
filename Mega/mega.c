#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef Tdezenas
#define Tdezenas 11760
#endif
#ifndef Tconcursos
#define Tconcursos 1960
#endif

void imprimeDezenas(int vetor1[60], int vetor2[60])
{
    int i;
  printf("As dezenas %i %i %i %i %i %i foram as menos sorteadas\n\n", vetor1[0],vetor1[1],vetor1[2],vetor1[3],vetor1[4],vetor1[5]);
  for (i = 0; i < 6; i++)
  {
    printf("A dezena %i aparece %i vez(es)\n", vetor1[i],vetor2[i]);
  }
  printf("\nAs dezenas %i %i %i %i %i %i foram as mais sorteadas\n\n", vetor1[54],vetor1[55],vetor1[56],vetor1[57],vetor1[58],vetor1[59]);
  for (i = 54; i < 60; i++)
  {
    printf("A dezena %i aparece %i vez(es)\n", vetor1[i],vetor2[i]);
  }
}

int main()
{
  FILE *f= fopen("arquivo.txt", "r");
  char linha[200];
  int dez1,dez2,dez3,dez4,dez5,dez6;
  int concurso;
  int matriz[1960][6];
  int i=0,k=0,h=0,j=0,y=0,q=0,p=0,r=0; //variaveis auxiliares
  int vetorMega[Tdezenas];
  int temp,temp2,temp3,temp4;
  int vetorNumero[60];
  int vetorQuantidade[60];
  char letra[10];


if (!f)
  {
    perror("arquivo.txt");
    exit(1);
  }

  //Le as dezenaz no arquivo e coloca em uma matriz.

  while (fgets(linha, 200, f) > 0)
  {
    if (strlen(linha)>90 && isdigit(linha[0]))
    {

      concurso = atoi(&linha[0]);
      if (concurso < 10)
      {
          matriz[i][0] = atoi(&linha[15]);
          matriz[i][1] = atoi(&linha[19]);
          matriz[i][2] = atoi(&linha[23]);
          matriz[i][3] = atoi(&linha[27]);
          matriz[i][4] = atoi(&linha[31]);
          matriz[i][5] = atoi(&linha[35]);
          i++;
      }
      if (concurso >= 10 && concurso < 100)
      {
          matriz[i][0] = atoi(&linha[16]);
          matriz[i][1] = atoi(&linha[20]);
          matriz[i][2] = atoi(&linha[24]);
          matriz[i][3] = atoi(&linha[28]);
          matriz[i][4] = atoi(&linha[32]);
          matriz[i][5] = atoi(&linha[36]);
          i++;
      }
      if (concurso >= 100 && concurso < 1000)
      {
          matriz[i][0] = atoi(&linha[17]);
          matriz[i][1] = atoi(&linha[21]);
          matriz[i][2] = atoi(&linha[25]);
          matriz[i][3] = atoi(&linha[29]);
          matriz[i][4] = atoi(&linha[33]);
          matriz[i][5] = atoi(&linha[37]);
          i++;
      }
        if (concurso >= 1000)
      {
          matriz[i][0] = atoi(&linha[18]);
          matriz[i][1] = atoi(&linha[22]);
          matriz[i][2] = atoi(&linha[26]);
          matriz[i][3] = atoi(&linha[30]);
          matriz[i][4] = atoi(&linha[34]);
          matriz[i][5] = atoi(&linha[38]);
          i++;
      }
    }
    if (linha)
    free(linha);
  }

  fclose(f);
  	i=0; //prenchimento de vetor com todas as dezenas da megasena
  	for (h = 0; h < 1960; h++)
	{
  		for (j = 0; j < 6; j++)
  		{
  			vetorMega[i] = matriz[h][j];
  			i++;
  		}
  	}

	for (y = 0; y < Tdezenas; y++) //ordenção dos valores de vetorMega
	{
		for (i = 0; i < Tdezenas; i++)
		{
			if (vetorMega[y] < vetorMega[i])
				{
					temp = vetorMega[i];
					temp2 = vetorMega[y];
					vetorMega[y] = temp;
					vetorMega[i] = temp2;
				}
		}
	}
	for (y = 0; y < Tdezenas; y++)//coloca as dezenas e suas respectivas aparicoes em em vetores
  {
		q=0;
		for (i = 0; i < Tdezenas; i++)
		{
			if (vetorMega[y] == vetorMega[i])
			{
				q++;
			}
		}
        vetorNumero[p] = vetorMega[y];
        vetorQuantidade[r] = q;
        p++;
        r++;
				y +=q-1;

	}
  for (y = 0; y < 60; y++) //ordenção dos valores de vetorMega
  {
    for (i = 0; i < 60; i++)
    {
      if (vetorQuantidade[y] < vetorQuantidade[i])
        {
          temp = vetorQuantidade[i];
          temp2 = vetorQuantidade[y];
          vetorQuantidade[y] = temp;
          vetorQuantidade[i] = temp2;
          temp3 = vetorNumero[i];
          temp4 = vetorNumero[y];
          vetorNumero[y] = temp3;
          vetorNumero[i] = temp4;
        }
    }
  }
  imprimeDezenas(vetorNumero,vetorQuantidade);

  puts("\nDigite 6 dezenas entre 01 e 60 para saber se elas ja foram sorteadas:\n");
  puts("Digite 'sim' para continuar ou 'sair' para encerrar o programa:");

  while(1)//cria um loop para digitar uma sequencia de dezenas e saber se ela foi sorteada
  {
      scanf("%s", letra);
      if (letra[0]=='s' && letra[1]=='a' && letra[2]=='i' && letra[3]=='r')
      {
          return 0;
      } else if (letra[0]=='s' && letra[1]=='i' && letra[2]=='m'){
          puts("Ok!.. digite as dezenas:");
          scanf("%i %i %i %i %i %i", &dez1, &dez2, &dez3, &dez4, &dez5, &dez6);
          //verifica se o que foi digitado foi um numero entre 0 e 60
          if (dez1>0 && dez1<61 && dez2>0 && dez2<61 && dez3>0 && dez3<61 && dez4>0 && dez4<61 && dez5>0 && dez5<61 && dez6>0 && dez6<61)
          {
              printf("\nAs dezenas digitadas foram: %i %i %i %i %i %i\n", dez1, dez2, dez3, dez4, dez5, dez6);
          } else {
              puts("\nAs dezanas digitadas nao sao validas!\n");
            }
      j=0;
      for (i = 0; i < Tconcursos; i++)// verifica se a sequencia digitada já foi sorteada
      {
        if ((dez1==matriz[i][0] || dez1==matriz[i][1] || dez1==matriz[i][2] || dez1==matriz[i][3] || dez1==matriz[i][4] || dez1==matriz[i][5]) && (dez2==matriz[i][0] || dez2==matriz[i][1] || dez2==matriz[i][2] || dez2==matriz[i][3] || dez2==matriz[i][4] || dez2==matriz[i][5]) && (dez3==matriz[i][0] || dez3==matriz[i][1] || dez3==matriz[i][2] || dez3==matriz[i][3] || dez3==matriz[i][4] || dez3==matriz[i][5]) && (dez4==matriz[i][0] || dez4==matriz[i][1] || dez4==matriz[i][2] || dez4==matriz[i][3] || dez4==matriz[i][4] || dez4==matriz[i][5]) && (dez5==matriz[i][0] || dez5==matriz[i][1] || dez5==matriz[i][2] || dez5==matriz[i][3] || dez5==matriz[i][4] || dez5==matriz[i][5]) && (dez6==matriz[i][0] || dez6==matriz[i][1] || dez6==matriz[i][2] || dez6==matriz[i][3] || dez6==matriz[i][4] || dez6==matriz[i][5]))
          {
          printf("Sequencia sorteada no concurso: %i\n", i+1);
          j++;
          }
      }
      if (j == 0)
      {
        puts("Sequencia nao sorteada.\n");
      }
      puts("Digite 'sim' para continuar ou 'sair' para encerrar o programa:\n");
    } else {
      puts ("Comando invalido...");// caso a palavra digitada não seja umas das especificadas no programa, ele ira apresentar essa mensagem de erro
    }
  }
  return 0;
}
