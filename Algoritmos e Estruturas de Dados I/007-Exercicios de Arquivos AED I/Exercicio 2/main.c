#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Enunciado:
//Crie um programa que receba um texto do usuário e grave o texto em um arquivo.

#define MAX 300

int main()
{
    FILE *saida = fopen("saida.txt","w");
    if(saida == NULL){
        printf("Nao foi possivel criar o arquivo.\n");
        return 1;
    }
    char textoUsuario[MAX];
    fflush(stdin);
    for (int i = 0; i < MAX; i++){
        scanf("%[^\n]", textoUsuario+i);
    }
    for (int i = 0; i<strlen(textoUsuario); i++)fprintf(saida, "%c", textoUsuario[i]);
    fclose(saida);
    return 0;
}
