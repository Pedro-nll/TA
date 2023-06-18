#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    float PrecoPorKg[N];
    for(int i = 0; i < N; i++){
        float P;
        scanf("%f", &P);
        int G;
        scanf("%d", &G);
        PrecoPorKg[i] = (P/G)*1000;
    }
    float menorPreco = PrecoPorKg[0];
    for(int i = 0; i < N; i++){
        if (PrecoPorKg[i]<menorPreco){
            menorPreco = PrecoPorKg[i];
        }
    }
    printf("%.2f", menorPreco);
}
