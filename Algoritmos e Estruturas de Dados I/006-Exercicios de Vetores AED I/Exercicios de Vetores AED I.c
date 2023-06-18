#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maior(int *vetor, int tamanho);
double media(double vetor[], int tamanho);

int main(void) {
  int QUESTAO;
  printf("Digite o numero da questao: ");
  scanf("%d", &QUESTAO);
  switch(QUESTAO){
    //Questão 1: Armazenar 10 numeros em um vetor e imprimir ele depois
    case 1:{
      int m[10];
      for(int i = 0; i<10; i++){
        printf("digite o numero %i: ", i+1);
        scanf("%i", &m[i]);
      }
      for(int i = 0; i<10; i++){
        printf("%d |", m[i]);
      }
      break;
    }
    //Questão 2: Imprimir um vetor de 100 elemenos os quais tem valor igual a sua posição elevada a 2 caso seja uma posição par e a 3 caso seja impar
    case 2:{
      int elementos = 100, m[elementos];
      for(int i = 0; i<elementos;i++){
        if(i%2==0){
          m[i] = i*i;
        }else{
          m[i] = i*i*i;
        }
        printf("%d |", m[i]);
      }
      break;
    }
    //Questão 3: fazer um programa dividido em 2 partes. 1) Ler as notas de 10 alunos e as armazenar em um vetor 2) processar o vetor imprimindo a maior, menor e media das notas.
    case 3:{
      int alunos = 10, notas[alunos], media = 0, menor = 11, maior = -1;
      //Leitura de dados
      for (int i = 0; i < alunos; i++){
        printf("digite a nota do aluno %d: ", i+1);
        scanf("%d", &notas[i]);
      }
      //Processamento de dados
      for(int i=0; i<alunos; i++){
        media += notas[i];
        if (notas[i]<menor){
          menor = notas[i];
        }
        if (notas[i]>maior){
          maior = notas[i];
        }
      }
      printf("Media = %d | Maior nota = %d | Menor nota = %d", media/alunos, maior, menor);
      break;
    }
    //Questão 4: Imprimir um vetor de 30 posições as quais o valor = posição elevada a 2
    case 4:{
      int elementos = 30, v[elementos];
      for (int i = 0; i<elementos; i++){
        v[i] = i*i;
        printf("%d |", v[i]);
      }
      break;
    }
    //Questão 5: Pegar um vetor com 10 numeros reais, imprimir a soma dos numeros positivos e a quantidade de numeros negativos
    case 5:{
      int soma = 0, negativos =0, v[10] = {-15, 16, -76, -73, -56, 22, 67, 85, -2, 84};
      for (int i = 0; i<10; i++){
        if(v[i]<0){
          negativos++;
        }else{
          soma += v[i];
        }
      }
      printf("soma dos positivos = %d | Quantidade de negativos = %d", soma, negativos);
      break;
    }
    //Questão 6: Ler um vetor de 100 posições e mostrar apenas os valores positivos
    case 6:{
      int elementos = 100, v[elementos];
      for (int i = 0; i<elementos; i++){
        printf("digite o %i valor: ", i+1);
        scanf("%d", &v[i]);
      }
      for (int i = 0; i<elementos; i++){
        if(v[i] >= 0){
          printf("%d | ", v[i]);
        }
      }
      break;
    }
    //Questão 7: Ler um vetor de N posições e imprimir os valores das posições impares
    case 7:{
      int n;
      printf("Digite o valor de n: ");
      scanf("%d", &n);
      int v[n];
      for (int i = 0; i < n; i++){
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &v[i]);
      }
      for (int i = 0; i < n; i++){
        if(i % 2 == 1){
          printf("%d | ", v[i]);
        }
      }
      break;
    }
    //Questão 8: Ler 2 vetores reais de 15 posições, criar um terceiro vetor no qual o valor de suas posições é igual a 1 se o valor daquela posição é igual nos dois primeiros vetores e 0 caso não seja, imprimir os 3 vetores.
    case 8:{
      int elementos = 15, v[3][elementos];
      for (int i = 0; i <=1; i++){
        for (int j = 0; j<elementos; j++){
          printf("digite o %d numero do %d vetor: ", j+1, i+1);
          scanf("%d", &v[i][j]);
        }
      }
      for(int i = 0; i < elementos; i++){
        if (v[0][i] == v[1][i]){
          v[2][i] = 1;
        }else{
          v[2][i] = 0;
        }
      }
      for (int i = 0; i<3 ; i++){
        printf("Vetor %i: \n", i+1);
        for (int j = 0; j<elementos; j++){
          printf("%d | ", v[i][j]);
        }
        printf("\n");
      }
      break;
    }
    //Questão 9: Preencher um vetor com 20 numeros reais, depois imprimir o somatorio S={(p1-p20)^2 + (p2-p19)^2... }
    case 9:{
      int soma = 0, elementos=20, v[elementos];
      for (int i=0; i < elementos; i++){
        printf("Digite o %i numero: ", i+1);
        scanf("%i", &v[i]);
      }
      for (int i=0; i<elementos/2; i++){
        printf("Soma = %d || i = %d || v[i] = %d || v[elementos -1 - i]= %d\n", soma,i,v[i],v[elementos-1-i]);
        soma += pow((v[i]-v[elementos-1-i]),2);
      }
      printf("S = %d", soma);
      break;
    }
    //Questão 10: Ler N, carregar um vetor com os N primeiros numeros da sequencia de fibonacci
    case 10:{
      int n;
      printf("Digite n: ");
      scanf("%d", &n);
      int fib[n], antigo = 0, atual = 1, novo;
      for (int i = 0; i<n; i++){
        fib[i] = atual;
        novo = atual + antigo;
        antigo = atual;
        atual = novo;
      }
      for (int i = 0; i<n; i++){
        printf("%d | ", fib[i]);
      }
      break;
    }
    //Questão 11: Ler dois vetores e criar um terceiro no qual cada posição tem o valor da soma dos valores da mesma posição nos vetores 1 e 2
    case 11:{
      int elementos=3,v[3][elementos];
      // i = numero de vetores
      for (int i = 0; i<2;i++){
        for(int j = 0; j<elementos; j++){
          printf("Digite o valor %d do vetor %d: ", j+1, i+1);
          scanf("%d", &v[i][j]);
        }
      }
      printf("Vetor resultante:\n");
      for (int i = 0; i < elementos; i++){
        v[2][i] = v[0][i] + v[1][i];
        printf("%d | ", v[2][i]);
      }
      
      break;
    }
    //Questão 12: Ler 10 valores, guardar eles em um vetor chamado vetorOriginal, criar um segundo vetor com os elementos na ordem inversa do original
    case 12:{
      int elementos = 10, vetorOriginal[elementos], vetorInverso[elementos];
      for(int i = 0; i <elementos; i++){
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &vetorOriginal[i]);
      }
      printf("Vetor original: \n");
      for (int i = 0; i<elementos; i++){
        printf("%d | ", vetorOriginal[i]);
      }
      printf("\nVetor inverso: \n");
      for(int i = 0; i < elementos; i++){
        vetorInverso[i]=vetorOriginal[elementos-1-i];
        printf("%d | ", vetorInverso[i]);
      }
      
      break;
    }
    //Questão 13:
    case 13:{
      
      break;
    }
    //Questão 14: Ler 2 vetores numericos, criar um terceiro vetor intercalando o valor das posições de cada um desses
    case 14:{
      int elementos = 5, v[2][elementos], v3[elementos*2];
      // i = numero de vetores
      //vetor 1 e 2
      for (int i=0;i<2;i++){
        for (int j = 0; j<elementos; j++){
          printf("Digite o %d valor do %d vetor: ", j+1, i+1);
          scanf("%d", &v[i][j]);
        }
      }
      //vetor 3
      int aux = -1;
      for(int i = 0; i<elementos; i++){
        for(int j = 0; j <= 1; j++){
          aux++;
          v3[aux] = v[j][i];
        }
      }
      //Resultados
      for (int i = 0; i<2;i++){
        printf("\nVetor %d: \n", i+1);
        for (int j=0; j<elementos; j++){
          printf("%d | ", v[i][j]);
        }
      }
      printf("\nVetor 3: \n");
      for (int j=0; j<elementos*2; j++){
        printf("%d | ", v3[j]);
      }
      break;
    }
    //Questão 15: Ler um vetor de 20 numeros inteiros, imprimir o vetor e quantos elementos se repetem dentro dele
    case 15:{
      int elementos = 20, repetidos = 0, v[elementos];
      for (int i = 0; i<elementos; i++){
        printf("digite o %d valor: ", i+1);
        scanf("%d", &v[i]);
      }
      for (int i = 0; i<elementos; i++){
        for (int j=0; j<elementos; j++){
          if(j != i ){
            if (v[i] == v[j]){
              repetidos++;
            }
          }
        }
      }
      printf("Quantidade de elementos repetidos: %d\n", repetidos/2);
      printf("Vetor: \n");
      for(int i = 0; i<elementos; i++){
        printf("%d | ", v[i]);
      }
      break;
    }
    //Questão 16: Ler um vetor e imprimir o maior elemento e sua posição
    case 16:{
      int maior = NULL, pos, elementos = 10, v[elementos];
      for (int i = 0; i < elementos; i++){
        printf("digite o %d numero: ", i+1);
        scanf("%d", &v[i]);
      }
      for (int i = 0; i<elementos; i++){
        if (v[i] > maior){
          maior = v[i];
          pos = i;
        }
      }
      printf("O maior numero e %d e esta na posicao %d.", maior, pos);
      break;
    }
    //Questão 17: Ler e guardar a idade de 40 alunos em um vetor, imprimir o mais velho, o mais novo, a media de idade, a quantidade de alunos abaixo e acima de 16 anos
    case 17:{
      int mVelho = 0, mNovo = 200, alunos = 40, soma = 0, abaixo = 0, acima = 0, v[alunos];
      for (int i = 0; i < alunos; i++){
        printf("Digite a idade do %d aluno: ", i+1);
        scanf("%d", &v[i]);
      }
      for (int i = 0; i< alunos; i++){
        soma += v[i];
        if (v[i] > 16){
          acima++;
        }
        if (v[i]<=16){
          abaixo++;
        }
        if (v[i] > mVelho){
          mVelho = v[i];
        }
        if (v[i] < mNovo){
          mNovo = v[i];
        }
      }
      printf("A sala tem %d alunos com 16 ou menos anos, e %d com 17 ou mais. Alem disso, a media de idade da sala e %d anos, o aluno mais velho tem %d e o mais novo %d anos", abaixo, acima, soma/alunos, mVelho, mNovo);
      break;
    }
    //Questão 18: ler 5 numeros e guardar eles em um vetor, ordenar esses numeros
    case 18:{
      int v[5], aux;
      for (int i = 0; i<5; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &v[i]);
      }
      for (int i = 0; i<5; i++){
        for (int j = i+1; j <5; j++){
          if(v[i] > v[j]){
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
          }
        }
      }
      for (int i = 0; i < 5; i++){
        printf("%d | ", v[i]);
      }
      break;
    }

    //EXERCICIOS REFERENTES AS VIDEOAULAS DA UFOP
    //Questão 1: Fazer uma função que retorne o maior valor de um vetor de inteiros
    case -1:{
      int v[5] = {1,2,3,4,5};
      int m = maior(v, 5);
      printf ("O maior numero e: %d", m);
      break;
    }

    //Questão 2: Calcular a media de um vetor utilizando o prototipo de função dado
    case -2:{
      double v[5] = {1,2,3,4,5};
      double m = media(v,5);
      printf("Media = %lf", m);
      break;
    }
    default:{
      printf("Questao invalida.");
      break;
    }
  }
}

int maior(int vetor[], int tamanho){
  int maior = 0;
  for (int i = 0; i<tamanho; i++){
    if (*(vetor+i) > maior){
      maior = *(vetor+i);
    }
  }
  return maior;
}

double media(double vetor[], int tamanho){
  double media = 0.0;
  for (int i = 0; i < tamanho; i++){
    media += vetor[i];
  }
  return media/tamanho;
}