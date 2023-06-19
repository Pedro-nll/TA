#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *entrada = fopen("entrada.txt", "w");
    FILE *saida = fopen("saida.txt", "w");
    for(int i = 0; i < 100; i++){
        for(int j = 0; j <100; j++){
            fprintf(entrada, "%d ", (i+1)*(j+1));
        }
        fprintf(entrada,"\n");
    }
    int textoArquivo[100][100];
    fclose(entrada);
    fopen("entrada.txt","r");
    for(int i = 0;i < 100; i++){
        for(int j = 0; j < 100; j++){
            fscanf(entrada,"%d ", &textoArquivo[i][j]);
        }
    }
    for(int i = 99; i >= 0; i--){
        for(int j = 0; j<100; j++){
            fprintf(saida,"%d ", textoArquivo[i][j]);
        }
        fprintf(saida,"\n");
    }
    fclose(entrada);
    fclose(saida);
    return 0;
}
