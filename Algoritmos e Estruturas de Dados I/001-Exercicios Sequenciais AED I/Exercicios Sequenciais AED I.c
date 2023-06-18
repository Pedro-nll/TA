#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n1(),n2(),n3(),QQ();
float y,h,x;

int main(void)
{
    QQ();
}

//Função para escolha de questões
int QQ() {
    int Q;
    printf("Numero da questao: ");
    scanf("%i", &Q);
    //Switch case para cada questão
    switch (Q){
        //Calcular o numero ao cubo, raiz quadrada, raiz cubica, seno, cosseno
        case 1:{
            x = n1();
            printf("Cubo de x = %.1f\n", x*x*x);
            printf("Raiz quadrada de x = %.1f\n", sqrt(x));
            printf("Raiz cubica de x = %.1f\n", cbrt(x));
            printf("Cosseno de x = %.1lf\n", cos((double) x * 3.14 / 180));
            printf("Seno de x = %.1lf\n", sin((double) x * 3.14 / 180));
            break;
        }
        //Ler X e Y e dividir x por y
        case 2:{
            x = n1();
            y = n2();
            printf("O resto da divisao de x por y e %d\n", (int) x % (int) y);
            break;
        }
        //Ler os lados de um retangulo e calcular area e perimetro
        case 3:{
            x = n1();
            y = n2();
            printf("Se x fosse o comprimento de um retangulo e y sua largura, sua area seria %.1f e seu perimetro seria %.1f\n", x*y, x*2+y*2);
            break;
        }
        //Ler o valor da base menor, maior e da altura de um trapezio e calcular sua area
        case 4:{
            x = n1();
            y = n2();
            h = n3();
            printf("Se x fosse a base menor, y a base maior e com sua altura sendo %.1f, sua area seria %.1f", h, (x+y)*h/2);
            break;
        }
        //Calcular uma circunferencia recebendo seu raio
        case 5:{
            x = n1();
            printf("Se x fosse o raio de uma circunferencia, sua area seria = %.2f\n", x*x*3.14);
            break;
        }
        //Calcular o salario final de um funcionario depois de ler seu salario inicial e valor total de vendas, sabendo que ele recebe 4% de comissão
        case 6:{
            x = n1();
            y = n2();
            printf("Se x fosse o salario fixo do funcionario e y o seu valor de vendas, a sua comissao seria $%.2f e seu salario final seria $%.2f\n", y*0.04, x+(y*0.04));
            break;
        }
        //Ler a quantidade de horas trabalhadas, horas extras e o valor do salario minimo e depois calcular o salario total
        case 7:{
            printf("Quantas horas foram trabalhadas? ");
            scanf("%f", &h);
            printf("Quantas horas extras? ");
            scanf("%f", &y);
            printf("Qual e o valor do salario minimo? ");
            scanf("%f", &x);

            printf("O valor a ser recebido e: $%.2f", (h * (x/8)) + (y*(x/4)));
            break;
        }
        //Receber uma quantidade x em horas e transformar em minutos
        case 8:{
            x = n1();
            printf("X em horas e igual a %.2f em minutos", x*60);
            break;
        }
        //Receber uma quantidade x em minutos e transformar em horas
        case 9:{
            x = n1();
            printf("x minutos e igual a %.2f horas.", x/60);
            break;
        }
        //Calcular a distancia entre dois pontos
        case 10:{
            double x2,y2;
            printf("Digite as coordenadas do primeiro ponto (digite x,y): ");
            scanf("%f,%f", &x, &y);
            printf("Digite as coordenadas do segundo ponto(digite x,y): ");
            scanf("%lf,%lf", &x2, &y2);
            printf("A distancia entre os dois pontos e %.1f", sqrt(pow(x2 - (double)x,2)+ pow(y2 - (double)y,2)));
            break;
        }
        default:{
            printf("Questao invalida.");
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
    printf("Digite o valor da altura do trapezio: ");
    scanf("%f", &h);
    return h;
}
