#include <stdio.h>
#include <stdlib.h>

//Enunciado:
/*Escreva um programa que concatene o conte�do de dois arquivos. O conte�do dos dois
arquivos dever� ser adicionado em um terceiro arquivo.*/
//Arquivo 1:
/*Engenharia de software e uma area da engenharia e da computacao voltada a especificacao, desenvolvimento,
manutencao e criacao de software, com a aplicacao de tecnologias e praticas de gerencia de projetos e outras disciplinas,
visando organizacao, produtividade e qualidade.*/
//Arquivo 2:
/*Atualmente, essas tecnologias e pr�ticas englobam linguagens de programa��o, banco de dados, ferramentas, plataformas,
bibliotecas, padr�es de projeto de software, processo de software e qualidade de software. Al�m disso, a engenharia de
software deve oferecer mecanismos para se planejar e gerenciar o processo de desenvolvimento de um sistema computacional
de qualidade e que atenda �s necessidades de um requisitante de software.*/

int main()
{
    FILE *arq1 = fopen("arquivo1.txt","r");
    FILE *arq2 = fopen("arquivo2.txt","r");
    FILE *saida = fopen("saida.txt", "w");
    if(arq1 == NULL){
        printf("Nao foi possivel abrir o arquivo 1.\n");
        return 1;
    }
    if(arq2 == NULL){
        printf("Nao foi possivel abrir o arquivo 2.\n");
        return 1;
    }
    if(saida == NULL){
        printf("Nao foi possivel criar o arquivo de saida.\n");
        return 1;
    }
    char caractereAtual;
    while(fscanf(arq1,"%c", &caractereAtual) == 1)fprintf(saida,"%c",caractereAtual);
    if(caractereAtual!= '\n')fprintf(saida,"\n");
    while(fscanf(arq2,"%c", &caractereAtual) == 1)fprintf(saida,"%c",caractereAtual);
    fclose(arq1);
    fclose(arq2);
    fclose(saida);
    return 0;
}
