#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Enuciado:
/*Implemente um programa que abra o arquivo texto (criado no exercício anterior) e conte a
quantidade de caracteres ‘a’ que estão presentes nele. Imprima a quantidade na tela.*/
//Exercicio anterior:
//Crie um programa que receba um texto do usuário e grave o texto em um arquivo.
//Texto gravado:
/*
"Engenharia de software e uma area da engenharia e da computacao voltada a especificacao,
desenvolvimento, manutencao e criacao de software, com a aplicacao de tecnologias e praticas
de gerencia de projetos e outras disciplinas, visando organizacao, produtividade e qualidade."
*/

int main()
{
    FILE *entrada = fopen("saida.txt", "r");
    if(entrada == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }
    int contador = 0;
    char caractereAtual;
    while (fscanf(entrada, "%c", &caractereAtual) == 1) {
        if (caractereAtual == 'a' || caractereAtual == 'A') {
            contador++;
        }
    }
    printf("%d", contador);
    fclose(entrada);
    return 0;
}
