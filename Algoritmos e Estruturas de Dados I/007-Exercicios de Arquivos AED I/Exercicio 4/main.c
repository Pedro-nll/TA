#include <stdio.h>
#include <stdlib.h>

//Enunciado
/*Implemente um programa que leia um arquivo texto e imprima, linha a linha, o seu conteúdo
na tela. Imprima também a quantidade de linhas que este arquivo possui.*/
//Arquivo texto:
/*Engenharia de software e uma area da engenharia e da computacao voltada a especificacao, desenvolvimento,
manutencao e criacao de software, com a aplicacao de tecnologias e praticas de gerencia de projetos e outras disciplinas,
visando organizacao, produtividade e qualidade.*/
//Quantidade de linhas:3

int main()
{
    FILE *entrada = fopen("saida.txt", "r");
    if(entrada == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }
    int contador = 0;
    char caractereAtual;
    while(fscanf(entrada, "%c", &caractereAtual) == 1){
        printf("%c", caractereAtual);
        if(caractereAtual == '\n') contador++;
    }
    //Verifica se o arquivo nao terminou em uma quebra de linha e contabiliza isso
    if (caractereAtual != '\n') {
        contador++;
    }
    printf("\nQuantidade de linhas: %d\n", contador);
    fclose(entrada);
    return 0;
}
