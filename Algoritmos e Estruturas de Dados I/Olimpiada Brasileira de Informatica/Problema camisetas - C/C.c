#include <stdio.h>

int main(void){
  //inicializa as variaveis a serem usadas
  int N, P, M, Pq=0, Mq=0;
  //Armazena a quantidade de premiados
  scanf("%d", &N);
  //Armazena os tamanhos desejados por cada premiado
  int T[N];
  for (int i = 0; i < N; i++){
      scanf("%d", &T[i]);
  }
  //Itera o array de tamanhos desejados e armazena a quantidade necessaria de cada tamanho
  for (int i=0; i< N; i++){
    if (T[i] == 1){
      Pq++;
    }else if(T[i] == 2){
      Mq++;
    }
  }
  //Recebe a quantidade de camisas P produzidas
  scanf("%d", &P);
  //Recebe a quantidade de camisas M produzidas
  scanf("%d", &M);
  //Saída
  if(Pq<=P && Mq<=M){
    printf("S\n");
  }else{
    printf("N\n");
  }
  return 0;
}
