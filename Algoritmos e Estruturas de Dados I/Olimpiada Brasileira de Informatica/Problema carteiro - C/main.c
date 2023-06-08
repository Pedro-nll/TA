#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Entrada
    int N, M;
    scanf("%d %d", &N, &M);
    int arrayCasas[N], arrayEntregas[M];
    //Guarda o numero das casas (obrigatoriamente em ordem crescente)
    for(int i = 0; i < N; i++){
        scanf("%d", arrayCasas+i);
    }
    //Le o endereço de cada entrega
    for (int i = 0; i<M; i++){
        scanf("%d", arrayEntregas+i);
    }
    //Solução
    int casaAtual=0;//Salva a POSIÇÂO da casa atual
    int contadorPassos = 0; //Variavel que registra a saída
    //roda 1 vez pra cada entrega
    for(int i = 0; i<M; i++){
        //Condição que decide se o entregador deve andar no sentido crescente ou decrescente das casas
        if(arrayEntregas[i]>arrayCasas[casaAtual]){
            //Loop contando quantos passos até chegar na casa desejada
            for(int j = 0; j<N; j++){
                if(arrayCasas[casaAtual+j] != arrayEntregas[i]){
                    contadorPassos++;
                }else{
                    casaAtual=casaAtual+j;
                    break;
                }
            }
        }else if(arrayEntregas[i]<arrayCasas[casaAtual]){
            //Loop contando quantos passos até chegar na casa desejada
            for(int j = 0; j<N; j++){
                if(arrayCasas[casaAtual-j] != arrayEntregas[i]){
                    contadorPassos++;
                }else{
                    casaAtual=casaAtual-j;
                    break;
                }
            }
        }
    }
    printf("%d", contadorPassos);
    return 0;
}
