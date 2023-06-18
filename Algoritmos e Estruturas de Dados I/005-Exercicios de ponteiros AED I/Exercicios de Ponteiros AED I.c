#include <stdio.h>

//Função para a questão 3:
void funcQ3(int *n1, int *n2);
//Função para a questão 4:
int funcQ4(int *n1, int *n2, int *n3);
//Cabeçalho pre-determinado para Q5:
void calcCircunferencia (float R, float *compr, float *area);

int main(void) {
  int Questao;
  printf("digite o numero da questao: ");
  scanf("%i", &Questao);
  //Switch para a seleçao de questões:
  switch(Questao){
    //Questão 1: Comparar o endereço de duas varaveis e mostrar o maior.
    case 1:{
      int x = 10, y=20;
      int *xPtr = &x, *yPtr = &y;
      //DEBUG: printf("x = %d, y = %d, xPtr = %p, yPtr = %p\n", x, y, xPtr, yPtr);
      if(xPtr > yPtr){
        printf("xPtr > yPtr: %p\n", xPtr);
      }else{
        printf("yPtr > xPtr: %p\n", yPtr);
      }
      break;
    }
    //Questão 2: Corrigir um erro de codigo (Trocar %d para %p)
    case 2:{
      int x, *p, **q;
      p = &x;
      q = &p;
      x = 10;
      printf("%p\n", &q);
      break;
    }
    //Questão 3: Ler dois valores inteiros, criar uma função que receba esses dois valores como parametros e mude o valor da primeira variavel para o maior valor e o da segunda para o menor valor.
    case 3:{
      int x, y;
      printf("Digite o valor de x: ");
      scanf("%d", &x);
      printf("Digite o valor de y: ");
      scanf("%d", &y);
      int *xPtr = &x, *yPtr = &y;
      //DEBUG: printf("x = %d || y = %d || *xPtr = %d || *yPtr = %d || xPtr = %p || yPtr = %p\n", x, y, *xPtr, *yPtr, xPtr, yPtr);
      funcQ3(xPtr, yPtr);
      printf("Maior = %d || Menor = %d\n", *xPtr, *yPtr);
      //DEBUG: printf("x = %d || y = %d\n", x, y);
      break;
    }
    //Questão 4: Ler 3 valores inteiros, trocar o valor das variaveis para a ordem crescente e printar eles, caso sejam iguais a função deve retornar o valor 1, caso sejam diferentes retornar o valor 0
    case 4:{
      int x,y,z;
      printf("Digite o valor de X: ");
      scanf("%d", &x);
      printf("Digite o valor de Y: ");
      scanf("%d", &y);
      printf("Digite o valor de Z: ");
      scanf("%d", &z);
      int *xPtr = &x, *yPtr = &y, *zPtr = &z;
      int v = funcQ4(xPtr, yPtr, zPtr);
      printf("%d, %d, %d\n", x,y,z);
      if(v == 1){
        printf("Os numeros sao iguais");
      }else{
        printf("Os numeros sao diferentes");
      }
      break;
    }
    //Questão 5: Ler o raio de uma circunferencia e calcular sua area e volume por meio de uma função com cabeçalho pre determimado. Mostrar os resultados da função
    case 5:{
      float r, a, c;
      printf("Digite o valor do raio da circunferencia: ");
      scanf("%f", &r);
      float *aPtr = &a, *cPtr = &c;
      calcCircunferencia(r, aPtr, cPtr);
      printf("Area = %.2f || Circunferencia = %.2f", a, c);
      break;
    }


    default:{
      printf("Questao invalida.");
      break;
    }
  }
}

void funcQ3(int *n1, int *n2){
  int aux;
  if(*n2 > *n1){
    aux = *n2;
    *n2 = *n1;
    *n1 = aux;
  }
}

int funcQ4(int *n1, int *n2, int *n3){
  int aux;
  if (*n1 > *n2){
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
  }
  if (*n2 > *n3){
    aux = *n2;
    *n2 = *n3;
    *n3 = aux;
  }  
  if (*n1 > *n2){
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
  }
  
  if(*n1 == *n2 && *n1 == *n3){
    return 1;
  }else{
    return 0;
  }
}

void calcCircunferencia (float R, float *compr, float *area){
  *compr = 2.0*3.14*R;
  *area = 3.14*R*R;
}