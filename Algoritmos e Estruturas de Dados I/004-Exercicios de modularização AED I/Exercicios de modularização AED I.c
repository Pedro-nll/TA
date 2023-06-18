#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//Função para a questão 1:
float radFunc(int graus); 
//Função para a questão 2:
int fatorialFunc(int x); 
//Função para a questão 3:
float reajusteFunc(float saldo, float reajuste); 
//Função para a questão 4:
int hipotenusaFunc(int cateto1, int cateto2); 
// Funções para a questão 5:
int areaQuadradoFunc(int lado);
int perimetroQuadradoFunc(int lado);
int diagonalQuadradoFunc(int lado);
//Função para a questão 6:
float mediaFunc(float nota1, float nota2, float nota3, char tipoDeMedia); 
//Função para a questão 7:
void funcCrescente(int numeroC1, int numeroC2, int numeroC3);
//Função para a questão 8:
void conceitoFunc(float media);
//função para a questão 9:
float somaSobreFatorialFunc(int termos);
//Função para a questao 10:
bool posOuNeg(int numero);
//Função para a questão 11:
float sequenciaQ11(int Qtermos);
//Função para a questão 12:
char categoriaNadador(int idade);


int main(void) {
  int n;
  printf("Digite o numero da questao: ");
  scanf("%i", &n);
  switch (n){
    //Questão 1: ler um valor ("g") em graus e utilizar uma função (radFunc) para converte-lo em rad.
    case 1:{
      int g;
      printf("Digite um angulo em graus: ");
      scanf("%i", &g);
      float rad = radFunc(g);
      printf("%i em graus e igual a %.2f radianos", g, rad);
      break;
    }

    //Questão 2: Ler um valor ("n") e calcular o seu fatorial utilizando uma função
    case 2:{
      int x;
      printf("Digite um valor para n: ");
      scanf("%i", &x);
      int f = fatorialFunc(x);
      printf("o fatorial de %i e %i", x, f);
      break;
    }

    //Questão 3: Ler o saldo e o % de reajuste de uma aplicação financeira e calcular o novo saldo por meio de uma func
    case 3:{
      float s, r;
      printf("Digite o saldo atual: ");
      scanf("%f", &s);
      printf("Digite a %% de reajuste: ");
      scanf("%f", &r);
      float saldoNovo = reajusteFunc(s, r);
      printf("O novo saldo e de %.2f", saldoNovo);
      break;
    }

    //Questão 4: Ler dois catetos de um triangulo e calcular sua hipotenusa por meio de uma função.
    case 4:{
      int c1,c2;
      printf("Digite o valor do primeiro cateto: ");
      scanf("%i", &c1);
      printf("Digite o valor do segundo cateto: ");
      scanf("%i", &c2);
      int h = hipotenusaFunc(c1,c2);
      printf("O triangulo com os catetos %i e %i tem %i como sua hipotenusa.", c1, c2, h);
      break;
    }

    //Questão 5: ler o lado de um quadrado e calcular o perimetro, area e diagonal de um quadrado usando uma função para cada.
    case 5:{
      int x;
      printf("Digite o lado do quadrado: ");
      scanf("%i", &x);
      printf("Um quadrado de lado %i tem como:\n", x);
      
      int a = areaQuadradoFunc(x), p = perimetroQuadradoFunc(x), d = diagonalQuadradoFunc(x);
      printf("area = %i\nperimetro = %i\ndiagonal = %i\n", a, p, d);
      break;
    }

    //Questão 6: Ler 3 nota de N alunos e calcular ou a media aritmetica ou a media ponderada de cada um deles:
    case 6:{
      int n;
      printf("Digite a quantidade de alunos: ");
      scanf("%i", &n);
      for (int i = 1; i <= n; i++){
        float n1,n2,n3;
        char t;
        printf("digite a nota 1 do aluno %i: ", i);
        scanf("%f", &n1);
        printf("digite a nota 2 do aluno %i: ", i);
        scanf("%f", &n2);
        printf("digite a nota 3 do aluno %i: ", i);
        scanf("%f", &n3);
        printf("digite o tipo de media a ser calculada ('a' para aritmetica e 'p' para ponderada): ");
        scanf("%s", &t);
        float m = mediaFunc(n1, n2, n3, t);
        printf("A media do aluno %i e %.2f\n", i, m);
      }
      break;
    }

    //Questão 7: ler N conjuntos de 3 numeros e organizar eles em ordem crescente (sem uso de arrays)
    case 7:{
      int n;
      printf("Digite a quantidade de conjuntos: ");
      scanf("%i", &n);
      for (int i = 1; i <= n; i++){
        int n1,n2,n3;
        printf("digite o primeiro numero do conjunto %i: ", i);
        scanf("%i", &n1);
        printf("digite o segundo numero do conjunto %i: ",i);
        scanf("%i", &n2);
        printf("digite o terceiro numero do conjunto %i: ", i);
        scanf("%i", &n3);
        funcCrescente(n1,n2,n3);
      }
      break;
    }

    //Questão 8: Ler a media de N alunos e fazer uma função para identificar o conceito que aquele aluno recebe
    case 8:{
      int n;
      printf("Digite o numero de alunos: ");
      scanf("%i", &n);
      for (int i = 1; i <= n; i++){
        float m;
        printf("Digite a media do aluno %i: ", i);
        scanf("%f", &m);
        conceitoFunc(m);
      }
      break;
    }

    //Questão 9: Ler uma quantidade N (inteira e positiva) de parametros, e retorna uma soma S = {1/1! + 1/2! + 1/3!...1/N!} 
    case 9:{
      int n;
      do{
        printf("Digite o valor de n (inteiro e positivo): ");
        scanf("%i", &n);
      }while(n<1);
      float s = somaSobreFatorialFunc(n);
      printf("%.2f", s);
      break;
    }

    //Questão 10: Ler N numeros, fazer uma função que retorna um valor logico (T/F), e dizer se o numero é positivo ou negativo
    case 10:{
      int n;
      printf("Quantos numeros serao digitados? ");
      scanf("%i", &n);
      for (int i = 1; i <= n; i++){
        int x;
        printf("Digite o %i numero: ", i);
        scanf("%i", &x);
        bool y = posOuNeg(x);
        if (y == true){
          printf("%i e positivo.\n", x);
        }else{
          printf("%i e negativo\n", x);
        }
      }
      break;
    }

    //Questão 11: Ler N e imprimir o valor de S = {2/4 + 5/5 + 10/6 ... (n^2+1)/(n+3)}
    case 11:{
      int n;
      printf("Digite o valor de n: ");
      scanf("%i", &n);
      float s = sequenciaQ11(n);
      printf("%.2f", s);  
      break;
    }

    //Questão 12: Ler a idade de um nadador e por meio de uma função imprimir a categoria deste
    case 12:{
      int i;
      printf("Digite a idade do nadador: ");
      scanf("%i", &i);
      char c = categoriaNadador(i);
      printf("Categoria %c\n", c);
      break;
    }
    default:{
      printf("questao invalida.");
      break;
    }
  }
}

