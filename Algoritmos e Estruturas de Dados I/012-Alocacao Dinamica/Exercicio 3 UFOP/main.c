#include <stdio.h>
#include <stdlib.h>

//Enunciado
/*Crie um programa que le e armazena os seguintes dados de n alunos:
    . numero da matricula
    . tempo no curso (numero de semestres)
    . notas em k avaliacoes
seu programa deve ler os valores de n e k no inicio da execucao
utilize alocação dinamica
*/

typedef struct{
    int matricula;
    int tempo;
    float *notas;
}Aluno;

int main(){
    //Cadastro da quantidade de notas e alunos
    int k, n;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);
    printf("Digite a quantidade de notas: ");
    scanf("%d", &k);

    //Cadastro de alunos
    Aluno *listaDeAlunos = malloc(n*sizeof(Aluno));
    int m=1;
    for(int i = 0; i < n; i++){
        listaDeAlunos[i].notas = malloc(k*sizeof(float));
        listaDeAlunos[i].matricula = m++;
        printf("Ha quanto tempo esse aluno esta no curso? ");
        scanf("%d", &listaDeAlunos[i].tempo);
        for(int j = 0; j<k; j++){
            printf("Digite a nota %d do aluno %d: ", j+1, i+1);
            scanf("%f", &listaDeAlunos[i].notas[j]);
        }
    }

    //Impressão de alunos
    for(int i = 0; i<n; i++){
        printf("\n---------------------------\n");
        printf("Aluno de matricula: %d\nTempo no curso:%d\nNotas:", listaDeAlunos[i].matricula, listaDeAlunos[i].tempo);
        for(int j =0; j<k; j++) j!=k-1? printf("%.2f, ", listaDeAlunos[i].notas[j]) : printf("%.2f", listaDeAlunos[i].notas[j]);
    }

    //Liberação de memoria
    for(int i = 0; i<n; i++)
        free(listaDeAlunos[i].notas);
    free(listaDeAlunos);
    return 0;
}
