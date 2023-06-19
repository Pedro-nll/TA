#include <stdio.h>
#include <stdlib.h>

//Enunciado:
/*Crie um programa que receba dados de vários alunos (Matricula e Telefone) e armazene em
um arquivo texto. Crie no mesmo programa uma opção de ler dados de um arquivo já
armazenado dados de alunos.*/

#define TAMANHOMATRICULA 4
#define TAMANHOTELEFONE 9

int cadastraAluno(){
    FILE *saida = fopen("bancoDeAlunos.txt", "a+");
    if(saida == NULL){
        saida = fopen("bancoDeAlunos.txt", "w");
        if(saida == NULL){
            printf("Nao foi possivel criar o banco de dados dos alunos.\n");
            return 1;
        }
    }
    int n;
    printf("Quantos alunos seram cadastrados? ");
    scanf("%d", &n);
    char matricula[TAMANHOMATRICULA];
    char telefone[TAMANHOTELEFONE];
    for (int j = 1; j<=n; j++){
        printf("Digite a matricula do aluno %d (no formato 0000): ", j);
        for(int i = 0; i<TAMANHOMATRICULA; i++){
            fscanf(stdin, " %c", &matricula[i]);
        }
        printf("Digite o telefone do aluno %d (no formato 998288251): ", j);
        for(int i = 0; i<TAMANHOTELEFONE; i++){
            fscanf(stdin," %c", &telefone[i]);
        }
        fprintf(saida, "Aluno de matricula: ");
        for(int i = 0; i < TAMANHOMATRICULA; i++)fprintf(saida, "%c", matricula[i]);
        fprintf(saida, " - telefone: ");
        for(int i = 0; i < TAMANHOTELEFONE; i++)fprintf(saida, "%c", telefone[i]);
        fprintf(saida,"\n");
    }
    fclose(saida);
    return 0;
}

int lerDados(){
    FILE *entrada = fopen("bancoDeAlunos.txt", "r");
    if(entrada == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }
    char caractereAtual;
    while(fscanf(entrada, "%c", &caractereAtual)==1){
        printf("%c", caractereAtual);
    }
    if(caractereAtual != '\n') printf("\n");
    fclose(entrada);
    return 0;
}

int main()
{
    int opcao;
    printf("digite 1 para cadastrar alunos e 2 para ver os dados cadastrados: ");
    scanf(" %d", &opcao);
    switch(opcao){
        case 1:{
            cadastraAluno();
            break;
        }
        case 2:{
            lerDados();
            break;
        }
        default:{
            printf("Opcao invalida.\n");
            return 1;
        }
    }
    return 0;
}
