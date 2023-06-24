#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXIMODEPASSAGEIROS 15
#define TAMANHO_CPF 15

typedef struct Passageiro{
    char nome[100];
    char cpf[TAMANHO_CPF];
    char endereco[200];
    char telefone[15];
    int numeroPassagem;
    int id;
    int numeroPoltrona;
    int numeroVoo;
    char horarioVoo[5];
}Passageiro;

int carregaBancoDeDadosDoVooSelecionado(int vooSelecionado,Passageiro *listaDePassageiros);
int menuInicial();
int menuVoos(int vooSelecionado);
int mostrarListaDePassageiros(Passageiro *listaDePassageiros, int quantidadeDePassageiros);
int buscarPassageiroPorNome(Passageiro *listaDePassageiros, int quantidadeDePassageiros);
int buscarPassageiroPorCPF(Passageiro *listaDePassageiros, int quantidadeDePassageiros);
int mostrarListaDeEspera(Passageiro *listaDePassageiros, int quantidadeDePassageiros);
int cadastrarPassageiro(Passageiro *listaDePassageiros, int *quantidadeDePassageiros, int vooSelecionado);
int excluirPassageiro(Passageiro *listaDePassageiros, int *quantidadeDePassageiros, int vooSelecionado);

int main()
{
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


int menuVoos(int vooSelecionado) {
    Passageiro listaDePassageiros[MAXIMODEPASSAGEIROS];
    int quantidadeDePassageiros = 0;

    quantidadeDePassageiros = carregaBancoDeDadosDoVooSelecionado(vooSelecionado, listaDePassageiros);
    int *PONTEIROquantidadeDePassageiros = &quantidadeDePassageiros;

    char voos[][20] = {"VOO BH-RIO", "VOO BH-SP", "VOO BH-BRASILIA"};
    int opcaoMenu = 0;

    printf("---------- EMPRESA AEREA QUEDA LIVRE - %s ----------\n", voos[vooSelecionado - 1]);
    printf("  MENU DE OPCOES  \n");
    printf("[1] Mostrar lista de passageiros\n[2] Pesquisar passageiro por CPF\n");
    printf("[3] Pesquisar passageiro por nome\n[4] Cadastrar passageiro\n");
    printf("[5] Excluir passageiro da lista\n[6] Mostrar lista de espera\n");
    printf("\n[9] Sair\n");
    printf("\nDigite sua opcao: ");

    char input[100];
    while (scanf("%s", input) == 1) {
        if (sscanf(input, "%d", &opcaoMenu) != 1) {
            printf("Valor invalido. Digite um numero inteiro: ");
        } else {
            switch (opcaoMenu) {
                case 1: {
                    mostrarListaDePassageiros(listaDePassageiros, quantidadeDePassageiros);
                    break;
                }
                case 2: {
                    buscarPassageiroPorCPF(listaDePassageiros, quantidadeDePassageiros);
                    break;
                }
                case 3: {
                    buscarPassageiroPorNome(listaDePassageiros, quantidadeDePassageiros);
                    break;
                }
                case 4: {
                    cadastrarPassageiro(listaDePassageiros, PONTEIROquantidadeDePassageiros, vooSelecionado);
                    break;
                }
                case 5: {
                    excluirPassageiro(listaDePassageiros, PONTEIROquantidadeDePassageiros, vooSelecionado);
                    break;
                }
                case 6: {
                    mostrarListaDeEspera(listaDePassageiros, quantidadeDePassageiros);
                    break;
                }
                case 9: {
                    menuInicial();
                    return 0;
                }
                default: {
                    printf("Opcao invalida.\n\n");
                }
            }
        }

        printf("\nDigite sua opcao (Voo selecionado no momento: %s): ", voos[vooSelecionado - 1]);
    }

    return 0;
}


int carregaBancoDeDadosDoVooSelecionado(int vooSelecionado, Passageiro *listaDePassageiros) {
    FILE *bancoDeDados;
    switch (vooSelecionado) {
        case 1: {
            bancoDeDados = fopen("BHRIO.txt", "r");
            printf("CARREGANDO DADOS DO VOO BHRIO...\n");
            break;
        }
        case 2: {
            bancoDeDados = fopen("BHSP.txt", "r");
            printf("CARREGANDO DADOS DO VOO BHSP...\n");
            break;
        }
        case 3: {
            bancoDeDados = fopen("BHBRASILIA.txt", "r");
            printf("CARREGANDO DADOS DO VOO BHBRASILIA...\n");
            break;
        }
        default: {
            printf("Nao foi possivel carregar o banco de dados do voo selecionado.\n");
            return 1;
        }
    }

    if (bancoDeDados == NULL) {
        printf("Nao foi possivel carregar os dados do voo.\n");
        return 1;
    }

    int quantidadeDePassageiros = 0;

    for (int i = 0; i < MAXIMODEPASSAGEIROS; i++) {
        int result = fscanf(bancoDeDados, "id: %d | cpf: %14[^|] | nome: %99[^|] | endereco: %199[^|] | telefone: %14[^|] | numero da passagem: %d | numero da poltrona: %d | numero do voo: %d | horario: %5[^\n]\n",
            &listaDePassageiros[i].id,
            &listaDePassageiros[i].cpf,
            &listaDePassageiros[i].nome,
            &listaDePassageiros[i].endereco,
            &listaDePassageiros[i].telefone,
            &listaDePassageiros[i].numeroPassagem,
            &listaDePassageiros[i].numeroPoltrona,
            &listaDePassageiros[i].numeroVoo,
            &listaDePassageiros[i].horarioVoo);

        if (result == EOF) {
            break;
        }

        quantidadeDePassageiros++;
    }

    fclose(bancoDeDados);
    return quantidadeDePassageiros;
}


int mostrarListaDePassageiros(Passageiro *listaDePassageiros, int quantidadeDePassageiros){
    for(int i = 0; i<quantidadeDePassageiros; i++){
        printf("Passageiro %d - Nome: %s | cpf: %s | numero da passagem: %d | numero da poltrona: %d\n",
            i+1, listaDePassageiros[i].nome, listaDePassageiros[i].cpf, listaDePassageiros[i].numeroPassagem, listaDePassageiros[i].numeroPoltrona);
    }
    return 0;
}

int buscarPassageiroPorNome(Passageiro *listaDePassageiros, int quantidadeDePassageiros){
    char inputNome[100];
    getchar();
    printf("Digite o nome do passageiro: ");
    scanf("%[^\n]",inputNome);
    getchar();
    int passageiroNoVoo = 0;
    for(int i = 0; inputNome[i]; i++){
      inputNome[i] = tolower(inputNome[i]);
    }
    char passageiroAtual[100];
    for(int i = 0; i<quantidadeDePassageiros; i++){
        strcpy(passageiroAtual, listaDePassageiros[i].nome);
        for(int i = 0; passageiroAtual[i]; i++){
          passageiroAtual[i] = tolower(passageiroAtual[i]);
        }
        if(strcmp(passageiroAtual, inputNome) == 0){
            printf("Passageiro: %s - CPF: %s - Telefone: %s - Numero da passagem: %d - Numero da poltrona: %d - Numero do voo: %d - Horario do voo: %s\n",
                   listaDePassageiros[i].nome,
                   listaDePassageiros[i].cpf,
                   listaDePassageiros[i].telefone,
                   listaDePassageiros[i].numeroPassagem,
                   listaDePassageiros[i].numeroPoltrona,
                   listaDePassageiros[i].numeroVoo,
                   listaDePassageiros[i].horarioVoo
                   );
            passageiroNoVoo = 1;
        }
    }
    if(passageiroNoVoo == 0){
        printf("Passageiro nao consta neste voo.\n");
    }
    return 0;
}

int buscarPassageiroPorCPF(Passageiro *listaDePassageiros, int quantidadeDePassageiros){
    char inputCPF[100];
    getchar();
    printf("Digite o CPF do passageiro: ");
    scanf("%[^\n]",inputCPF);
    getchar();
    int passageiroNoVoo = 0;
    for(int i = 0; i<quantidadeDePassageiros; i++){
        if(strcmp(listaDePassageiros[i].cpf, inputCPF) == 0){
            printf("Passageiro: %s - CPF: %s - Telefone: %s - Numero da passagem: %d - Numero da poltrona: %d - Numero do voo: %d - Horario do voo: %s\n",
                   listaDePassageiros[i].nome,
                   listaDePassageiros[i].cpf,
                   listaDePassageiros[i].telefone,
                   listaDePassageiros[i].numeroPassagem,
                   listaDePassageiros[i].numeroPoltrona,
                   listaDePassageiros[i].numeroVoo,
                   listaDePassageiros[i].horarioVoo
                   );
            passageiroNoVoo = 1;
        }
    }
    if(passageiroNoVoo == 0){
        printf("Passageiro nao consta neste voo.\n");
    }
    return 0;
}

int mostrarListaDeEspera(Passageiro *listaDePassageiros, int quantidadeDePassageiros){
    if(quantidadeDePassageiros<=10){
        printf("Esse voo esta sem lista de espera.\n");
    }else{
        for(int i = 10; i<=quantidadeDePassageiros-1; i++){
            printf("Passageiro %d - Nome: %s | cpf: %s | numero da passagem: %d | numero da poltrona: %d\n",
            i+1, listaDePassageiros[i].nome, listaDePassageiros[i].cpf, listaDePassageiros[i].numeroPassagem, listaDePassageiros[i].numeroPoltrona);
        }
    }
    return 0;
}

int cadastrarPassageiro(Passageiro *listaDePassageiros, int *quantidadeDePassageiros, int vooSelecionado) {
    FILE *bancoDeDados;
    switch (vooSelecionado) {
        case 1: {
            bancoDeDados = fopen("BHRIO.txt", "a+");
            break;
        }
        case 2: {
            bancoDeDados = fopen("BHSP.txt", "a+");
            break;
        }
        case 3: {
            bancoDeDados = fopen("BHBRASILIA.txt", "a+");
            break;
        }
        default: {
            printf("Nao foi possivel carregar o banco de dados do voo selecionado.\n");
            return 1;
        }
    }

    if (bancoDeDados == NULL) {
        printf("Nao foi possivel carregar os dados do voo.\n");
        return 1;
    }
    if (*quantidadeDePassageiros >= 15) {
        printf("Fila cheia, a reserva nao pode ser feita.\n");
        return 1;
    }

    int p = *quantidadeDePassageiros;
    int ultimaPoltrona = listaDePassageiros[p-1].numeroPoltrona;
    int ultimaPassagem = listaDePassageiros[p-1].numeroPassagem;

    char input[200];

    printf("----- CADASTRO DE PASSAGEIROS -----\n");
    printf("Digite o nome do passageiro: ");
    getchar();
    scanf("%[^\n]", listaDePassageiros[*quantidadeDePassageiros].nome);
    getchar();

    int cpfValido;
    do {
        cpfValido = 1;
        printf("Digite o CPF do passageiro: ");
        scanf(" %[^\n]", input);
        getchar();
        for (int i = 0; i < *quantidadeDePassageiros - 1; i++) {
            if (strcmp(input, listaDePassageiros[i].cpf) == 0) {
                printf("CPF invalido. Tente novamente:\n");
                cpfValido = 0;
                break;
            }
        }
        if (cpfValido)
            strcpy(listaDePassageiros[*quantidadeDePassageiros].cpf, input);
    } while (!cpfValido);

    printf("Digite o endereco do passageiro: ");
    scanf(" %[^\n]", listaDePassageiros[*quantidadeDePassageiros].endereco);
    getchar();

    printf("Digite o telefone do passageiro: ");
    scanf(" %[^\n]", listaDePassageiros[*quantidadeDePassageiros].telefone);
    getchar();

    strcpy(listaDePassageiros[*quantidadeDePassageiros].horarioVoo, listaDePassageiros[1].horarioVoo);
    listaDePassageiros[*quantidadeDePassageiros].numeroVoo = vooSelecionado;
    listaDePassageiros[*quantidadeDePassageiros].id = *quantidadeDePassageiros+1;
    listaDePassageiros[*quantidadeDePassageiros].numeroPassagem = ultimaPassagem+1;
    listaDePassageiros[*quantidadeDePassageiros].numeroPoltrona = ultimaPoltrona+1;

    fprintf(bancoDeDados, "id: %d | cpf: %s| nome: %s| endereco: %s | telefone: %s | numero da passagem: %d | numero da poltrona: %d | numero do voo: %d | horario: %s\n",
            listaDePassageiros[*quantidadeDePassageiros].id,
            listaDePassageiros[*quantidadeDePassageiros].cpf,
            listaDePassageiros[*quantidadeDePassageiros].nome,
            listaDePassageiros[*quantidadeDePassageiros].endereco,
            listaDePassageiros[*quantidadeDePassageiros].telefone,
            listaDePassageiros[*quantidadeDePassageiros].numeroPassagem,
            listaDePassageiros[*quantidadeDePassageiros].numeroPoltrona,
            listaDePassageiros[*quantidadeDePassageiros].numeroVoo,
            listaDePassageiros[*quantidadeDePassageiros].horarioVoo);
    printf("\n--------CADASTRO COMPLETO--------\n");

    (*quantidadeDePassageiros)++;
    fclose(bancoDeDados);
    return 0;
}

int excluirPassageiro(Passageiro listaDePassageiros[], int *quantidadeDePassageiros, int vooSelecionado) {
    FILE *bancoDeDados;
    switch (vooSelecionado) {
        case 1: {
            bancoDeDados = fopen("BHRIO.txt", "r+");
            break;
        }
        case 2: {
            bancoDeDados = fopen("BHSP.txt", "r+");
            break;
        }
        case 3: {
            bancoDeDados = fopen("BHBRASILIA.txt", "r+");
            break;
        }
        default: {
            printf("Nao foi possivel carregar o banco de dados do voo selecionado.\n");
            return 1;
        }
    }

    if (bancoDeDados == NULL) {
        printf("Nao foi possivel carregar os dados do voo.\n");
        return 1;
    }
    if (*quantidadeDePassageiros == 0) {
        printf("Voo vazio.\n");
        fclose(bancoDeDados);
        return 1;
    }

    int idExcluir;
    printf("Digite o ID do passageiro a ser excluido: ");
    scanf("%d", &idExcluir);

    int indiceExcluir = -1;

    for (int i = 0; i < *quantidadeDePassageiros; i++) {
        if (listaDePassageiros[i].id == idExcluir) {
            indiceExcluir = i;
            break;
        }
    }

    if (indiceExcluir == -1) {
        printf("Passageiro nao encontrado.\n");
        fclose(bancoDeDados);
        return 1;
    }

    for (int i = indiceExcluir; i < *quantidadeDePassageiros - 1; i++) {
        listaDePassageiros[i] = listaDePassageiros[i + 1];
    }

    *quantidadeDePassageiros -= 1;

    fclose(bancoDeDados);
    FILE *bancoDeDados2;
    switch (vooSelecionado) {
        case 1: {
            bancoDeDados2 = fopen("BHRIO.txt", "w");
            break;
        }
        case 2: {
            bancoDeDados2 = fopen("BHSP.txt", "w");
            break;
        }
        case 3: {
            bancoDeDados2 = fopen("BHBRASILIA.txt", "w");
            break;
        }
        default: {
            printf("Nao foi possivel carregar o banco de dados do voo selecionado.\n");
            return 1;
        }
    }

    if (bancoDeDados2 == NULL) {
        printf("Nao foi possivel carregar os dados do voo.\n");
        return 1;
    }

    for (int i = 0; i < *quantidadeDePassageiros; i++) {
        fprintf(bancoDeDados, "id: %d | cpf: %s | nome: %s | endereco: %s | telefone: %s | numero da passagem: %d | numero da poltrona: %d | numero do voo: %d | horario: %s\n",
                listaDePassageiros[i].id, listaDePassageiros[i].cpf, listaDePassageiros[i].nome, listaDePassageiros[i].endereco,
                listaDePassageiros[i].telefone, listaDePassageiros[i].numeroPassagem, listaDePassageiros[i].numeroPoltrona,
                listaDePassageiros[i].numeroVoo, listaDePassageiros[i].horarioVoo);
    }

    fclose(bancoDeDados2);
    printf("Passageiro excluído com sucesso.\n");
    return 0;
}
