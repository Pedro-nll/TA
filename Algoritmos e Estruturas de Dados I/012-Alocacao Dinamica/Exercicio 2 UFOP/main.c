#include <stdio.h>
#include <stdlib.h>

//Enunciado:
/*Defina uma função que retorne a trasposta de uma matriz m com lins x cols elementos. Utilize o prototipo
int **transposta(int **m, int lins, int cols);
dica: dada uma matriz A de tamanho n x m, lembre-se que sua transposta T tem tamanho m x n e cada celula
Tij = Aij;
*/

int **transposta(int **m, int lins, int cols){
    int **mTransp = malloc (cols * sizeof(int*));
    for(int i = 0; i < cols; i++){
        mTransp[i] = malloc(lins*sizeof(int));
        for(int j = 0; j < lins; j++){
            mTransp[i][j] = m[j][i];
        }
    }
    return mTransp;
}

int main()
{
    int lins = 3, cols = 3;
    int **m = malloc(lins * sizeof(int*));
    for (int i = 0; i < lins; i++) {
        m[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m[i][j] = i + j;
        }
    }

    int **mTransp = transposta(m,lins,cols);
    for(int i = 0; i<lins; i++){
        for(int j=0;j<cols;j++){
            printf("%d ", mTransp[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i<cols; i++){
        free(mTransp[i]);
        free(m[i]);
    }
    free(mTransp);
    free(m);
    return 0;
}
