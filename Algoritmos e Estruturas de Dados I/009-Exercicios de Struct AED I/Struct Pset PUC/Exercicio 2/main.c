#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAMANHO 15

//ENUNCIADO:
/*
Uma pessoa cadastrou um conjunto de 15 registros contendo o nome da loja, telefone e preço
de um eletrodoméstico. Desenvolver um algoritmo que permita exibir qual foi a média dos
preços cadastrados e uma relação contendo o nome e o telefone das lojas cujo preço estava
abaixo da média
*/

typedef struct{
    char nomeDaLoja[50];
    char telefone[14];
    int preco;
}Registro;

int main()
{
    //Lista de lojas aleatorias
    Registro listaDeRegistros[TAMANHO];
    srand(time(NULL));
    char telefone[14];
    for(int i = 0; i<TAMANHO; i++){
        long long int min = 5531111111111;
        long long int max = 5531999999999;
        int telefone_aleatorio = min + (rand() % (max-min+1));
        int min2 = 100;
        int max2 = 1000;
        int preco_aleatorio = min2 + (rand() % (max2-min2+1));
        char nomeLoja[50];
        sprintf(nomeLoja, "Loja %d", i+1);
        strcpy(listaDeRegistros[i].nomeDaLoja, nomeLoja);
        sprintf(telefone, "%lld", telefone_aleatorio);
        strcpy(listaDeRegistros[i].telefone, telefone);
        listaDeRegistros[i].preco = preco_aleatorio;
    }
    //Solução
    int media, soma = 0;
    for(int i = 0; i<TAMANHO; i++){
        soma += listaDeRegistros[i].preco;
    }
    media = soma / TAMANHO;
    printf("O preco do eletrodomestico esta abaixo da media nas lojas a seguir:\n");
    for(int i = 0; i< TAMANHO; i++){
        if(listaDeRegistros[i].preco<media){
            printf("%s - Telefone: %s\n", listaDeRegistros[i].nomeDaLoja, listaDeRegistros[i].telefone);
        }
    }
    return 0;
}
