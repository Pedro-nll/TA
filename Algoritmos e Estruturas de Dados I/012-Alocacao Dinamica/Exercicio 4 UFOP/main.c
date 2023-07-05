#include <stdio.h>
#include <stdlib.h>

//Enunciado:
/*
Crie um procedimento alocaMatriz que recebe por parametro:
    1. referencia de um ponteiro para alocar e retornar uma matriz de inteiros
    2. numero de linhas (n)
    3. numero de colunas (m).
A função deve alocar uma matriz n x m dinamicamente e preencher todos os campos com valor zero.
importante: implemente a função main para mostar um exemplo de uso da função criada anteriormente.
*/

void **alocaMatriz (int ***matriz, int n, int m){
    *matriz = calloc(n, sizeof(int*));
    for(int i =0; i<n; i++){
        (*matriz)[i] = calloc(m, sizeof(int));
    }
}

int main()
{
    int **matriz;
    alocaMatriz(&matriz, 3, 3);
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i<3; i++) free(matriz[i]);
    free(matriz);
    return 0;
}
