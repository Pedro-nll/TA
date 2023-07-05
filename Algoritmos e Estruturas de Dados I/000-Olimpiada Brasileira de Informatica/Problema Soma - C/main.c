#include <stdio.h>
#include <stdlib.h>

int main()
{
  //entrada
  int N, K;
  scanf("%d %d", &N, &K);
  int arr[N];
  for(int i = 0; i<N; i++){
    scanf("%d", arr+i);
  }
  //Contador de retangulos
  int retangulos = 0;
  for(int i = 0; i<N; i++){
    if(arr[i] == K){
      retangulos++;
      //Se o elemento atual for igual a linha acima soma 1 retangulo, as linhas abaixo lidam com K = 0
      int somaAtual = arr[i];
      for(int j=i-1; j>=0; j--){
        somaAtual += arr[j];
        if (somaAtual>K)break;
        else retangulos++; 
      }
    }else if(arr[i] < K){
      //Se o elemento atual for menor que K, o loop abaixo tenta somar os elementos anteriores ate a soma ser >= K
      int somaAtual = arr[i];
      for(int j=i-1; j>=0; j--){
        if (somaAtual>=K)break;
        else somaAtual += arr[j];
      }
      if(somaAtual==K)retangulos++;
    }
  }
  //Saída
  printf("%d", retangulos);
  return 0;
}