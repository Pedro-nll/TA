using System;

class Program {
  public static void Main (string[] args) {
    //inicializa as variaveis a serem usadas
    int N, P, M, Pq = 0, Mq = 0;
    //Armazena a quantidade de premiados
    N = int.Parse(Console.ReadLine());
    //Armazena os tamanhos desejados por cada premiado
    int[] T = new int[N];
    for (int i = 0; i < N; i++){
      T[i] = int.Parse(Console.ReadLine());
    }
    //itera o array de tamanhos desejados e armazena a quantidade necessaria de cada tamanho
    for (int i = 0; i < N; i++){
      if(T[i] == 1){
        Pq++;
      }else if (T[i] == 2){
        Mq++;
      }
    }
    //Recebe a quantidade de camisas P produzidas
    P = int.Parse(Console.ReadLine());
    //Recebe a quantidade de camisas M produzidas
    M = int.Parse(Console.ReadLine());
    //Saída
    if(Pq<=P && Mq<=M){
      Console.WriteLine("S");
    }else{
      Console.WriteLine("N");
    }
  }
}