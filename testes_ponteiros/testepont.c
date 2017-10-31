#include <stdio.h>
#include <stdlib.h>


typedef struct pilha{
  int vetor[10];
  int topo;
} pilha;

void incial(pilha *p);
void incremeta_topo(pilha *p);


int main(int argc, char const *argv[]) {
  pilha p;
  printf("%d\n", p.topo);
  incial(&p);
  printf("%d\n", (&p)->topo);
  incremeta_topo(&p);
  printf("%d\n", (&p)->topo);
  //p.topo = 0;
  return 0;
}

void incial(pilha *p){
  p->topo = 0;

}

void incremeta_topo(pilha *p){
  p->topo ++;
}
