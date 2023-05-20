import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    //Inicializa o scanner
    Scanner scanner = new Scanner(System.in);
    //Inicializa as variaveis a serem usadas
    int N, P, M, Pq = 0, Mq = 0;
    //armazena a quantidade de premiados
    N = scanner.nextInt();
    //Armazena os tamanhos desejados por cada premiado
     int[] T = new int[N];
    for (int i = 0; i < N; i++){
      T[i] = scanner.nextInt();
    }
    //Itera o array de tamanhos desejados e armazena a quantidade necessaria de cada tamanho
    for(int i =0; i< N; i++){
      if(T[i] == 1){
        Pq++;
      }else{
        Mq++;
      }
    }
    //Recebe a quantidade de camisas P produzidas
    P = scanner.nextInt();
    //Recebe a quantidade de camisas M produzidas
    M = scanner.nextInt();
    //Saída
    if(Pq <= P && Mq <= M){
      System.out.println("S");
    }else{
      System.out.println("N");
    }
  }
}