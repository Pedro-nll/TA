#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 500

//ENUNCIADO:
/*
Um provedor de acesso à Internet mantém o seguinte cadastro de clientes: código do cliente,
e-mail, número de horas de acesso, página (S-sim ou N-não). Elaborar um algoritmo
que calcule e mostre um relatório contendo o valor a pagar por cada cliente, sabendo-se que
as primeiras 20 horas de acesso é R$35,00 e as horas que excederam tem o custo de R$2,50
por hora. Para os clientes que têm página, adicionar R$40,00. Inserir um conjunto de
registros (máximo 500)
*/

typedef struct{
    int codigoDoCliente;
    int numeroDeHorasDeAcesso;
    char pagina;
    char email[100];
}Cliente;

Cliente cadastroDeCliente(Cliente c){
    printf("Digite o codigo do cliente: ");
    scanf("%d", &c.codigoDoCliente);
    printf("Digite o numero de horas de acesso: ");
    scanf("%d", &c.numeroDeHorasDeAcesso);
    printf("O cliente tem pagina? ");
    scanf(" %c", &c.pagina);
    getchar();
    printf("Digite o email do cliente: ");
    scanf("%[^\n]", c.email);
    return c;
}

int main()
{
    Cliente listaDeClientes[MAX];
    srand(time(NULL));
    //gera um registro aleatorio de 250 clientes
    for(int i = 0; i<MAX/2; i++){
        listaDeClientes[i].codigoDoCliente = i+1;
        char email[100];
        sprintf(email, "pessoa%d@gmail.com", i+1);
        strcpy(listaDeClientes[i].email,email);
        int min = 1;
        int max = 730; //Numero de horas em um mês.
        int nHorasAcesso_aleatorio = min + (rand() % (max - min + 1));
        listaDeClientes[i].numeroDeHorasDeAcesso = nHorasAcesso_aleatorio;
        int min2 = 1;
        int max2 = 2; //Numero de horas em um mês.
        int pagina_aleatorio = min2 + (rand() % (max2 - min2 + 1));
        if(pagina_aleatorio == 1) listaDeClientes[i].pagina = 's';
        else listaDeClientes[i].pagina = 'n';
    }
    //Solução
    int opcao, novosClientes=0;
    do{
        printf("Digite 1 para cadastrar um cliente e 2 para receber o relatorio de contas a pagar por cliente: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                int n;
                printf("Quantos clientes deseja cadastrar? ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++){
                    Cliente c;
                    listaDeClientes[MAX/2+i] = cadastroDeCliente(c);
                    novosClientes++;
                }
                break;
            }
            case 2:{
                for(int i = 0; i<MAX/2+novosClientes; i++){
                    float soma = 0.0;
                    if(listaDeClientes[i].numeroDeHorasDeAcesso<21) soma += 35;
                    else soma += 35 + ((listaDeClientes[i].numeroDeHorasDeAcesso-20)* 2.5);
                    if(listaDeClientes[i].pagina == 's') soma += 40;
                    printf("O cliente %d deve pagar %.2f reais.\n", listaDeClientes[i].codigoDoCliente, soma);
                }
                break;
            }
        }
    }while(opcao != 0);
    return 0;
}
