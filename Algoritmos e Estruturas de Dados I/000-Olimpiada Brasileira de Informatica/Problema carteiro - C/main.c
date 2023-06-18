#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int casas[N];
    for(int i =0; i < N; i++){
        scanf("%d", casas + i);
    }
    int entregas[M];
    for(int i = 0; i<M; i++){
        scanf("%d", entregas + i);
    }
    int passos = 0;
    int casaAtual = 0;
    for(int i = 0; i < M; i++){
        if(entregas[i]>casas[casaAtual]){
            for(int j = 0; j<N; j++){
                if(entregas[i] == casas[casaAtual + j]){
                    casaAtual += j;
                    break;
                }
                else{
                    passos++;
                }
            }
        }else{
            for(int j = 0; j<N; j++){
                if(entregas[i] == casas[casaAtual - j]){
                    casaAtual -= j;
                    break;
                }
                else{
                    passos++;
                }
            }
        }
    }
    printf("%d", passos);
    return 0;
}
