#include <stdio.h>
#include <stdlib.h>

//Enunciado:
/*Faça um programa para inserir N letras informadas pelo usuário em um arquivo texto. Onde
N é uma quantidade de letras definida pelo usuário. Depois de inseridas as N letras, o
programa deverá ler todas as N letras do arquivo, calcular e mostrar a quantidade de vogais,
ou seja, quantas letras a, e, i, o, u*/


int main()
{
    FILE *saida = fopen("saida.txt", "w");
    if (saida == NULL) {
        printf("Não foi possível criar o arquivo.\n");
        return 1;
    }

    int n;
    printf("Digite a quantidade de letras a serem informadas: ");
    scanf("%d", &n);

    char letras[n];

    for (int i = 0; i < n; i++) {
        printf("Digite a letra %d: ", i + 1);
        scanf(" %c", &letras[i]);
        fprintf(saida, "%c", letras[i]);
    }

    fclose(saida);

    int contador = 0;
    FILE *arquivo = fopen("saida.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    char caractereAtual;
    while (fscanf(arquivo, "%c", &caractereAtual) == 1) {
        if (caractereAtual == 'a' || caractereAtual == 'e' || caractereAtual == 'i' ||
            caractereAtual == 'o' || caractereAtual == 'u') {
            contador++;
        }
    }

    fclose(arquivo);

    printf("Foram digitadas %d vogais.\n", contador);

    return 0;
}