float radFunc(int graus){ 
  return (graus * 3.14) / 180;
}

int fatorialFunc(int x){
  int produto =1;
  for (int i = 1; i <= x; i++){
    produto *= i;
  }
  return produto;
}

float reajusteFunc(float saldo, float reajuste){
  return saldo * (1 + (reajuste/100));
}

int hipotenusaFunc(int cateto1, int cateto2){
  return sqrt(pow(cateto1, 2) + pow(cateto2, 2));
}

int areaQuadradoFunc(int lado){
  return lado*lado;
}

int perimetroQuadradoFunc (int lado){
  return lado*4;
}

int diagonalQuadradoFunc(int lado){
  return lado * sqrt(2);
}

float mediaFunc(float nota1, float nota2, float nota3, char tipoDeMedia){
  if(tipoDeMedia == 'a'){
    return (nota1 + nota2 + nota3)/3;
  }else if(tipoDeMedia == 'p'){
    return ((nota1 * 5) + (nota2 * 3) + (nota3 * 2))/10;
  }
}

void funcCrescente(int numeroC1, int numeroC2, int numeroC3){
  if (numeroC1>numeroC2 && numeroC1>numeroC3 && numeroC2>numeroC3){
    printf("%i, ", numeroC3);
    printf("%i, ", numeroC2);
    printf("%i.\n ", numeroC1);
  }else if (numeroC1>numeroC2 && numeroC1>numeroC3 && numeroC3>numeroC2){
    printf("%i, ", numeroC2);
    printf("%i, ", numeroC3);
    printf("%i.\n ", numeroC1);
  }else if (numeroC2>numeroC1 && numeroC2>numeroC3 && numeroC1>numeroC3){
    printf("%i, ", numeroC3);
    printf("%i, ", numeroC1);
    printf("%i.\n ", numeroC2);
  }else if (numeroC2>numeroC1 && numeroC2>numeroC3 && numeroC3>numeroC1){
    printf("%i, ", numeroC1);
    printf("%i, ", numeroC3);
    printf("%i.\n ", numeroC2);
  }else if (numeroC3>numeroC1 && numeroC3>numeroC2 && numeroC2>numeroC1){
    printf("%i, ", numeroC1);
    printf("%i, ", numeroC2);
    printf("%i.\n ", numeroC3);
  }else if (numeroC3>numeroC1 && numeroC3>numeroC2 && numeroC1>numeroC2){
    printf("%i, ", numeroC2);
    printf("%i, ", numeroC1);
    printf("%i.\n ", numeroC3);
  }
}

void conceitoFunc(float media){
  if (media < 40){
    printf("Conceito F\n");
  }else if(media < 60){
    printf("conceito E\n");
  }else if(media < 70){
    printf("conceito D\n");
  }else if(media <80){
    printf("Conceito C\n");
  }else if(media < 90){
    printf("conceito B\n");
  }else if(media >= 90){
    printf("conceito A\n");
  }
}

float somaSobreFatorialFunc(int termos){
  float soma = 1;
  for(int i = 1; i <= termos; i++){
    int fatorial = 1;
    for (int j = 1; j <= i; j++){
      fatorial *= j;
    }
    soma += 1.0/(float) fatorial;
  }
  return soma;
}

bool posOuNeg(int numero){
  bool valor;
  if (numero >= 0){
    valor = true;
  }else{
    valor = false;
  }
  return valor;
}

float sequenciaQ11(int Qtermos){
  float soma = 0;
  for (int i = 1; i <= Qtermos; i++){
    soma += (pow(i,2.0) + 1.0)/(i+3.0);
  }
  return soma;
}

char categoriaNadador(int idade){
  if (idade >= 5 && idade < 8){
    return 'f';
  }else if(idade < 11){
    return 'e';
  }else if(idade < 14){
    return 'd';
  }else if(idade < 16){
    return 'c';
  }else if(idade < 18){
    return 'b';
  }else if(idade >= 18){
    return 'a';
  }else{
    return 'X';
  }
}