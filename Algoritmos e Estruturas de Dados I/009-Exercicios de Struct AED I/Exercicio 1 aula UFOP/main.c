#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    float altura;
    int anoDeNascimento;
} Pessoa;

Pessoa cadastroDePessoa(Pessoa pessoa, int n){
    printf("Digite o nome da pessoa: ");
    getchar();
    scanf("%[^\n]", pessoa.nome);
    getchar();
    printf("Digite a altura da pessoa: ");
    scanf("%f", &pessoa.altura);
    printf("Digite o ano de nascimento da pessoa: ");
    scanf("%d", &pessoa.anoDeNascimento);
    return pessoa;
}

void imprimeLista(Pessoa pessoas[], int n){
    for(int i=0; i<n; i++){
        printf("----------- PESSOA %d ------------\n", i+1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Altura: %.2f\n", pessoas[i].altura);
    }
}

void imprimePessoasPorAno(Pessoa pessoas[], int n, int ano){
    for(int i = 0; i<n; i++){
        if(pessoas[i].anoDeNascimento>ano)printf("%s\n", pessoas[i].nome);
    }
}

int main()
{
    int opcao, n = 0;
    Pessoa listaDePessoas[100];
    do{
        printf("Digite:\n1 - Para inserir uma nova pessoa.\n2 - Para listar todos os nomes e alturas\n3 - Para listar o nome de todas as pessoas que nasceram depois de um certo ano\n0 - Para parar.\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                listaDePessoas[n] = cadastroDePessoa(listaDePessoas[n], n);
                n++;
                break;
            }
            case 2:{
                imprimeLista(listaDePessoas, n);
                break;
            }
            case 3:{
                int ano;
                printf("Digite o ano desejado: ");
                scanf("%d", &ano);
                imprimePessoasPorAno(listaDePessoas, n, ano);
                break;
            }
        }
    }while(opcao != 0);
    return 0;
}
