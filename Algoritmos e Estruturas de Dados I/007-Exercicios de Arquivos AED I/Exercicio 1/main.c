#include <stdio.h>
#include <stdlib.h>

//Enunciado:
/*Crie um programa que escreva de 1 at� 10 em um arquivo, armazenando um n�mero por
linha.*/

#define MAX 10

int main()
{
    FILE * arq = fopen("saida.txt", "w");
    if(arq==NULL){
        printf("Nao foi possivel criar o arquivo.");
        return 1;
    }
    for(int i=1; i<=MAX; i++){
        fprintf(arq, "%d\n", i);
    }
    fclose(arq);
    return 0;
}
