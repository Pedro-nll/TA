#include <stdio.h>
#include <stdlib.h>

//Enunciado
/*Crie uma função que receba um vetor v e seu tamanho n por parametro, crie um novo vetor por alocação dinamica,
preenchendo-o com o conteudo de V em ordem inversa e retorne esse novo vetor*/

int *inverso(int *v, int n) {
    int *novoVetor = malloc(n * sizeof(int));
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        novoVetor[j++] = v[i];
    }
    return novoVetor;
}

int main() {
    int n = 6;
    int *v = malloc(n * sizeof(int));

    for (int i = 0; i<n; i++) v[i] = i;

    int *v2 = inverso(v, n);
    free(v);

    for (int i = 0; i < n; i++) {
        printf("%d ", v2[i]);
    }
    free(v2);
    return 0;
}
