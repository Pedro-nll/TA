#include <stdio.h>
#include <stdlib.h>

#define TAMANHOMAX 50

typedef struct{
    char nome[50];
    char funcao[50];
    int idade;
    float salario;
}Funcionario;

int main()
{
    Funcionario listaDeFuncionarios[TAMANHOMAX];
    int n;
    printf("Digite o numero de funcionarios: ");
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        printf("Digite o nome do funcionario: ");
        getchar();
        scanf("%[^\n]", listaDeFuncionarios[i].nome);
        getchar();
        printf("Digite a funcao do funcionario: ");
        scanf("%[^\n]", listaDeFuncionarios[i].funcao);
        getchar();
        printf("Digite a idade do funcionario: ");
        scanf("%d", &listaDeFuncionarios[i].idade);
        printf("Digite o salario do funcionario: ");
        scanf("%f", &listaDeFuncionarios[i].salario);
    }
    for(int i=0;i<n;i++){
        printf("Nome do funcionario %d: %s\n", i+1, listaDeFuncionarios[i].nome);
        printf("Funcao do funcionario %d: %s\n", i+1, listaDeFuncionarios[i].funcao);
        printf("Idade do funcionario %d: %d\n", i+1, listaDeFuncionarios[i].idade);
        printf("Salario do funcionario %d: %.2f\n", i+1, listaDeFuncionarios[i].salario);
    }
    return 0;
}
