#include <stdio.h>
#include <stdlib.h>

//Enunciado:
/*Considere um arquivo texto que armazene números em ponto flutuante em cada uma de suas
linhas. Escreva um programa em C que determine o valor máximo, o valor mínimo e a média
desses valores armazenados no arquivo. Imprima esses valores na tela.*/

//Arquivo texto:
/*
3.14
2.718
1.618
0.577
*/

int main()
{
    FILE *entrada = fopen("entrada.txt", "r");
    if(entrada == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }
    float max,min,qntNumeros = 0,media = 0,nAtual;
    fscanf(entrada, "%f",&max);
    fscanf(entrada, "%f",&min);
    while(fscanf(entrada, "%f\n",&nAtual)==1){
        if(nAtual>max) max = nAtual;
        if(nAtual<min) min = nAtual;
        media += nAtual;
        qntNumeros++;
    }
    media = media/qntNumeros;
    printf("Maior numero: %f\nMenor numero: %f\nMedia: %f\n", max, min, media);
    fclose(entrada);
    return 0;
}
