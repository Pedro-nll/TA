#include <stdio.h>
#include <stdlib.h>

#define MAXIMODEPASSAGEIROS 15
#define TAMANHO_CPF 15

typedef struct Passageiro{
    char nome[100];
    char cpf[TAMANHO_CPF];
    char endereco[200];
    char telefone[15];
    int id;
    int numeroPassagem;
    int numeroPoltrona;
    int numeroVoo;
    char horarioVoo[5];
}Passageiro;

int carregaBancoDeDadosBHRIO(Passageiro *passageirosBHRIO, int tamanhoArray);
int carregaBancoDeDadosBHSP(Passageiro *passageirosBHSP, int tamanhoArray);
int carregaBancoDeDadosBHBRASILIA(Passageiro *passageirosBHBRASILIA, int tamanhoArray);
int menuInicial();
int menuVoos(int vooSelecionado);


int main()
{
    Passageiro passageirosBHRIO[MAXIMODEPASSAGEIROS];
    carregaBancoDeDadosBHRIO(passageirosBHRIO, MAXIMODEPASSAGEIROS);

    Passageiro passageirosBHSP[MAXIMODEPASSAGEIROS];
    carregaBancoDeDadosBHSP(passageirosBHSP, MAXIMODEPASSAGEIROS);

    Passageiro passageirosBHBRASILIA[MAXIMODEPASSAGEIROS];
    carregaBancoDeDadosBHBRASILIA(passageirosBHBRASILIA, MAXIMODEPASSAGEIROS);

    menuInicial();
    return 0;
}

//return 0 - para fechar o programa // sem codigo de erro pq ta num while loop
int menuInicial() {
    int vooSelecionado;
    char input[100];

    do {
        printf("---------- EMPRESA AEREA QUEDA LIVRE ----------\n");
        printf("    MENU DE VOOS    \n");
        printf("[1]BH-RIO\n[2]BH-SP\n[3]BH-BRASILIA\n\n[9]Para fechar o programa.\n\n");
        printf("Digite a opcao referente ao voo desejado: ");

        do {
            scanf("%s", input);
            if (sscanf(input, "%d", &vooSelecionado) != 1) {
                printf("Valor invalido. Digite um numero inteiro: ");
            }
        } while (sscanf(input, "%d", &vooSelecionado) != 1);

        switch (vooSelecionado) {
            case 1: {
                menuVoos(1);
                break;
            }
            case 2: {
                menuVoos(2);
                break;
            }
            case 3: {
                menuVoos(3);
                break;
            }
            case 9: {
                return 0;
                break;
            }
            default: {
                printf("Voo invalido.\n\n");
            }
        }
    } while (vooSelecionado != 1 && vooSelecionado != 2 && vooSelecionado != 3);

    return 0;
}


int menuVoos(int vooSelecionado){
    char voos[][20] = {"VOO BH-RIO", "VOO BH-SP", "VOO BH-BRASILIA"};
    int opcaoMenu;
    printf("---------- EMPRESA AEREA QUEDA LIVRE - %s ----------\n", voos[vooSelecionado-1]);
    printf("  MENU DE OPCOES  \n");
    printf("[1]Mostrar lista de passageiros\n[2]Pesquisar passageiro por CPF\n[3]Pesquisar passageiro por nome\n");
    printf("[4]Cadastrar passageiro\n[5]Excluir passageiro da lista\n[6]Mostrar lista de espera\n");
    printf("\n[9]Sair\n");
    printf("\nDigite sua opcao: ");

    char input[100];
    do{
        scanf("%s", input);
        if (sscanf(input, "%d", &opcaoMenu) != 1) {
                printf("Valor invalido. Digite um numero inteiro: ");
            }
    }while(sscanf(input, "%d", &opcaoMenu) != 1);

    switch(opcaoMenu){
        case 9:{
            menuInicial();
            return 0;
        }
        default:{
            printf("Opcao invalida.\n\n");
            menuVoos(vooSelecionado);
        }
    }
    return 0;
}

int carregaBancoDeDadosBHRIO(Passageiro *passageirosBHRIO, int tamanhoArray) {
    FILE *BDbhrj = fopen("BHRIO.txt", "r");

    if (BDbhrj == NULL) {
        printf("Nao foi possivel carregar os dados do voo BHRIO.");
        return 1;
    }
    for(int i = 0; i < tamanhoArray;i++){
        fscanf(BDbhrj, "id: %d | cpf: %14[^|] | nome: %99[^|] | endereco: %199[^|] | telefone: %14[^|] | numero da passagem: %99[^|] | numero da poltrona: %d | numero do voo: %d | horario: %5[^\n]\n",
            &passageirosBHRIO[i].id,
            &passageirosBHRIO[i].cpf,
            &passageirosBHRIO[i].nome,
            &passageirosBHRIO[i].endereco,
            &passageirosBHRIO[i].telefone,
            &passageirosBHRIO[i].numeroPassagem,
            &passageirosBHRIO[i].numeroPoltrona,
            &passageirosBHRIO[i].numeroVoo,
            &passageirosBHRIO[i].horarioVoo);

    }

    fclose(BDbhrj);
    return 0;
}

int carregaBancoDeDadosBHSP(Passageiro *passageirosBHSP, int tamanhoArray) {
    FILE *BDbhsp = fopen("BHSP.txt", "r");

    if (BDbhsp == NULL) {
        printf("Nao foi possivel carregar os dados do voo BHSP.");
        return 1;
    }
    for(int i = 0; i < tamanhoArray;i++){
        fscanf(BDbhsp, "id: %d | cpf: %14[^|] | nome: %99[^|] | endereco: %199[^|] | telefone: %14[^|] | numero da passagem: %99[^|] | numero da poltrona: %d | numero do voo: %d | horario: %5[^\n]\n",
            &passageirosBHSP[i].id,
            &passageirosBHSP[i].cpf,
            &passageirosBHSP[i].nome,
            &passageirosBHSP[i].endereco,
            &passageirosBHSP[i].telefone,
            &passageirosBHSP[i].numeroPassagem,
            &passageirosBHSP[i].numeroPoltrona,
            &passageirosBHSP[i].numeroVoo,
            &passageirosBHSP[i].horarioVoo);

    }

    fclose(BDbhsp);
    return 0;
}

int carregaBancoDeDadosBHBRASILIA(Passageiro *passageirosBHBRASILIA, int tamanhoArray){
    FILE *BDbhbrasilia = fopen("BHBRASILIA.txt", "r");

    if (BDbhbrasilia == NULL) {
        printf("Nao foi possivel carregar os dados do voo BHBRASILIA.");
        return 1;
    }
    for(int i = 0; i < tamanhoArray;i++){
        fscanf(BDbhbrasilia, "id: %d | cpf: %14[^|] | nome: %99[^|] | endereco: %199[^|] | telefone: %14[^|] | numero da passagem: %99[^|] | numero da poltrona: %d | numero do voo: %d | horario: %5[^\n]\n",
            &passageirosBHBRASILIA[i].id,
            &passageirosBHBRASILIA[i].cpf,
            &passageirosBHBRASILIA[i].nome,
            &passageirosBHBRASILIA[i].endereco,
            &passageirosBHBRASILIA[i].telefone,
            &passageirosBHBRASILIA[i].numeroPassagem,
            &passageirosBHBRASILIA[i].numeroPoltrona,
            &passageirosBHBRASILIA[i].numeroVoo,
            &passageirosBHBRASILIA[i].horarioVoo);

    }

    fclose(BDbhbrasilia);
    return 0;
}

