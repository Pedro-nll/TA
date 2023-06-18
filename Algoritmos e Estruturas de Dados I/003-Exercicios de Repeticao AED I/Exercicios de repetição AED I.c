#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int Questao;
    printf("Digite o numero da questao: ");
    scanf("%i", &Questao);
    switch(Questao){
        //Questão 1: Imprimir todos os numeros pares de 2 ate 50
        case 1:{
            for(int i = 2; i <= 50; i += 2){
                printf("%i\n", i);
            }
            break;
        }

        //Questão 2: Imprimir todos os numeros seguindo um periodo de 10 a partir do numero 11
        case 2:{
            for(int i = 11; i <= 101; i += 10){
                printf("%i\n", i);
            }
            break;
        }

        //Questão 3: Ler 10 numeros reais e imprimir o menor e o maior
        case 3:{
            //Declaro max e min, caso esses começem zerados aux não consegue substituir eles, portanto dei um valor mt pequeno para max e mt alto para min.
            float max=-2000000, min=2000000000;
            for(int i = 1; i <11; i++){
                //aux recebe o valor digitado pelo usuario e caso este seja maior que o maior valor previamente digitado ou menor que o menor, max/min recebe esse valor
                float aux;
                printf("Digite o %iº numero: ", i);
                scanf("%f", &aux);
                if (aux > max){
                    max = aux;
                }
                if (aux < min){
                    min = aux;
                }
                //DEBUG: printf("      aux = %.2f , min = %.2f, max = %.2f\n", aux, min, max);
                //Final do for loop, ou seja, aux é zerado e o valor digitado só sera gravado caso seja menor ou maior que o previo
            }
            printf("O maior numero digitado foi %.2f, e o menor %.2f.\n", max, min);
            break;
        }

        //Questão 4: Calcular a soma de todos os numeros ate 20
        case 4:{
            int soma = 0;
            for(int i = 0; i <= 20; i++){
                soma += i;
                //DEBUG: printf("    i = %i, soma = %i\n", i, soma);
            }
            printf("Soma = %i", soma);
            break;
        }

        //Questão 5: Calcular o produto de todos os numeros ate 20
        case 5:{
            //Valor final é muito maior que a capacidade de um int, ou ate mesmo de um long, portanto há a necessidade de chamar um long
            long long int produto = 1;
            for(int i = 1; i <= 20; i++){
                produto *= i;
                //DEBUG: printf("    i = %i, soma = %lli\n", i, produto);
            }
            printf("Produto final = %lld", produto);
            break;
        }

        //Questão 6: ler e somar 100 numeros inteiros
        case 6:{
            int soma = 0;
            for(int i = 1; i <= 100; i++){
                int aux = 0;
                printf("Digite o seu %iº numero: ", i);
                scanf("%d", &aux);
                soma += aux;
            }
            printf("soma = %d", soma);
            break;
        }

        //Questão 7: Ler N numeros e somar todos os numeros impares, N é informado pelo usuario
        case 7:{
            int n, aux, soma = 0;
            printf("Quantos numeros serao digitados? ");
            scanf("%d", &n);
            for(int i = 1; i <= n; i++){
                printf("Digite o %iº numero: ", i);
                scanf("%i", &aux);
                if (aux % 2 == 1){
                    soma += aux;
                }
            }
            printf("Soma dos numeros impares = %i", soma);
            break;
        }

        //Questão 8: Ler 30 numeros inteiros e somar os divisiveis por 5:
        case 8:{
            int aux, soma=0;
            for(int i = 1; i <= 30; i++){
                printf("Digite o %iº numero: ", i);
                scanf("%i", &aux);
                if(aux % 5 == 0){
                    soma += aux;
                }
            }
            printf("Soma = %i", soma);
            break;
        }

        //Questão 9: Ler 100 numeros inteiros e exibir o produto:
        case 9:{
            int produto = 1;
            for(int i = 1; i <= 10; i++){
                int aux = 0;
                printf("Digite o seu %iº numero: ", i);
                scanf("%i", &aux);
                produto = produto * aux;
                //DEBUG: printf("Aux = %i, Produto = %i\n", aux, produto);
            }
            printf("Produto = %i", produto);
            break;
        }

        //Questão 10: Ler N numeros inteiros e exibir o produto dos pares
        case 10:{
            int n, produto = 1;
            printf("Quantos numeros serao lidos? ");
            scanf("%i", &n);
            for (int i = 1; i <= n; i++){
                int aux;
                printf("Digite o %iº numero: ", i);
                scanf("%i", &aux);
                if (aux % 2 == 0){
                    produto *= aux;
                }
            }
            printf("Produto = %i", produto);
            break;
        }

        /*Questão 11: Ler numeros informados pelo usuario ate o numero -1 ser digitado, escrever a quantidade de numeros digitados
        e quantas vezes o numero 5 estava presente entre eles*/
        case 11:{
            int aux, nDigitados = 0, qnt5 = 0;
            do{
                printf("Digite um numero (digite -1 para parar): ");
                scanf("%i", &aux);
                nDigitados++;
                if (aux == 5){
                    qnt5++;
                }
            }while(aux != -1);
            printf("Foram digitados %i numeros , e o numero 5 apareceu %i vezes.", nDigitados-1, qnt5);
            break;
        }

        //Questão 12: Soma e media de n alunos, cada aluno tem 3 provas
        case 12:{
            int n;
            float aux, auxDivisao, soma;
            printf("Quantos alunos participaram das avaliacoes: ");
            scanf("%i", &n);
            for(int i = 1; i<=n; i++){
                for(int j = 1; j <= 3; j++){
                    printf("Digite a %iº nota do aluno %i: ", j, i);
                    scanf("%f", &aux);
                    soma += aux;
                    auxDivisao++;
                }
            }
            printf("A soma de todas as notas dos alunos foi de %.2f, com a media sendo %.2f", soma, soma/auxDivisao);
            break;
        }

        //Questão 13: identificar se o numero do usuario é ou nao primo
        case 13:{
            int n, aux=0;
            printf("Digite um numero inteiro: ");
            scanf("%i", &n);
            for (int i = 2; i<n; i++){
                if(n % i == 0){
                    aux++;
                    break;
                }
                //DEBUG: printf("Aux = %i, i = %i, n = %i\n", aux, i, n);
            }
            if(aux == 0){
                printf("%i e primo.", n);
            }else{
                printf("%i nao e primo", n);
            }
            break;
        }

      //Questao 14: Imprimir a quantidade de numeros primos de 0 a 1000
      case 14:{
        int qntNumeros=0;
        for(int i = 2; i<=1000; i++){
          int divisores=0;
          for(int j= 2; j<i; j++){
            if (i % j == 0){
              divisores++;
              break;
            }
          }
          if(divisores==0){
            qntNumeros++;
            //DEBUG: printf("%i\n", i);
          }
        }
        printf("quantidade de numeros primos = %i.", qntNumeros);
        break;
      }

      //Questão 15: imprimir a sequencia de fibonacci ate n
      case 15:{
        int n,aux2, aux=1;
        printf("digite o valor de n: ");
        scanf("%i", &n);
        printf("A sequencia que chega mais perto de %i e: \n", n);
        printf("%i, ",aux);
        for(int f=1; f<= n; f += aux2){
          printf("%i, ", f);
          aux2 = aux;
          aux = f;
        }
        break;
      }

      //Questão 16: somar 1 + 1/2 + 1/3 ... 1/n
      case 16:{
        float soma = 0;
        int n;
        printf("Digite o valor de n: ");
        scanf("%i", &n);
        for (int i = 1; i < n+1; i++){
          soma += 1/ (float) i;
          //DEBUG: printf("Soma = %.2f || i= %i || n = %i\n", soma, i, n);
        }
        printf("Soma = %.2f", soma);
        break;
      }

        //Questão 17: somar 1/1 + 3/2 + 5/3... onde o numero de termos é n
        case 17:{
          float divisor, dividendo, soma=0;
          int n;
          printf("digite o valor de n: ");
          scanf("%i", &n);
          for(int i = 1; i <= n; i++){
            dividendo = 1 + 2 * (i-1);
            divisor = i;
            soma += dividendo/divisor;
            //DEBUG: printf("divisor = %.2f || dividendo = %.2f || n = %i || i = %i || soma = %.2f\n", divisor, dividendo, n, i, soma);
          }
          printf("Soma = %.2f\n", soma);
          break;
        }

      //Questão 18: Valor aproximado de pi usando raiz quadrada de S x 32, em que S = 1/1+1/3+1/5...1/(1+2x)
      case 18:{
        int n;
        float s = 0;
        printf("Digite o valor de N: ");
        scanf("%i", &n);
        for(int i = 0; i < n; i++){
          float aux = 1.0/(1+2*i);
          int sinal = (i%2 == 0) ? 1 : -1;
          float termo = aux*sinal;
          s += termo;
          //DEBUG: printf("n = %i || s = %f || aux = %f || sinal = %i || termo = %f\n", n, s, aux, sinal, termo);
        }
        printf("Pi e aproximadamente %f", s*4);
        break;
      }

      //Questão 19: Descobrir o fatorial de um numero N
      case 19:{
        int n, fatorial=1;
        printf("Digite o valor de N: ");
        scanf("%i", &n);
        for (int i = 1; i<=n; i++){
            fatorial *= i;
            //DEBUG: printf("n = %i || fatorial = %i || i = %i\n", n, fatorial, i);
        }
        printf("Fatorial = %i", fatorial);
        break;
      }

      //Questão 20: Calcular o seno de x seguindo a sequencia de Mac-laurin, com n termos. N e x são fornecidos pelo usuario
      case 20:{
        int x, n;
        float seno = 0;

        do{
          printf("Digite o valor de x (entre 0 e 2) ");
          scanf("%i", &x);
        }while(x < 0 || x > 2);
        do{
          printf("Digite uma quantidade N de termos (n>0) ");
          scanf("%i", &n);
        }while(n<0);
        for (int j = 0; j < n; j++){
          int periodo = 1 + 2*j;
          float fatorial = 1;
          for (int i = 1; i <= periodo; i++){
            fatorial *= i;
          }
          float dividendo = pow(x,periodo);
          seno += dividendo/fatorial;
        //DEBUG: printf("fatorial = %f || j = %i || dividendo = %f\n", fatorial, j, dividendo);
        }
        printf("Seno de %i radianos = %.2f", x, seno);
        break;
      }

      //Questão 21: Receber votos em 4 candidatos por meio de codigo, calcular os votos em cada candidato,total de votos nulos, % de votos brancos sobre o total
      case 21:{
        int n, c1=0,c2=0,c3=0,c4=0,nulo=0,branco=0;
        do{
          printf("Digite o cod do candidato (digite 0 para parar) ");
          scanf("%i", &n);
          switch (n){
            case 1:{
              c1++;
              break;
            }case 2:{
              c2++;
              break;
            }case 3:{
              c3++;
              break;
            }case 4:{
              c4++;
              break;
            }case 5:{
              nulo++;
              break;
            }case 6:{
              branco++;
              break;
            }case 0:{
              printf("Votacao encerrada! \n");
              break;
            }default:{
              printf("Codigo invalido \n");
              break;
            }
          }
        }while(n != 0);
        int total = c1+c2+c3+c4+nulo+branco;
        printf("O candidato 1 recebeu %i votos, o 2 recebeu %i votos, o 3 recebeu %i votos e o 4 recebeu %i votos. A votação teve %i votos nulos e os votos brancos foram %.2f%% do total.", c1,c2,c3,c4,nulo, (float) branco*100.0/(float)total);
        break;
      }
        default:{
            printf("Questao invalida.");
            break;
        }
        }
}
