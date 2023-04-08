#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


float x,y,z;
int main()
{
    int Q;
    printf("Numero da questao: ");
    scanf("%i", &Q);
    //Switch case para a escolha de questão
    switch (Q){
        //Questão 1: Comparar dois numeros e imprimir o maior
        case 1:{
            n1();
            n2();
            if (x > y){
                printf("X e maior que Y.\n");
            }
            else if (y > x){
                printf("Y e maior que X\n");
            }
            else {
                printf("Os numeros sao iguais\n");
            }
            break;
        }
        //Questão 2: Imprimir se o numero é par ou impar
        case 2:{
            n1();
            if ((int)x % 2 == 0){
                printf("X e par.");
            }
            else{
                printf("X e impar");
            }
            break;
        }
        //Questão 3: Verificar se as operações logicas são verdadeiras
        case 3:{
            int r,s,t,x,y,z;
            r = 2;
            s = 5;
            t = -1;
            x = 3;
            y = 1;
            z = 0;
            //Afirmativa A
            if((r >= 5 || t > z) && x - y + r > 3*z){
                printf("A = true\n");
            }else{
                printf("A = false\n");
            }
            //Afirmativa B
            if (t < 0){
                t = t*-1;
                if((t + 3>= 4) && !(3*r/2<s*3)){
                    printf("b = true\n");
                }else{
                    printf("b = false\n");
                }
            }
            else{
                if((t + 3>= 4) && !(3*r/2<s*3)){
                    printf("b = true\n");
                }else{
                    printf("b = false");
                }
            }
            t = -1;
            //Afirmativa C
            if(x == 2 || y == 1 && (z == 0 || r > 3) && s < 10){
                printf("c = true\n");
            }else{
                printf("c = false\n");
            }
            //Afirmativa D
            if(r!= s || !(sqrt(r)< sqrt(x)) && (4327*x*s*z==0)){
                printf("D = true\n");
            }else{
                printf("D = false\n");
            }
            break;
        }
        //Questão 4: Verificar se as operações logicas sao verdadeiras
        case 4:{
            bool p = 1, q = 0;
            printf("!p = %d\n", !p);
            printf("!q = %d\n", !q);
            printf("p && q = %d\n", p&&q);
            printf("p || q = %d\n", p||q);
            printf("(!p) && q = %d\n", (!p)&&q);
            printf("p && (!q) = %d\n", p && (!q));
            printf("p || (!q) = %d\n", p || (!q));
            printf("(!p) && (!q) = %d\n", (!p)&&(!q));
            printf("(!p) || (!q) = %d\n", (!p)||(!q));
            break;
        }
        //Questão 5: Imprimir menu de opções com as opções sendo soma e raiz quadrada de numeros digitados pelo usuario
        case 5:{
            int m;
            printf("Menu de opcoes:\n");
            printf("1. Somar dois numeros.\n2. Raiz quadrada de um numero.\ndigite a opcao desejada: ");
            scanf("%i", &m);
            switch (m){
                case 1:{
                    n1();
                    n2();
                    printf("X + Y = %.2f\n", x + y);
                    break;
                }
                case 2:{
                    n1();
                    printf("Raiz quadrada de x = %.1f\n", sqrt((x)));
                    break;
                }
                default:{
                    printf("opcao inexistente.\n");
                }
            }
            break;
        }
        //Questão 6: Calcular a media e a situação de aprovação de um aluno que fez 3 provas
        case 6:{
            printf("Digite as notas das provas com x sendo a primeira, y a segunda e z a terceira:\n");
            n1();
            n2();
            n3();
            float nota = (x + y + z)/3;
            if (nota >= 0 && nota < 4 ){
                printf("A nota final do aluno foi %.2f, com isso ele esta reprovado.\n", nota);
            }else if(nota >= 4 && nota < 7){
                printf("A nota final do aluno foi %.2f, com isso ele tera que fazer uma reavaliacao.\n", nota);
            }else if(nota >= 7 && nota <= 10){
                printf("O aluno foi aprovado com uma nota de %.2f!\n", nota);
            }else{
                printf("Nota invalida.\n");
            }
            break;
        }
        //Questão 7: Calcular e categorizar a media ponderada de um aluno considerando 3 notas diferentes
        case 7:{
            float lab,ava,prova;
            printf("Digite as notas das provas com x sendo a nota do laboratorio, y a da avaliacao semestral e z a prova final:\n");
            n1();
            n2();
            n3();
            printf("Qual e o peso do laboratorio? ");
            scanf("%f", &lab);
            printf("Qual e o peso da avaliacao semestral? ");
            scanf("%f", &ava);
            printf("Qual e o peso da prova final? ");
            scanf("%f", &prova);
            float nota = (x * lab + y * ava + z * prova)/(lab + ava + prova);
            if (nota >= 0 && nota < 4 ){
                printf("A nota final do aluno foi %.2f, com isso ele esta reprovado.\n", nota);
            }else if(nota >= 4 && nota < 7){
                printf("A nota final do aluno foi %.2f, com isso ele tera que fazer uma reavaliacao.\n", nota);
            }else if(nota >= 7 && nota <= 10){
                printf("O aluno foi aprovado com uma nota de %.2f!\n", nota);
            }else{
                printf("Nota invalida.\n");
            }
            break;
        }
        //Questão 8: Calcular o valor do aumento e o novo salario de um funcionario baseado em promoções
        case 8:{
            //c = cargo; s = salario atual
            int c;
            float s;
            printf("Qual e o seu cargo atual (1: Escrituario, 2: secretario, 3: caixa, 4: gerente, 5: diretor)? ");
            scanf("%i", &c);
            printf("Qual e seu salario atual? ");
            scanf("%f", &s);
            switch (c){
                case 1:{
                    printf("Caso voce receba uma promocao para secretario seu novo salario sera de %.2f, representando um aumento de 50%%\n", s*1.5);
                    printf("Caso voce receba uma promocao para caixa seu novo salario sera de %.2f, representando um aumento de 102.50%%\n", s*2.025);
                    printf("Caso voce receba uma promocao para gerente seu novo salario sera de %.2f, representando um aumento de 143%%\n", s*2.43);
                    printf("Caso voce receba uma promocao para diretor seu novo salario sera de %.2f, representando um aumento de 167.3%%\n", s*2.673);
                    break;
                }
                case 2:{
                    printf("Caso voce receba uma promocao para caixa seu novo salario sera de %.2f, representando um aumento de 35%%\n", s*1.35);
                    printf("Caso voce receba uma promocao para gerente seu novo salario sera de %.2f, representando um aumento de 62%%\n", s*1.62);
                    printf("Caso voce receba uma promocao para diretor seu novo salario sera de %.2f, representando um aumento de 78.2%%\n", s*1.782);
                    break;
                }
                case 3:{
                    printf("Caso voce receba uma promocao para gerente seu novo salario sera de %.2f, representando um aumento de 20%%\n", s*1.2);
                    printf("Caso voce receba uma promocao para diretor seu novo salario sera de %.2f, representando um aumento de 32%%\n", s*1.32);
                    break;
                }
                case 4:{
                    printf("Caso voce receba uma promocao para diretor seu novo salario sera de %.2f, representando um aumento de 10%%\n", s*1.1);
                    break;
                }
                case 5:{
                    printf("Voce ja chegou ao fim da carreira!");
                    break;
                }
                default:{
                    printf("Codigo invalido!");
                    break;
                }
            }
            break;
        }
        //Questão 9: Ler a idade de um nadador e exibir a categoria que ele pertence
      case 9:{
        printf("Com x sendo a idade do nadador, ");
        n1();
        if (x < 5){
          printf("idade invalida!.");
        }
        else if(x <= 7){
          printf("Essa idade pertence a categoria infantil");
        }
        else if(x <= 10){
          printf("Essa idade pertence a categoria juvenil");
        }
        else if(x <= 15){
          printf("Essa idade pertence a categoria adolescente");
        }
        else if(x <= 30){
          printf("Essa idade pertence a categoria adulto");
        }
        else if(x > 30){
          printf("Essa idade pertence a categoria senior");
        }
        break;
        }
        //Questão 10: Ler a idade e altura de um jogador de basquete, ver se ele se encaixa em alguma categoria e exibi-la
      case 10:{
        printf("Com x sendo a idade do jogador e y a altura (em cm), ");
        n1();
        n2();
        if (x <= 5){
          printf("Nao apto.");
        }
        else if(x <= 10 && y/100 > 1){
          printf("Esse jogador pertence a categoria infantil");
        }
        else if(x <= 17 && y/100 > 1.4){
          printf("Esse jogador pertence a categoria junior");
        }
        else if(x <= 35 && y/100 > 1.7){
          printf("Esse jogador pertence a categoria profissional");
        }
        else if(x > 35 && y/100 > 1.6){
          printf("Esse jogador pertence a categoria senior");
        }
        else{
          printf("Nao apto.");
        }
        break;
      }
      //Questão 11: Ler os lados de um triangulo e ver se esse seria um triangulo valido, depois exibir se ele é equilatero/escaleno/isoceles
      case 11:{
        printf("com x, y e z sendo numeros inteiros e os lados do triangulo\n");
        n1();
        n2();
        n3();
        bool a = abs( (int) y - (int) z) < x && x < y + z;
        bool b = abs( (int) x - (int) z) < y && y < x + z;
        bool c = abs( (int) x - (int) y) < z && z < y + x;
        if (a == 1 || b == 1 || c == 1){
          if (x == y && x == z){
            printf("triangulo equilatero");
          }
          else if(x != y && x != z && y != z){
            printf("triangulo escaleno");
          }
          else{
            printf("triangulo isosceles");
          }
        }
        else{
          printf("triangulo invalido.");
        }
        break;
      }
      //Questão 12: Calcular o novo salario de um funcionario baseado em um aumento de 30% caso este tenha um salario inferior a 700 e de 10% caso tenha um salario maior.
      case 12:{
        printf("Com x sendo o salario atual do funcionario, ");
        n1();
        if(x < 0){
          printf("Salario invalido");
        }else if(x<700){
          printf("O novo salario e %.2f", x*1.3);
        }else if(x >= 700){
          printf("O novo salario e %.2f", x*1.1);
        }
        else{
          printf("salario invalido");
        }
        break;
      }
      //Questão 13: encontrar as raizes de uma equação do segundo grau depois de ler os coeficientes A, B e C
      case 13:{
        float a,b,c;
        printf("digite os valores de a,b,c da equacao do segundo grau: ");
        scanf("%f,%f,%f", &a, &b, &c);
        if (b*b - 4 * a * c >= 0){
          float rd = sqrt(b *  b  - 4 *  a * c);
          float resPos = (-b + rd)/ 2*a;
          float resNeg = (-b - rd)/ 2*a;
          printf("S = {%f,%f}", resPos, resNeg);
        }
        else{
          printf("S = conjunto vazio");
        }
        break;
      }
      //Questão 14: Seguir as instruções de um fluxograma. Ler N1 e N2, compara-los e caso N1 seja maior, somar -10 e designar N1 + 10 a N2, caso N2 seja maior imprimir isso
      case 14:{
        n1();
        n2();
        if (x > y){
          x -= 10;
          y += 10;
        }else{
          printf("X e menor que y");
        }
        break;
      }
      //Questão 15: Ler um peso na terra e calcular o novo peso em um planeta a escolha do usuario
      case 15:{
        printf("Com x sendo o peso na Terra, ");
        n1();
        int cod;
        printf("Considerando: \n");
        printf("1: Mercurio\n2: Venus\n3: Marte\n4: Jupiter\n5: Saturno\n6: Urano\n");
        printf("Digite o codigo do planeta desejado: ");
        scanf("%i", &cod);

        switch(cod){
          case 1:{
            printf("Peso em Mercurio = %.2f", (x / 10) * 0.37);
            break;
          }
          case 2:{
            printf("Peso em Venus = %.2f", (x/10) * 0.88);
            break;
          }
          case 3:{
            printf("Peso em Marte = %.2f", (x/10) * 0.38);
            break;
          }
          case 4:{
            printf("Peso em Jupiter = %.2f", (x/10) * 2.64);
            break;
          }
          case 5:{
            printf("Peso em Saturno = %.2f", (x/10) * 1.15);
            break;
          }
          case 6:{
            printf("Peso em Urano = %.2f", (x/10) * 1.17);
            break;
          }
          default:{
            printf("Codigo invalido.");
          }
        }
      break;
      }
      //Questão 16: Calcular h(x) = x^2 - 16, f(x) = {h(x), se h(x) >=0 || 1, se h(x) < 0} e g(x) = {x^2 + 16, se x > 5 || -x/2 se x <= 5}.
      case 16:{
        float h,f,g;
        n1();
        h = x*x-16;
        if (h >= 0){
          f = h;
        }else{
          f = 1;
        }
        if (x > 5){
          g = x*x+16;
        }else{
          g = -x/2;
        }
        printf("h(x) =%.2f\nf(x) = %.2f\ng(x) = %.2f", h, f, g);
        break;
      }
      default:{
          printf("Questao invalida.\n");
        }
      }
    }




int n1 (){
    printf("Digite o valor de x: ");
    scanf("%f", &x);
    return x;
}
int n2(){
    printf("digite o valor de y: ");
    scanf("%f", &y);
    return y;
}
int n3(){
    printf("digite o valor de z: ");
    scanf("%f", &z);
    return z;
}
