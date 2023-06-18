#include <iostream>
int main(){
  //inicializa as variaveis a serem usadas
  int N, P, M, Pq=0, Mq=0;
  //Armazena a quantidade de premiados
  std::cin >> N;
  //Armazena os tamanhos desejados por cada premiado
  int T[N];
  for(int i = 0; i<N; i++){
    std::cin>>T[i];
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
  std::cin >> P;
  //Recebe a quantidade de camisas M produzidas
  std::cin >> M;
  //Saída
  if(Pq<=P && Mq<=M){
    std::cout << 'S';
  }else{
    std::cout << 'N';
  }
  return 0;
}