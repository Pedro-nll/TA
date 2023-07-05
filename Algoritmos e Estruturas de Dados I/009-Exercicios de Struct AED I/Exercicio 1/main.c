#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 40

//ENUNCIADO:
/*
Dados os seguintes campos de um registro: nome, dia de aniversário e mês de aniversário,
desenvolver um algoritmo que mostre em cada um dos meses do ano quem são as pessoas
que fazem aniversário, exibir também o dia. Considere um conjunto de 40 pessoas.
*/

typedef struct{
    char nome[50];
    int diaDeNiver;
    int mesDeNiver;
}Pessoa;

int main()
{
    //Registro de pessoas aleatorias
    Pessoa listaDePessoas[TAMANHO];
    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        int min = 1;
        int max = 28;
        int numero_aleatorio = min + (rand() % (max - min + 1));
        int min2 = 1;
        int max2 = 12;
        int numero_aleatorio2 = min2 + (rand() % (max2 - min2 + 1));
        char nomePessoa[50];
        sprintf(nomePessoa, "Pessoa %d", i + 1);
        strcpy(listaDePessoas[i].nome, nomePessoa);
        listaDePessoas[i].diaDeNiver = numero_aleatorio;
        listaDePessoas[i].mesDeNiver = numero_aleatorio2;
    }
    //solução
    for(int i = 1; i<=12; i++){
        printf("No mes %d as seguintes pessoas fazem aniversario:\n",i);
        for(int j = 0; j<TAMANHO; j++){
            if(listaDePessoas[j].mesDeNiver == i)printf("%s - no dia %d\n", listaDePessoas[j].nome, listaDePessoas[j].diaDeNiver);
        }
        printf("\n");
    }
    return 0;
}
